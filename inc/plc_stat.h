/**
  * @file  plc_stat.h
  * @brief     plc_stat.c的头文件
  * @author    hyafz
  */

#ifndef _PLC_STAT_H
#define _PLC_STAT_H

#include "plc_port.h"

/* define -------------------------------------------------------------------*/
/* 与统计功能相关的选项 */
#define MAX_STAT_DATA_REGION_SIZE      300    /**< 统计数据区域最大字节数 */

#define STAT_DATA_NORMAL_MODE           0   /**< 普通模式保存统计数据 */
#define STAT_DATA_COMPACT_MODE			1   /**< 紧凑模式保存统计数据 */
#define STAT_DATA_SAVE_MODE             STAT_DATA_NORMAL_MODE   /**< 统计数据保存模式 */
/**
  * 统计数据包括：label + evt (+ time length) + time
  * 普通模式下，统计数据结构（固定6个字节）：
  * Byte 1: 	label  	事件对象标签.
  *                		对于任务，label = 任务优先级
  *                		对于资源，label = 最低任务优先级PLC_TASK_LOWEST_PRIORITY + 1
  * Byte 2: 	evt    	事件类型，取值范围[0 ~ 255]，总共可以表示256种事件，即每种事件对象可以定义256种事件类型.
  * Byte 3 ~ 6 	time 	表示当前事件到上次事件的时间增量，单位: 微秒(us).
  * 紧凑模式下，统计数据结构（长度可变）:
  * Byte 1: 	label  				事件对象标签.
  *                					对于任务，label = 任务优先级
  *                					对于资源，label = 最低任务优先级PLC_TASK_LOWEST_PRIORITY + 1
  * Byte 2: 	evt + time length  	事件类型 + 时间域长度.
  *                					低6位为事件类型，取值范围[0 ~ 63]，总共可以表示64种事件，即每种事件对象可以定义64种事件类型.
  *                					高2位为时间域的字节长度，取值范围[0 ~ 3]，分别表示: 0(1字节)，1(2字节)，2(3字节)，3(4字节).
  * Byte 3 ~   	time   				时间域最短1字节(time length == 0)，最长4字节(time length == 3)，
  *                                 表示当前事件到上次事件的时间增量，单位: 微秒(us).
  */

#define SINGLE_STAT_DATA_SIZE        6                 /**< 每条统计数据最大字节数. 
                                                            1byte(label) + 1byte(evt + time length) + 4bytes(time zone)  */

#define PLC_TASK_STAT_DATA_SIZE	(12 * 4)
#define PLC_RSC_STAT_DATA_SIZE	(8 * 4 + PLC_TASK_STAT_DATA_SIZE * (MAX_TASK_NUM_PER_RSC + 1))
#if ((PLC_RSC_STAT_DATA_SIZE + SINGLE_STAT_DATA_SIZE) > MAX_STAT_DATA_REGION_SIZE)
#error "Stat data region size is too small."
#endif
/* typedef ------------------------------------------------------------------*/
/**
  * @brief 统计事件类型枚举
  */
typedef enum Stat_Event_Type_Enum{
	SE_TYPE_NONE = 0,
	SE_RSC_RUN,
	SE_RSC_STOP,
	SE_RSC_UPDATE,
	SE_RSC_CYCLE_BEGIN,
	SE_RSC_CYCLE_OVER,
	SE_RSC_DI_REFRESH_BEGIN,
	SE_RSC_DI_REFRESH_OVER,
	SE_RSC_DQ_REFRESH_BEGIN,
	SE_RSC_DQ_REFRESH_OVER,
	SE_TASK_TRIGGED,
	SE_TASK_BEGIN,
	SE_TASK_OVER
}STAT_EVT_TYPE_E;
/* Export variables declaration ---------------------------------------------*/
/* Export function declaration ----------------------------------------------*/
void plcStatBssZeroTest(void);
void statInit(void);
void statBegin(void);
void statStop(void);
void statClear(void);
unsigned int statEventAdd(unsigned char label, STAT_EVT_TYPE_E evt);
unsigned int statDataAdd(unsigned char* data, unsigned int len);
void statOutput(void);

#endif

