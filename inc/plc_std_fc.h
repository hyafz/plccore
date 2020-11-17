/**
  * @file  plc_std_fc.h
  * @brief     plc_std_fc.c的头文件
  * @author    fengzhou
  */

#ifndef _PLC_STANDARD_FC_H_
#define _PLC_STANDARD_FC_H_

#include "plc_type_define.h"
#include "plc_port.h"
#include <stdlib.h>
#include <math.h>


typedef struct{
    SINT IN;
}SINT_TO_INT_S;
extern SINT_TO_INT_S _SINT_TO_INT;
#define _SINT_TO_INT_()	((INT)(_SINT_TO_INT.IN))

typedef struct{
    INT IN;
}INT_TO_SINT_S;
extern INT_TO_SINT_S _INT_TO_SINT;
#define _INT_TO_SINT_()	(SINT)(_INT_TO_SINT.IN)


typedef struct{
    INT IN;
}INT_TO_DINT_S;
extern INT_TO_DINT_S _INT_TO_DINT;
#define _INT_TO_DINT_()	((DINT)(_INT_TO_DINT.IN))

typedef struct{
    DINT IN;
}DINT_TO_INT_S;
extern DINT_TO_INT_S _DINT_TO_INT;
#define _DINT_TO_INT_()	((INT)(_DINT_TO_INT.IN))

#if (DT_LINT_EN > 0)
typedef struct{
    DINT IN;
}DINT_TO_LINT_S;
extern DINT_TO_LINT_S _DINT_TO_LINT;
#define _DINT_TO_LINT_()	((LINT)(_DINT_TO_LINT.IN))

typedef struct{
    LINT in;
}LINT_TO_DINT_S;
extern LINT_TO_DINT_S _LINT_TO_DINT;
#define _LINT_TO_DINT_()	((DINT)(_LINT_TO_DINT.IN))
#endif

typedef struct{
    USINT IN;
}USINT_TO_UINT_S;
extern USINT_TO_UINT_S _USINT_TO_UINT;
#define _USINT_TO_UINT_()	((UINT)(_USINT_TO_UINT.IN))

typedef struct{
    UINT IN;
}UINT_TO_USINT_S;
extern UINT_TO_USINT_S _UINT_TO_USINT;
#define _UINT_TO_USINT_()	((USINT)(_UINT_TO_USINT.IN))


typedef struct{
    UINT IN;
}UINT_TO_UDINT_S;
extern UINT_TO_UDINT_S _UINT_TO_UDINT;
#define _UINT_TO_UDINT_()	((UDINT)(_UINT_TO_UDINT.IN))

typedef struct{
    UDINT IN;
}UDINT_TO_UINT_S;
extern UDINT_TO_UINT_S _UDINT_TO_UINT;
#define _UDINT_TO_UINT_()	((UINT)(_UDINT_TO_UINT.IN))

#if (DT_ULINT_EN > 0)
typedef struct{
    UDINT IN;
}UDINT_TO_ULINT_S;
extern UDINT_TO_ULINT_S _UDINT_TO_ULINT;
#define _UDINT_TO_ULINT_()	((ULINT)(_UDINT_TO_ULINT.IN))

typedef struct{
    ULINT IN;
}ULINT_TO_UDINT_S;
extern ULINT_TO_UDINT_S _ULINT_TO_UDINT;
#define _ULINT_TO_UDINT_()	((UDINT)(_ULINT_TO_UDINT.IN))
#endif

typedef struct{
    USINT IN;
}USINT_TO_SINT_S;
extern USINT_TO_SINT_S _USINT_TO_SINT;
#define _USINT_TO_SINT_()	((SINT)(_USINT_TO_SINT.IN))

typedef struct{
    SINT IN;
}SINT_TO_USINT_S;
extern SINT_TO_USINT_S _SINT_TO_USINT;
#define _SINT_TO_USINT_()	((USINT)(_SINT_TO_USINT.IN))

typedef struct{
    UINT IN;
}UINT_TO_INT_S;
extern UINT_TO_INT_S _UINT_TO_INT;
#define _UINT_TO_INT_()	((INT)(_UINT_TO_INT.IN))

typedef struct{
    INT IN;
}INT_TO_UINT_S;
extern INT_TO_UINT_S _INT_TO_UINT;
#define _INT_TO_UINT_()	((UINT)(_INT_TO_UINT.IN))


typedef struct{
    UDINT IN;
}UDINT_TO_DINT_S;
extern UDINT_TO_DINT_S _UDINT_TO_DINT;
#define _UDINT_TO_DINT_()	((DINT)(_UDINT_TO_DINT.IN))

typedef struct{
    DINT IN;
}DINT_TO_UDINT_S;
extern DINT_TO_UDINT_S _DINT_TO_UDINT;
#define _DINT_TO_UDINT_()	((UDINT)(_DINT_TO_UDINT.IN))

#if ((DT_ULINT_EN > 0) && (DT_LINT_EN > 0))
typedef struct{
    ULINT IN;
}ULINT_TO_LINT_S;
extern ULINT_TO_LINT_S _ULINT_TO_LINT;
#define _ULINT_TO_LINT_()	((LINT)(_ULINT_TO_LINT.IN))

typedef struct{
    LINT IN;
}LINT_TO_ULINT_S;
extern LINT_TO_ULINT_S _LINT_TO_ULINT;
#define _LINT_TO_ULINT_()	((ULINT)(_LINT_TO_ULINT.IN))
#endif

typedef struct{
    BOOL IN;
}BOOL_TO_BYTE_S;
extern BOOL_TO_BYTE_S _BOOL_TO_BYTE;
#define _BOOL_TO_BYTE_()	((BYTE)(_BOOL_TO_BYTE.IN))

typedef struct{
    BYTE IN;
}BYTE_TO_BOOL_S;
extern BYTE_TO_BOOL_S _BYTE_TO_BOOL;
#define _BYTE_TO_BOOL_()	((BOOL)(_BYTE_TO_BOOL.IN))


typedef struct{
    BYTE IN;
}BYTE_TO_WORD_S;
extern BYTE_TO_WORD_S _BYTE_TO_WORD;
#define _BYTE_TO_WORD_()	((WORD)(_BYTE_TO_WORD.IN))

typedef struct{
    WORD IN;
}WORD_TO_BYTE_S;
extern WORD_TO_BYTE_S _WORD_TO_BYTE;
#define _WORD_TO_BYTE_()	((BYTE)(_WORD_TO_BYTE.IN))


typedef struct{
    WORD IN;
}WORD_TO_DWORD_S;
extern WORD_TO_DWORD_S _WORD_TO_DWORD;
#define _WORD_TO_DWORD_()	((DWORD)(_WORD_TO_DWORD.IN))

typedef struct{
    DWORD IN;
}DWORD_TO_WORD_S;
extern DWORD_TO_WORD_S _DWORD_TO_WORD;
#define _DWORD_TO_WORD_()	((WORD)(_DWORD_TO_WORD.IN))

#if (DT_LWORD_EN > 0)
typedef struct{
    DWORD IN;
}DWORD_TO_LWORD_S;
extern DWORD_TO_LWORD_S _DWORD_TO_LWORD;
#define _DWORD_TO_LWORD_()	((LWORD)(_DWORD_TO_LWORD.IN))

typedef struct{
    LWORD IN;
}LWORD_TO_DWORD_S;
extern LWORD_TO_DWORD_S _LWORD_TO_DWORD;
#define _LWORD_TO_DWORD_()	((DWORD)(_LWORD_TO_DWORD.IN))
#endif


typedef struct{
    BYTE IN;
}BYTE_TO_USINT_S;
extern BYTE_TO_USINT_S _BYTE_TO_USINT;
#define _BYTE_TO_USINT_()	((USINT)(_BYTE_TO_USINT.IN))

typedef struct{
    USINT IN;
}USINT_TO_BYTE_S;
extern USINT_TO_BYTE_S _USINT_TO_BYTE;
#define _USINT_TO_BYTE_()	((BYTE)(_USINT_TO_BYTE.IN))

typedef struct{
    WORD IN;
}WORD_TO_UINT_S;
extern WORD_TO_UINT_S _WORD_TO_UINT;
#define _WORD_TO_UINT_()	((UINT)(_WORD_TO_UINT.IN))

typedef struct{
    UINT IN;
}UINT_TO_WORD_S;
extern UINT_TO_WORD_S _UINT_TO_WORD;
#define _UINT_TO_WORD_()	((WORD)(_UINT_TO_WORD.IN))

typedef struct{
    DWORD IN;
}DWORD_TO_UDINT_S;
extern DWORD_TO_UDINT_S _DWORD_TO_UDINT;
#define _DWORD_TO_UDINT_()	((UDINT)(_DWORD_TO_UDINT.IN))

typedef struct{
    UDINT IN;
}UDINT_TO_DWORD_S;
extern UDINT_TO_DWORD_S _UDINT_TO_DWORD;
#define _UDINT_TO_DWORD_()	((DINT)(_UDINT_TO_DWORD.IN))

#if ((DT_ULINT_EN > 0) && (DT_LWORD_EN > 0))
typedef struct{
    LWORD IN;
}LWORD_TO_ULINT_S;
extern LWORD_TO_ULINT_S _LWORD_TO_ULINT;
#define _LWORD_TO_ULINT_()	((ULINT)(_LWORD_TO_ULINT.IN))

typedef struct{
    ULINT IN;
}ULINT_TO_LWORD_S;
extern ULINT_TO_LWORD_S _ULINT_TO_LWORD;
#define _ULINT_TO_LWORD_()	((LWORD)(_ULINT_TO_LWORD.IN))
#endif

