/**
  * @file  plc_cfg.c
  * @brief     符合IEC61131-3标准的PLC配置元素相关功能源文件
  * @author    fengzhou
  */
/* includes -----------------------------------------------------------------*/
#include <string.h>
#include <rtthread.h>
#include "plc_mem.h"
#include "plc_cr.h"
#include "plc_debug.h"
#include "plc_define.h"
#include "plc_cfg.h"
#include "plc_timer.h"
#include "plc_io.h"
#include "plc_comm.h"
#include "plc_stat.h"

extern void _configuration_init_(void);

/* Private define -----------------------------------------------------------*/
/*任务属性相关定义*/
#define TASK_SINGLE_EN                 0x8000  /*SINGLE参数使能标识*/

#define TASK_SINGLE_PARA_TYPE_MASK     0x4000  /*SINGLE参数类型掩码*/
#define TASK_SINGLE_PARA_TYPE_VR       0x4000  /*SINGLE为变量引用*/
#define TASK_SINGLE_PARA_TYPE_DV       0x0000  /*SINGLE为直接表示变量*/

#define TASK_INTERVAL_PARA_TYPE_MASK   0x3000  /*INTERVAL参数类型掩码*/
#define TASK_INTERVAL_PARA_CONST       0x2000  /*INTERVAL参数为常量*/
#define TASK_INTERVAL_PARA_VR          0x1000  /*INTERVAL参数为变量引用*/
#define TASK_INTERVAL_PARA_DV          0x0000  /*INTERVAL参数为直接表示变量*/

#define TASK_PRIORITY_MASK             0x00FF  /*任务优先级掩码*/

#define TASK_ID_NULL                   0xFFFF  /*无效的任务ID*/
/* Private typedef ----------------------------------------------------------*/
/* Private macro ------------------------------------------------------------*/
/* Variables ----------------------------------------------------------------*/
CFG_CB_S CfgCB; /*PLC配置控制块*/


/*PLC任务堆栈*/
struct rt_thread PlcTaskThread[MAX_TASK_NUM_PER_RSC];
unsigned char PlcTaskRunTaskStks[MAX_TASK_NUM_PER_RSC + 1][PLC_TASK_RUN_TASK_STK_SIZE];

struct rt_messagequeue PlcRscMsgQ;
unsigned char PlcRscMsgPool[MAX_SIZE_OF_RSC_MSG_QUEUE * RSC_MSG_SIZE];

/* Private function declaration ---------------------------------------------*/
/* Functions ----------------------------------------------------------------*/
void plcTaskStatDataOutput(TASK_CB_S* pTaskCB)
{
	statDataAdd((unsigned char*)&(pTaskCB->priority), 1);
	statDataAdd((unsigned char*)&(pTaskCB->stkUsedMax), 1);
	statDataAdd((unsigned char*)&(pTaskCB->trigCnt), 4);
	statDataAdd((unsigned char*)&(pTaskCB->runCnt), 4);
	statDataAdd((unsigned char*)&(pTaskCB->runTimeMin), 4);
	statDataAdd((unsigned char*)&(pTaskCB->runTimeMax), 4);
	statDataAdd((unsigned char*)&(pTaskCB->runTimeAverage), 4);
	statDataAdd((unsigned char*)&(pTaskCB->gapTimeMin), 4);
	statDataAdd((unsigned char*)&(pTaskCB->gapTimeMax), 4);
	statDataAdd((unsigned char*)&(pTaskCB->gapTimeAverage), 4);
	if(pTaskCB->trigCnt > 0){
		statDataAdd((unsigned char*)&(pTaskCB->delayTimeMin), 4);
		statDataAdd((unsigned char*)&(pTaskCB->delayTimeMax), 4);
		statDataAdd((unsigned char*)&(pTaskCB->delayTimeAverage), 4);
	}
}

/**
  * @brief 资源运行时统计数据输出至缓存区
  */
