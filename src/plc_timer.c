/**
  * @file  plc_timer.c
  * @brief  PLC与定时相关的实现，PLC定时器的时基固定为1毫秒。
  * @author  hyafz    
  */
/* includes -----------------------------------------------------------------*/
#include <rtthread.h>
#ifdef RT_USING_DEVICE
#include <rtdevice.h>
#endif
#include "plc_port.h"
#include "plc_cfg.h"
#include "plc_io.h"
#include "plc_comm.h"

/* Private define -----------------------------------------------------------*/
/* Private typedef ----------------------------------------------------------*/
/* Private macro ------------------------------------------------------------*/
/* Variables ----------------------------------------------------------------*/
#ifdef RT_USING_DEVICE
rt_device_t plc_hwtimer_dev;                     /* PLC定时器设备句柄 */
#else
unsigned int PlcTimeMsec = 0; /*PLC毫秒时间*/
#endif

/* Private function declaration ---------------------------------------------*/
/* Functions ----------------------------------------------------------------*/

/**
  * @brief PLC定时器超时回调函数，每毫秒调用一次。
  */
void plcTimeoutCallback(void)
{
    int8_t runMode = PLC_SW_STOP;
#ifndef RT_USING_DEVICE
    rt_base_t level = rt_hw_interrupt_disable();
    PlcTimeMsec++;
    rt_hw_interrupt_enable(level);
#endif

    /* 输入扫描 */
    plcInputScan();

    /* 通信接收超时判断与处理 */
    plcCommRxTimeoutCheck();

    /*判断开关是否有动作*/
    runMode = isRunMode();
    if(isRunModeSwitched()){
        if((runMode == PLC_SW_RUN)){
            plcSendMsgToRsc(PLC_RSC_EVT_ORDER_TO_RUN, (TASK_CB_S*)0);
        }else if(runMode == PLC_SW_STOP){
            plcSendMsgToRsc(PLC_RSC_EVT_ORDER_TO_STOP, (TASK_CB_S*)0);
        }
    }

    /* 任务调度处理 */
    plcRscTaskSched(&(CfgCB.rscCB));
}

#ifdef RT_USING_DEVICE
rt_err_t plcTimeoutIndicate(rt_device_t dev, rt_size_t size)
{
    plcTimeoutCallback();
    return RT_EOK;
}
#endif

/**
 * @brief PLC定时器初始化
 */
void plcTimerInit(void)
{
#ifdef RT_USING_DEVICE
    rt_err_t ret = RT_EOK;
    rt_hwtimer_mode_t mode;         /* 定时器模式 */
    rt_uint32_t freq = 1000000;       /* 计数频率 */
    /* 查找定时器设备 */
    plc_hwtimer_dev = rt_device_find(PLC_HWTIMER_DEV_NAME);
    if (plc_hwtimer_dev == RT_NULL)
    {
        rt_kprintf("plc hwtimer run failed! can't find %s device!\n", PLC_HWTIMER_DEV_NAME);
        return;
    }
    /* 以读写方式打开设备 */
    ret = rt_device_open(plc_hwtimer_dev, RT_DEVICE_OFLAG_RDWR);
    if (ret != RT_EOK)
    {
        rt_kprintf("open %s device failed!\n", PLC_HWTIMER_DEV_NAME);
        return;
    }
    /* 设置超时回调函数 */
    rt_device_set_rx_indicate(plc_hwtimer_dev, plcTimeoutIndicate);
    /* 设置计数频率 ( 默认 1MHz 或支持的最小计数频率 )  */
    rt_device_control(plc_hwtimer_dev, HWTIMER_CTRL_FREQ_SET, &freq);
    /* 设置模式为周期性定时器 */
    mode = HWTIMER_MODE_PERIOD;
    ret = rt_device_control(plc_hwtimer_dev, HWTIMER_CTRL_MODE_SET, &mode);
    if (ret != RT_EOK)
    {
        rt_kprintf("set mode failed! ret is :%d\n", ret);
        return;
    }
#else
    extern void devTimerInit();
    devTimerInit();
#endif
}

/**
  * @brief PLC定时器启动
  */
void plcTimerStart(void)
{
#ifdef RT_USING_DEVICE
    rt_hwtimerval_t timeout_s;      /* 定时器超时值 */
    /* 设置定时器超时值为1000us并启动定时器 */
    timeout_s.sec = 0;      /* 秒 */
    timeout_s.usec = 1000;     /* 微秒 */
    if (rt_device_write(plc_hwtimer_dev, 0, &timeout_s, sizeof(timeout_s)) != sizeof(timeout_s))
    {
        rt_kprintf("set timeout value failed\n");
    }
#else
    extern void devTimerInit(void);
    extern void devTimerStart(void);
    devTimerInit();
    devTimerStart();
#endif
}

void plcTimerStop(void)
{
    /* 设置定时器停止 */
#ifdef RT_USING_DEVICE
    rt_device_control(plc_hwtimer_dev, HWTIMER_CTRL_STOP, (void*)0);
#else
    extern void devTimerStop(void);
    devTimerStop();
#endif
}

/**
  * @brief 获取PLC毫秒时间
  */
unsigned int plcTimeMsecGet(void)
{
    unsigned int msec = 0;
#ifdef RT_USING_DEVICE
    rt_hwtimerval_t time;
    /* 读取定时器当前值 */
    rt_device_read(plc_hwtimer_dev, 0, &time, sizeof(time));
    msec = (unsigned int)time.sec * 1000 + time.usec / 1000;
#else
    rt_base_t level = rt_hw_interrupt_disable();
    msec = PlcTimeMsec;
    rt_hw_interrupt_enable(level);
#endif
    return msec;
}

/**
  * @brief 获取PLC微秒时间
  */
unsigned int plcTimeUsecGet(void)
{
    unsigned int usec = 0;
    unsigned int usec1 = 0;
    rt_base_t level;
#ifdef RT_USING_DEVICE
    rt_hwtimerval_t time;
    rt_hwtimerval_t time1;
    level = rt_hw_interrupt_disable();
    /* 读取定时器当前值 */
    rt_device_read(plc_hwtimer_dev, 0, &time, sizeof(rt_hwtimerval_t));
    rt_hw_interrupt_enable(level);

    level = rt_hw_interrupt_disable();
    /* 再次读取定时器当前值 */
    rt_device_read(plc_hwtimer_dev, 0, &time1, sizeof(rt_hwtimerval_t));
    rt_hw_interrupt_enable(level);

    usec = (unsigned int)time.sec * 1000000 + (unsigned int)time.usec;
    usec1 = (unsigned int)time1.sec * 1000000 + (unsigned int)time1.usec;
#else
    extern unsigned int devTimerCountGet(void);
    level = rt_hw_interrupt_disable();
    usec = PlcTimeMsec * 1000 + devTimerCountGet();
    rt_hw_interrupt_enable(level);
    /*退出临界区，如果定时器中断到，则会先响应中断，更新PlcTimeMSec。*/
    level = rt_hw_interrupt_disable();
    usec1 = PlcTimeMsec * 1000 + devTimerCountGet();
    rt_hw_interrupt_enable(level);
#endif
    if(usec1 > usec){
        usec = usec1;
    }
    return usec;
}

/**
  * @ brief 计算从起始到结束的耗时
  */
unsigned int timeConsumedCalc(unsigned int begin, unsigned int end)
{
	return (end - begin);
}