#if (DT_REAL_EN > 0)
typedef struct{
    REAL IN;
}REAL_TO_DINT_S;
extern REAL_TO_DINT_S _REAL_TO_DINT;
/**
 * @brief REAL类型转换为DINT类型
 * @note 直接调用round()函数四舍五入的实现是不符合标准的，需要修改。
 * @note 强制类型转换相当于丢弃小数部分，更不符合要求。
 */
#define _REAL_TO_DINT_()	((DINT)(_REAL_TO_DINT.IN))

typedef struct{
    DINT IN;
}DINT_TO_REAL_S;
extern DINT_TO_REAL_S _DINT_TO_REAL;
/**
 * @brief DINT类型转换为REAL类型
 * @note 目前的实现是不标准的，需要修改。
 */
#define _DINT_TO_REAL_()	((REAL)(_DINT_TO_REAL.IN))
#endif

#if ((DT_LINT_EN > 0) && (DT_LREAL_EN > 0))
typedef struct{
    LREAL IN;
}LREAL_TO_LINT_S;
extern LREAL_TO_LINT_S _LREAL_TO_LINT;
/**
 * @brief LREAL类型转换为LINT类型
 * @note 直接调用round()函数四舍五入的实现是不符合标准的，需要修改。
 * @note 强制类型转换相当于丢弃小数部分，更不符合要求。
 */
#define _LREAL_TO_LINT_()	((LINT)(_LREAL_TO_LINT.IN))

typedef struct{
    LINT IN;
}LINT_TO_LREAL_S;
extern LINT_TO_LREAL_S _LINT_TO_LREAL;
/**
 * @brief LINT类型转换为LREAL类型
 * @note 目前的实现是不标准的，需要修改。
 */
#define _LINT_TO_LREAL_()	((LREAL)(_LINT_TO_LREAL.IN))

#endif

/*
 * =============================================
 * ADD
 * =============================================
*/
typedef struct{
    SINT IN1;
    SINT IN2;
}ADD_SINT_S;
extern ADD_SINT_S _ADD_SINT;
#define _ADD_SINT_()	(_ADD_SINT.IN1 + _ADD_SINT.IN2)

typedef struct{
    INT IN1;
    INT IN2;
}ADD_INT_S;
extern ADD_INT_S _ADD_INT;
#define _ADD_INT_()	(_ADD_INT.IN1 + _ADD_INT.IN2)

typedef struct{
    DINT IN1;
    DINT IN2;
}ADD_DINT_S;
extern ADD_DINT_S _ADD_DINT;
#define _ADD_DINT_()	(_ADD_DINT.IN1 + _ADD_DINT.IN2)

#if (DT_LINT_EN > 0)
typedef struct{
    LINT IN1;
    LINT IN2;
}ADD_LINT_S;
extern ADD_LINT_S _ADD_LINT;
#define _ADD_LINT_()	(_ADD_LINT.IN1 + _ADD_LINT.IN2)
#endif

typedef struct{
    USINT IN1;
    USINT IN2;
}ADD_USINT_S;
extern ADD_USINT_S _ADD_USINT;
#define _ADD_USINT_()	(_ADD_USINT.IN1 + _ADD_USINT.IN2)

typedef struct{
    UINT IN1;
    UINT IN2;
}ADD_UINT_S;
extern ADD_UINT_S _ADD_UINT;
#define _ADD_UINT_()	(_ADD_UINT.IN1 + _ADD_UINT.IN2)

typedef struct{
    UDINT IN1;
    UDINT IN2;
}ADD_UDINT_S;
extern ADD_UDINT_S _ADD_UDINT;
#define _ADD_UDINT_()	(_ADD_UDINT.IN1 + _ADD_UDINT.IN2)

#if (DT_LINT_EN > 0)
typedef struct{
    ULINT IN1;
    ULINT IN2;
}ADD_ULINT_S;
extern ADD_ULINT_S _ADD_ULINT;
#define _ADD_ULINT_()	(_ADD_ULINT.IN1 + _ADD_ULINT.IN2)
#endif

#if (DT_REAL_EN > 0)
typedef struct{
    REAL IN1;
    REAL IN2;
}ADD_REAL_S;
extern ADD_REAL_S _ADD_REAL;
#define _ADD_REAL_()	(_ADD_REAL.IN1 + _ADD_REAL.IN2)
#endif

#if (DT_LREAL_EN > 0)
typedef struct{
    LREAL IN1;
    LREAL IN2;
}ADD_LREAL_S;
extern ADD_LREAL_S _ADD_LREAL;
#define _ADD_LREAL_()	(_ADD_LREAL.IN1 + _ADD_LREAL.IN2)
#endif

/*
 * =============================================
 * SUB
 * =============================================
*/
typedef struct{
    SINT IN1;
    SINT IN2;
}SUB_SINT_S;
extern SUB_SINT_S _SUB_SINT;
#define _SUB_SINT_()	(_SUB_SINT.IN1 - _SUB_SINT.IN2)

typedef struct{
    INT IN1;
    INT IN2;
}SUB_INT_S;
extern SUB_INT_S _SUB_INT;
#define _SUB_INT_()	(_SUB_INT.IN1 - _SUB_INT.IN2)

typedef struct{
    DINT IN1;
    DINT IN2;
}SUB_DINT_S;
extern SUB_DINT_S _SUB_DINT;
#define _SUB_DINT_()	(_SUB_DINT.IN1 - _SUB_DINT.IN2)

#if (DT_LINT_EN > 0)
typedef struct{
    LINT IN1;
    LINT IN2;
}SUB_LINT_S;
extern SUB_LINT_S _SUB_LINT;
#define _SUB_LINT_()	(_SUB_LINT.IN1 - _SUB_LINT.IN2)
#endif

typedef struct{
    USINT IN1;
    USINT IN2;
}SUB_USINT_S;
extern SUB_USINT_S _SUB_USINT;
#define _SUB_USINT_()	(_SUB_USINT.IN1 - _SUB_USINT.IN2)

typedef struct{
    UINT IN1;
    UINT IN2;
}SUB_UINT_S;
extern SUB_UINT_S _SUB_UINT;
#define _SUB_UINT_()	(_SUB_UINT.IN1 - _SUB_UINT.IN2)

typedef struct{
    UDINT IN1;
    UDINT IN2;
}SUB_UDINT_S;
extern SUB_UDINT_S _SUB_UDINT;
#define _SUB_UDINT_()	(_SUB_UDINT.IN1 - _SUB_UDINT.IN2)

#if (DT_LINT_EN > 0)
typedef struct{
    ULINT IN1;
    ULINT IN2;
}SUB_ULINT_S;
extern SUB_ULINT_S _SUB_ULINT;
#define _SUB_ULINT_()	(_SUB_ULINT.IN1 - _SUB_ULINT.IN2)
#endif

#if (DT_REAL_EN > 0)
typedef struct{
    REAL IN1;
    REAL IN2;
}SUB_REAL_S;
extern SUB_REAL_S _SUB_REAL;
#define _SUB_REAL_()	(_SUB_REAL.IN1 - _SUB_REAL.IN2)
#endif

#if (DT_LREAL_EN > 0)
typedef struct{
    LREAL IN1;
    LREAL IN2;
}SUB_LREAL_S;
extern SUB_LREAL_S _SUB_LREAL;
#define _SUB_LREAL_()	(_SUB_LREAL.IN1 - _SUB_LREAL.IN2)
#endif

/*
 * =============================================
 * MUL
 * =============================================
*/
typedef struct{
    SINT IN1;
    SINT IN2;
}MUL_SINT_S;
extern MUL_SINT_S _MUL_SINT;
#define _MUL_SINT_()	(_MUL_SINT.IN1 * _MUL_SINT.IN2)

typedef struct{
    INT IN1;
    INT IN2;
}MUL_INT_S;
extern MUL_INT_S _MUL_INT;
#define _MUL_INT_()	(_MUL_INT.IN1 * _MUL_INT.IN2)

typedef struct{
    DINT IN1;
    DINT IN2;
}MUL_DINT_S;
extern MUL_DINT_S _MUL_DINT;
#define _MUL_DINT_()	(_MUL_DINT.IN1 * _MUL_DINT.IN2)

#if (DT_LINT_EN > 0)
typedef struct{
    LINT IN1;
    LINT IN2;
}MUL_LINT_S;
extern MUL_LINT_S _MUL_LINT;
#define _MUL_LINT_()	(_MUL_LINT.IN1 * _MUL_LINT.IN2)
#endif

typedef struct{
    USINT IN1;
    USINT IN2;
}MUL_USINT_S;
extern MUL_USINT_S _MUL_USINT;
#define _MUL_USINT_()	(_MUL_USINT.IN1 * _MUL_USINT.IN2)

typedef struct{
    UINT IN1;
    UINT IN2;
}MUL_UINT_S;
extern MUL_UINT_S _MUL_UINT;
#define _MUL_UINT_()	(_MUL_UINT.IN1 * _MUL_UINT.IN2)

typedef struct{
    UDINT IN1;
    UDINT IN2;
}MUL_UDINT_S;
extern MUL_UDINT_S _MUL_UDINT;
#define _MUL_UDINT_()	(_MUL_UDINT.IN1 * _MUL_UDINT.IN2)

#if (DT_LINT_EN > 0)
typedef struct{
    ULINT IN1;
    ULINT IN2;
}MUL_ULINT_S;
extern MUL_ULINT_S _MUL_ULINT;
#define _MUL_ULINT_()	(_MUL_ULINT.IN1 * _MUL_ULINT.IN2)
#endif

#if (DT_REAL_EN > 0)
typedef struct{
    REAL IN1;
    REAL IN2;
}MUL_REAL_S;
extern MUL_REAL_S _MUL_REAL;
#define _MUL_REAL_()	(_MUL_REAL.IN1 * _MUL_REAL.IN2)
#endif

