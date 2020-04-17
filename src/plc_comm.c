/**
  * @file  plc_comm.c
  * @brief  PLC通信功能的实现
  * @author hyafz   
  */
/* includes -----------------------------------------------------------------*/
#include <string.h>
#include <stdio.h>
#include <rtthread.h>
#ifdef RT_USING_DEVICE
#include <rtdevice.h>
#endif
#include "plc_port.h"
#include "plc_debug.h"
#include "plc_cfg.h"
#include "plc_timer.h"
#include "plc_io.h"
#include "plc_stat.h"
#include "plc_comm.h"

/* Private define -----------------------------------------------------------*/
/* Private typedef ----------------------------------------------------------*/
/* Private macro ------------------------------------------------------------*/
#define MIN_CMD_FRAME_LENGTH            6	/**< 帧头(2bytes) + 帧长(2bytes) + cmd(1byte) + data(0bytes) + checksum(1byte) */
#define CMD_RESPONSE_FRAME_MAX_LENGTH	32

/* Variables ----------------------------------------------------------------*/
static struct rt_semaphore CommRxSem;  /* 用于接收消息的信号量 */
static struct rt_thread PlcCommThread;
#define PLC_COMM_THREAD_STK_SIZE    256
static unsigned char PlcCommThreadStk[PLC_COMM_THREAD_STK_SIZE];

#ifdef RT_USING_DEVICE
static rt_device_t CommDev;            /* PLC串口设备句柄  */
#endif

unsigned char CommRxBuf[RX_DATA_BUF_SIZE];
unsigned int CommRxCnt = 0;
int CommRxTimeCnt = 0;
/* Private function declaration ---------------------------------------------*/
/* Functions ----------------------------------------------------------------*/
void plcCommRxTimeoutCheck(void)
{
/** 接收超时时长，单位ms。        每毫秒计数加一，每收到一个字节将超时计数清零。
      * 如果计数超过超时值则认为传输已中断，将接收计数清零，防止某一帧接收错误影响下一帧的接收。
      * 必须小于上位机重发间隔时长。原理：
      * 上位机发送完一帧后，等待下位机回应。
      * 如果下位机没有收到完整的帧，则不会应答，过了超时时间后，则会清除接收缓存区中已收到的字节，丢弃当前帧，等待接收下一帧。
      * 上位机未收到应答，则会启动重发，使收发过程恢复正常状态。
      * 如果重发间隔时长小于接收超时时长，则下位机会将重发的数据
      * 与缓存区已接收数据组合成一个错误的帧，同时破坏了两帧数据。
      * 目前上位机重发时间设置为3000ms
*/
#define RX_TIMEOUT  1000
    rt_base_t level;
    CommRxTimeCnt++;
    if(CommRxTimeCnt > RX_TIMEOUT){
        CommRxTimeCnt = 0;
        level = rt_hw_interrupt_disable();
        CommRxCnt = 0;
        rt_hw_interrupt_enable(level);
#ifndef RT_USING_DEVICE
        extern void devCommRxStart(void);
        devCommRxStart();
#endif
    }
}

/**
 * @brief 计算校验和
 * @param frame
 * @return
 */
unsigned char checkSumCalc(unsigned char* frame, int length)
{
    unsigned char checksum = 0;
	int i;
    for(i = 2; i < length - 1; i++){
        checksum += frame[i];
    }
    return checksum;
}

/**
  * @brief 生成并发送数据帧
  * @param cmd 命令码
  * @param data 附加数据
  * @param length 附加数据长度
  */
void plcCommDataFrameSend(unsigned char cmd, unsigned char* data, int length)
{
	int i;
	unsigned char checksum = 0;
	int frameLen = MIN_CMD_FRAME_LENGTH + length;
	unsigned char buf[5];
	buf[0] = 0xa5;
	buf[1] = 0x5a;
	buf[2] = (unsigned char)(frameLen & 0xFF);
	buf[3] = (unsigned char)((frameLen >> 8) & 0xFF);
	buf[4] = cmd;
	for(i = 2; i < 5; i++){
		checksum += buf[i];
	}
	for(i = 0; i < length; i++){
		checksum += data[i];
	}
	/* 发送字符串 */
#ifdef RT_USING_DEVICE
	rt_device_write(CommDev, 0, buf, 5);
    rt_device_write(CommDev, 0, data, length);
    rt_device_write(CommDev, 0, &checksum, 1);
#else
    extern void devCommSend(unsigned char* pbuf, unsigned int size);
    devCommSend(buf, 5);
    devCommSend(data, length);
    devCommSend(&checksum, 1);
#endif
}

#define CMD_BUF_SIZE    64
static char CmdBuf[CMD_BUF_SIZE];
extern void iapModeEnter(void);
static unsigned char CmdDataBuf[CMD_RESPONSE_FRAME_MAX_LENGTH - MIN_CMD_FRAME_LENGTH];
/**
  * @brief 命令处理
  */
void cmdProcess(void)
{
    int dataLen = 0;
    unsigned char cmd = CMD_NONE;
    cmd = (unsigned char)CmdBuf[4];
    switch(cmd){
        case CMD_ENTER_IAP_MODE:
            if(isRunMode() == 1){
                //开关处于运行模式不允许进入IAP模式
                CmdDataBuf[0] = 0x01;
                dataLen = 1;
            }else{
                //开关处于停止模式允许进入IAP模式
                iapModeEnter();
            }
            break;
        case CMD_PROGRAM_READY:
        case CMD_PROGRAMMING:
        case CMD_PROGRAM_OVER:
        case CMD_JUMP_TO_APP:
            /* IAP模式下才会收到的命令，不需要做任何处理，或者只需要回复当前不处于IAP模式。 */
            break;
        default:
            dataLen = 0;
            break;
    }

    plcCommDataFrameSend(cmd, CmdDataBuf, dataLen);
}

