/**
  * @file  plc_cr.h
  * @brief     plc_cr.c的头文件
  * @author    hyafz
  */

#ifndef _PLC_CR_H_
#define _PLC_CR_H_

#include "plc_type_define.h"
#include "plc_port.h"
#include <math.h>

extern void debugOutput(unsigned int code);

typedef union Current_Result_Union
{
#if (DT_64BIT_EN == 1)
	UINT64         value;
#else
	UINT32         value;
#endif
    USINT          usintv;         /*usint*/
    SINT           sintv;          /*sint*/
    UINT           uintv;          /*uint*/
    INT            intv;           /*int*/
    UDINT          udintv;         /*udint*/
    DINT           dintv;          /*dint*/
#if (DT_ULINT_EN == 1)
    ULINT          ulintv;         /*ulint*/
#endif
#if (DT_LINT_EN  == 1)
    LINT           lintv;          /*lint*/
#endif
#if (DT_REAL_EN == 1)
    REAL           realv;          /*real*/
#endif
#if (DT_LREAL_EN == 1)
    LREAL          lrealv;         /*lreal*/
#endif
    
    BOOL           boolv;          /*bool*/
    BYTE           bytev;          /*byte*/
    WORD           wordv;          /*word*/
    DWORD          dwordv;         /*dword*/
#if (DT_LWORD_EN == 1)
    LWORD          lwordv;         /*lword*/
#endif
#if (DT_DATE_EN == 1)
    DATE           datev;          /*date*/
#endif
#if (DT_TOD_EN == 1)
    TOD            todv;           /*time of day*/
#endif
#if (DT_TIME_EN == 1)
    TIME           timev;          /*time*/
#endif
#if (DT_DT_EN == 1)
    DT             dtv;            /*date and time*/
#endif
}CURRENT_RESULT_U;

#define CR_BOOL  CurrentResult.boolv
#define CR_BYTE  CurrentResult.bytev
#define CR_WORD  CurrentResult.wordv
#define CR_DWORD CurrentResult.dwordv
#define CR_LWORD CurrentResult.lwordv
#define CR_SINT  CurrentResult.sintv
#define CR_INT   CurrentResult.intv
#define CR_DINT  CurrentResult.dintv
#define CR_LINT  CurrentResult.lintv
#define CR_USINT CurrentResult.usintv
#define CR_UINT  CurrentResult.uintv
#define CR_UDINT CurrentResult.udintv
#define CR_ULINT CurrentResult.ulintv
#define CR_REAL  CurrentResult.realv
#define CR_LREAL CurrentResult.lrealv
#define CR_TIME  CurrentResult.timev
#define CR_TOD   CurrentResult.todv
#define CR_DATE  CurrentResult.datev
#define CR_DT    CurrentResult.dtv

#define CRB_BOOL  CurrentResultBackup.boolv
#define CRB_BYTE  CurrentResultBackup.bytev
#define CRB_WORD  CurrentResultBackup.wordv
#define CRB_DWORD CurrentResultBackup.dwordv
#define CRB_LWORD CurrentResultBackup.lwordv
#define CRB_SINT  CurrentResultBackup.sintv
#define CRB_INT   CurrentResultBackup.intv
#define CRB_DINT  CurrentResultBackup.dintv
#define CRB_LINT  CurrentResultBackup.lintv
#define CRB_USINT CurrentResultBackup.usintv
#define CRB_UINT  CurrentResultBackup.uintv
#define CRB_UDINT CurrentResultBackup.udintv
#define CRB_LDINT CurrentResultBackup.ulintv
#define CRB_REAL  CurrentResultBackup.realv
#define CRB_LREAL CurrentResultBackup.lrealv
#define CRB_TIME  CurrentResultBackup.timev
#define CRB_TOD   CurrentResultBackup.todv
#define CRB_DATE  CurrentResultBackup.datev
#define CRB_DT    CurrentResultBackup.dtv
	
/**
  * @bug 每一条指令都涉及对CR的操作，但是都没有进行临界区保护！ [Fixed]
  * @details 
  * <pre>
  * 解决思路与方法：
  * 将CR相关变量（CR、CRB、CRStack、CRStackIndex）都定义在程序、功能、功能块实现函数内部，不是全局变量就不用考虑临界保护了。
  * 在每个程序、功能、功能块的入口处调用宏CR_Init()，使程序、功能、功能块的实现函数都变成可重入函数。
  * 所有原来用函数实现的指令功能，如果涉及到CR相关变量操作，都改成宏定义，可直接对CR相关变量进行操作。
  * 这样修改后，CR栈深度和指令CAL的调用深度都必须与实际挂勾，慎重设置，防止RTOS任务栈溢出。
  * 用宏定义替代函数，会导致占用更多程序空间和RAM空间。
  * </pre>
  */