#if (DT_LREAL_EN > 0)
typedef struct{
    LREAL IN1;
    LREAL IN2;
}MUL_LREAL_S;
extern MUL_LREAL_S _MUL_LREAL;
#define _MUL_LREAL_()	(_MUL_LREAL.IN1 * _MUL_LREAL.IN2)
#endif

/*
 * =============================================
 * DIV
 * =============================================
*/
typedef struct{
    SINT IN1;
    SINT IN2;
}DIV_SINT_S;
extern DIV_SINT_S _DIV_SINT;
#define _DIV_SINT_()	((_DIV_SINT.IN2 == 0) ? \
        0 :  (_DIV_SINT.IN1 / _DIV_SINT.IN2))

typedef struct{
    INT IN1;
    INT IN2;
}DIV_INT_S;
extern DIV_INT_S _DIV_INT;
#define _DIV_INT_()	((_DIV_INT.IN2 == 0) ? \
        0 : (_DIV_INT.IN1 / _DIV_INT.IN2))

typedef struct{
    DINT IN1;
    DINT IN2;
}DIV_DINT_S;
extern DIV_DINT_S _DIV_DINT;
#define _DIV_DINT_()	((_DIV_DINT.IN2 == 0) ? \
        0 : (_DIV_DINT.IN1 / _DIV_DINT.IN2))

#if (DT_LINT_EN > 0)
typedef struct{
    LINT IN1;
    LINT IN2;
}DIV_LINT_S;
extern DIV_LINT_S _DIV_LINT;
#define _DIV_LINT_()	((_DIV_LINT.IN2 == 0) ? \
        0 : (_DIV_LINT.IN1 / _DIV_LINT.IN2))
#endif

typedef struct{
    USINT IN1;
    USINT IN2;
}DIV_USINT_S;
extern DIV_USINT_S _DIV_USINT;
#define _DIV_USINT_()	((_DIV_USINT.IN2 == 0) ? \
        0 : (_DIV_USINT.IN1 / _DIV_USINT.IN2))

typedef struct{
    UINT IN1;
    UINT IN2;
}DIV_UINT_S;
extern DIV_UINT_S _DIV_UINT;
#define _DIV_UINT_()	((_DIV_UINT.IN2 == 0) ? \
        0 : (_DIV_UINT.IN1 / _DIV_UINT.IN2))

typedef struct{
    UDINT IN1;
    UDINT IN2;
}DIV_UDINT_S;
extern DIV_UDINT_S _DIV_UDINT;
#define _DIV_UDINT_()	((_DIV_UDINT.IN2 == 0) ? \
        0 : (_DIV_UDINT.IN1 / _DIV_UDINT.IN2))

#if (DT_LINT_EN > 0)
typedef struct{
    ULINT IN1;
    ULINT IN2;
}DIV_ULINT_S;
extern DIV_ULINT_S _DIV_ULINT;
#define _DIV_ULINT_()	((_DIV_ULINT.IN2 == 0) ? \
        0 : (_DIV_ULINT.IN1 / _DIV_ULINT.IN2))
#endif

#if (DT_REAL_EN > 0)
typedef struct{
    REAL IN1;
    REAL IN2;
}DIV_REAL_S;
extern DIV_REAL_S _DIV_REAL;
#define _DIV_REAL_()	((_DIV_REAL.IN2 == 0) ? \
        0 : (_DIV_REAL.IN1 / _DIV_REAL.IN2))
#endif

#if (DT_LREAL_EN > 0)
typedef struct{
    LREAL IN1;
    LREAL IN2;
}DIV_LREAL_S;
extern DIV_LREAL_S _DIV_LREAL;
#define _DIV_LREAL_()	((_DIV_LREAL.IN2 == 0) ? \
                         0 : (_DIV_LREAL.IN1 / _DIV_LREAL.IN2))
#endif

/*
 * =============================================
 * MOD
 * =============================================
*/
typedef struct{
    SINT IN1;
    SINT IN2;
}MOD_SINT_S;
extern MOD_SINT_S _MOD_SINT;
#define _MOD_SINT_()	(_MOD_SINT.IN1 % _MOD_SINT.IN2)

typedef struct{
    INT IN1;
    INT IN2;
}MOD_INT_S;
extern MOD_INT_S _MOD_INT;
#define _MOD_INT_()	(_MOD_INT.IN1 % _MOD_INT.IN2)

typedef struct{
    DINT IN1;
    DINT IN2;
}MOD_DINT_S;
extern MOD_DINT_S _MOD_DINT;
#define _MOD_DINT_()	(_MOD_DINT.IN1 % _MOD_DINT.IN2)

#if (DT_LINT_EN > 0)
typedef struct{
    LINT IN1;
    LINT IN2;
}MOD_LINT_S;
extern MOD_LINT_S _MOD_LINT;
#define _MOD_LINT_()	(_MOD_LINT.IN1 % _MOD_LINT.IN2)
#endif

typedef struct{
    USINT IN1;
    USINT IN2;
}MOD_USINT_S;
extern MOD_USINT_S _MOD_USINT;
#define _MOD_USINT_()	(_MOD_USINT.IN1 % _MOD_USINT.IN2)

typedef struct{
    UINT IN1;
    UINT IN2;
}MOD_UINT_S;
extern MOD_UINT_S _MOD_UINT;
#define _MOD_UINT_()	(_MOD_UINT.IN1 % _MOD_UINT.IN2)

typedef struct{
    UDINT IN1;
    UDINT IN2;
}MOD_UDINT_S;
extern MOD_UDINT_S _MOD_UDINT;
#define _MOD_UDINT_()	(_MOD_UDINT.IN1 % _MOD_UDINT.IN2)

#if (DT_LINT_EN > 0)
typedef struct{
    ULINT IN1;
    ULINT IN2;
}MOD_ULINT_S;
extern MOD_ULINT_S _MOD_ULINT;
#define _MOD_ULINT_()	(_MOD_ULINT.IN1 % _MOD_ULINT.IN2)
#endif
/*
 * =============================================
 * EXPT
 * =============================================
*/

#if (DT_REAL_EN > 0)
typedef struct{
    REAL IN1;
    REAL IN2;
}EXPT_REAL_S;
extern EXPT_REAL_S _EXPT_REAL;
#define _EXPT_REAL_()	(pow(_EXPT_REAL.IN1, _EXPT_REAL.IN2))
#endif

#if (DT_LREAL_EN > 0)
typedef struct{
    LREAL IN1;
    LREAL IN2;
}EXPT_LREAL_S;
extern EXPT_LREAL_S _EXPT_LREAL;
#define _EXPT_LREAL_()	(pow(_EXPT_LREAL.IN1, _EXPT_LREAL.IN2))
#endif

/*
 * =============================================
 * MOVE
 * =============================================
*/
typedef struct{
    BOOL IN;
}MOVE_BOOL_S;
extern MOVE_BOOL_S _MOVE_BOOL;
#define _MOVE_BOOL_()	(_MOVE_BOOL.IN)

typedef struct{
    BYTE IN;
}MOVE_BYTE_S;
extern MOVE_BYTE_S _MOVE_BYTE;
#define _MOVE_BYTE_()	(_MOVE_BYTE.IN)

typedef struct{
    WORD IN;
}MOVE_WORD_S;
extern MOVE_WORD_S _MOVE_WORD;
#define _MOVE_WORD_()	(_MOVE_WORD.IN)

typedef struct{
    DWORD IN;
}MOVE_DWORD_S;
extern MOVE_DWORD_S _MOVE_DWORD;
#define _MOVE_DWORD_()	(_MOVE_DWORD.IN)

#if (DT_LWORD_EN > 0)
typedef struct{
    LWORD IN;
}MOVE_LWORD_S;
extern MOVE_LWORD_S _MOVE_LWORD;
#define _MOVE_LWORD_()	(_MOVE_LWORD.IN)
#endif

typedef struct{
    SINT IN;
}MOVE_SINT_S;
extern MOVE_SINT_S _MOVE_SINT;
#define _MOVE_SINT_()	(_MOVE_SINT.IN)

typedef struct{
    INT IN;
}MOVE_INT_S;
extern MOVE_INT_S _MOVE_INT;
#define _MOVE_INT_()	(_MOVE_INT.IN)

typedef struct{
    DINT IN;
}MOVE_DINT_S;
extern MOVE_DINT_S _MOVE_DINT;
#define _MOVE_DINT_()	(_MOVE_DINT.IN)

#if (DT_LINT_EN > 0)
typedef struct{
    LINT IN;
}MOVE_LINT_S;
extern MOVE_LINT_S _MOVE_LINT;
#define _MOVE_LINT_()	(_MOVE_LINT.IN)
#endif

typedef struct{
    USINT IN;
}MOVE_USINT_S;
extern MOVE_USINT_S _MOVE_USINT;
#define _MOVE_USINT_()	(_MOVE_USINT.IN)

typedef struct{
    UINT IN;
}MOVE_UINT_S;
extern MOVE_UINT_S _MOVE_UINT;
#define _MOVE_UINT_()	(_MOVE_UINT.IN)

typedef struct{
    UDINT IN;
}MOVE_UDINT_S;
extern MOVE_UDINT_S _MOVE_UDINT;
#define _MOVE_UDINT_()	(_MOVE_UDINT.IN)

#if (DT_LINT_EN > 0)
typedef struct{
    ULINT IN;
}MOVE_ULINT_S;
extern MOVE_ULINT_S _MOVE_ULINT;
#define _MOVE_ULINT_()	(_MOVE_ULINT.IN)
#endif