void plcRscStatDataOutput(RSC_CB_S* pRscCB)
{
	int i;
	statDataAdd((unsigned char*)&(pRscCB->cycleCnt), 4);
	statDataAdd((unsigned char*)&(pRscCB->cycleTimeMin), 4);
	statDataAdd((unsigned char*)&(pRscCB->cycleTimeMax), 4);
	statDataAdd((unsigned char*)&(pRscCB->cycleTimeAverage), 4);
	statDataAdd((unsigned char*)&(pRscCB->gapTimeMin), 4);
	statDataAdd((unsigned char*)&(pRscCB->gapTimeMax), 4);
	statDataAdd((unsigned char*)&(pRscCB->gapTimeAverage), 4);
	statDataAdd((unsigned char*)&(pRscCB->taskNum), 4);
	for(i = 0; i < pRscCB->taskNum; i++){
		plcTaskStatDataOutput(&(pRscCB->taskCB[i]));
	}
	plcTaskStatDataOutput(&(pRscCB->taskDefaultCB));
}

/**
  * @brief PLC资源扫描周期开始时的处理.
  */
static void plcRscRunCycleBegin(RSC_CB_S* pRsc)
{
	UDINT begin;
	UDINT end;
	UDINT prevBegin;

	/* 记录资源主循环周期开始时间 */
	prevBegin = pRsc->cycleBegin;
	//pRsc->cycleBegin = statEventAdd(PLC_TASK_LOWEST_PRIORITY + 1, SE_RSC_CYCLE_BEGIN);
	pRsc->cycleBegin = plcTimeUsecGet();
	
	if(pRsc->cycleCnt > 0){
		/* 记录相邻两次循环间隔时间，并计算最大值、最小值与平均值 */
		pRsc->gapTime = timeConsumedCalc(prevBegin, pRsc->cycleBegin);
		if(pRsc->gapTime > pRsc->gapTimeMax){
			pRsc->gapTimeMax = pRsc->gapTime;
		}
		if(pRsc->gapTime < pRsc->gapTimeMin){
			pRsc->gapTimeMin = pRsc->gapTime;
		}
		pRsc->gapTimeSum += pRsc->gapTime;
		pRsc->gapTimeAverage = pRsc->gapTimeSum / pRsc->cycleCnt;
	}
	pRsc->cycleCnt ++;
	
	/* DI/AI refresh */
	begin = pRsc->cycleBegin;
    plcLocalDiRefresh();
    plcLocalAiRefresh();
	end = plcTimeUsecGet();
	pRsc->diRefreshTime = timeConsumedCalc(begin, end);

	/* 调度默认任务执行 */	
	rt_sem_release(&(pRsc->taskDefaultCB.semTask));
	pRsc->taskRunningCnt ++;
}

/**
  * @brief PLC资源扫描周期结束时的处理.
  */
static void plcRscRunCycleOver(RSC_CB_S* pRsc)
{
	UDINT begin, end;

	/* DQ/AQ refresh */
	begin = plcTimeUsecGet();
	plcLocalDqRefresh();
	plcLocalAqRefresh();
	plcLocalPwmOutputRefresh();
	
	/* 记录资源主循环周期结束时间 */
	//pRsc->cycleEnd = statEventAdd(PLC_TASK_LOWEST_PRIORITY + 1, SE_RSC_CYCLE_OVER);
	pRsc->cycleEnd = plcTimeUsecGet();

	/*计算DQ更新的时间*/
	end = pRsc->cycleEnd;
	pRsc->dqRefreshTime = timeConsumedCalc(begin, end);
	
	/* 计算主循环运行时间 */
	pRsc->cycleTime = timeConsumedCalc(pRsc->cycleBegin, pRsc->cycleEnd);
	if(pRsc->cycleTime > pRsc->cycleTimeMax)
	{
		pRsc->cycleTimeMax = pRsc->cycleTime;
	}
	if(pRsc->cycleTime < pRsc->cycleTimeMin)
	{
		pRsc->cycleTimeMin = pRsc->cycleTime;
	}
	pRsc->cycleTimeSum += pRsc->cycleTime;
	pRsc->cycleTimeAverage = pRsc->cycleTimeSum / pRsc->cycleCnt;

	statOutput();	/* 每次执行周期结束输出统计数据，然后清除。 */
	statClear();
}