#define CR_Init(stk_depth) \
	CURRENT_RESULT_U CurrentResultStk[stk_depth]; \
	int CurrentResultStkIdx = 0; \
	CURRENT_RESULT_U CurrentResult; \
	CURRENT_RESULT_U CurrentResultBackup; \
	(void)(CurrentResultStk); \
	(void)(CurrentResultStkIdx); \
	(void)(CurrentResult); \
	(void)(CurrentResultBackup)

#define CR_Push() \
	do{ \
	    CurrentResultStk[CurrentResultStkIdx++].value = CurrentResult.value; \
	}while(0)

#define CR_Pop() \
	do{ \
		CurrentResult.value = CurrentResultStk[--CurrentResultStkIdx].value; \
	}while(0)

#define CR_Clear() \
	do{ \
		CurrentResult.value = 0; \
	}while(0)

#define CR_Backup() \
	do{ \
		CurrentResultBackup.value = CurrentResult.value; \
	}while(0)

#define CRB_Clear() \
	do{ \
		CurrentResultBackup.value = 0; \
	}while(0)

#define CR_BOOL_LD(val)		(CR_BOOL = (val) & 0x01)
#define CR_BYTE_LD(val)		(CR_BYTE = (val))
#define CR_WORD_LD(val)		(CR_WORD = (val))
#define CR_DWORD_LD(val)	(CR_DWORD = (val))
#define CR_LWORD_LD(val)	(CR_LWORD = (val))
#define CR_SINT_LD(val)		(CR_SINT = (val))
#define CR_INT_LD(val)		(CR_INT = (val))
#define CR_DINT_LD(val)		(CR_DINT = (val))
#define CR_LINT_LD(val)		(CR_LINT = (val))
#define CR_USINT_LD(val)	(CR_USINT = (val))
#define CR_UINT_LD(val)		(CR_UINT = (val))
#define CR_UDINT_LD(val)	(CR_UDINT = (val))
#define CR_ULINT_LD(val)	(CR_ULINT = (val))
#define CR_REAL_LD(val)		(CR_REAL = (val))
#define CR_LREAL_LD(val)	(CR_LREAL = (val))
#define CR_TIME_LD(val)		(CR_TIME = (val))
#define CR_TOD_LD(val)		(CR_TOD = (val))
#define CR_DATE_LD(val)		(CR_DATE = (val))
#define CR_DT_LD(val)		(CR_DT = (val))

#define CR_BOOL_AND(val)	(CR_BOOL = ((CR_BOOL & (val)) & 0x01))
#define CR_BYTE_AND(val)	(CR_BYTE &= (val))
#define CR_WORD_AND(val)	(CR_WORD &= (val))
#define CR_DWORD_AND(val)	(CR_DWORD &= (val))
#define CR_LWORD_AND(val)	(CR_LWORD &= (val))
#define CR_SINT_AND
#define CR_INT_AND
#define CR_DINT_AND
#define CR_LINT_AND
#define CR_USINT_AND
#define CR_UINT_AND
#define CR_UDINT_AND
#define CR_ULINT_AND
#define CR_REAL_AND
#define CR_LREAL_AND
#define CR_TIME_AND
#define CR_TOD_AND
#define CR_DATE_AND
#define CR_DT_AND

#define CR_BOOL_OR(val)		(CR_BOOL = ((CR_BOOL | (val)) & 0x01))
#define CR_BYTE_OR(val)		(CR_BYTE |= (val))
#define CR_WORD_OR(val)		(CR_WORD |= (val))
#define CR_DWORD_OR(val)	(CR_DWORD |= (val))
#define CR_LWORD_OR(val)	(CR_LWORD |= (val))
#define CR_SINT_OR
#define CR_INT_OR
#define CR_DINT_OR
#define CR_LINT_OR
#define CR_USINT_OR
#define CR_UINT_OR
#define CR_UDINT_OR
#define CR_ULINT_OR
#define CR_REAL_OR
#define CR_LREAL_OR
#define CR_TIME_OR
#define CR_TOD_OR
#define CR_DATE_OR
#define CR_DT_OR

