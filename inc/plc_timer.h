/******************************************************************************
** 文 件 名:  plc_timer.h
** 说 明:     plc_timer.c的头文件
** 创建人:    hyafz
** 修改信息： 
**         修改人    修改日期       修改内容
**       
******************************************************************************/

#ifndef _PLC_TIMER_H
#define _PLC_TIMER_H

/* define -------------------------------------------------------------------*/
/* typedef ------------------------------------------------------------------*/
/* Export variables declaration ---------------------------------------------*/
/* Export function declaration ----------------------------------------------*/
void plcTimerInit(void);
void plcTimerStart(void);
/*PLC定时器中断处理HOOK*/
void plcTimeoutCallback(void);
/*获取PLC毫秒时间*/
unsigned int plcTimeMsecGet(void);
/*获取PLC微秒时间*/
unsigned int plcTimeUsecGet(void);
unsigned int timeConsumedCalc(unsigned int begin, unsigned int end);

#endif