#if (DT_REAL_EN > 0)
typedef struct{
    REAL IN;
}MOVE_REAL_S;
extern MOVE_REAL_S _MOVE_REAL;
#define _MOVE_REAL_()	(_MOVE_REAL.IN)
#endif

#if (DT_LREAL_EN > 0)
typedef struct{
    LREAL IN;
}MOVE_LREAL_S;
extern MOVE_LREAL_S _MOVE_LREAL;
#define _MOVE_LREAL_()	(_MOVE_LREAL.IN)
#endif

/*
 * =============================================
 * ABS
 * =============================================
*/

typedef struct{
    SINT IN;
}ABS_SINT_S;
extern ABS_SINT_S _ABS_SINT;
#define _ABS_SINT_()	(abs(_ABS_SINT.IN))

typedef struct{
    INT IN;
}ABS_INT_S;
extern ABS_INT_S _ABS_INT;
#define _ABS_INT_()	(abs(_ABS_INT.IN))

typedef struct{
    DINT IN;
}ABS_DINT_S;
extern ABS_DINT_S _ABS_DINT;
#define _ABS_DINT_()	(abs(_ABS_DINT.IN))

#if (DT_LINT_EN > 0)
typedef struct{
    LINT IN;
}ABS_LINT_S;
extern ABS_LINT_S _ABS_LINT;
#define _ABS_LINT_()	(abs(_ABS_LINT.IN))
#endif

typedef struct{
    USINT IN;
}ABS_USINT_S;
extern ABS_USINT_S _ABS_USINT;
#define _ABS_USINT_()	(abs(_ABS_USINT.IN))

typedef struct{
    UINT IN;
}ABS_UINT_S;
extern ABS_UINT_S _ABS_UINT;
#define _ABS_UINT_()	(abs(_ABS_UINT.IN))

typedef struct{
    UDINT IN;
}ABS_UDINT_S;
extern ABS_UDINT_S _ABS_UDINT;
#define _ABS_UDINT_()	(abs(_ABS_UDINT.IN))

#if (DT_LINT_EN > 0)
typedef struct{
    ULINT IN;
}ABS_ULINT_S;
extern ABS_ULINT_S _ABS_ULINT;
#define _ABS_ULINT_()	(abs(_ABS_ULINT.IN))
#endif

#if (DT_REAL_EN > 0)
typedef struct{
    REAL IN;
}ABS_REAL_S;
extern ABS_REAL_S _ABS_REAL;
#define _ABS_REAL_()	(fabs(_ABS_REAL.IN))
#endif

#if (DT_LREAL_EN > 0)
typedef struct{
    LREAL IN;
}ABS_LREAL_S;
extern ABS_LREAL_S _ABS_LREAL;
#define _ABS_LREAL_()	(fabs(_ABS_LREAL.IN))
#endif

/*
 * =============================================
 * SQRT
 * =============================================
*/
#if (DT_REAL_EN > 0)
typedef struct{
    REAL IN;
}SQRT_REAL_S;
extern SQRT_REAL_S _SQRT_REAL;
#define _SQRT_REAL_()	(sqrt(_SQRT_REAL.IN))
#endif

#if (DT_LREAL_EN > 0)
typedef struct{
    LREAL IN;
}SQRT_LREAL_S;
extern SQRT_LREAL_S _SQRT_LREAL;
#define _SQRT_LREAL_()	(sqrt(_SQRT_LREAL.IN))
#endif

/*
 * =============================================
 * LN
 * =============================================
*/
#if (DT_REAL_EN > 0)
typedef struct{
    REAL IN;
}LN_REAL_S;
extern LN_REAL_S _LN_REAL;
#define _LN_REAL_()	(logf(_LN_REAL.IN))
#endif

#if (DT_LREAL_EN > 0)
typedef struct{
    LREAL IN;
}LN_LREAL_S;
extern LN_LREAL_S _LN_LREAL;
#define _LN_LREAL_()	(log(_LN_LREAL.IN))
#endif

/*
 * =============================================
 * LOG
 * =============================================
*/
#if (DT_REAL_EN > 0)
typedef struct{
    REAL IN;
}LOG_REAL_S;
extern LOG_REAL_S _LOG_REAL;
#define _LOG_REAL_()	(log10f(_LOG_REAL.IN))
#endif

#if (DT_LREAL_EN > 0)
typedef struct{
    LREAL IN;
}LOG_LREAL_S;
extern LOG_LREAL_S _LOG_LREAL;
#define _LOG_LREAL_()	(log10(_LOG_LREAL.IN))
#endif

/*
 * =============================================
 * EXP
 * =============================================
*/
#if (DT_REAL_EN > 0)
typedef struct{
    REAL IN;
}EXP_REAL_S;
extern EXP_REAL_S _EXP_REAL;
#define _EXP_REAL_()	(expf(_EXP_REAL.IN))
#endif

#if (DT_LREAL_EN > 0)
typedef struct{
    LREAL IN;
}EXP_LREAL_S;
extern EXP_LREAL_S _EXP_LREAL;
#define _EXP_LREAL_()	(exp(_EXP_LREAL.IN))
#endif

/*
 * =============================================
 * SIN
 * =============================================
*/
#if (DT_REAL_EN > 0)
typedef struct{
    REAL IN;
}SIN_REAL_S;
extern SIN_REAL_S _SIN_REAL;
#define _SIN_REAL_()	(sinf(_SIN_REAL.IN))
#endif

#if (DT_LREAL_EN > 0)
typedef struct{
    LREAL IN;
}SIN_LREAL_S;
extern SIN_LREAL_S _SIN_LREAL;
#define _SIN_LREAL_()	(sin(_SIN_LREAL.IN))
#endif

/*
 * =============================================
 * COS
 * =============================================
*/
#if (DT_REAL_EN > 0)
typedef struct{
    REAL IN;
}COS_REAL_S;
extern COS_REAL_S _COS_REAL;
#define _COS_REAL_()	(cosf(_COS_REAL.IN))
#endif

#if (DT_LREAL_EN > 0)
typedef struct{
    LREAL IN;
}COS_LREAL_S;
extern COS_LREAL_S _COS_LREAL;
#define _COS_LREAL_()	(cos(_COS_LREAL.IN))
#endif

/*
 * =============================================
 * TAN
 * =============================================
*/
#if (DT_REAL_EN > 0)
typedef struct{
    REAL IN;
}TAN_REAL_S;
extern TAN_REAL_S _TAN_REAL;
#define _TAN_REAL_()	(tanf(_TAN_REAL.IN))
#endif

#if (DT_LREAL_EN > 0)
typedef struct{
    LREAL IN;
}TAN_LREAL_S;
extern TAN_LREAL_S _TAN_LREAL;
#define _TAN_LREAL_()	(tan(_TAN_LREAL.IN))
#endif

/*
 * =============================================
 * ASIN
 * =============================================
*/
#if (DT_REAL_EN > 0)
typedef struct{
    REAL IN;
}ASIN_REAL_S;
extern ASIN_REAL_S _ASIN_REAL;
#define _ASIN_REAL_()	(asinf(_ASIN_REAL.IN))
#endif

#if (DT_LREAL_EN > 0)
typedef struct{
    LREAL IN;
}ASIN_LREAL_S;
extern ASIN_LREAL_S _ASIN_LREAL;
#define _ASIN_LREAL_()	(asin(_ASIN_LREAL.IN))
#endif

/*
 * =============================================
 * ACOS
 * =============================================
*/
#if (DT_REAL_EN > 0)
typedef struct{
    REAL IN;
}ACOS_REAL_S;
extern ACOS_REAL_S _ACOS_REAL;
#define _ACOS_REAL_()	(acosf(_ACOS_REAL.IN))
#endif

#if (DT_LREAL_EN > 0)
typedef struct{
    LREAL IN;
}ACOS_LREAL_S;
extern ACOS_LREAL_S _ACOS_LREAL;
#define _ACOS_LREAL_()	(acos(_ACOS_LREAL.IN))
#endif

/*
 * =============================================
 * ATAN
 * =============================================
*/
#if (DT_REAL_EN > 0)
typedef struct{
    REAL IN;
}ATAN_REAL_S;
extern ATAN_REAL_S _ATAN_REAL;
#define _ATAN_REAL_()	(atanf(_ATAN_REAL.IN))
#endif

#if (DT_LREAL_EN > 0)
typedef struct{
    LREAL IN;
}ATAN_LREAL_S;
extern ATAN_LREAL_S _ATAN_LREAL;
#define _ATAN_LREAL_()	(atan(_ATAN_LREAL.IN))
#endif

/*
 * =============================================
 * SHL
 * =============================================
*/
typedef struct{
    BYTE IN;
    DINT N;
}SHL_BYTE_S;
extern SHL_BYTE_S _SHL_BYTE;
#define _SHL_BYTE_()	((BYTE)(_SHL_BYTE.IN << _SHL_BYTE.N))

typedef struct{
    WORD IN;
    DINT N;
}SHL_WORD_S;
extern SHL_WORD_S _SHL_WORD;
#define _SHL_WORD_()	((WORD)(_SHL_WORD.IN << _SHL_WORD.N))

typedef struct{
    DWORD IN;
    DINT N;
}SHL_DWORD_S;
extern SHL_DWORD_S _SHL_DWORD;
#define _SHL_DWORD_()	((DWORD)(_SHL_DWORD.IN << _SHL_DWORD.N))

#if (DT_LWORD_EN > 0)
typedef struct{
    LWORD IN;
    DINT N;
}SHL_LWORD_S;
extern SHL_LWORD_S _SHL_LWORD;
#define _SHL_LWORD_()	((LWORD)(_SHL_LWORD.IN << _SHL_LWORD.N))
#endif