#define CR_BOOL_XOR(val)	(CR_BOOL = ((CR_BOOL ^ (val)) & 0x01))
#define CR_BYTE_XOR(val)	(CR_BYTE ^= (val))
#define CR_WORD_XOR(val)	(CR_WORD ^= (val))
#define CR_DWORD_XOR(val)	(CR_DWORD ^= (val))
#define CR_LWORD_XOR(val)	(CR_LWORD ^= (val))
#define CR_SINT_XOR
#define CR_INT_XOR
#define CR_DINT_XOR
#define CR_LINT_XOR
#define CR_USINT_XOR
#define CR_UINT_XOR
#define CR_UDINT_XOR
#define CR_ULINT_XOR
#define CR_REAL_XOR
#define CR_LREAL_XOR
#define CR_TIME_XOR
#define CR_TOD_XOR
#define CR_DATE_XOR
#define CR_DT_XOR

#define CR_BOOL_GT(val)		((CR_BOOL & 0x01) > ((val) & 0x01))
#define CR_BYTE_GT(val)		(CR_BYTE > (val))
#define CR_WORD_GT(val)		(CR_WORD > (val))
#define CR_DWORD_GT(val)	(CR_DWORD > (val))
#define CR_LWORD_GT(val)	(CR_LWORD > (val))
#define CR_SINT_GT(val)		(CR_SINT > (val))
#define CR_INT_GT(val)		(CR_INT > (val))
#define CR_DINT_GT(val)		(CR_DINT > (val))
#define CR_LINT_GT(val)		(CR_LINT > (val))
#define CR_USINT_GT(val)	(CR_USINT > (val))
#define CR_UINT_GT(val)		(CR_UINT > (val))
#define CR_UDINT_GT(val)	(CR_UDINT > (val))
#define CR_ULINT_GT(val)	(CR_ULINT > (val))
#define CR_REAL_GT(val)		(CR_REAL > (val))
#define CR_LREAL_GT(val)	(CR_LREAL > (val))
#define CR_TIME_GT(val)		(CR_TIME > (val))
#define CR_TOD_GT(val)		(CR_TOD > (val))
#define CR_DATE_GT(val)		(CR_DATE > (val))
#define CR_DT_GT(val)		(CR_DT > (val))

#define CR_BOOL_GE(val)		((CR_BOOL & 0x01) >= ((val) & 0x01))
#define CR_BYTE_GE(val)		(CR_BYTE >= (val))
#define CR_WORD_GE(val)		(CR_WORD >= (val))
#define CR_DWORD_GE(val)	(CR_DWORD >= (val))
#define CR_LWORD_GE(val)	(CR_LWORD >= (val))
#define CR_SINT_GE(val)		(CR_SINT >= (val))
#define CR_INT_GE(val)		(CR_INT >= (val))
#define CR_DINT_GE(val)		(CR_DINT >= (val))
#define CR_LINT_GE(val)		(CR_LINT >= (val))
#define CR_USINT_GE(val)	(CR_USINT >= (val))
#define CR_UINT_GE(val)		(CR_UINT >= (val))
#define CR_UDINT_GE(val)	(CR_UDINT >= (val))
#define CR_ULINT_GE(val)	(CR_ULINT >= (val))
#define CR_REAL_GE(val)		(CR_REAL >= (val))
#define CR_LREAL_GE(val)	(CR_LREAL >= (val))
#define CR_TIME_GE(val)		(CR_TIME >= (val))
#define CR_TOD_GE(val)		(CR_TOD >= (val))
#define CR_DATE_GE(val)		(CR_DATE >= (val))
#define CR_DT_GE(val)		(CR_DT >= (val))

#define CR_BOOL_EQ(val)		((CR_BOOL & 0x01) == ((val) & 0x01))
#define CR_BYTE_EQ(val)		(CR_BYTE == (val))
#define CR_WORD_EQ(val)		(CR_WORD == (val))
#define CR_DWORD_EQ(val)	(CR_DWORD == (val))
#define CR_LWORD_EQ(val)	(CR_LWORD == (val))
#define CR_SINT_EQ(val)		(CR_SINT == (val))
#define CR_INT_EQ(val)		(CR_INT == (val))
#define CR_DINT_EQ(val)		(CR_DINT == (val))
#define CR_LINT_EQ(val)		(CR_LINT == (val))
#define CR_USINT_EQ(val)	(CR_USINT == (val))
#define CR_UINT_EQ(val)		(CR_UINT == (val))
#define CR_UDINT_EQ(val)	(CR_UDINT == (val))
#define CR_ULINT_EQ(val)	(CR_ULINT == (val))
#define CR_REAL_EQ(val)		(fabs(CR_REAL - (val)) < 0.000001f)
#define CR_LREAL_EQ(val)	(fabs(CR_LREAL - (val)) < 0.000001f)
#define CR_TIME_EQ(val)		(CR_TIME == (val))
#define CR_TOD_EQ(val)		(CR_TOD == (val))
#define CR_DATE_EQ(val)		(CR_DATE == (val))
#define CR_DT_EQ(val)		(CR_DT == (val))

