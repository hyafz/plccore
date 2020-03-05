/**
 * @file  plc_cfg.h
 * @brief plc_cfg.c的头文件
 * @author hyafz  
 */

#ifndef _PLC_CFG_H_
#define _PLC_CFG_H_

#include <rtthread.h>
#include "plc_type_define.h"
#include "plc_port.h"

typedef enum Task_Status_Enum{
	TASK_UNAVAILABLE = 0,
	TASK_READY = 1,
	TASK_RUNNING = 2,
	TASK_ERROR = 3
}TASK_STA_E;

/* 任务时间统计结构体 */
typedef struct Task_Time_Statistics_Struct{
	USINT       priority;    /* 标记所属任务 */
	UDINT       trigTime;    /* 任务触发的时刻 */
	UDINT       beginTime;   /* 任务开始执行的时刻 */
	UDINT       endTime;     /* 任务执行结束的时刻 */
	UDINT       runTime;     /* 任务运行的时间 */
	struct Task_Time_Statistics_Struct* pNext;
}TASK_TIME_STAT_S;

/*定义PLC任务控制块结构体*/
typedef struct Task_Ctrl_Block_Struct{
    UINT        id;
	USINT       priority;              /**< 优先级，0最高，255最低*/
    BOOL (*singleGet)(void);       /**< 获得single的值*/
    TIME (*intervalGet)(void);     /**< 获得interval的值*/
	void (*taskRun)(void);
    /*运行时变量*/
	TASK_STA_E  taskSta;
	struct rt_semaphore	semTask;
	BOOL        singlePrevious;    /**< 前一次single输入值，用于判断single输入的上升沿*/
	TIME        intervalBegin;     /**< interval起始时间*/

	/* 次数统计 */
	UDINT       trigCnt;		   /**< 触发次数 */
	UDINT       runCnt;            /**< 运行次数 */

	/*运行时间统计，均以微秒(usec)为单位*/
	UDINT       trigTime;          /**<  当次任务触发时间 */
	UDINT       beginTime;         /**<  当次任务运行开始时间 */
	UDINT       endTime;           /**<  当次任务运行结束时间 */
	
	UDINT       runTime;           /**<  当次任务运行时间 = endTime - beginTime */
	UDINT       runTimeMin;
	UDINT       runTimeMax;
	UDINT       runTimeAverage;
	UINT64      runTimeSum;
	
	UDINT       gapTime;           /**<  相邻两次任务间隔时间 =     current beginTime - previous beginTime */
	UDINT       gapTimeMin;
	UDINT       gapTimeMax;       
	UDINT       gapTimeAverage;
	UINT64      gapTimeSum;
	
	UDINT       delayTime;         /**<  当次任务从触发到开始运行的延迟时间 = beginTime - trigTime */
	UDINT       delayTimeMin;
	UDINT       delayTimeMax;
	UDINT       delayTimeAverage;
	UINT64      delayTimeSum;	
	/* 栈空间已使用的最大百分比统计 */
	USINT       stkUsedMax;
}TASK_CB_S;

#define MAX_SIZE_OF_RSC_MSG_QUEUE      16  /*资源事件队列中最多消息数目*/

/*定义PLC资源事件*/
#define PLC_RSC_EVT_NULL               0
#define PLC_RSC_EVT_ORDER_TO_RUN       1  /*命令资源启动*/
#define PLC_RSC_EVT_ORDER_TO_STOP      2  /*命令资源停止*/
#define PLC_RSC_EVT_TASK_READY         3  /*任务准备就绪*/
#define PLC_RSC_EVT_TASK_TRIGGED       4  /*任务触发*/
#define PLC_RSC_EVT_TASK_RETURN        5  /*任务执行结束返回*/
#define PLC_RSC_EVT_TASK_ERROR         6  /*任务执行出错*/

typedef struct{
	BYTE       evt;                          /*事件编码*/
	BYTE       reserved[3];                  /*保留，用于字节对齐*/
    TASK_CB_S* ptaskcb;                      /*  */
}RSC_MSG_S;
#define RSC_MSG_SIZE                   sizeof(RSC_MSG_S)

typedef enum Resource_Status_Enum{
	RSC_INITIALIZING = 0,	/**< 正在初始化状态 */
	RSC_READY_TO_RUN,		/**< 准备运行状态 */
	RSC_STOP,				/**< 停机状态 */
	RSC_RUNNING,			/**< 运行状态 */
	RSC_GOTO_STOP,    		/**< 正在停止状态 */
	RSC_ERROR				/**< 错误状态 */
}RSC_STA_E;

/*定义资源控制块*/
typedef struct Resource_Ctrl_Block_Struct{
    UDINT       taskNum;                /**< 用户任务数目，不包含默认任务 */
	TASK_CB_S   taskCB[MAX_TASK_NUM_PER_RSC]; /**< 用户任务控制块列表，不包含默认任务 */
    TASK_CB_S   taskDefaultCB;          /**< 默认任务控制块 */
    /*运行时变量*/
	RSC_STA_E   rscState;			/**< 资源运行状态 */
	UDINT       cycleCnt;         /**< 扫描循环计数，从当次开始运行计数 */
	UDINT       taskRunningCnt;   /**< 正在运行的任务数目，包括默认任务 */
	
	/*与计时相关的变量，均以微秒(usec)为单位*/
	UDINT       runTime;           /**< 本次运行启动时间 */
	UDINT       stopTime;          /**< 本次运行停机的时间 */
	UDINT       updateTime;        /**< 上次运行状态更新时间 */
	/* 主循环计时 */
	UDINT       cycleBegin;        /**< 当次主循环开始时间 */
	UDINT       cycleEnd;          /**< 当次主循环结束时间 */
	
	UDINT       cycleTime;         /**< 当次主循环运行时间 = endTime - beginTime */
	UDINT       cycleTimeMin;      /**< 历次主循环最短运行时间 */
	UDINT       cycleTimeMax;      /**< 历次主循环最长运行时间 */
	UDINT       cycleTimeAverage;  /**< 历次主循环平均运行时间 */
	UINT64      cycleTimeSum;
	
	UDINT       gapTime;	       /**< 相邻两次主循环间隔时间 = current cycleBegin - perious cycleBegin */
	UDINT       gapTimeMin;        /**< 相邻两次主循环最短间隔时间 */
	UDINT       gapTimeMax;        /**< 相邻两次主循环最长间隔时间 */
	UDINT       gapTimeAverage;    /**< 相邻两次主循环平均间隔时间 */
	UINT64      gapTimeSum;
	/* 分项计时 */
	UDINT       diRefreshTime;    /**< DI刷新耗时 */
	UDINT       dqRefreshTime;    /**< DQ刷新耗时 */

	TASK_TIME_STAT_S* ttsListHeader;  /**< 本周期任务调度运行时间统计表头指针 */
	
}RSC_CB_S;

typedef enum Configuration_Status_Enum{
	CFG_UNAVAILABLE = 0,
	CFG_READY = 1,
	CFG_RUNNING = 2,
	CFG_ERROR = 3
}CFG_STA_E;

/*定义配置控制块*/
typedef struct{
	RSC_CB_S    rscCB;                         /*当前资源控制块*/
}CFG_CB_S;

extern CFG_CB_S CfgCB;

/* Export function declaration ----------------------------------------------*/
void plcCfgRun(void);
void plcRscTaskSched(RSC_CB_S* pRscCB);
void plcSendMsgToRsc(BYTE evt, TASK_CB_S* pTaskCB);

#endif

