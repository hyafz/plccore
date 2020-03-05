/**
  * @file  plc_comm.c
  * @brief  PLC通信功能的实现
  * @author hyafz   
  */
/* includes -----------------------------------------------------------------*/
#include <string.h>
#include <stdio.h>
#include <rtthread.h>
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

/** 接收超时时长，单位ms。        每毫秒计数加一，每收到一个字节将超时计数清零。
  * 如果计数超过超时值则认为传输已中断，将接收计数清零，防止某一帧接收错误影响下一帧的接收。
  * 必须小于上位机重发间隔时长。原理：
  * 上位机发送完一帧后，等待下位机回应。
  * 如果下位机没有收到完整的帧，则不会应答，过了超时时间后，则会清除接收缓存区中已收到的字节，丢弃当前帧，等待接收下一帧。
  * 上位机未收到应答，则会启动重发，使收发过程恢复正常状态。
  * 如果重发间隔时长小于接收超时时长，则下位机会将重发的数据
  * 与缓存区已接收数据组合成一个错误的帧，同时破坏了两帧数据。
  */
#define RX_TIMEOUT  1000

/* Variables ----------------------------------------------------------------*/
uint8_t CommTxBuf[TX_DATA_BUF_SIZE];
int CommTxLength = 0;
uint8_t CommTxFinished = 0;

unsigned short CommRxData;
unsigned char CommRxBuf[RX_DATA_BUF_SIZE];
unsigned int CommRxCnt = 0;
int CommRxTimeCnt = 0;
/* Private function declaration ---------------------------------------------*/
/* Functions ----------------------------------------------------------------*/
void devCommSend(unsigned char* pbuf, unsigned int size);

void commRxTimeoutCheck(void)
{
    rt_base_t level;
    CommRxTimeCnt++;
    if(CommRxTimeCnt > RX_TIMEOUT){
        CommRxTimeCnt = 0;
        level = rt_hw_interrupt_disable();
        CommRxCnt = 0;
        rt_hw_interrupt_enable(level);
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
void dataFrameSend(unsigned char cmd, unsigned char* data, int length)
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
	devCommSend(buf, 5);
    devCommSend(data, length);
    devCommSend(&checksum, 1);
}

#define CMD_BUF_SIZE	64
static char CmdBuf[CMD_BUF_SIZE];
static unsigned int CmdBufLength = 0;
static unsigned char CmdIsProcessing = 0;
/**
  * @brief 命令接收与检查
  * @param pbuf 命令帧缓存区
  * @param length 命令帧长度
  */
void cmdReceiveAndCheck(unsigned char* pbuf, int length)
{
	if((unsigned char)pbuf[length - 1] == checkSumCalc(pbuf, length)){
		//校验通过
		memcpy((void*)CmdBuf, (void*)pbuf, length);
		CmdBufLength = length;
		CmdIsProcessing = 1;
	}else{
		CmdBufLength = 0;
		CmdIsProcessing = 0;
	}
}

void dataReceive(unsigned char data)
{
    rt_base_t level;
    unsigned int length = 0;
    unsigned char restartFlag = 0;

    CommRxTimeCnt = 0;    //清除用于断帧的超时计数

    CommRxBuf[CommRxCnt] = data;
    CommRxCnt++;

    devCommRxStart();   //重新启动接收

    if(CommRxCnt > RX_DATA_BUF_SIZE){
        //接收出错，重新开始接收。
        restartFlag = 1;
    }else{
        /* 命令帧格式：帧头2字节（0xa5, 0x5a） + 帧长度2字节 + 命令码1字节 + 命令数据n（n >= 0)字节 + 校验和1字节 */
        if(((CommRxCnt == 1) && (CommRxBuf[0] != (char)0xa5))
            || ((CommRxCnt == 2) && (CommRxBuf[1] != (char)0x5a))){
            /* 帧头不正确，重新开始接收 */
            restartFlag = 1;
        }else if(CommRxCnt > 3){
            length = (unsigned int)CommRxBuf[2] \
                + ((unsigned int)CommRxBuf[3] << 8);
            if(length > RX_DATA_BUF_SIZE){
                /* 帧长超过了最大帧长，是一种错误，重新开始接收 */
                restartFlag = 1;
            }else if(length == CommRxCnt){
                /* 接收一帧完成，进行检查与处理 */
                cmdReceiveAndCheck(CommRxBuf, CommRxCnt);
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

extern void iapModeEnter(void);
static unsigned char CmdDataBuf[CMD_RESPONSE_FRAME_MAX_LENGTH - MIN_CMD_FRAME_LENGTH];
/**
  * @brief 命令处理
  */
void cmdProcess(void)
{	
	int dataLen = 0;
	unsigned char cmd = CMD_NONE;
	if(CmdIsProcessing == 0){
		return;
	}
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
	
	dataFrameSend(cmd, CmdDataBuf, dataLen);
	CmdIsProcessing = 0;
}