/*
 * =============================================
 * SHR
 * =============================================
*/
typedef struct{
    BYTE IN;
    DINT N;
}SHR_BYTE_S;
extern SHR_BYTE_S _SHR_BYTE;
#define _SHR_BYTE_()	((BYTE)(_SHR_BYTE.IN >> _SHR_BYTE.N))

typedef struct{
    WORD IN;
    DINT N;
}SHR_WORD_S;
extern SHR_WORD_S _SHR_WORD;
#define _SHR_WORD_()	((WORD)(_SHR_WORD.IN >> _SHR_WORD.N))

typedef struct{
    DWORD IN;
    DINT N;
}SHR_DWORD_S;
extern SHR_DWORD_S _SHR_DWORD;
#define _SHR_DWORD_()	((DWORD)(_SHR_DWORD.IN >> _SHR_DWORD.N))

#if (DT_LWORD_EN > 0)
typedef struct{
    LWORD IN;
    DINT N;
}SHR_LWORD_S;
extern SHR_LWORD_S _SHR_LWORD;
#define _SHR_LWORD_()	((LWORD)(_SHR_LWORD.IN >> _SHR_LWORD.N))
#endif

/*
 * =============================================
 * ROR
 * =============================================
*/
typedef struct{
    BYTE IN;
    DINT N;
}ROR_BYTE_S;
extern ROR_BYTE_S _ROR_BYTE;
#define _ROR_BYTE_()	((BYTE)((_ROR_BYTE.IN >> (_ROR_BYTE.N % 8)) \
                         | (_ROR_BYTE.IN << (8 - (_ROR_BYTE.N % 8)))))

typedef struct{
    WORD IN;
    DINT N;
}ROR_WORD_S;
extern ROR_WORD_S _ROR_WORD;
#define _ROR_WORD_()	((WORD)((_ROR_WORD.IN >> (_ROR_WORD.N % 16)) \
                         | (_ROR_WORD.IN << (16 - (_ROR_WORD.N % 16)))))

typedef struct{
    DWORD IN;
    DINT N;
}ROR_DWORD_S;
extern ROR_DWORD_S _ROR_DWORD;
#define _ROR_DWORD_()	((DWORD)((_ROR_DWORD.IN >> (_ROR_DWORD.N % 32)) \
                         | (_ROR_DWORD.IN << (32 - (_ROR_DWORD.N % 32)))))

#if (DT_LWORD_EN > 0)
typedef struct{
    LWORD IN;
    DINT N;
}ROR_LWORD_S;
extern ROR_LWORD_S _ROR_LWORD;
#define _ROR_LWORD_()	((LWORD)((_ROR_LWORD.IN >> (_ROR_LWORD.N % 64)) \
                         | (_ROR_LWORD.IN << (64 - (_ROR_LWORD.N % 64)))))
#endif

/*
 * =============================================
 * ROL
 * =============================================
*/
typedef struct{
    BYTE IN;
    DINT N;
}ROL_BYTE_S;
extern ROL_BYTE_S _ROL_BYTE;
#define _ROL_BYTE_()	((BYTE)((_ROL_BYTE.IN << (_ROR_BYTE.N % 8)) \
                                | (_ROL_BYTE.IN >> (8 - (_ROR_BYTE.N % 8)))))

typedef struct{
    WORD IN;
    DINT N;
}ROL_WORD_S;
extern ROL_WORD_S _ROL_WORD;
#define _ROL_WORD_()	((WORD)((_ROL_WORD.IN << (_ROR_WORD.N % 16)) \
                                | (_ROL_WORD.IN >> (16 - (_ROR_WORD.N % 16)))))

typedef struct{
    DWORD IN;
    DINT N;
}ROL_DWORD_S;
extern ROL_DWORD_S _ROL_DWORD;
#define _ROL_DWORD_()	((DWORD)((_ROL_DWORD.IN << (_ROR_DWORD.N % 32)) \
                                 | (_ROL_DWORD.IN >> (32 - (_ROR_DWORD.N % 32)))))

#if (DT_LWORD_EN > 0)
typedef struct{
    LWORD IN;
    DINT N;
}ROL_LWORD_S;
extern ROL_LWORD_S _ROL_LWORD;
#define _ROL_LWORD_()	((LWORD)((_ROL_LWORD.IN << (_ROR_LWORD.N % 64)) \
                                 | (_ROL_LWORD.IN >> (64 - (_ROR_LWORD.N % 64)))))
#endif

/*
 * =============================================
 * AND
 * =============================================
*/
typedef struct{
    BOOL IN1;
    BOOL IN2;
}AND_BOOL_S;
extern AND_BOOL_S _AND_BOOL;
#define _AND_BOOL_()	(_AND_BOOL.IN1 & _AND_BOOL.IN2)

typedef struct{
    BYTE IN1;
    BYTE IN2;
}AND_BYTE_S;
extern AND_BYTE_S _AND_BYTE;
#define _AND_BYTE_()	(_AND_BYTE.IN1 & _AND_BYTE.IN2)

typedef struct{
    WORD IN1;
    WORD IN2;
}AND_WORD_S;
extern AND_WORD_S _AND_WORD;
#define _AND_WORD_()	(_AND_WORD.IN1 & _AND_WORD.IN2)

typedef struct{
    DWORD IN1;
    DWORD IN2;
}AND_DWORD_S;
extern AND_DWORD_S _AND_DWORD;
#define _AND_DWORD_()	(_AND_DWORD.IN1 & _AND_DWORD.IN2)

#if (DT_LWORD_EN > 0)
typedef struct{
    LWORD IN1;
    LWORD IN2;
}AND_LWORD_S;
extern AND_LWORD_S _AND_LWORD;
#define _AND_LWORD_()	(_AND_LWORD.IN1 & _AND_LWORD.IN2)
#endif

/*
 * =============================================
 * OR
 * =============================================
*/
typedef struct{
    BOOL IN1;
    BOOL IN2;
}OR_BOOL_S;
extern OR_BOOL_S _OR_BOOL;
#define _OR_BOOL_()	(_OR_BOOL.IN1 | _OR_BOOL.IN2)

typedef struct{
    BYTE IN1;
    BYTE IN2;
}OR_BYTE_S;
extern OR_BYTE_S _OR_BYTE;
#define _OR_BYTE_()	(_OR_BYTE.IN1 | _OR_BYTE.IN2)

typedef struct{
    WORD IN1;
    WORD IN2;
}OR_WORD_S;
extern OR_WORD_S _OR_WORD;
#define _OR_WORD_()	(_OR_WORD.IN1 | _OR_WORD.IN2)

typedef struct{
    DWORD IN1;
    DWORD IN2;
}OR_DWORD_S;
extern OR_DWORD_S _OR_DWORD;
#define _OR_DWORD_()	(_OR_DWORD.IN1 | _OR_DWORD.IN2)

#if (DT_LWORD_EN > 0)
typedef struct{
    LWORD IN1;
    LWORD IN2;
}OR_LWORD_S;
extern OR_LWORD_S _OR_LWORD;
#define _OR_LWORD_()	(_OR_LWORD.IN1 | _OR_LWORD.IN2)
#endif

/*
 * =============================================
 * XOR
 * =============================================
*/
typedef struct{
    BOOL IN1;
    BOOL IN2;
}XOR_BOOL_S;
extern XOR_BOOL_S _XOR_BOOL;
#define _XOR_BOOL_()	(_XOR_BOOL.IN1 ^ _XOR_BOOL.IN2)

typedef struct{
    BYTE IN1;
    BYTE IN2;
}XOR_BYTE_S;
extern XOR_BYTE_S _XOR_BYTE;
#define _XOR_BYTE_()	(_XOR_BYTE.IN1 ^ _XOR_BYTE.IN2)

typedef struct{
    WORD IN1;
    WORD IN2;
}XOR_WORD_S;
extern XOR_WORD_S _XOR_WORD;
#define _XOR_WORD_()	(_XOR_WORD.IN1 ^ _XOR_WORD.IN2)

typedef struct{
    DWORD IN1;
    DWORD IN2;
}XOR_DWORD_S;
extern XOR_DWORD_S _XOR_DWORD;
#define _XOR_DWORD_()	(_XOR_DWORD.IN1 ^ _XOR_DWORD.IN2)

#if (DT_LWORD_EN > 0)
typedef struct{
    LWORD IN1;
    LWORD IN2;
}XOR_LWORD_S;
extern XOR_LWORD_S _XOR_LWORD;
#define _XOR_LWORD_()	(_XOR_LWORD.IN1 ^ _XOR_LWORD.IN2)
#endif

/*
 * =============================================
 * NOT
 * =============================================
*/
typedef struct{
    BOOL IN1;
}NOT_BOOL_S;
extern NOT_BOOL_S _NOT_BOOL;
#define _NOT_BOOL_()	(~(_NOT_BOOL.IN1))

typedef struct{
    BYTE IN1;
}NOT_BYTE_S;
extern NOT_BYTE_S _NOT_BYTE;
#define _NOT_BYTE_()	(~(_NOT_BYTE.IN1))

typedef struct{
    WORD IN1;
}NOT_WORD_S;
extern NOT_WORD_S _NOT_WORD;
#define _NOT_WORD_()	(~(_NOT_WORD.IN1))

typedef struct{
    DWORD IN1;
}NOT_DWORD_S;
extern NOT_DWORD_S _NOT_DWORD;
#define _NOT_DWORD_()	(~(_NOT_DWORD.IN1))

#if (DT_LWORD_EN > 0)
typedef struct{
    LWORD IN1;
}NOT_LWORD_S;
extern NOT_LWORD_S _NOT_LWORD;
#define _NOT_LWORD_()	(~(_NOT_LWORD.IN1))
#endif

