/**
  * @file  plc_timer.c
  * @brief  PLC与定时相关的实现，PLC定时器的时基固定为1毫秒。
  * @author  hyafz    
  */
/* includes -----------------------------------------------------------------*/
#include <rtthread.h>
#include "plc_port.h"
#include "plc_cfg.h"
#include "plc_io.h"
#include "plc_comm.h"

extern void devTimerStart(void);
extern void devTimerStop(void);
extern unsigned int devTimerCountGet(void);

/* Private define -----------------------------------------------------------*/
/* Private typedef ----------------------------------------------------------*/
/* Private macro ------------------------------------------------------------*/
/* Variables ----------------------------------------------------------------*/
unsigned int PlcTimeMsec = 0; /*PLC毫秒时间*/

/* Private function declaration ---------------------------------------------*/
/* Functions ----------------------------------------------------------------*/
/**
  * @brief PLC定时器启动
  */
void plcTimerStart(void)
{
    rt_base_t level = rt_hw_interrupt_disable();
    PlcTimeMsec = 0;
    rt_hw_interrupt_enable(level);
    devTimerStart();
}

void plcTimerStop(void)
{
    devTimerStop();
}

/**
  * @brief 获取PLC毫秒时间
  */
unsigned int plcTimeMsecGet(void)
{
    unsigned int msec = 0;
    rt_base_t level = rt_hw_interrupt_disable();
    msec = PlcTimeMsec;
    rt_hw_interrupt_enable(level);
    return msec;
}

/**
  * @brief 获取PLC微秒时间
  */
unsigned int plcTimeUsecGet(void)
{
    rt_base_t level;
    unsigned int msec1 = 0;
    unsigned int count1 = 0;
    unsigned int msec2 = 0;
    unsigned int count2 = 0;
    unsigned int usec = 0;
#if 0
    unsigned int usec1 = 0;
    unsigned int usec2 = 0;
#endif

    level = rt_hw_interrupt_disable();
    msec1 = PlcTimeMsec;
    count1 = devTimerCountGet();
    rt_hw_interrupt_enable(level);
    /*退出临界区，如果定时器中断到，则会先响应中断，更新PlcTimeMSec。*/
    level = rt_hw_interrupt_disable();
    msec2 = PlcTimeMsec;
    count2 = devTimerCountGet();
    rt_hw_interrupt_enable(level);

#if 1
    if(msec1 == msec2) /* msec相等，表示第一次读取的值没有跳变，采用第一次读取的值 */
    {
        usec = msec1 * (unsigned int)1000 + count1;
    }
    else /* msec不相等，表示第二次读取时值已经跳变完成，采用第二次读取的值 */
    {
        usec = msec2 * (unsigned int)1000 + count2;
    }
#else
    usec1 = msec1 * (unsigned int)1000 + count1;
    usec2 = msec2 * (unsigned int)1000 + count2;
    if(usec2 >= usec1){
        usec = usec2;
    }else{
        usec = (msec2 + 1) * (unsigned int)1000 + count2;
    }
#endif
    return usec;
}

/**
  * @brief PLC定时器中断处理HOOK，每毫秒调用一次。
  */
void plcTimerHook(void)
{
    int8_t runMode = PLC_SW_STOP;
    rt_base_t level = rt_hw_interrupt_disable();
    PlcTimeMsec++;
    rt_hw_interrupt_enable(level);

    /* 输入扫描 */
    devInputScan();

    /*判断开关是否有动作*/
    runMode = isRunMode();
    if(isRunModeSwitched()){
        if((runMode == PLC_SW_RUN)){
            plcSendMsgToRsc(PLC_RSC_EVT_ORDER_TO_RUN, (TASK_CB_S*)0);
        }else if(runMode == PLC_SW_STOP){
            plcSendMsgToRsc(PLC_RSC_EVT_ORDER_TO_STOP, (TASK_CB_S*)0);
        }
    }

    /* COMM通信接收超时检查 */
    commRxTimeoutCheck();

    /* 通信指令处理 */
    cmdProcess();

    /* 任务调度处理 */
    plcRscTaskSched(&(CfgCB.rscCB));
}

/**
  * @ brief 计算从起始到结束的耗时
  */
unsigned int timeConsumedCalc(unsigned int begin, unsigned int end)
{
	unsigned int consumedTime = 0;
	/* 要考虑计时器翻转的情况 */
	if(end >= begin)
	{
		consumedTime = end - begin;
	}
	else
	{
		consumedTime = 0xFFFFFFFF - begin + end;
	}
	return consumedTime;
}