void plcRscRunStatusUpdate(RSC_CB_S* pRscCB)
{
	unsigned int msTime = plcTimeMsecGet();
#define PLC_RSC_RUN_STATE_UPDATE_PERIOD 1000	/**< PLC资源运行时状态更新周期，单位ms */
	unsigned int updateGapTime = timeConsumedCalc(pRscCB->updateTime, msTime);
	if(updateGapTime >= PLC_RSC_RUN_STATE_UPDATE_PERIOD){
		updateGapTime = 0;
		pRscCB->updateTime = msTime;
		/* 更新运行时统计数据 */
		//statEventAdd(PLC_TASK_LOWEST_PRIORITY + 1, SE_RSC_UPDATE);
		//plcRscStatDataOutput(pRscCB);
		/* 更新M区数据 */
		//plcCommDataFrameSend(CMD_M_OUTPUT, M, sizeof(M));
	}
}

/**
  * @brief 初始化任务的运行时变量
  * @param 任务控制块指针
  */
void plcTaskRunTimeInit(TASK_CB_S* pTaskCB)
{
	pTaskCB->singlePrevious = 0;
	pTaskCB->intervalBegin = plcTimeMsecGet();

	pTaskCB->trigCnt = 0;
	pTaskCB->runCnt = 0;
	
	pTaskCB->runTimeMin = 0xFFFFFFFF;
	pTaskCB->runTimeMax = 0;
	pTaskCB->runTimeAverage = 0;
	pTaskCB->runTimeSum = 0;
	
	pTaskCB->gapTimeMin = 0xFFFFFFFF;
	pTaskCB->gapTimeMax = 0;
	pTaskCB->gapTimeAverage = 0;
	pTaskCB->gapTimeSum = 0;
	
	pTaskCB->delayTimeMin = 0xFFFFFFFF;
	pTaskCB->delayTimeMax = 0;
	pTaskCB->delayTimeAverage = 0;
	pTaskCB->delayTimeSum = 0;
}

/**
  * @brief PLC任务线程入口函数
  * @note 任务收到启动信号量后，会一直运行直到结束，除非被更高优先级任务中断，任务自身不会主动放弃CPU控制权。
  *       故最低优先级任务执行完成返回后，本轮循环结束。
  */