/*
 * =============================================
 * SEL
 * =============================================
*/
typedef struct{
    BOOL G;
    BOOL IN0;
    BOOL IN1;
}SEL_BOOL_S;
extern SEL_BOOL_S _SEL_BOOL;
#define _SEL_BOOL_()	((_SEL_BOOL.G == 0) ? \
                          _SEL_BOOL.IN0 : _SEL_BOOL.IN1)
 
typedef struct{
    BOOL G;
    BYTE IN0;
    BYTE IN1;
}SEL_BYTE_S;
extern SEL_BYTE_S _SEL_BYTE;
#define _SEL_BYTE_()	((_SEL_BYTE.G == 0) ? \
                         _SEL_BYTE.IN0 : _SEL_BYTE.IN1)

typedef struct{
    BOOL G;
    WORD IN0;
    WORD IN1;
}SEL_WORD_S;
extern SEL_WORD_S _SEL_WORD;
#define _SEL_WORD_()	((_SEL_WORD.G == 0) ? \
                         _SEL_WORD.IN0 : _SEL_WORD.IN1)

typedef struct{
    BOOL G;
    DWORD IN0;
    DWORD IN1;
}SEL_DWORD_S;
extern SEL_DWORD_S _SEL_DWORD;
#define _SEL_DWORD_()	((_SEL_DWORD.G == 0) ? \
                         _SEL_DWORD.IN0 : _SEL_DWORD.IN1)

#if (DT_LWORD_EN > 0)
typedef struct{
    BOOL G;
    LWORD IN0;
    LWORD IN1;
}SEL_LWORD_S;
extern SEL_LWORD_S _SEL_LWORD;
#define _SEL_LWORD_()	((_SEL_LWORD.G == 0) ? \
                         _SEL_LWORD.IN0 : _SEL_LWORD.IN1)
#endif

typedef struct{
    BOOL G;
    SINT IN0;
    SINT IN1;
}SEL_SINT_S;
extern SEL_SINT_S _SEL_SINT;
#define _SEL_SINT_()	((_SEL_SINT.G == 0) ? \
                          _SEL_SINT.IN0 : _SEL_SINT.IN1)

typedef struct{
    BOOL G;
    INT IN0;
    INT IN1;
}SEL_INT_S;
extern SEL_INT_S _SEL_INT;
#define _SEL_INT_()	((_SEL_INT.G == 0) ? \
                      _SEL_INT.IN0 : _SEL_INT.IN1)

typedef struct{
    BOOL G;
    DINT IN0;
    DINT IN1;
}SEL_DINT_S;
extern SEL_DINT_S _SEL_DINT;
#define _SEL_DINT_()	((_SEL_DINT.G == 0) ? \
                         _SEL_DINT.IN0 : _SEL_DINT.IN1)

#if (DT_LINT_EN > 0)
typedef struct{
    BOOL G;
    LINT IN0;
    BOOL IN1;
}SEL_LINT_S;
extern SEL_LINT_S _SEL_LINT;
#define _SEL_LINT_()	((_SEL_LINT.G == 0) ? \
                         _SEL_LINT.IN0 : _SEL_LINT.IN1)
#endif

typedef struct{
    BOOL G;
    USINT IN0;
    USINT IN1;
}SEL_USINT_S;
extern SEL_USINT_S _SEL_USINT;
#define _SEL_USINT_()	((_SEL_USINT.G == 0) ? \
                         _SEL_USINT.IN0 : _SEL_USINT.IN1)

typedef struct{
    BOOL G;
    UINT IN0;
    UINT IN1;
}SEL_UINT_S;
extern SEL_UINT_S _SEL_UINT;
#define _SEL_UINT_()	((_SEL_UINT.G == 0) ? \
                         _SEL_UINT.IN0 : _SEL_UINT.IN1)

typedef struct{
    BOOL G;
    UDINT IN0;
    UDINT IN1;
}SEL_UDINT_S;
extern SEL_UDINT_S _SEL_UDINT;
#define _SEL_UDINT_()	((_SEL_UDINT.G == 0) ? \
                         _SEL_UDINT.IN0 : _SEL_UDINT.IN1)

#if (DT_LINT_EN > 0)
typedef struct{
    BOOL G;
    ULINT IN0;
    ULINT IN1;
}SEL_ULINT_S;
extern SEL_ULINT_S _SEL_ULINT;
#define _SEL_ULINT_()	((_SEL_ULINT.G == 0) ? \
                         _SEL_ULINT.IN0 : _SEL_ULINT.IN1)
#endif

#if (DT_REAL_EN > 0)
typedef struct{
    BOOL G;
    REAL IN0;
    REAL IN1;
}SEL_REAL_S;
extern SEL_REAL_S _SEL_REAL;
#define _SEL_REAL_()	((_SEL_REAL.G == 0) ? \
                         _SEL_REAL.IN0 : _SEL_REAL.IN1)
#endif

#if (DT_LREAL_EN > 0)
typedef struct{
    BOOL G;
    LREAL IN0;
    LREAL IN1;
}SEL_LREAL_S;
extern SEL_LREAL_S _SEL_LREAL;
#define _SEL_LREAL_()	((_SEL_LREAL.G == 0) ? \
                         _SEL_LREAL.IN0 : _SEL_LREAL.IN1)
#endif

/*
 * =============================================
 * GT
 * =============================================
*/
typedef struct{
    BOOL IN1;
    BOOL IN2;
}GT_BOOL_S;
extern GT_BOOL_S _GT_BOOL;
#define _GT_BOOL_()	(_GT_BOOL.IN1 > _GT_BOOL.IN2)

typedef struct{
    BYTE IN1;
    BYTE IN2;
}GT_BYTE_S;
extern GT_BYTE_S _GT_BYTE;
#define _GT_BYTE_()	(_GT_BYTE.IN1 > _GT_BYTE.IN2)

typedef struct{
    WORD IN1;
    WORD IN2;
}GT_WORD_S;
extern GT_WORD_S _GT_WORD;
#define _GT_WORD_()	(_GT_WORD.IN1 > _GT_WORD.IN2)

typedef struct{
    DWORD IN0;
    DWORD IN1;
}GT_DWORD_S;
extern GT_DWORD_S _GT_DWORD;
#define _GT_DWORD_()	(_GT_DWORD.IN1 > _GT_DWORD.IN2)

#if (DT_LWORD_EN > 0)
typedef struct{
    LWORD IN1;
    LWORD IN2;
}GT_LWORD_S;
extern GT_LWORD_S _GT_LWORD;
#define _GT_LWORD_()	(_GT_LWORD.IN1 > _GT_LWORD.IN2)
#endif

typedef struct{
    SINT IN1;
    SINT IN2;
}GT_SINT_S;
extern GT_SINT_S _GT_SINT;
#define _GT_SINT_()	(_GT_SINT.IN1 > _GT_SINT.IN2)

typedef struct{
    INT IN1;
    INT IN2;
}GT_INT_S;
extern GT_INT_S _GT_INT;
#define _GT_INT_()	(_GT_INT.IN1 > _GT_INT.IN2)

typedef struct{
    DINT IN1;
    DINT IN2;
}GT_DINT_S;
extern GT_DINT_S _GT_DINT;
#define _GT_DINT_()	(_GT_DINT.IN1 > _GT_DINT.IN2)

#if (DT_LINT_EN > 0)
typedef struct{
    LINT IN1;
    LINT IN2;
}GT_LINT_S;
extern GT_LINT_S _GT_LINT;
#define _GT_LINT_()	(_GT_LINT.IN1 > _GT_LINT.IN2)
#endif

typedef struct{
    USINT IN1;
    USINT IN2;
}GT_USINT_S;
extern GT_USINT_S _GT_USINT;
#define _GT_USINT_()	(_GT_USINT.IN1 > _GT_USINT.IN2)

typedef struct{
    UINT IN1;
    UINT IN2;
}GT_UINT_S;
extern GT_UINT_S _GT_UINT;
#define _GT_UINT_()	(_GT_UINT.IN1 > _GT_UINT.IN2)

typedef struct{
    UDINT IN1;
    UDINT IN2;
}GT_UDINT_S;
extern GT_UDINT_S _GT_UDINT;
#define _GT_UDINT_()	(_GT_UDINT.IN1 > _GT_UDINT.IN2)

#if (DT_LINT_EN > 0)
typedef struct{
    ULINT IN1;
    ULINT IN2;
}GT_ULINT_S;
extern GT_ULINT_S _GT_ULINT;
#define _GT_ULINT_()	(_GT_ULINT.IN1 > _GT_ULINT.IN2)
#endif

#if (DT_REAL_EN > 0)
typedef struct{
    REAL IN1;
    REAL IN2;
}GT_REAL_S;
extern GT_REAL_S _GT_REAL;
#define _GT_REAL_()	(_GT_REAL.IN1 > _GT_REAL.IN2)
#endif

#if (DT_LREAL_EN > 0)
typedef struct{
    LREAL IN1;
    LREAL IN2;
}GT_LREAL_S;
extern GT_LREAL_S _GT_LREAL;
#define _GT_LREAL_()	(_GT_LREAL.IN1 > _GT_LREAL.IN2)
#endif

/*
 * =============================================
 * GE
 * =============================================
*/
typedef struct{
    BOOL IN1;
    BOOL IN2;
}GE_BOOL_S;
extern GE_BOOL_S _GE_BOOL;
#define _GE_BOOL_()	(_GE_BOOL.IN1 >= _GE_BOOL.IN2)

typedef struct{
    BYTE IN1;
    BYTE IN2;
}GE_BYTE_S;
extern GE_BYTE_S _GE_BYTE;
#define _GE_BYTE_()	(_GE_BYTE.IN1 >= _GE_BYTE.IN2)

