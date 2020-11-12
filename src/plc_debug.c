/**
  * @file  plc_debug.c
  * @brief 调试信息输出功能实现文件
  * @author fengzhou
  */

/* includes -----------------------------------------------------------------*/
#include "plc_debug.h"
#include "plc_type_define.h"
#include "plc_comm.h"
#include "plc_io.h"

#define SYSTEM_DEBUG_EN         1
#ifdef SYSTEM_DEBUG_EN
void dbg_err(char* errStr)
{
	//DBG_PRINTF("ERROR: %s\r\n", errStr);
}

void dbg_warn(char* warnStr)
{
	//DBG_PRINTF("WARNNING: %s\r\n", warnStr);
}

void dbg_log(char* logStr)
{
	//DBG_PRINTF("LOG: %s\r\n", logStr);
}

void dbg_loc(char* file, unsigned int line)
{
	//DBG_PRINTF("LOCATION: file(%s),line(%u).\r\n", file, line);
}

/******************************************************************************
** 函 数 名： dbg_assert
** 说    明:  断言处理函数
** 输    入： cond, file, line
** 返    回： none
******************************************************************************/
void dbg_assert(BOOL cond, char* file, unsigned int line)
 {
 	if(!cond)
 	{
 		//DBG_PRINTF("ASSERT: file(%s),line(%u).\r\n", file, line);
 		debugOutput(line);
		while(1);
 	}
 }


#endif

#include "plc_comm.h" 
extern void plcCommDataFrameSend(unsigned char cmd, unsigned char* data, int length);

void debugOutput(unsigned int code)
{
	unsigned char buf[4];
	*(unsigned int*)buf = code;
	plcCommDataFrameSend(CMD_DEBUG, buf, 4);
}

void debugOutputStr(unsigned char *buf, int len)
{
    plcCommDataFrameSend(CMD_DEBUG, buf, len);
}

void debugLedToggle(void)
{
	int i;
	
	while(1){
		LED_RUN_ON();
		for(i = 0; i < 1000000; i++)
		{
			i = i;
		}
		LED_RUN_OFF();
		for(i = 0; i < 1000000; i++)
		{
			i = i;
		}
		debugOutput(0xED);
	}
}

