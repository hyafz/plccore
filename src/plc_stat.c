/**
  * @file     plc_stat.c
  * @brief    PLC运行统计功能的实现.
  * @author   hyafz
**/
/* includes -----------------------------------------------------------------*/
#include <string.h>
#include <rtthread.h>
#include "plc_debug.h"
#include "plc_stat.h"
#include "plc_timer.h"
#include "plc_comm.h"

/* Private define -----------------------------------------------------------*/
/* Private typedef ----------------------------------------------------------*/
/* Private macro ------------------------------------------------------------*/
/* Variables ----------------------------------------------------------------*/
static struct rt_semaphore	SemStat;                 /**<  调用统计功能的信号量 */
unsigned char StatDataRegion[MAX_STAT_DATA_REGION_SIZE];  /**< 统计数据区 */
unsigned int StatDataCnt = 0;      /**< 统计数据区字节计数  */
unsigned int StatBeginTime = 0;    /**< 统计功能启动的时间 */
unsigned int StatLastEvtTime = 0;  /**< 上一次事件发生的时间 */
unsigned char StatFlag = 0;        /**< 统计功能标志 0: 统计停止，1: 统计进行. */
/* Private function declaration ---------------------------------------------*/
/* Functions ----------------------------------------------------------------*/
/**
  * @brief 统计功能初始化函数.
  */
void statInit(void)
{
	/* 创建统计功能信号量 */
	rt_err_t err;
	err = rt_sem_init(&SemStat, 
	                  "", 
					  1, 
					  RT_IPC_FLAG_FIFO);
	RT_ASSERT(RT_EOK == err);
	memset((void*)StatDataRegion, 0, sizeof(StatDataRegion));
	StatDataCnt = 0;
	StatFlag = 0;
	StatBeginTime = 0;
	StatLastEvtTime = 0;
}

/**
  * @brief 统计开始函数，用于初始化统计数据区域.
  */
void statBegin(void)
{
	rt_err_t err;

	err = rt_sem_take(&SemStat, RT_WAITING_FOREVER);
	RT_ASSERT(RT_EOK == err);
	
	//memset((void*)StatDataRegion, 0, sizeof(StatDataRegion));
	StatDataCnt = 0;
	debugOutput(PLC_EVT_STAT_START);
	StatBeginTime = plcTimeUsecGet();
	StatLastEvtTime = StatBeginTime;
	StatFlag = 1;

	rt_sem_release(&SemStat);
}

/**
  * @brief 统计结束函数.
  */
void statStop(void)
{
	rt_err_t err;

	err = rt_sem_take(&SemStat, RT_WAITING_FOREVER);
	RT_ASSERT(RT_EOK == err);
	StatFlag = 0;
	rt_sem_release(&SemStat);
	debugOutput(PLC_EVT_STAT_STOP);
}

/**
  * @brief 统计数据清除函数，只清除数据
  */
void statClear(void)
{
	rt_err_t err;
	if((StatFlag == 1) && (StatDataCnt > 0))
	{
		/* 等待信号量 */
		err = rt_sem_take(&SemStat, RT_WAITING_FOREVER);
		RT_ASSERT(RT_EOK == err);
		StatDataCnt = 0;
		/* 释放信号量 */
		rt_sem_release(&SemStat);
	}
}

/**
  * @brief  统计事件增加函数.
  * @param  label 事件对象标签
  * @param  evt   事件类型
  * @return 事件发生的时刻
  */
unsigned int statEventAdd(unsigned char label, STAT_EVT_TYPE_E evt)
{
	rt_err_t err;
	unsigned int evtTime;  /* 事件发生的时间 */
#if (STAT_DATA_SAVE_MODE == STAT_DATA_COMPACT_MODE) /* 以紧凑模式保存统计数据 */
	unsigned int timeInc;  /* 时间增量 */
	unsigned char timeLen = 0;
#endif
	/* 获取事件发生的时间 */
	evtTime = plcTimeUsecGet();

	if((StatFlag == 0) || (StatDataCnt >= (MAX_STAT_DATA_REGION_SIZE - SINGLE_STAT_DATA_SIZE)))
	{
		/* 未启动统计功能，或不够空间存储新的事件 */
		return evtTime;
	}

	/* 等待信号量 */
	err = rt_sem_take(&SemStat, RT_WAITING_FOREVER);
	RT_ASSERT(RT_EOK == err);

	/* 写入统计数据区 */
	StatDataRegion[StatDataCnt++] = label;
	StatDataRegion[StatDataCnt] = evt;

#if (STAT_DATA_SAVE_MODE == STAT_DATA_COMPACT_MODE)	/* 以紧凑模式保存统计数据 */	
	/* 计算时间增量 */
	timeInc = timeConsumedCalc(StatLastEvtTime, evtTime);
	/*更新上次事件时间*/
	StatLastEvtTime = evtTime;
	/* 计算时间域长度 */
	if(timeInc < 0x100){
		timeLen = 0;
	}else if(timeInc < 0x10000){
		timeLen = 1;
	}else if(timeInc < 0x1000000){
		timeLen = 2;
	}else{
		timeLen = 3;
	}
	StatDataRegion[StatDataCnt++] |= (timeLen << 6);
	do{
		StatDataRegion[StatDataCnt++] = (unsigned char)(timeInc & 0xFF);
		timeInc >>= 8;
	}while(timeLen--);
#else	/* 以普通模式保存统计数据 */
	StatDataCnt++;
	StatDataRegion[StatDataCnt++] = ((unsigned char)evtTime) & 0xFF;
	StatDataRegion[StatDataCnt++] = ((unsigned char)(evtTime >> 8)) & 0xFF;
	StatDataRegion[StatDataCnt++] = ((unsigned char)(evtTime >> 16)) & 0xFF;
	StatDataRegion[StatDataCnt++] = ((unsigned char)(evtTime >> 24)) & 0xFF;
#endif
	
	/* 释放信号量 */
	rt_sem_release(&SemStat);

	return evtTime;
}

/**
  * @brief  统计数据增加函数，如果统计数据存储空间不够，则会截断部分数据。
  * @param data 数据指针
  * @param len  数据长度
  * @return 成功写入的字节数
  */
unsigned int statDataAdd(unsigned char* data, unsigned int len)
{
	unsigned int num = 0;
	unsigned int i;

	rt_err_t err;
	if((StatFlag == 0) || (StatDataCnt >= MAX_STAT_DATA_REGION_SIZE))
	{
		/* 未启动统计功能，或不够空间存储新的事件 */
		return num;
	}

	/* 等待信号量 */
	err = rt_sem_take(&SemStat, RT_WAITING_FOREVER);
	RT_ASSERT(RT_EOK == err);
	
	for(i = 0; i < len; i++){
		if(StatDataCnt < MAX_STAT_DATA_REGION_SIZE){
			StatDataRegion[StatDataCnt++] = data[i];
			num++;
		}else{
			break;
		}
	}
	/* 释放信号量 */
	rt_sem_release(&SemStat);
	return num;
}


/**
  * @brief 将统计数据发送给上位机
  */
void statOutput(void)
{
	if((StatFlag == 1) && (StatDataCnt > 0))
	{
	    plcCommDataFrameSend(CMD_STAT_OUTPUT, StatDataRegion, StatDataCnt);
	}
}