typedef struct{
    WORD IN1;
    WORD IN2;
}GE_WORD_S;
extern GE_WORD_S _GE_WORD;
#define _GE_WORD_()	(_GE_WORD.IN1 >= _GE_WORD.IN2)

typedef struct{
    DWORD IN1;
    DWORD IN2;
}GE_DWORD_S;
extern GE_DWORD_S _GE_DWORD;
#define _GE_DWORD_()	(_GE_DWORD.IN1 >= _GE_DWORD.IN2)

#if (DT_LWORD_EN > 0)
typedef struct{
    LWORD IN1;
    LWORD IN2;
}GE_LWORD_S;
extern GE_LWORD_S _GE_LWORD;
#define _GE_LWORD_()	(_GE_LWORD.IN1 >= _GE_LWORD.IN2)
#endif

typedef struct{
    SINT IN1;
    SINT IN2;
}GE_SINT_S;
extern GE_SINT_S _GE_SINT;
#define _GE_SINT_()	(_GE_SINT.IN1 >= _GE_SINT.IN2)

typedef struct{
    INT IN1;
    INT IN2;
}GE_INT_S;
extern GE_INT_S _GE_INT;
#define _GE_INT_()	(_GE_INT.IN1 >= _GE_INT.IN2)

typedef struct{
    DINT IN1;
    DINT IN2;
}GE_DINT_S;
extern GE_DINT_S _GE_DINT;
#define _GE_DINT_()	(_GE_DINT.IN1 >= _GE_DINT.IN2)

#if (DT_LINT_EN > 0)
typedef struct{
    LINT IN1;
    LINT IN2;
}GE_LINT_S;
extern GE_LINT_S _GE_LINT;
#define _GE_LINT_()	(_GE_LINT.IN1 >= _GE_LINT.IN2)
#endif

typedef struct{
    USINT IN1;
    USINT IN2;
}GE_USINT_S;
extern GE_USINT_S _GE_USINT;
#define _GE_USINT_()	(_GE_USINT.IN1 >= _GE_USINT.IN2)

typedef struct{
    UINT IN1;
    UINT IN2;
}GE_UINT_S;
extern GE_UINT_S _GE_UINT;
#define _GE_UINT_()	(_GE_UINT.IN1 >= _GE_UINT.IN2)

typedef struct{
    UDINT IN1;
    UDINT IN2;
}GE_UDINT_S;
extern GE_UDINT_S _GE_UDINT;
#define _GE_UDINT_()	(_GE_UDINT.IN1 >= _GE_UDINT.IN2)

#if (DT_LINT_EN > 0)
typedef struct{
    ULINT IN1;
    ULINT IN2;
}GE_ULINT_S;
extern GE_ULINT_S _GE_ULINT;
#define _GE_ULINT_()	(_GE_ULINT.IN1 >= _GE_ULINT.IN2)
#endif

#if (DT_REAL_EN > 0)
typedef struct{
    REAL IN1;
    REAL IN2;
}GE_REAL_S;
extern GE_REAL_S _GE_REAL;
#define _GE_REAL_()	(_GE_REAL.IN1 >= _GE_REAL.IN2)
#endif

#if (DT_LREAL_EN > 0)
typedef struct{
    LREAL IN1;
    LREAL IN2;
}GE_LREAL_S;
extern GE_LREAL_S _GE_LREAL;
#define _GE_LREAL_()	(_GE_LREAL.IN1 >= _GE_LREAL.IN2)
#endif

/*
 * =============================================
 * EQ
 * =============================================
*/
typedef struct{
    BOOL IN1;
    BOOL IN2;
}EQ_BOOL_S;
extern EQ_BOOL_S _EQ_BOOL;
#define _EQ_BOOL_()	(_EQ_BOOL.IN1 == _EQ_BOOL.IN2)

typedef struct{
    BYTE IN1;
    BYTE IN2;
}EQ_BYTE_S;
extern EQ_BYTE_S _EQ_BYTE;
#define _EQ_BYTE_()	(_EQ_BYTE.IN1 == _EQ_BYTE.IN2)

typedef struct{
    WORD IN1;
    WORD IN2;
}EQ_WORD_S;
extern EQ_WORD_S _EQ_WORD;
#define _EQ_WORD_()	(_EQ_WORD.IN1 == _EQ_WORD.IN2)

typedef struct{
    DWORD IN1;
    DWORD IN2;
}EQ_DWORD_S;
extern EQ_DWORD_S _EQ_DWORD;
#define _EQ_DWORD_()	(_EQ_DWORD.IN1 == _EQ_DWORD.IN2)

#if (DT_LWORD_EN > 0)
typedef struct{
    LWORD IN1;
    LWORD IN2;
}EQ_LWORD_S;
extern EQ_LWORD_S _EQ_LWORD;
#define _EQ_LWORD_()	(_EQ_LWORD.IN1 == _EQ_LWORD.IN2)
#endif

typedef struct{
    SINT IN1;
    SINT IN2;
}EQ_SINT_S;
extern EQ_SINT_S _EQ_SINT;
#define _EQ_SINT_()	(_EQ_SINT.IN1 == _EQ_SINT.IN2)

typedef struct{
    INT IN1;
    INT IN2;
}EQ_INT_S;
extern EQ_INT_S _EQ_INT;
#define _EQ_INT_()	(_EQ_INT.IN1 == _EQ_INT.IN2)

typedef struct{
    DINT IN1;
    DINT IN2;
}EQ_DINT_S;
extern EQ_DINT_S _EQ_DINT;
#define _EQ_DINT_()	(_EQ_DINT.IN1 == _EQ_DINT.IN2)

#if (DT_LINT_EN > 0)
typedef struct{
    LINT IN1;
    LINT IN2;
}EQ_LINT_S;
extern EQ_LINT_S _EQ_LINT;
#define _EQ_LINT_()	(_EQ_LINT.IN1 == _EQ_LINT.IN2)
#endif

typedef struct{
    USINT IN1;
    USINT IN2;
}EQ_USINT_S;
extern EQ_USINT_S _EQ_USINT;
#define _EQ_USINT_()	(_EQ_USINT.IN1 == _EQ_USINT.IN2)

typedef struct{
    UINT IN1;
    UINT IN2;
}EQ_UINT_S;
extern EQ_UINT_S _EQ_UINT;
#define _EQ_UINT_()	(_EQ_UINT.IN1 == _EQ_UINT.IN2)

typedef struct{
    UDINT IN1;
    UDINT IN2;
}EQ_UDINT_S;
extern EQ_UDINT_S _EQ_UDINT;
#define _EQ_UDINT_()	(_EQ_UDINT.IN1 == _EQ_UDINT.IN2)

#if (DT_LINT_EN > 0)
typedef struct{
    ULINT IN1;
    ULINT IN2;
}EQ_ULINT_S;
extern EQ_ULINT_S _EQ_ULINT;
#define _EQ_ULINT_()	(_EQ_ULINT.IN1 == _EQ_ULINT.IN2)
#endif

#if (DT_REAL_EN > 0)
typedef struct{
    REAL IN1;
    REAL IN2;
}EQ_REAL_S;
extern EQ_REAL_S _EQ_REAL;
#define _EQ_REAL_()	(fabs(_EQ_REAL.IN1 - _EQ_REAL.IN2) < 1e-6)
#endif

#if (DT_LREAL_EN > 0)
typedef struct{
    LREAL IN1;
    LREAL IN2;
}EQ_LREAL_S;
extern EQ_LREAL_S _EQ_LREAL;
#define _EQ_LREAL_()	(fabs(_EQ_LREAL.IN1 - _EQ_LREAL.IN2) < 1e-15)
#endif

/*
 * =============================================
 * LE
 * =============================================
*/
typedef struct{
    BOOL IN1;
    BOOL IN2;
}LE_BOOL_S;
extern LE_BOOL_S _LE_BOOL;
#define _LE_BOOL_()	(_LE_BOOL.IN1 <= _LE_BOOL.IN2)

typedef struct{
    BYTE IN1;
    BYTE IN2;
}LE_BYTE_S;
extern LE_BYTE_S _LE_BYTE;
#define _LE_BYTE_()	(_LE_BYTE.IN1 <= _LE_BYTE.IN2)

typedef struct{
    WORD IN1;
    WORD IN2;
}LE_WORD_S;
extern LE_WORD_S _LE_WORD;
#define _LE_WORD_()	(_LE_WORD.IN1 <= _LE_WORD.IN2)

typedef struct{
    DWORD IN1;
    DWORD IN2;
}LE_DWORD_S;
extern LE_DWORD_S _LE_DWORD;
#define _LE_DWORD_()	(_LE_DWORD.IN1 <= _LE_DWORD.IN2)

#if (DT_LWORD_EN > 0)
typedef struct{
    LWORD IN1;
    LWORD IN2;
}LE_LWORD_S;
extern LE_LWORD_S _LE_LWORD;
#define _LE_LWORD_()	(_LE_LWORD.IN1 <= _LE_LWORD.IN2)
#endif

typedef struct{
    SINT IN1;
    SINT IN2;
}LE_SINT_S;
extern LE_SINT_S _LE_SINT;
#define _LE_SINT_()	(_LE_SINT.IN1 <= _LE_SINT.IN2)

typedef struct{
    INT IN1;
    INT IN2;
}LE_INT_S;
extern LE_INT_S _LE_INT;
#define _LE_INT_()	(_LE_INT.IN1 <= _LE_INT.IN2)

typedef struct{
    DINT IN1;
    DINT IN2;
}LE_DINT_S;
extern LE_DINT_S _LE_DINT;
#define _LE_DINT_()	(_LE_DINT.IN1 <= _LE_DINT.IN2)

#if (DT_LINT_EN > 0)
typedef struct{
    LINT IN1;
    LINT IN2;
}LE_LINT_S;
extern LE_LINT_S _LE_LINT;
#define _LE_LINT_()	(_LE_LINT.IN1 <= _LE_LINT.IN2)
#endif

