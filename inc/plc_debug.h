/**
  * @file  plc_debug.h
  * @author hyafz
  */
#ifndef _PLC_DEBUG_H
#define _PLC_DEBUG_H
#include "plc_type_define.h"

#if (SYSTEM_DEBUG_EN > 0)
//extern void CONSOL_printf(char *fmt,...);
void dbg_err(char *errStr); /*输出错误信息*/
void dbg_warn(char *warnStr); /*输出警告信息*/
void dbg_log(char *logStr);  /*输出记录信息*/
void dbg_loc(char *file, unsigned int line);  /*输出代码位置信息*/
void dbg_assert(BOOL cond, char* file, unsigned int line);

#define DBG_PRINTF(...)	//#define DBG_PRINTF CONSOL_printf
#define DBG_ERR(errStr) dbg_err(errStr)
#define DBG_WARN(warnStr) dbg_warn(warnStr)
#define DBG_LOG(infoStr) dbg_log(infoStr)
#define DBG_LOC() dbg_loc(__FILE__, __LINE__)
#define DBG_ASSERT(cond) dbg_assert(cond, __FILE__, __LINE__)  
#define DBG_ASSERT_NOT_NULL(ptr) DBG_ASSERT((void*)(ptr) != NULL)
#define DBG_ASSERT_EQUAL(expected, given) DBG_ASSERT((expected) == (given))
#define DBG_ASSERT_NOT_EQUAL(expected, given) DBG_ASSERT((expected) != (given))
#else
#define DBG_PRINTF(...)
#define DBG_ERR(...)
#define DBG_WARN(...)
#define DBG_LOG(...)
#define DBG_LOC(...)
#define DBG_ASSERT(cond)
#define DBG_ASSERT_NOT_NULL(ptr)
#define DBG_ASSERT_EQUAL(expected, given)
#define DBG_ASSERT_NOT_EQUAL(expected, given)
#endif

#define PLC_DEBUG_STR                   0x1c
#define PLC_EVT_TIMER_START				0x1d
#define PLC_EVT_STAT_START              0x1e
#define PLC_EVT_STAT_STOP               0x1f
#define PLC_EVT_READY_TO_RUN            0x20
#define PLC_EVT_BEGIN_TO_RUN			0x21
#define PLC_EVT_STOPPED					0x22
#define PLC_EVT_ERROR                   0x23

#define PLC_ERR_PUSH_WHEN_CR_STACK_FULL	0xE0	//致命错误0xE0：当前结果栈满时进行push操作
#define PLC_ERR_POP_WHEN_CR_STACK_EMPTY 0xE1	//致命错误0xE1：当前结果栈为空时进行pop操作

void debugOutput(unsigned int code);
void debugOutputStr(unsigned char *buf, int len);
void debugLedToggle(void);


#endif