static void plcTaskThreadEntry(void *pArg)
{
	rt_err_t err;
	UDINT prevBeginTime;

	TASK_CB_S* pTaskCB = (TASK_CB_S*)pArg;
	RT_ASSERT(pTaskCB != (void*)0);

	/* 初始化任务信号量 */
	err = rt_sem_init(&(pTaskCB->semTask), 
	                  "", 
					  0,
					  RT_IPC_FLAG_FIFO);
	RT_ASSERT(RT_EOK == err);

	/*初始化运行时变量*/
	plcTaskRunTimeInit(pTaskCB);

	pTaskCB->taskSta = TASK_READY;

	/*任务准备就绪,发消息通知资源*/
	plcSendMsgToRsc(PLC_RSC_EVT_TASK_READY, pTaskCB);
	
	while(1)
	{
		err = rt_sem_take(&(pTaskCB->semTask), RT_WAITING_FOREVER);
		if(err != RT_EOK){
			continue;
		}

		pTaskCB->taskSta = TASK_RUNNING;
		
		/* 记录任务当次开始运行时间，非默认任务需要记录起始事件，默认任务不记录。 */
		prevBeginTime = pTaskCB->beginTime;
		//if(pTaskCB->priority == PLC_TASK_LOWEST_PRIORITY){
			pTaskCB->beginTime = plcTimeUsecGet();
		//}else{
		//	pTaskCB->beginTime = statEventAdd(pTaskCB->priority, SE_TASK_BEGIN);
		//}
		/* 计算延迟时间，默认任务不考虑延迟时间 */
		if(pTaskCB->trigCnt > 0){
			pTaskCB->delayTime = timeConsumedCalc(pTaskCB->trigTime, pTaskCB->beginTime);
			if(pTaskCB->delayTime > pTaskCB->delayTimeMax){
				pTaskCB->delayTimeMax = pTaskCB->delayTime;
			}
			if(pTaskCB->delayTime < pTaskCB->delayTimeMin){
				pTaskCB->delayTimeMin = pTaskCB->delayTime;
			}
			pTaskCB->delayTimeSum += pTaskCB->delayTime;
			pTaskCB->delayTimeAverage = pTaskCB->delayTimeSum / pTaskCB->trigCnt;
		}

		/* 计算间隔时间 */
		if(pTaskCB->runCnt > 0){
			pTaskCB->gapTime = timeConsumedCalc(prevBeginTime, pTaskCB->beginTime);
			if(pTaskCB->gapTime > pTaskCB->gapTimeMax){
				pTaskCB->gapTimeMax = pTaskCB->gapTime;
			}
			if(pTaskCB->gapTime < pTaskCB->gapTimeMin){
				pTaskCB->gapTimeMin = pTaskCB->gapTime;
			}
			pTaskCB->gapTimeSum += pTaskCB->gapTime;
			pTaskCB->gapTimeAverage = pTaskCB->gapTimeSum / pTaskCB->runCnt;
		}
		pTaskCB->runCnt++;
		
		/* 执行任务函数 */
		pTaskCB->taskRun();

		/* 记录任务当次运行结束时间，非默认任务需要记录结束事件，默认任务记录。 */
		//if(pTaskCB->priority == PLC_TASK_LOWEST_PRIORITY){
			pTaskCB->endTime = plcTimeUsecGet();
		//}else{
		//	pTaskCB->endTime = statEventAdd(pTaskCB->priority, SE_TASK_OVER);
		//}
		
		/*计算任务运行时间*/
		pTaskCB->runTime = timeConsumedCalc(pTaskCB->beginTime, pTaskCB->endTime);
		
		/*统计历次任务运行最长、最短时间、平均时间 */
		if(pTaskCB->runTime > pTaskCB->runTimeMax)
		{
			pTaskCB->runTimeMax = pTaskCB->runTime;
		}
		if(pTaskCB->runTime < pTaskCB->runTimeMin)
		{
			pTaskCB->runTimeMin = pTaskCB->runTime;
		}		
		pTaskCB->runTimeSum += pTaskCB->runTime;
		pTaskCB->runTimeAverage = pTaskCB->runTimeSum / pTaskCB->runCnt;

		/** @todo 统计任务栈使用情况，RTT暂不支持 */

		pTaskCB->taskSta = TASK_READY;
		
		/*任务执行完毕,发消息通知资源*/
		plcSendMsgToRsc(PLC_RSC_EVT_TASK_RETURN, pTaskCB);
	}
}

/**
  * @brief 初始化PLC资源运行时参数
  * @param 资源控制块指针
  */
void plcRscRunTimeInit(RSC_CB_S* pRscCB)
{
	int i = 0;
	
	pRscCB->cycleCnt = 0;
	pRscCB->taskRunningCnt = 0;
	
	pRscCB->cycleBegin = 0;
	pRscCB->cycleEnd = 0;
	pRscCB->cycleTime = 0;
	pRscCB->cycleTimeMin = 0xFFFFFFFF;
	pRscCB->cycleTimeMax = 0;
	pRscCB->cycleTimeAverage = 0;
	pRscCB->cycleTimeSum = 0;
	
	pRscCB->gapTime = 0;
	pRscCB->gapTimeMin = 0xFFFFFFFF;
	pRscCB->gapTimeMax = 0;
	pRscCB->gapTimeAverage = 0;
	pRscCB->gapTimeSum = 0;

	pRscCB->diRefreshTime = 0;
	pRscCB->dqRefreshTime = 0;

	for(i = 0; i < pRscCB->taskNum; i++){
		plcTaskRunTimeInit(&(pRscCB->taskCB[i]));
	}
	plcTaskRunTimeInit(&(pRscCB->taskDefaultCB));
	
	plcMemInit();
}