typedef struct{
    USINT IN1;
    USINT IN2;
}LE_USINT_S;
extern LE_USINT_S _LE_USINT;
#define _LE_USINT_()	(_LE_USINT.IN1 <= _LE_USINT.IN2)

typedef struct{
    UINT IN1;
    UINT IN2;
}LE_UINT_S;
extern LE_UINT_S _LE_UINT;
#define _LE_UINT_()	(_LE_UINT.IN1 <= _LE_UINT.IN2)

typedef struct{
    UDINT IN1;
    UDINT IN2;
}LE_UDINT_S;
extern LE_UDINT_S _LE_UDINT;
#define _LE_UDINT_()	(_LE_UDINT.IN1 <= _LE_UDINT.IN2)

#if (DT_LINT_EN > 0)
typedef struct{
    ULINT IN1;
    ULINT IN2;
}LE_ULINT_S;
extern LE_ULINT_S _LE_ULINT;
#define _LE_ULINT_()	(_LE_ULINT.IN1 <= _LE_ULINT.IN2)
#endif

#if (DT_REAL_EN > 0)
typedef struct{
    REAL IN1;
    REAL IN2;
}LE_REAL_S;
extern LE_REAL_S _LE_REAL;
#define _LE_REAL_()	(_LE_REAL.IN1 <= _LE_REAL.IN2)
#endif

#if (DT_LREAL_EN > 0)
typedef struct{
    LREAL IN1;
    LREAL IN2;
}LE_LREAL_S;
extern LE_LREAL_S _LE_LREAL;
#define _LE_LREAL_()	(_LE_LREAL.IN1 <= _LE_LREAL.IN2)
#endif

/*
 * =============================================
 * LT
 * =============================================
*/
typedef struct{
    BOOL IN1;
    BOOL IN2;
}LT_BOOL_S;
extern LT_BOOL_S _LT_BOOL;
#define _LT_BOOL_()	(_LT_BOOL.IN1 < _LT_BOOL.IN2)

typedef struct{
    BYTE IN1;
    BYTE IN2;
}LT_BYTE_S;
extern LT_BYTE_S _LT_BYTE;
#define _LT_BYTE_()	(_LT_BYTE.IN1 < _LT_BYTE.IN2)

typedef struct{
    WORD IN1;
    WORD IN2;
}LT_WORD_S;
extern LT_WORD_S _LT_WORD;
#define _LT_WORD_()	(_LT_WORD.IN1 < _LT_WORD.IN2)

typedef struct{
    DWORD IN1;
    DWORD IN2;
}LT_DWORD_S;
extern LT_DWORD_S _LT_DWORD;
#define _LT_DWORD_()	(_LT_DWORD.IN1 < _LT_DWORD.IN2)

#if (DT_LWORD_EN > 0)
typedef struct{
    LWORD IN1;
    LWORD IN2;
}LT_LWORD_S;
extern LT_LWORD_S _LT_LWORD;
#define _LT_LWORD_()	(_LT_LWORD.IN1 < _LT_LWORD.IN2)
#endif

typedef struct{
    SINT IN1;
    SINT IN2;
}LT_SINT_S;
extern LT_SINT_S _LT_SINT;
#define _LT_SINT_()	(_LT_SINT.IN1 < _LT_SINT.IN2)

typedef struct{
    INT IN1;
    INT IN2;
}LT_INT_S;
extern LT_INT_S _LT_INT;
#define _LT_INT_()	(_LT_INT.IN1 < _LT_INT.IN2)

typedef struct{
    DINT IN1;
    DINT IN2;
}LT_DINT_S;
extern LT_DINT_S _LT_DINT;
#define _LT_DINT_()	(_LT_DINT.IN1 < _LT_DINT.IN2)

#if (DT_LINT_EN > 0)
typedef struct{
    LINT IN1;
    LINT IN2;
}LT_LINT_S;
extern LT_LINT_S _LT_LINT;
#define _LT_LINT_()	(_LT_LINT.IN1 < _LT_LINT.IN2)
#endif

typedef struct{
    USINT IN1;
    USINT IN2;
}LT_USINT_S;
extern LT_USINT_S _LT_USINT;
#define _LT_USINT_()	(_LT_USINT.IN1 < _LT_USINT.IN2)

typedef struct{
    UINT IN1;
    UINT IN2;
}LT_UINT_S;
extern LT_UINT_S _LT_UINT;
#define _LT_UINT_()	(_LT_UINT.IN1 < _LT_UINT.IN2)

typedef struct{
    UDINT IN1;
    UDINT IN2;
}LT_UDINT_S;
extern LT_UDINT_S _LT_UDINT;
#define _LT_UDINT_()	(_LT_UDINT.IN1 < _LT_UDINT.IN2)

#if (DT_LINT_EN > 0)
typedef struct{
    ULINT IN1;
    ULINT IN2;
}LT_ULINT_S;
extern LT_ULINT_S _LT_ULINT;
#define _LT_ULINT_()	(_LT_ULINT.IN1 < _LT_ULINT.IN2)
#endif

#if (DT_REAL_EN > 0)
typedef struct{
    REAL IN1;
    REAL IN2;
}LT_REAL_S;
extern LT_REAL_S _LT_REAL;
#define _LT_REAL_()	(_LT_REAL.IN1 < _LT_REAL.IN2)
#endif

#if (DT_LREAL_EN > 0)
typedef struct{
    LREAL IN1;
    LREAL IN2;
}LT_LREAL_S;
extern LT_LREAL_S _LT_LREAL;
#define _LT_LREAL_()	(_LT_LREAL.IN1 < _LT_LREAL.IN2)
#endif

/*
 * =============================================
 * NE
 * =============================================
*/
typedef struct{
    BOOL IN1;
    BOOL IN2;
}NE_BOOL_S;
extern NE_BOOL_S _NE_BOOL;
#define _NE_BOOL_()	(_NE_BOOL.IN1 != _NE_BOOL.IN2)

typedef struct{
    BYTE IN1;
    BYTE IN2;
}NE_BYTE_S;
extern NE_BYTE_S _NE_BYTE;
#define _NE_BYTE_()	(_NE_BYTE.IN1 != _NE_BYTE.IN2)

typedef struct{
    WORD IN1;
    WORD IN2;
}NE_WORD_S;
extern NE_WORD_S _NE_WORD;
#define _NE_WORD_()	(_NE_WORD.IN1 != _NE_WORD.IN2)

typedef struct{
    DWORD IN1;
    DWORD IN2;
}NE_DWORD_S;
extern NE_DWORD_S _NE_DWORD;
#define _NE_DWORD_()	(_NE_DWORD.IN1 != _NE_DWORD.IN2)

#if (DT_LWORD_EN > 0)
typedef struct{
    LWORD IN1;
    LWORD IN2;
}NE_LWORD_S;
extern NE_LWORD_S _NE_LWORD;
#define _NE_LWORD_()	(_NE_LWORD.IN1 != _NE_LWORD.IN2)
#endif

typedef struct{
    SINT IN1;
    SINT IN2;
}NE_SINT_S;
extern NE_SINT_S _NE_SINT;
#define _NE_SINT_()	(_NE_SINT.IN1 != _NE_SINT.IN2)

typedef struct{
    INT IN1;
    INT IN2;
}NE_INT_S;
extern NE_INT_S _NE_INT;
#define _NE_INT_()	(_NE_INT.IN1 != _NE_INT.IN2)

typedef struct{
    DINT IN1;
    DINT IN2;
}NE_DINT_S;
extern NE_DINT_S _NE_DINT;
#define _NE_DINT_()	(_NE_DINT.IN1 != _NE_DINT.IN2)

#if (DT_LINT_EN > 0)
typedef struct{
    LINT IN1;
    LINT IN2;
}NE_LINT_S;
extern NE_LINT_S _NE_LINT;
#define _NE_LINT_()	(_NE_LINT.IN1 != _NE_LINT.IN2)
#endif

typedef struct{
    USINT IN1;
    USINT IN2;
}NE_USINT_S;
extern NE_USINT_S _NE_USINT;
#define _NE_USINT_()	(_NE_USINT.IN1 != _NE_USINT.IN2)

typedef struct{
    UINT IN1;
    UINT IN2;
}NE_UINT_S;
extern NE_UINT_S _NE_UINT;
#define _NE_UINT_()	(_NE_UINT.IN1 != _NE_UINT.IN2)

typedef struct{
    UDINT IN1;
    UDINT IN2;
}NE_UDINT_S;
extern NE_UDINT_S _NE_UDINT;
#define _NE_UDINT_()	(_NE_UDINT.IN1 != _NE_UDINT.IN2)

#if (DT_LINT_EN > 0)
typedef struct{
    ULINT IN1;
    ULINT IN2;
}NE_ULINT_S;
extern NE_ULINT_S _NE_ULINT;
#define _NE_ULINT_()	(_NE_ULINT.IN1 != _NE_ULINT.IN2)
#endif

#if (DT_REAL_EN > 0)
typedef struct{
    REAL IN1;
    REAL IN2;
}NE_REAL_S;
extern NE_REAL_S _NE_REAL;
#define _NE_REAL_()	(fabs((_NE_REAL.IN1 - _NE_REAL.IN2)) >= 1e-6)
#endif

#if (DT_LREAL_EN > 0)
typedef struct{
    LREAL IN1;
    LREAL IN2;
}NE_LREAL_S;
extern NE_LREAL_S _NE_LREAL;
#define _NE_LREAL_()	(fabs(_NE_LREAL.IN1 - _NE_LREAL.IN2) >= 1e-15)
#endif






#endif