void plcCommDataReceived()
{
    rt_base_t level;
    unsigned int length = 0;
    unsigned char restartFlag = 0;

    CommRxTimeCnt = 0;    //清除用于断帧的超时计数

    if(CommRxCnt > RX_DATA_BUF_SIZE){
        //接收出错，重新开始接收。
        restartFlag = 1;
    }else if(CommRxCnt >= 2){
        /* 命令帧格式：帧头2字节（0xa5, 0x5a） + 帧长度2字节 + 命令码1字节 + 命令数据n（n >= 0)字节 + 校验和1字节 */
        if((CommRxBuf[0] != (char)0xa5) || (CommRxBuf[1] != (char)0x5a)){
            /* 帧头不正确，重新开始接收 */
            restartFlag = 1;
        }else if(CommRxCnt >= 4){
            length = (unsigned int)CommRxBuf[2] \
                + ((unsigned int)CommRxBuf[3] << 8);
            if(length > RX_DATA_BUF_SIZE){
                /* 帧长超过了最大帧长，是一种错误，重新开始接收 */
                restartFlag = 1;
            }else if(length == CommRxCnt){
                /* 接收一帧完成，进行校验与处理 */
                if(CommRxBuf[CommRxCnt - 1] == checkSumCalc(CommRxBuf, CommRxCnt)){
                    //校验通过
                    memcpy(CmdBuf, CommRxBuf, CommRxCnt);
                    rt_sem_release(&CommRxSem);
                }
                restartFlag = 1;
            }
        }
    }
    if(restartFlag == 1){
        memset(CommRxBuf, 0, CommRxCnt);
        level = rt_hw_interrupt_disable();
        CommRxCnt = 0;
        rt_hw_interrupt_enable(level);
    }
}

#ifdef RT_USING_DEVICE
/* 接收数据回调函数 */
static rt_err_t plcCommRxIndicate(rt_device_t dev, rt_size_t size)
{
    int rxCnt = 0;
    /* 串口接收到数据后产生中断，调用此回调函数，然后发送接收信号量 */
    if (size > 0)
    {
        rxCnt = rt_device_read(CommDev, 0, &CommRxBuf[CommRxCnt], size);
        if (rxCnt > 0){
            CommRxCnt += rxCnt;
            plcCommDataReceived();
        }
    }
    return RT_EOK;
}
#endif

/**
 * @brief PLC通信处理线程
 */
static void plcCommProcess(void *parameter)
{
    while (1)
    {
        rt_sem_control(&CommRxSem, RT_IPC_CMD_RESET, RT_NULL);
        rt_sem_take(&CommRxSem, RT_WAITING_FOREVER);
        /* 通信指令处理 */
        cmdProcess();
    }
}

/**
 * @brief PLC通信初始化并启动
 */
void plcCommInit(void)
{
    rt_err_t err;
    /* 初始化信号量 */
    rt_sem_init(&CommRxSem, "comm_rx_sem", 0, RT_IPC_FLAG_FIFO);

#ifdef RT_USING_DEVICE
    err = RT_EOK;
    struct serial_configure config = RT_SERIAL_CONFIG_DEFAULT;  /* 初始化配置参数 */
    /* 查找系统中的串口设备 */
    CommDev = rt_device_find(PLC_UART_NAME);
    if (!CommDev)
    {
        rt_kprintf("find %s failed!\n", PLC_UART_NAME);
        return;
    }

    /* 修改串口配置参数 */
    config.baud_rate = BAUD_RATE_115200;      //修改波特率为 115200
    config.data_bits = DATA_BITS_8;           //数据位 8
    config.stop_bits = STOP_BITS_1;           //停止位 1
    config.bufsz     = RX_DATA_BUF_SIZE;      //修改缓冲区 buff size
    config.parity    = PARITY_NONE;           //无奇偶校验位

    /* 控制串口设备。通过控制接口传入命令控制字，与控制参数 */
    err = rt_device_control(CommDev, RT_DEVICE_CTRL_CONFIG, &config);
    if(err != RT_EOK){
        return;
    }

    /* 设置接收回调函数 */
    rt_device_set_rx_indicate(CommDev, plcCommRxIndicate);

    /* 以中断接收及轮询发送模式打开串口设备 */
    rt_device_open(CommDev, RT_DEVICE_FLAG_INT_RX);
#else
    extern void devCommInit(void);
    extern void devCommRxStart(void);
    devCommInit();
    /* PLC主通信端口接收启动 */
    devCommRxStart();

#endif

    /* 初始化 plc_comm_process 线程 */
    err = rt_thread_init(&PlcCommThread,
                         "plc_comm_process",
                         plcCommProcess,
                         (void*)0,
                         (void*)PlcCommThreadStk,
                         (unsigned int)PLC_COMM_THREAD_STK_SIZE,
                         1,
                         10);

    RT_ASSERT(RT_EOK == err);
    /* 创建成功则启动线程 */
    rt_thread_startup(&PlcCommThread);
}