/**
  * @brief PLC资源内部任务调度函数，由PLC系统定时器中断调用。
  */
void plcRscTaskSched(RSC_CB_S* pRscCB)
{
	UDINT cnt;
	TASK_CB_S* pTaskCB;
	BOOL singleCurrent;
	TIME intervalSet;
	TIME intervalTime;
	unsigned int currentTimeMsec;

	if(pRscCB->rscState != RSC_RUNNING)
	{
		return;
	}
	
	for(cnt = 0; cnt < pRscCB->taskNum; cnt++)
	{
		pTaskCB = &(pRscCB->taskCB[cnt]);
		
		/*检测任务是否准备好*/
		if(pTaskCB->taskSta == TASK_UNAVAILABLE)
		{
			pTaskCB->singlePrevious = 0;
			pTaskCB->intervalBegin = plcTimeMsecGet();
			continue;
		}
		
		/*检测single输入上升沿*/
		singleCurrent = pTaskCB->singleGet();
		if((pTaskCB->singlePrevious == 0) && 
			(singleCurrent == 1))
		{
			/*检测到single输入上升沿，任务被触发，通知资源进行调度。*/
			plcSendMsgToRsc(PLC_RSC_EVT_TASK_TRIGGED, pTaskCB);
		}
		/*保存single输入当前状态*/
		pTaskCB->singlePrevious = singleCurrent;
		
		/*如果single输入不为0，则周期调用设置的interval输入不起作用*/
		if(singleCurrent != 0)
		{
			pTaskCB->intervalBegin = plcTimeMsecGet();
			continue;
		}

		/*如果single输入为0，则需要检测周期调用的interval时间是否到达。*/
		
		/*检测interval时间*/
		intervalSet = pTaskCB->intervalGet();
		if(intervalSet > 0)
		{
			currentTimeMsec = plcTimeMsecGet();
			intervalTime = timeConsumedCalc(pTaskCB->intervalBegin, currentTimeMsec);
			if(intervalTime >= intervalSet)
			{
				/*检测到周期调用interval时间到，任务被触发，通知资源进行调度。*/
				plcSendMsgToRsc(PLC_RSC_EVT_TASK_TRIGGED, pTaskCB);
				/*保存当前PLC毫秒时间为下一个周期调用间隔起始时间*/
				pTaskCB->intervalBegin = currentTimeMsec;
			}
		}
	}
}

void plcRscRun(RSC_CB_S* pRscCB)
{
	/*资源运行时变量初始化*/
	plcRscRunTimeInit(pRscCB);
	LED_RUN_ON();
	LED_STOP_OFF();
	debugOutput(PLC_EVT_BEGIN_TO_RUN);	
		
	/* 记录资源启动时间 */
	//pRscCB->runTime = statEventAdd(PLC_TASK_LOWEST_PRIORITY + 1, SE_RSC_RUN);
	pRscCB->runTime = plcTimeUsecGet();

	/* 记录资源运行状态更新时间 */
	pRscCB->updateTime = plcTimeMsecGet();
	
	/* 启动运行周期 */
	plcRscRunCycleBegin(pRscCB);
}

void plcRscStop(RSC_CB_S* pRscCB)
{
	plcLocalDqOutputWhenStopped();
	/* 记录资源停机时间 */
	pRscCB->stopTime = statEventAdd(PLC_TASK_LOWEST_PRIORITY + 1, SE_RSC_STOP);
	plcRscStatDataOutput(pRscCB);	
	statOutput();	/* 资源停机时输出统计数据，然后清除。 */
	statClear();
	
	LED_RUN_OFF();
	LED_STOP_ON();
	debugOutput(PLC_EVT_STOPPED);
}