#define CR_BOOL_NE(val)		((CR_BOOL & 0x01) != ((val) & 0x01))
#define CR_BYTE_NE(val)		(CR_BYTE != (val))
#define CR_WORD_NE(val)		(CR_WORD != (val))
#define CR_DWORD_NE(val)	(CR_DWORD != (val))
#define CR_LWORD_NE(val)	(CR_LWORD != (val))
#define CR_SINT_NE(val)		(CR_SINT != (val))
#define CR_INT_NE(val)		(CR_INT != (val))
#define CR_DINT_NE(val)		(CR_DINT != (val))
#define CR_LINT_NE(val)		(CR_LINT != (val))
#define CR_USINT_NE(val)	(CR_USINT != (val))
#define CR_UINT_NE(val)		(CR_UINT != (val))
#define CR_UDINT_NE(val)	(CR_UDINT != (val))
#define CR_ULINT_NE(val)	(CR_ULINT != (val))
#define CR_REAL_NE(val)		(fabs(CR_REAL - (val)) > 0.000001f)
#define CR_LREAL_NE(val)	(fabs(CR_LREAL - (val)) > 0.000001f)
#define CR_TIME_NE(val)		(CR_TIME != (val))
#define CR_TOD_NE(val)		(CR_TOD != (val))
#define CR_DATE_NE(val)		(CR_DATE != (val))
#define CR_DT_NE(val)		(CR_DT != (val))

#define CR_BOOL_LE(val)		((CR_BOOL & 0x01) <= ((val) & 0x01))
#define CR_BYTE_LE(val)		(CR_BYTE <= (val))
#define CR_WORD_LE(val)		(CR_WORD <= (val))
#define CR_DWORD_LE(val)	(CR_DWORD <= (val))
#define CR_LWORD_LE(val)	(CR_LWORD <= (val))
#define CR_SINT_LE(val)		(CR_SINT <= (val))
#define CR_INT_LE(val)		(CR_INT <= (val))
#define CR_DINT_LE(val)		(CR_DINT <= (val))
#define CR_LINT_LE(val)		(CR_LINT <= (val))
#define CR_USINT_LE(val)	(CR_USINT <= (val))
#define CR_UINT_LE(val)		(CR_UINT <= (val))
#define CR_UDINT_LE(val)	(CR_UDINT <= (val))
#define CR_ULINT_LE(val)	(CR_ULINT <= (val))
#define CR_REAL_LE(val)		(CR_REAL <= (val))
#define CR_LREAL_LE(val)	(CR_LREAL <= (val))
#define CR_TIME_LE(val)		(CR_TIME <= (val))
#define CR_TOD_LE(val)		(CR_TOD <= (val))
#define CR_DATE_LE(val)		(CR_DATE <= (val))
#define CR_DT_LE(val)		(CR_DT <= (val))

#define CR_BOOL_LT(val)		((CR_BOOL & 0x01) < ((val) & 0x01))
#define CR_BYTE_LT(val)		(CR_BYTE < (val))
#define CR_WORD_LT(val)		(CR_WORD < (val))
#define CR_DWORD_LT(val)	(CR_DWORD < (val))
#define CR_LWORD_LT(val)	(CR_LWORD < (val))
#define CR_SINT_LT(val)		(CR_SINT < (val))
#define CR_INT_LT(val)		(CR_INT < (val))
#define CR_DINT_LT(val)		(CR_DINT < (val))
#define CR_LINT_LT(val)		(CR_LINT < (val))
#define CR_USINT_LT(val)	(CR_USINT < (val))
#define CR_UINT_LT(val)		(CR_UINT < (val))
#define CR_UDINT_LT(val)	(CR_UDINT < (val))
#define CR_ULINT_LT(val)	(CR_ULINT < (val))
#define CR_REAL_LT(val)		(CR_REAL < (val))
#define CR_LREAL_LT(val)	(CR_LREAL < (val))
#define CR_TIME_LT(val)		(CR_TIME < (val))
#define CR_TOD_LT(val)		(CR_TOD < (val))
#define CR_DATE_LT(val)		(CR_DATE < (val))
#define CR_DT_LT(val)		(CR_DT < (val))

void CR_NOP(void);

#define CR_NOT() \
	do{ \
		CR_DWORD = ~CR_DWORD; \
	}while(0)

#endif