/**
  * @brief PLC资源运行入口函数
  * @param p_arg reserved
  */
static void plcRscRunEntry(void* p_arg)
{
	rt_err_t err;
	UDINT i;
	RSC_CB_S* pRscCB;
	TASK_CB_S* pTaskCB;
	RSC_MSG_S rscMsg;
	/*用指针指向资源,便于访问*/
	pRscCB = &(CfgCB.rscCB);

	/* 初始化资源消息队列 */
	err = rt_mq_init(&PlcRscMsgQ, 
					"", 
					(void*)PlcRscMsgPool, 
					RSC_MSG_SIZE, 
					sizeof(PlcRscMsgPool), 
					RT_IPC_FLAG_FIFO);
	
	/*创建从属于本资源的任务的运行任务*/
	for(i = 0; i < pRscCB->taskNum; i++)
	{
		pTaskCB = &(pRscCB->taskCB[i]);
		RT_ASSERT(pTaskCB->priority + PLC_TASK_HIGHEST_PRIORITY < PLC_TASK_LOWEST_PRIORITY);
		err = rt_thread_init(&PlcTaskThread[i],
		                     "",
							 plcTaskThreadEntry,
							 (void*)pTaskCB,
							 (void*)&(PlcTaskRunTaskStks[i][0]),
							 (unsigned int)PLC_TASK_RUN_TASK_STK_SIZE,
							 PLC_TASK_HIGHEST_PRIORITY + pTaskCB->priority,
							 100);
	    RT_ASSERT(RT_EOK == err);
	    rt_thread_startup(&PlcTaskThread[i]);

	}
	/*创建本资源的默认任务*/
	pTaskCB = &(pRscCB->taskDefaultCB);

	err = rt_thread_init(&PlcTaskThread[i],
		                 "",
						 plcTaskThreadEntry,
						 (void*)pTaskCB,
						 (void*)&(PlcTaskRunTaskStks[i][0]),
						 (unsigned int)PLC_TASK_RUN_TASK_STK_SIZE,
						 pTaskCB->priority,
						 100);
    RT_ASSERT(RT_EOK == err);
    rt_thread_startup(&PlcTaskThread[i]);

	/*初始化运行时变量*/
	plcRscRunTimeInit(pRscCB);
	pRscCB->rscState = RSC_INITIALIZING;	/* 资源运行状态先置为正在初始化状态 */
	
	while(1)
	{		
		/*等待消息到来*/
		err = rt_mq_recv(&PlcRscMsgQ, (void*)&rscMsg, RSC_MSG_SIZE, RT_WAITING_FOREVER);
	    RT_ASSERT(RT_EOK == err);
		if(err != RT_EOK){
			continue;
		}
		//DBG_PRINTF("(RSC)Message received, evt = %d\r\n", rscMsg.evt);

		//资源运行状态机处理
		switch(pRscCB->rscState)
		{
		case RSC_INITIALIZING:
			if(PLC_RSC_EVT_TASK_READY == rscMsg.evt)
			{
				if(PLC_TASK_LOWEST_PRIORITY == rscMsg.ptaskcb->priority)
                {
					debugOutput(PLC_EVT_READY_TO_RUN);
                    /*最低优先级任务准备就绪，表明资源中配置的所有任务都已准备就绪，资源初始化完成。*/
					if(isRunMode() == 0){
						pRscCB->rscState = RSC_READY_TO_RUN;
					}else{
						pRscCB->rscState = RSC_RUNNING;
						plcRscRun(pRscCB);
					}
                }
			}
			break;
		case RSC_READY_TO_RUN:
		case RSC_STOP:
			if(PLC_RSC_EVT_ORDER_TO_RUN == rscMsg.evt)
			{
				pRscCB->rscState = RSC_RUNNING;
				plcRscRun(pRscCB);
			}
			break;
		case RSC_RUNNING:
			if((PLC_RSC_EVT_TASK_RETURN == rscMsg.evt) 
				|| (PLC_RSC_EVT_TASK_ERROR == rscMsg.evt))
			{
				pRscCB->taskRunningCnt --;
				if(0 == pRscCB->taskRunningCnt)
                {
                	/* 没有任务在执行了 */
                	/* 结束本次运行周期 */
                	plcRscRunCycleOver(pRscCB);
					/* 重新启动运行周期 */
               		plcRscRunCycleBegin(pRscCB);
                }
			}
			else if(PLC_RSC_EVT_TASK_TRIGGED == rscMsg.evt)
			{
				/* 有任务被触发，发送信号量启动该任务。 */
				//rscMsg.ptaskcb->trigTime = statEventAdd(rscMsg.ptaskcb->priority, SE_TASK_TRIGGED);
				rscMsg.ptaskcb->trigTime = plcTimeUsecGet();
				rscMsg.ptaskcb->trigCnt++;
				err = rt_sem_release(&(rscMsg.ptaskcb->semTask));
				pRscCB->taskRunningCnt ++;
			}
			else if(PLC_RSC_EVT_ORDER_TO_STOP == rscMsg.evt)
			{
				/* 收到停机事件，进入准备停机状态 */
				pRscCB->rscState = RSC_GOTO_STOP;
			}
			plcRscRunStatusUpdate(pRscCB);
			break;
		case RSC_GOTO_STOP:
			if((PLC_RSC_EVT_TASK_RETURN == rscMsg.evt) 
				|| (PLC_RSC_EVT_TASK_ERROR == rscMsg.evt))
			{
				pRscCB->taskRunningCnt --;				
				if(0 == pRscCB->taskRunningCnt)
                {
                	/* 没有任务在执行了，结束本次运行周期 */
                	plcRscRunCycleOver(pRscCB);
                }
			}
			if(0 == pRscCB->taskRunningCnt)
			{
				//所有任务结束，停机				
				pRscCB->rscState = RSC_STOP;
				plcRscStop(pRscCB);
			}
			break;
		case RSC_ERROR:
			debugOutput(PLC_EVT_ERROR);
			break;
		default:
			break;
		}
	}
}

/**
  * @brief PLC配置运行函数
  * @details
  * <pre>
  * PLC配置启动需要初始化配置全局变量，并启动所有资源，注意同步。
  * PLC配置运行需要及时刷新配置全局变量，处理存取路径访问。
  * PLC配置停止需要停止所有资源，注意同步。
  * </pre>
  */
void plcCfgRun(void)
{	
    /*连接用户代码*/
    _configuration_init_();
   
	/*目前只支持一个资源，直接执行资源运行任务，不会返回。 */
    plcRscRunEntry((void*)0);
}

/**
  * @brief PLC运行时向资源发送消息函数
  * @param evt 事件ID
  * @param pTaskCB 任务控制块指针，如果为空，表示事件不是由任务产生的
  */
void plcSendMsgToRsc(BYTE evt, TASK_CB_S* pTaskCB)
{
	rt_err_t err;
	RSC_MSG_S rscMsg;
	//DBG_PRINTF("Message need to be send to RSC, evt = %d\r\n", evt);
	//if(isNotNull(pTaskCB))
	//{
	//	DBG_PRINTF("Message from task(%d)\r\n", pTaskCB->priority);
	//}
    rscMsg.evt = evt;
	rscMsg.ptaskcb = pTaskCB;
    //DBG_PRINTF("Send message to RSC, evt = %d\r\n", rscMsg.evt);
    err = rt_mq_send(&PlcRscMsgQ, (void*)&rscMsg, RSC_MSG_SIZE);
    RT_ASSERT(RT_EOK == err);
}
