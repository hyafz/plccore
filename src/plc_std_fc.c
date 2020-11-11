#include "plc_cr.h"
#include <stdlib.h>
#include <math.h>
#include <plc_std_fc.h>

SINT_TO_INT_S _SINT_TO_INT;
INT _SINT_TO_INT_(void)
{
    return (INT)(_SINT_TO_INT.IN);
}

INT_TO_SINT_S _INT_TO_SINT;
SINT _INT_TO_SINT_(void)
{
    return (SINT)(_INT_TO_SINT.IN);
}

INT_TO_DINT_S _INT_TO_DINT;
DINT _INT_TO_DINT_(void)
{
    return (DINT)(_INT_TO_DINT.IN);
}

DINT_TO_INT_S _DINT_TO_INT;
INT _DINT_TO_INT_(void)
{
    return (INT)(_DINT_TO_INT.IN);
}

#if (DT_LINT_EN > 0)
DINT_TO_LINT_S _DINT_TO_LINT;
LINT _DINT_TO_LINT_(void)
{
    return (LINT)(_DINT_TO_LINT.IN);
}

LINT_TO_DINT_S _LINT_TO_DINT;
DINT _LINT_TO_DINT_(void)
{
    return (DINT)(_LINT_TO_DINT.IN);
}
#endif

USINT_TO_UINT_S _USINT_TO_UINT;
UINT _USINT_TO_UINT_(void)
{
    return (UINT)(_USINT_TO_UINT.IN);
}

UINT_TO_USINT_S _UINT_TO_USINT;
USINT _UINT_TO_USINT_(void)
{
    return (USINT)(_UINT_TO_USINT.IN);
}

UINT_TO_UDINT_S _UINT_TO_UDINT;
UDINT _UINT_TO_UDINT_(void)
{
    return (UDINT)(_UINT_TO_UDINT.IN);
}

UDINT_TO_UINT_S _UDINT_TO_UINT;
UINT _UDINT_TO_UINT_(void)
{
    return (UINT)(_UDINT_TO_UINT.IN);
}

#if (DT_ULINT_EN > 0)
UDINT_TO_ULINT_S _UDINT_TO_ULINT;
ULINT _UDINT_TO_ULINT_(void)
{
    return (ULINT)(_UDINT_TO_ULINT.IN);
}

ULINT_TO_UDINT_S _ULINT_TO_UDINT;
UDINT _ULINT_TO_UDINT_(void)
{
    return (UDINT)(_ULINT_TO_UDINT.IN);
}
#endif

USINT_TO_SINT_S _USINT_TO_SINT;
SINT _USINT_TO_SINT_(void)
{
    return (SINT)(_USINT_TO_SINT.IN);
}

SINT_TO_USINT_S _SINT_TO_USINT;
USINT _SINT_TO_USINT_(void)
{
    return (USINT)(_SINT_TO_USINT.IN);
}

UINT_TO_INT_S _UINT_TO_INT;
INT _UINT_TO_INT_(void)
{
    return (INT)(_UINT_TO_INT.IN);
}

INT_TO_UINT_S _INT_TO_UINT;
UINT _INT_TO_UINT_(void)
{
    return (UINT)(_INT_TO_UINT.IN);
}

UDINT_TO_DINT_S _UDINT_TO_DINT;
DINT _UDINT_TO_DINT_(void)
{
    return (DINT)(_UDINT_TO_DINT.IN);
}

DINT_TO_UDINT_S _DINT_TO_UDINT;
UDINT _DINT_TO_UDINT_(void)
{
    return (UDINT)(_DINT_TO_UDINT.IN);
}

#if ((DT_ULINT_EN > 0) && (DT_LINT_EN > 0))
ULINT_TO_LINT_S _ULINT_TO_LINT;
LINT _ULINT_TO_LINT_(void)
{
    return (LINT)(_ULINT_TO_LINT.IN);
}

LINT_TO_ULINT_S _LINT_TO_ULINT;
ULINT _LINT_TO_ULINT_(void)
{
    return (ULINT)(_LINT_TO_ULINT.IN);
}
#endif

BOOL_TO_BYTE_S _BOOL_TO_BYTE;
BYTE _BOOL_TO_BYTE_(void)
{
    return (BYTE)(_BOOL_TO_BYTE.IN);
}

BYTE_TO_BOOL_S _BYTE_TO_BOOL;
BOOL _BYTE_TO_BOOL_(void)
{
    return (BOOL)(_BYTE_TO_BOOL.IN);
}

BYTE_TO_WORD_S _BYTE_TO_WORD;
WORD _BYTE_TO_WORD_(void)
{
    return (WORD)(_BYTE_TO_WORD.IN);
}

WORD_TO_BYTE_S _WORD_TO_BYTE;
BYTE _WORD_TO_BYTE_(void)
{
    return (BYTE)(_WORD_TO_BYTE.IN);
}

WORD_TO_DWORD_S _WORD_TO_DWORD;
DWORD _WORD_TO_DWORD_(void)
{
    return (DWORD)(_WORD_TO_DWORD.IN);
}

DWORD_TO_WORD_S _DWORD_TO_WORD;
WORD _DWORD_TO_WORD_(void)
{
    return (WORD)(_DWORD_TO_WORD.IN);
}

#if (DT_LWORD_EN > 0)
DWORD_TO_LWORD_S _DWORD_TO_LWORD;
LWORD _DWORD_TO_LWORD_(void)
{
    return (LWORD)(_DWORD_TO_LWORD.IN);
}

LWORD_TO_DWORD_S _LWORD_TO_DWORD;
DWORD _LWORD_TO_DWORD_(void)
{
    return (DWORD)(_LWORD_TO_DWORD.IN);
}
#endif

BYTE_TO_USINT_S _BYTE_TO_USINT;
USINT _BYTE_TO_USINT_(void)
{
    return (USINT)(_BYTE_TO_USINT.IN);
}

USINT_TO_BYTE_S _USINT_TO_BYTE;
BYTE _USINT_TO_BYTE_(void)
{
    return (BYTE)(_USINT_TO_BYTE.IN);
}

WORD_TO_UINT_S _WORD_TO_UINT;
UINT _WORD_TO_UINT_(void)
{
    return (UINT)(_WORD_TO_UINT.IN);
}

UINT_TO_WORD_S _UINT_TO_WORD;
WORD _UINT_TO_WORD_(void)
{
    return (WORD)(_UINT_TO_WORD.IN);
}

DWORD_TO_UDINT_S _DWORD_TO_UDINT;
UDINT _DWORD_TO_UDINT_(void)
{
    return (UDINT)(_DWORD_TO_UDINT.IN);
}

UDINT_TO_DWORD_S _UDINT_TO_DWORD;
DWORD _UDINT_TO_DWORD_(void)
{
    return (DINT)(_UDINT_TO_DWORD.IN);
}

#if ((DT_ULINT_EN > 0) && (DT_LWORD_EN > 0))
LWORD_TO_ULINT_S _LWORD_TO_ULINT;
ULINT _LWORD_TO_ULINT_(void)
{
    return (ULINT)(_LWORD_TO_ULINT.IN);
}

ULINT_TO_LWORD_S _ULINT_TO_LWORD;
LWORD _ULINT_TO_LWORD_(void)
{
    return (LWORD)(_ULINT_TO_LWORD.IN);
}
#endif

#if (DT_REAL_EN > 0)
REAL_TO_DINT_S _REAL_TO_DINT;
/**
 * @brief REAL类型转换为DINT类型
 * @note 直接调用round()函数四舍五入的实现是不符合标准的，需要修改。
 * @note 强制类型转换相当于丢弃小数部分，更不符合要求。
 * @return
 */
DINT _REAL_TO_DINT_(void)
{
    //return (DINT)round(_REAL_TO_DINT.IN);
    return (DINT)(_REAL_TO_DINT.IN);
}

DINT_TO_REAL_S _DINT_TO_REAL;
/**
 * @brief DINT类型转换为REAL类型
 * @note 目前的实现是不标准的，需要修改。
 * @return
 */
REAL _DINT_TO_REAL_(void)
{
    return (REAL)(_DINT_TO_REAL.IN);
}
#endif

#if ((DT_LINT_EN > 0) && (DT_LREAL_EN > 0))

LREAL_TO_LINT_S _LREAL_TO_LINT;
/**
 * @brief LREAL类型转换为LINT类型
 * @note 直接调用round()函数四舍五入的实现是不符合标准的，需要修改。
 * @note 强制类型转换相当于丢弃小数部分，更不符合要求。
 * @return
 */
LINT _LREAL_TO_LINT_(void)
{
    //return (LINT)round(_LREAL_TO_LINT.IN);
    return (LINT)(_LREAL_TO_LINT.IN);
}

LINT_TO_LREAL_S _LINT_TO_LREAL;
/**
 * @brief LINT类型转换为LREAL类型
 * @note 目前的实现是不标准的，需要修改。
 * @return
 */
LREAL _LINT_TO_LREAL_(void)
{
    return (LREAL)(_LINT_TO_LREAL.IN);
}
#endif

/*
 * =============================================
 * ADD
 * =============================================
*/
ADD_SINT_S _ADD_SINT;
SINT _ADD_SINT_(void)
{
    return _ADD_SINT.IN1 + _ADD_SINT.IN2;
}

ADD_INT_S _ADD_INT;
INT _ADD_INT_(void)
{
    return _ADD_INT.IN1 + _ADD_INT.IN2;
}

ADD_DINT_S _ADD_DINT;
DINT _ADD_DINT_(void)
{
    return _ADD_DINT.IN1 + _ADD_DINT.IN2;
}

#if (DT_LINT_EN > 0)
ADD_LINT_S _ADD_LINT;
LINT _ADD_LINT_(void)
{
    return _ADD_LINT.IN1 + _ADD_LINT.IN2;
}
#endif

ADD_USINT_S _ADD_USINT;
USINT _ADD_USINT_(void)
{
    return _ADD_USINT.IN1 + _ADD_USINT.IN2;
}

ADD_UINT_S _ADD_UINT;
UINT _ADD_UINT_(void)
{
    return _ADD_UINT.IN1 + _ADD_UINT.IN2;
}

ADD_UDINT_S _ADD_UDINT;
UDINT _ADD_UDINT_(void)
{
    return _ADD_UDINT.IN1 + _ADD_UDINT.IN2;
}

#if (DT_ULINT_EN > 0)
ADD_ULINT_S _ADD_ULINT;
ULINT _ADD_ULINT_(void)
{
    return _ADD_ULINT.IN1 + _ADD_ULINT.IN2;
}
#endif

#if (DT_REAL_EN > 0)
ADD_REAL_S _ADD_REAL;
REAL _ADD_REAL_(void)
{
    return _ADD_REAL.IN1 + _ADD_REAL.IN2;
}
#endif

#if (DT_LREAL_EN > 0)
ADD_LREAL_S _ADD_LREAL;
LREAL _ADD_LREAL_(void)
{
    return _ADD_LREAL.IN1 + _ADD_LREAL.IN2;
}
#endif

/*
 * =============================================
 * SUB
 * =============================================
*/
SUB_SINT_S _SUB_SINT;
SINT _SUB_SINT_(void)
{
    return _SUB_SINT.IN1 - _SUB_SINT.IN2;
}

SUB_INT_S _SUB_INT;
INT _SUB_INT_(void)
{
    return _SUB_INT.IN1 - _SUB_INT.IN2;
}

SUB_DINT_S _SUB_DINT;
DINT _SUB_DINT_(void)
{
    return _SUB_DINT.IN1 - _SUB_DINT.IN2;
}

#if (DT_LINT_EN > 0)
SUB_LINT_S _SUB_LINT;
LINT _SUB_LINT_(void)
{
    return _SUB_LINT.IN1 - _SUB_LINT.IN2;
}
#endif

SUB_USINT_S _SUB_USINT;
USINT _SUB_USINT_(void)
{
    return _SUB_USINT.IN1 - _SUB_USINT.IN2;
}

SUB_UINT_S _SUB_UINT;
UINT _SUB_UINT_(void)
{
    return _SUB_UINT.IN1 - _SUB_UINT.IN2;
}

SUB_UDINT_S _SUB_UDINT;
UDINT _SUB_UDINT_(void)
{
    return _SUB_UDINT.IN1 - _SUB_UDINT.IN2;
}

#if (DT_ULINT_EN > 0)
SUB_ULINT_S _SUB_ULINT;
ULINT _SUB_ULINT_(void)
{
    return _SUB_ULINT.IN1 - _SUB_ULINT.IN2;
}
#endif

#if (DT_REAL_EN > 0)
SUB_REAL_S _SUB_REAL;
REAL _SUB_REAL_(void)
{
    return _SUB_REAL.IN1 - _SUB_REAL.IN2;
}
#endif

#if (DT_LREAL_EN > 0)
SUB_LREAL_S _SUB_LREAL;
LREAL _SUB_LREAL_(void)
{
    return _SUB_LREAL.IN1 - _SUB_LREAL.IN2;
}
#endif

/*
 * =============================================
 * MUL
 * =============================================
*/
MUL_SINT_S _MUL_SINT;
SINT _MUL_SINT_(void)
{
    return _MUL_SINT.IN1 * _MUL_SINT.IN2;
}

MUL_INT_S _MUL_INT;
INT _MUL_INT_(void)
{
    return _MUL_INT.IN1 * _MUL_INT.IN2;
}

MUL_DINT_S _MUL_DINT;
DINT _MUL_DINT_(void)
{
    return _MUL_DINT.IN1 * _MUL_DINT.IN2;
}

#if (DT_LINT_EN > 0)
MUL_LINT_S _MUL_LINT;
LINT _MUL_LINT_(void)
{
    return _MUL_LINT.IN1 * _MUL_LINT.IN2;
}
#endif

MUL_USINT_S _MUL_USINT;
USINT _MUL_USINT_(void)
{
    return _MUL_USINT.IN1 * _MUL_USINT.IN2;
}

MUL_UINT_S _MUL_UINT;
UINT _MUL_UINT_(void)
{
    return _MUL_UINT.IN1 * _MUL_UINT.IN2;
}

MUL_UDINT_S _MUL_UDINT;
UDINT _MUL_UDINT_(void)
{
    return _MUL_UDINT.IN1 * _MUL_UDINT.IN2;
}

#if (DT_ULINT_EN > 0)
MUL_ULINT_S _MUL_ULINT;
ULINT _MUL_ULINT_(void)
{
    return _MUL_ULINT.IN1 * _MUL_ULINT.IN2;
}
#endif

#if (DT_REAL_EN > 0)
MUL_REAL_S _MUL_REAL;
REAL _MUL_REAL_(void)
{
    return _MUL_REAL.IN1 * _MUL_REAL.IN2;
}
#endif

#if (DT_LREAL_EN > 0)
MUL_LREAL_S _MUL_LREAL;
LREAL _MUL_LREAL_(void)
{
    return _MUL_LREAL.IN1 * _MUL_LREAL.IN2;
}
#endif

/*
 * =============================================
 * DIV
 * =============================================
*/
DIV_SINT_S _DIV_SINT;
SINT _DIV_SINT_(void)
{
    if(_DIV_SINT.IN2 == 0){
        return 0;
    }
    return _DIV_SINT.IN1 / _DIV_SINT.IN2;
}

DIV_INT_S _DIV_INT;
INT _DIV_INT_(void)
{
    if(_DIV_SINT.IN2 == 0){
        return 0;
    }
    return _DIV_INT.IN1 / _DIV_INT.IN2;
}

DIV_DINT_S _DIV_DINT;
DINT _DIV_DINT_(void)
{
    if(_DIV_SINT.IN2 == 0){
        return 0;
    }
    return _DIV_DINT.IN1 / _DIV_DINT.IN2;
}

#if (DT_LINT_EN > 0)
DIV_LINT_S _DIV_LINT;
LINT _DIV_LINT_(void)
{
    if(_DIV_SINT.IN2 == 0){
        return 0;
    }
    return _DIV_LINT.IN1 / _DIV_LINT.IN2;
}
#endif

DIV_USINT_S _DIV_USINT;
USINT _DIV_USINT_(void)
{
    if(_DIV_SINT.IN2 == 0){
        return 0;
    }
    return _DIV_USINT.IN1 / _DIV_USINT.IN2;
}

DIV_UINT_S _DIV_UINT;
UINT _DIV_UINT_(void)
{
    if(_DIV_SINT.IN2 == 0){
        return 0;
    }
    return _DIV_UINT.IN1 / _DIV_UINT.IN2;
}

DIV_UDINT_S _DIV_UDINT;
UDINT _DIV_UDINT_(void)
{
    if(_DIV_SINT.IN2 == 0){
        return 0;
    }
    return _DIV_UDINT.IN1 / _DIV_UDINT.IN2;
}

#if (DT_ULINT_EN > 0)
DIV_ULINT_S _DIV_ULINT;
ULINT _DIV_ULINT_(void)
{
    if(_DIV_SINT.IN2 == 0){
        return 0;
    }
    return _DIV_ULINT.IN1 / _DIV_ULINT.IN2;
}
#endif

#if (DT_REAL_EN > 0)
DIV_REAL_S _DIV_REAL;
REAL _DIV_REAL_(void)
{
    if(_DIV_SINT.IN2 == 0){
        return 0;
    }
    return _DIV_REAL.IN1 / _DIV_REAL.IN2;
}
#endif

#if (DT_LREAL_EN > 0)
DIV_LREAL_S _DIV_LREAL;
LREAL _DIV_LREAL_(void)
{
    if(_DIV_SINT.IN2 == 0){
        return 0;
    }
    return _DIV_LREAL.IN1 / _DIV_LREAL.IN2;
}
#endif

/*
 * =============================================
 * MOD
 * =============================================
*/
MOD_SINT_S _MOD_SINT;
SINT _MOD_SINT_(void)
{
    return _MOD_SINT.IN1 % _MOD_SINT.IN2;
}

MOD_INT_S _MOD_INT;
INT _MOD_INT_(void)
{
    return _MOD_INT.IN1 % _MOD_INT.IN2;
}

MOD_DINT_S _MOD_DINT;
DINT _MOD_DINT_(void)
{
    return _MOD_DINT.IN1 % _MOD_DINT.IN2;
}

#if (DT_LINT_EN > 0)
MOD_LINT_S _MOD_LINT;
LINT _MOD_LINT_(void)
{
    return _MOD_LINT.IN1 % _MOD_LINT.IN2;
}
#endif

MOD_USINT_S _MOD_USINT;
USINT _MOD_USINT_(void)
{
    return _MOD_USINT.IN1 % _MOD_USINT.IN2;
}

MOD_UINT_S _MOD_UINT;
UINT _MOD_UINT_(void)
{
    return _MOD_UINT.IN1 % _MOD_UINT.IN2;
}

MOD_UDINT_S _MOD_UDINT;
UDINT _MOD_UDINT_(void)
{
    return _MOD_UDINT.IN1 % _MOD_UDINT.IN2;
}

#if (DT_ULINT_EN > 0)
MOD_ULINT_S _MOD_ULINT;
ULINT _MOD_ULINT_(void)
{
    return _MOD_ULINT.IN1 % _MOD_ULINT.IN2;
}
#endif

/*
 * =============================================
 * EXPT
 * =============================================
*/

#if (DT_REAL_EN > 0)
EXPT_REAL_S _EXPT_REAL;
REAL _EXPT_REAL_(void)
{
    if(_EXPT_REAL.IN2 == 0){
        return 1;
    }
    return pow(_EXPT_REAL.IN1, _EXPT_REAL.IN2);
}
#endif

#if (DT_LREAL_EN > 0)
EXPT_LREAL_S _EXPT_LREAL;
LREAL _EXPT_LREAL_(void)
{
    if(_EXPT_LREAL.IN2 == 0){
        return 1;
    }
    return pow(_EXPT_LREAL.IN1, _EXPT_LREAL.IN2);
}
#endif

/*
 * =============================================
 * MOVE
 * =============================================
*/
MOVE_BOOL_S _MOVE_BOOL;
BOOL _MOVE_BOOL_(void)
{
    return _MOVE_BOOL.IN;
}

MOVE_BYTE_S _MOVE_BYTE;
BYTE _MOVE_BYTE_(void)
{
    return _MOVE_BYTE.IN;
}

MOVE_WORD_S _MOVE_WORD;
WORD _MOVE_WORD_(void)
{
    return _MOVE_WORD.IN;
}

MOVE_DWORD_S _MOVE_DWORD;
DWORD _MOVE_DWORD_(void)
{
    return _MOVE_DWORD.IN;
}

#if (DT_LWORD_EN > 0)
MOVE_LWORD_S _MOVE_LWORD;
LWORD _MOVE_LWORD_(void)
{
    return _MOVE_LWORD.IN;
}
#endif

MOVE_SINT_S _MOVE_SINT;
SINT _MOVE_SINT_(void)
{
    return _MOVE_SINT.IN;
}

MOVE_INT_S _MOVE_INT;
INT _MOVE_INT_(void)
{
    return _MOVE_INT.IN;
}

MOVE_DINT_S _MOVE_DINT;
DINT _MOVE_DINT_(void)
{
    return _MOVE_DINT.IN;
}

#if (DT_LINT_EN > 0)
MOVE_LINT_S _MOVE_LINT;
LINT _MOVE_LINT_(void)
{
    return _MOVE_LINT.IN;
}
#endif

MOVE_USINT_S _MOVE_USINT;
USINT _MOVE_USINT_(void)
{
    return _MOVE_USINT.IN;
}

MOVE_UINT_S _MOVE_UINT;
UINT _MOVE_UINT_(void)
{
    return _MOVE_UINT.IN;
}

MOVE_UDINT_S _MOVE_UDINT;
UDINT _MOVE_UDINT_(void)
{
    return _MOVE_UDINT.IN;
}

#if (DT_ULINT_EN > 0)
MOVE_ULINT_S _MOVE_ULINT;
ULINT _MOVE_ULINT_(void)
{
    return _MOVE_ULINT.IN;
}
#endif

#if (DT_REAL_EN > 0)
MOVE_REAL_S _MOVE_REAL;
REAL _MOVE_REAL_(void)
{
    return _MOVE_REAL.IN;
}
#endif

#if (DT_LREAL_EN > 0)
MOVE_LREAL_S _MOVE_LREAL;
LREAL _MOVE_LREAL_(void)
{
    return _MOVE_LREAL.IN;
}
#endif

/*
 * =============================================
 * ABS
 * =============================================
*/

ABS_SINT_S _ABS_SINT;
SINT _ABS_SINT_(void)
{
    return abs(_ABS_SINT.IN);
}

ABS_INT_S _ABS_INT;
INT _ABS_INT_(void)
{
    return abs(_ABS_INT.IN);
}

ABS_DINT_S _ABS_DINT;
DINT _ABS_DINT_(void)
{
    return abs(_ABS_DINT.IN);
}

#if (DT_LINT_EN > 0)
ABS_LINT_S _ABS_LINT;
LINT _ABS_LINT_(void)
{
    return abs(_ABS_LINT.IN);
}
#endif

ABS_USINT_S _ABS_USINT;
USINT _ABS_USINT_(void)
{
    return abs(_ABS_USINT.IN);
}

ABS_UINT_S _ABS_UINT;
UINT _ABS_UINT_(void)
{
    return abs(_ABS_UINT.IN);
}

ABS_UDINT_S _ABS_UDINT;
UDINT _ABS_UDINT_(void)
{
    return abs(_ABS_UDINT.IN);
}

#if (DT_ULINT_EN > 0)
ABS_ULINT_S _ABS_ULINT;
ULINT _ABS_ULINT_(void)
{
    return abs(_ABS_ULINT.IN);
}
#endif

#if (DT_REAL_EN > 0)
ABS_REAL_S _ABS_REAL;
REAL _ABS_REAL_(void)
{
    return fabs(_ABS_REAL.IN);
}
#endif

#if (DT_LREAL_EN > 0)
ABS_LREAL_S _ABS_LREAL;
LREAL _ABS_LREAL_(void)
{
    return fabs(_ABS_LREAL.IN);
}
#endif

/*
 * =============================================
 * SQRT
 * =============================================
*/
#if (DT_REAL_EN > 0)
SQRT_REAL_S _SQRT_REAL;
REAL _SQRT_REAL_(void)
{
    return sqrt(_SQRT_REAL.IN);
}
#endif

#if (DT_LREAL_EN > 0)
SQRT_LREAL_S _SQRT_LREAL;
LREAL _SQRT_LREAL_(void)
{
    return sqrt(_SQRT_LREAL.IN);
}
#endif

/*
 * =============================================
 * LN
 * =============================================
*/
#if (DT_REAL_EN > 0)
LN_REAL_S _LN_REAL;
REAL _LN_REAL_(void)
{
    return logf(_LN_REAL.IN);
}
#endif

#if (DT_LREAL_EN > 0)
LN_LREAL_S _LN_LREAL;
LREAL _LN_LREAL_(void)
{
    return log(_LN_LREAL.IN);
}
#endif

/*
 * =============================================
 * LOG
 * =============================================
*/
#if (DT_REAL_EN > 0)
LOG_REAL_S _LOG_REAL;
REAL _LOG_REAL_(void)
{
    return log10f(_LOG_REAL.IN);
}
#endif

#if (DT_LREAL_EN > 0)
LOG_LREAL_S _LOG_LREAL;
LREAL _LOG_LREAL_(void)
{
    return log10(_LOG_LREAL.IN);
}
#endif

/*
 * =============================================
 * EXP
 * =============================================
*/
#if (DT_REAL_EN > 0)
EXP_REAL_S _EXP_REAL;
REAL _EXP_REAL_(void)
{
    return expf(_EXP_REAL.IN);
}
#endif

#if (DT_LREAL_EN > 0)
EXP_LREAL_S _EXP_LREAL;
LREAL _EXP_LREAL_(void)
{
    return exp(_EXP_LREAL.IN);
}
#endif

/*
 * =============================================
 * SIN
 * =============================================
*/
#if (DT_REAL_EN > 0)
SIN_REAL_S _SIN_REAL;
REAL _SIN_REAL_(void)
{
    return sinf(_SIN_REAL.IN);
}
#endif

#if (DT_LREAL_EN > 0)
SIN_LREAL_S _SIN_LREAL;
LREAL _SIN_LREAL_(void)
{
    return sin(_SIN_LREAL.IN);
}
#endif

/*
 * =============================================
 * COS
 * =============================================
*/
#if (DT_REAL_EN > 0)
COS_REAL_S _COS_REAL;
REAL _COS_REAL_(void)
{
    return cosf(_COS_REAL.IN);
}
#endif

#if (DT_LREAL_EN > 0)
COS_LREAL_S _COS_LREAL;
LREAL _COS_LREAL_(void)
{
    return cos(_COS_LREAL.IN);
}
#endif

/*
 * =============================================
 * TAN
 * =============================================
*/
#if (DT_REAL_EN > 0)
TAN_REAL_S _TAN_REAL;
REAL _TAN_REAL_(void)
{
    return tanf(_TAN_REAL.IN);
}
#endif

#if (DT_LREAL_EN > 0)
TAN_LREAL_S _TAN_LREAL;
LREAL _TAN_LREAL_(void)
{
    return tan(_TAN_LREAL.IN);
}
#endif

/*
 * =============================================
 * ASIN
 * =============================================
*/
#if (DT_REAL_EN > 0)
ASIN_REAL_S _ASIN_REAL;
REAL _ASIN_REAL_(void)
{
    return asinf(_ASIN_REAL.IN);
}
#endif

#if (DT_LREAL_EN > 0)
ASIN_LREAL_S _ASIN_LREAL;
LREAL _ASIN_LREAL_(void)
{
    return asin(_ASIN_LREAL.IN);
}
#endif

/*
 * =============================================
 * ACOS
 * =============================================
*/
#if (DT_REAL_EN > 0)
ACOS_REAL_S _ACOS_REAL;
REAL _ACOS_REAL_(void)
{
    return acosf(_ACOS_REAL.IN);
}
#endif

#if (DT_LREAL_EN > 0)
ACOS_LREAL_S _ACOS_LREAL;
LREAL _ACOS_LREAL_(void)
{
    return acos(_ACOS_LREAL.IN);
}
#endif

/*
 * =============================================
 * ATAN
 * =============================================
*/
#if (DT_REAL_EN > 0)
ATAN_REAL_S _ATAN_REAL;
REAL _ATAN_REAL_(void)
{
    return atanf(_ATAN_REAL.IN);
}
#endif

#if (DT_LREAL_EN > 0)
ATAN_LREAL_S _ATAN_LREAL;
LREAL _ATAN_LREAL_(void)
{
    return atan(_ATAN_LREAL.IN);
}
#endif

/*
 * =============================================
 * SHL
 * =============================================
*/
SHL_BYTE_S _SHL_BYTE;
BYTE _SHL_BYTE_(void)
{
    return (BYTE)(_SHL_BYTE.IN << _SHL_BYTE.N);
}

SHL_WORD_S _SHL_WORD;
WORD _SHL_WORD_(void)
{
    return (WORD)(_SHL_WORD.IN << _SHL_WORD.N);
}

SHL_DWORD_S _SHL_DWORD;
DWORD _SHL_DWORD_(void)
{
    return (DWORD)(_SHL_DWORD.IN << _SHL_DWORD.N);
}

#if (DT_LWORD_EN > 0)
SHL_LWORD_S _SHL_LWORD;
LWORD _SHL_LWORD_(void)
{
    return (LWORD)(_SHL_LWORD.IN << _SHL_LWORD.N);
}
#endif

/*
 * =============================================
 * SHR
 * =============================================
*/
SHR_BYTE_S _SHR_BYTE;
BYTE _SHR_BYTE_(void)
{
    return (BYTE)(_SHR_BYTE.IN >> _SHR_BYTE.N);
}

SHR_WORD_S _SHR_WORD;
WORD _SHR_WORD_(void)
{
    return (WORD)(_SHR_WORD.IN >> _SHR_WORD.N);
}

SHR_DWORD_S _SHR_DWORD;
DWORD _SHR_DWORD_(void)
{
    return (DWORD)(_SHR_DWORD.IN >> _SHR_DWORD.N);
}

#if (DT_LWORD_EN > 0)
SHR_LWORD_S _SHR_LWORD;
LWORD _SHR_LWORD_(void)
{
    return (LWORD)(_SHR_LWORD.IN >> _SHR_LWORD.N);
}
#endif

/*
 * =============================================
 * ROR
 * =============================================
*/
ROR_BYTE_S _ROR_BYTE;
BYTE _ROR_BYTE_(void)
{
    int n = _ROR_BYTE.N % 8;
    return (BYTE)((_ROR_BYTE.IN >> n) | (_ROR_BYTE.IN << (8 - n)));
}

ROR_WORD_S _ROR_WORD;
WORD _ROR_WORD_(void)
{
    int n = _ROR_WORD.N % 16;
    return (WORD)((_ROR_WORD.IN >> n) | (_ROR_WORD.IN << (16 - n)));
}

ROR_DWORD_S _ROR_DWORD;
DWORD _ROR_DWORD_(void)
{
    int n = _ROR_DWORD.N % 32;
    return (DWORD)((_ROR_DWORD.IN >> n) | (_ROR_DWORD.IN << (32 - n)));
}

#if (DT_LWORD_EN > 0)
ROR_LWORD_S _ROR_LWORD;
LWORD _ROR_LWORD_(void)
{
    int n = _ROR_LWORD.N % 64;
    return (LWORD)((_ROR_LWORD.IN >> n) | (_ROR_LWORD.IN << (64 - n)));
}
#endif

/*
 * =============================================
 * ROL
 * =============================================
*/
ROL_BYTE_S _ROL_BYTE;
BYTE _ROL_BYTE_(void)
{
    int n = _ROL_BYTE.N % 8;
    return (BYTE)((_ROL_BYTE.IN << n) | (_ROL_BYTE.IN >> (8 - n)));
}

ROL_WORD_S _ROL_WORD;
WORD _ROL_WORD_(void)
{
    int n = _ROL_WORD.N % 16;
    return (WORD)((_ROL_WORD.IN << n) | (_ROL_WORD.IN >> (16 - n)));
}

ROL_DWORD_S _ROL_DWORD;
DWORD _ROL_DWORD_(void)
{
    int n = _ROL_DWORD.N % 32;
    return (DWORD)((_ROL_DWORD.IN << n) | (_ROL_DWORD.IN >> (32 - n)));
}

#if (DT_LWORD_EN > 0)
ROL_LWORD_S _ROL_LWORD;
LWORD _ROL_LWORD_(void)
{
    int n = _ROL_LWORD.N % 64;
    return (LWORD)((_ROL_LWORD.IN << n) | (_ROL_LWORD.IN >> (64 - n)));
}
#endif

/*
 * =============================================
 * AND
 * =============================================
*/
AND_BOOL_S _AND_BOOL;
BOOL _AND_BOOL_(void)
{
    return (_AND_BOOL.IN1 & _AND_BOOL.IN2);
}

AND_BYTE_S _AND_BYTE;
BYTE _AND_BYTE_(void)
{
    return (_AND_BYTE.IN1 & _AND_BYTE.IN2);
}

AND_WORD_S _AND_WORD;
WORD _AND_WORD_(void)
{
    return (_AND_WORD.IN1 & _AND_WORD.IN2);
}

AND_DWORD_S _AND_DWORD;
DWORD _AND_DWORD_(void)
{
    return (_AND_DWORD.IN1 & _AND_DWORD.IN2);
}

#if (DT_LWORD_EN > 0)
AND_LWORD_S _AND_LWORD;
LWORD _AND_LWORD_(void)
{
    return (_AND_LWORD.IN1 & _AND_LWORD.IN2);
}
#endif

/*
 * =============================================
 * OR
 * =============================================
*/
OR_BOOL_S _OR_BOOL;
BOOL _OR_BOOL_(void)
{
    return (_OR_BOOL.IN1 | _OR_BOOL.IN2);
}

OR_BYTE_S _OR_BYTE;
BYTE _OR_BYTE_(void)
{
    return (_OR_BYTE.IN1 | _OR_BYTE.IN2);
}

OR_WORD_S _OR_WORD;
WORD _OR_WORD_(void)
{
    return (_OR_WORD.IN1 | _OR_WORD.IN2);
}

OR_DWORD_S _OR_DWORD;
DWORD _OR_DWORD_(void)
{
    return (_OR_DWORD.IN1 | _OR_DWORD.IN2);
}

#if (DT_LWORD_EN > 0)
OR_LWORD_S _OR_LWORD;
LWORD _OR_LWORD_(void)
{
    return (_OR_LWORD.IN1 | _OR_LWORD.IN2);
}
#endif

/*
 * =============================================
 * XOR
 * =============================================
*/
XOR_BOOL_S _XOR_BOOL;
BOOL _XOR_BOOL_(void)
{
    return (_XOR_BOOL.IN1 ^ _XOR_BOOL.IN2);
}

XOR_BYTE_S _XOR_BYTE;
BYTE _XOR_BYTE_(void)
{
    return (_XOR_BYTE.IN1 ^ _XOR_BYTE.IN2);
}

XOR_WORD_S _XOR_WORD;
WORD _XOR_WORD_(void)
{
    return (_XOR_WORD.IN1 ^ _XOR_WORD.IN2);
}

XOR_DWORD_S _XOR_DWORD;
DWORD _XOR_DWORD_(void)
{
    return (_XOR_DWORD.IN1 ^ _XOR_DWORD.IN2);
}

#if (DT_LWORD_EN > 0)
XOR_LWORD_S _XOR_LWORD;
LWORD _XOR_LWORD_(void)
{
    return (_XOR_LWORD.IN1 ^ _XOR_LWORD.IN2);
}
#endif

/*
 * =============================================
 * NOT
 * =============================================
*/
NOT_BOOL_S _NOT_BOOL;
BOOL _NOT_BOOL_(void)
{
    return ~(_NOT_BOOL.IN1);
}

NOT_BYTE_S _NOT_BYTE;
BYTE _NOT_BYTE_(void)
{
    return ~(_NOT_BYTE.IN1);
}

NOT_WORD_S _NOT_WORD;
WORD _NOT_WORD_(void)
{
    return ~(_NOT_WORD.IN1);
}

NOT_DWORD_S _NOT_DWORD;
DWORD _NOT_DWORD_(void)
{
    return ~(_NOT_DWORD.IN1);
}

#if (DT_LWORD_EN > 0)
NOT_LWORD_S _NOT_LWORD;
LWORD _NOT_LWORD_(void)
{
    return ~(_NOT_LWORD.IN1);
}
#endif

/*
 * =============================================
 * SEL
 * =============================================
*/
SEL_BOOL_S _SEL_BOOL;
BOOL _SEL_BOOL_(void)
{
    if(_SEL_BOOL.G == 0) return _SEL_BOOL.IN0;
    else return _SEL_BOOL.IN1;
}

SEL_BYTE_S _SEL_BYTE;
BYTE _SEL_BYTE_(void)
{
    if(_SEL_BOOL.G == 0) return _SEL_BOOL.IN0;
    else return _SEL_BOOL.IN1;
}

SEL_WORD_S _SEL_WORD;
WORD _SEL_WORD_(void)
{
    if(_SEL_BOOL.G == 0) return _SEL_BOOL.IN0;
    else return _SEL_BOOL.IN1;
}

SEL_DWORD_S _SEL_DWORD;
DWORD _SEL_DWORD_(void)
{
    if(_SEL_BOOL.G == 0) return _SEL_BOOL.IN0;
    else return _SEL_BOOL.IN1;
}

#if (DT_LWORD_EN > 0)
SEL_LWORD_S _SEL_LWORD;
LWORD _SEL_LWORD_(void)
{
    if(_SEL_BOOL.G == 0) return _SEL_BOOL.IN0;
    else return _SEL_BOOL.IN1;
}
#endif

SEL_SINT_S _SEL_SINT;
SINT _SEL_SINT_(void)
{
    if(_SEL_BOOL.G == 0) return _SEL_BOOL.IN0;
    else return _SEL_BOOL.IN1;
}

SEL_INT_S _SEL_INT;
INT _SEL_INT_(void)
{
    if(_SEL_BOOL.G == 0) return _SEL_BOOL.IN0;
    else return _SEL_BOOL.IN1;
}

SEL_DINT_S _SEL_DINT;
DINT _SEL_DINT_(void)
{
    if(_SEL_BOOL.G == 0) return _SEL_BOOL.IN0;
    else return _SEL_BOOL.IN1;
}

#if (DT_LINT_EN > 0)
SEL_LINT_S _SEL_LINT;
LINT _SEL_LINT_(void)
{
    if(_SEL_BOOL.G == 0) return _SEL_BOOL.IN0;
    else return _SEL_BOOL.IN1;
}
#endif

SEL_USINT_S _SEL_USINT;
USINT _SEL_USINT_(void)
{
    if(_SEL_BOOL.G == 0) return _SEL_BOOL.IN0;
    else return _SEL_BOOL.IN1;
}

SEL_UINT_S _SEL_UINT;
UINT _SEL_UINT_(void)
{
    if(_SEL_BOOL.G == 0) return _SEL_BOOL.IN0;
    else return _SEL_BOOL.IN1;
}

SEL_UDINT_S _SEL_UDINT;
UDINT _SEL_UDINT_(void)
{
    if(_SEL_BOOL.G == 0) return _SEL_BOOL.IN0;
    else return _SEL_BOOL.IN1;
}

#if (DT_ULINT_EN > 0)
SEL_ULINT_S _SEL_ULINT;
ULINT _SEL_ULINT_(void)
{
    if(_SEL_BOOL.G == 0) return _SEL_BOOL.IN0;
    else return _SEL_BOOL.IN1;
}
#endif

#if (DT_REAL_EN > 0)
SEL_REAL_S _SEL_REAL;
REAL _SEL_REAL_(void)
{
    if(_SEL_BOOL.G == 0) return _SEL_BOOL.IN0;
    else return _SEL_BOOL.IN1;
}
#endif

#if (DT_LREAL_EN > 0)
SEL_LREAL_S _SEL_LREAL;
LREAL _SEL_LREAL_(void)
{
    if(_SEL_BOOL.G == 0) return _SEL_BOOL.IN0;
    else return _SEL_BOOL.IN1;
}
#endif

/*
 * =============================================
 * GT
 * =============================================
*/
GT_BOOL_S _GT_BOOL;
BOOL _GT_BOOL_(void)
{
    return (_GT_BOOL.IN1 > _GT_BOOL.IN2);
}

GT_BYTE_S _GT_BYTE;
BOOL _GT_BYTE_(void)
{
    return (_GT_BOOL.IN1 > _GT_BOOL.IN2);
}

GT_WORD_S _GT_WORD;
BOOL _GT_WORD_(void)
{
    return (_GT_BOOL.IN1 > _GT_BOOL.IN2);
}

GT_DWORD_S _GT_DWORD;
BOOL _GT_DWORD_(void)
{
    return (_GT_BOOL.IN1 > _GT_BOOL.IN2);
}

#if (DT_LWORD_EN > 0)
GT_LWORD_S _GT_LWORD;
BOOL _GT_LWORD_(void)
{
    return (_GT_BOOL.IN1 > _GT_BOOL.IN2);
}
#endif

GT_SINT_S _GT_SINT;
BOOL _GT_SINT_(void)
{
    return (_GT_BOOL.IN1 > _GT_BOOL.IN2);
}

GT_INT_S _GT_INT;
BOOL _GT_INT_(void)
{
    return (_GT_BOOL.IN1 > _GT_BOOL.IN2);
}

GT_DINT_S _GT_DINT;
BOOL _GT_DINT_(void)
{
    return (_GT_BOOL.IN1 > _GT_BOOL.IN2);
}

#if (DT_LINT_EN > 0)
GT_LINT_S _GT_LINT;
BOOL _GT_LINT_(void)
{
    return (_GT_BOOL.IN1 > _GT_BOOL.IN2);
}
#endif

GT_USINT_S _GT_USINT;
BOOL _GT_USINT_(void)
{
    return (_GT_BOOL.IN1 > _GT_BOOL.IN2);
}

GT_UINT_S _GT_UINT;
BOOL _GT_UINT_(void)
{
    return (_GT_BOOL.IN1 > _GT_BOOL.IN2);
}

GT_UDINT_S _GT_UDINT;
BOOL _GT_UDINT_(void)
{
    return (_GT_BOOL.IN1 > _GT_BOOL.IN2);
}

#if (DT_ULINT_EN > 0)
GT_ULINT_S _GT_ULINT;
BOOL _GT_ULINT_(void)
{
    return (_GT_BOOL.IN1 > _GT_BOOL.IN2);
}
#endif

#if (DT_REAL_EN > 0)
GT_REAL_S _GT_REAL;
BOOL _GT_REAL_(void)
{
    return (_GT_BOOL.IN1 > _GT_BOOL.IN2);
}
#endif

#if (DT_LREAL_EN > 0)
GT_LREAL_S _GT_LREAL;
BOOL _GT_LREAL_(void)
{
    return (_GT_BOOL.IN1 > _GT_BOOL.IN2);
}
#endif

/*
 * =============================================
 * GE
 * =============================================
*/
GE_BOOL_S _GE_BOOL;
BOOL _GE_BOOL_(void)
{
    return (_GE_BOOL.IN1 >= _GE_BOOL.IN2);
}

GE_BYTE_S _GE_BYTE;
BOOL _GE_BYTE_(void)
{
    return (_GE_BOOL.IN1 >= _GE_BOOL.IN2);
}

GE_WORD_S _GE_WORD;
BOOL _GE_WORD_(void)
{
    return (_GE_BOOL.IN1 >= _GE_BOOL.IN2);
}

GE_DWORD_S _GE_DWORD;
BOOL _GE_DWORD_(void)
{
    return (_GE_BOOL.IN1 >= _GE_BOOL.IN2);
}

#if (DT_LWORD_EN > 0)
GE_LWORD_S _GE_LWORD;
BOOL _GE_LWORD_(void)
{
    return (_GE_BOOL.IN1 >= _GE_BOOL.IN2);
}
#endif

GE_SINT_S _GE_SINT;
BOOL _GE_SINT_(void)
{
    return (_GE_BOOL.IN1 >= _GE_BOOL.IN2);
}

GE_INT_S _GE_INT;
BOOL _GE_INT_(void)
{
    return (_GE_BOOL.IN1 >= _GE_BOOL.IN2);
}

GE_DINT_S _GE_DINT;
BOOL _GE_DINT_(void)
{
    return (_GE_BOOL.IN1 >= _GE_BOOL.IN2);
}

#if (DT_LINT_EN > 0)
GE_LINT_S _GE_LINT;
BOOL _GE_LINT_(void)
{
    return (_GE_BOOL.IN1 >= _GE_BOOL.IN2);
}
#endif

GE_USINT_S _GE_USINT;
BOOL _GE_USINT_(void)
{
    return (_GE_BOOL.IN1 >= _GE_BOOL.IN2);
}

GE_UINT_S _GE_UINT;
BOOL _GE_UINT_(void)
{
    return (_GE_BOOL.IN1 >= _GE_BOOL.IN2);
}

GE_UDINT_S _GE_UDINT;
BOOL _GE_UDINT_(void)
{
    return (_GE_BOOL.IN1 >= _GE_BOOL.IN2);
}

#if (DT_ULINT_EN > 0)
GE_ULINT_S _GE_ULINT;
BOOL _GE_ULINT_(void)
{
    return (_GE_BOOL.IN1 >= _GE_BOOL.IN2);
}
#endif

#if (DT_REAL_EN > 0)
GE_REAL_S _GE_REAL;
BOOL _GE_REAL_(void)
{
    return (_GE_BOOL.IN1 >= _GE_BOOL.IN2);
}
#endif

#if (DT_LREAL_EN > 0)
GE_LREAL_S _GE_LREAL;
BOOL _GE_LREAL_(void)
{
    return (_GE_BOOL.IN1 >= _GE_BOOL.IN2);
}
#endif

/*
 * =============================================
 * EQ
 * =============================================
*/
EQ_BOOL_S _EQ_BOOL;
BOOL _EQ_BOOL_(void)
{
    return (_EQ_BOOL.IN1 == _EQ_BOOL.IN2);
}

EQ_BYTE_S _EQ_BYTE;
BOOL _EQ_BYTE_(void)
{
    return (_EQ_BOOL.IN1 == _EQ_BOOL.IN2);
}

EQ_WORD_S _EQ_WORD;
BOOL _EQ_WORD_(void)
{
    return (_EQ_BOOL.IN1 == _EQ_BOOL.IN2);
}

EQ_DWORD_S _EQ_DWORD;
BOOL _EQ_DWORD_(void)
{
    return (_EQ_BOOL.IN1 == _EQ_BOOL.IN2);
}

#if (DT_LWORD_EN > 0)
EQ_LWORD_S _EQ_LWORD;
BOOL _EQ_LWORD_(void)
{
    return (_EQ_BOOL.IN1 == _EQ_BOOL.IN2);
}
#endif

EQ_SINT_S _EQ_SINT;
BOOL _EQ_SINT_(void)
{
    return (_EQ_BOOL.IN1 == _EQ_BOOL.IN2);
}

EQ_INT_S _EQ_INT;
BOOL _EQ_INT_(void)
{
    return (_EQ_BOOL.IN1 == _EQ_BOOL.IN2);
}

EQ_DINT_S _EQ_DINT;
BOOL _EQ_DINT_(void)
{
    return (_EQ_BOOL.IN1 == _EQ_BOOL.IN2);
}

#if (DT_LINT_EN > 0)
EQ_LINT_S _EQ_LINT;
BOOL _EQ_LINT_(void)
{
    return (_EQ_BOOL.IN1 == _EQ_BOOL.IN2);
}
#endif

EQ_USINT_S _EQ_USINT;
BOOL _EQ_USINT_(void)
{
    return (_EQ_BOOL.IN1 == _EQ_BOOL.IN2);
}

EQ_UINT_S _EQ_UINT;
BOOL _EQ_UINT_(void)
{
    return (_EQ_BOOL.IN1 == _EQ_BOOL.IN2);
}

EQ_UDINT_S _EQ_UDINT;
BOOL _EQ_UDINT_(void)
{
    return (_EQ_BOOL.IN1 == _EQ_BOOL.IN2);
}

#if (DT_ULINT_EN > 0)
EQ_ULINT_S _EQ_ULINT;
BOOL _EQ_ULINT_(void)
{
    return (_EQ_BOOL.IN1 == _EQ_BOOL.IN2);
}
#endif

#if (DT_REAL_EN > 0)
EQ_REAL_S _EQ_REAL;
BOOL _EQ_REAL_(void)
{
    return (_EQ_BOOL.IN1 == _EQ_BOOL.IN2);
}
#endif

#if (DT_LREAL_EN > 0)
EQ_LREAL_S _EQ_LREAL;
BOOL _EQ_LREAL_(void)
{
    return (_EQ_BOOL.IN1 == _EQ_BOOL.IN2);
}
#endif

/*
 * =============================================
 * LE
 * =============================================
*/
LE_BOOL_S _LE_BOOL;
BOOL _LE_BOOL_(void)
{
    return (_LE_BOOL.IN1 <= _LE_BOOL.IN2);
}

LE_BYTE_S _LE_BYTE;
BOOL _LE_BYTE_(void)
{
    return (_LE_BOOL.IN1 <= _LE_BOOL.IN2);
}

LE_WORD_S _LE_WORD;
BOOL _LE_WORD_(void)
{
    return (_LE_BOOL.IN1 <= _LE_BOOL.IN2);
}

LE_DWORD_S _LE_DWORD;
BOOL _LE_DWORD_(void)
{
    return (_LE_BOOL.IN1 <= _LE_BOOL.IN2);
}

#if (DT_LWORD_EN > 0)
LE_LWORD_S _LE_LWORD;
BOOL _LE_LWORD_(void)
{
    return (_LE_BOOL.IN1 <= _LE_BOOL.IN2);
}
#endif

LE_SINT_S _LE_SINT;
BOOL _LE_SINT_(void)
{
    return (_LE_BOOL.IN1 <= _LE_BOOL.IN2);
}

LE_INT_S _LE_INT;
BOOL _LE_INT_(void)
{
    return (_LE_BOOL.IN1 <= _LE_BOOL.IN2);
}

LE_DINT_S _LE_DINT;
BOOL _LE_DINT_(void)
{
    return (_LE_BOOL.IN1 <= _LE_BOOL.IN2);
}

#if (DT_LINT_EN > 0)
LE_LINT_S _LE_LINT;
BOOL _LE_LINT_(void)
{
    return (_LE_BOOL.IN1 <= _LE_BOOL.IN2);
}
#endif

LE_USINT_S _LE_USINT;
BOOL _LE_USINT_(void)
{
    return (_LE_BOOL.IN1 <= _LE_BOOL.IN2);
}

LE_UINT_S _LE_UINT;
BOOL _LE_UINT_(void)
{
    return (_LE_BOOL.IN1 <= _LE_BOOL.IN2);
}

LE_UDINT_S _LE_UDINT;
BOOL _LE_UDINT_(void)
{
    return (_LE_BOOL.IN1 <= _LE_BOOL.IN2);
}

#if (DT_ULINT_EN > 0)
LE_ULINT_S _LE_ULINT;
BOOL _LE_ULINT_(void)
{
    return (_LE_BOOL.IN1 <= _LE_BOOL.IN2);
}
#endif

#if (DT_REAL_EN > 0)
LE_REAL_S _LE_REAL;
BOOL _LE_REAL_(void)
{
    return (_LE_BOOL.IN1 <= _LE_BOOL.IN2);
}
#endif

#if (DT_LREAL_EN > 0)
LE_LREAL_S _LE_LREAL;
BOOL _LE_LREAL_(void)
{
    return (_LE_BOOL.IN1 <= _LE_BOOL.IN2);
}
#endif

/*
 * =============================================
 * LT
 * =============================================
*/
LT_BOOL_S _LT_BOOL;
BOOL _LT_BOOL_(void)
{
    return (_LT_BOOL.IN1 < _LT_BOOL.IN2);
}

LT_BYTE_S _LT_BYTE;
BOOL _LT_BYTE_(void)
{
    return (_LT_BOOL.IN1 < _LT_BOOL.IN2);
}

LT_WORD_S _LT_WORD;
BOOL _LT_WORD_(void)
{
    return (_LT_BOOL.IN1 < _LT_BOOL.IN2);
}

LT_DWORD_S _LT_DWORD;
BOOL _LT_DWORD_(void)
{
    return (_LT_BOOL.IN1 < _LT_BOOL.IN2);
}

#if (DT_LWORD_EN > 0)
LT_LWORD_S _LT_LWORD;
BOOL _LT_LWORD_(void)
{
    return (_LT_BOOL.IN1 < _LT_BOOL.IN2);
}
#endif

LT_SINT_S _LT_SINT;
BOOL _LT_SINT_(void)
{
    return (_LT_BOOL.IN1 < _LT_BOOL.IN2);
}

LT_INT_S _LT_INT;
BOOL _LT_INT_(void)
{
    return (_LT_BOOL.IN1 < _LT_BOOL.IN2);
}

LT_DINT_S _LT_DINT;
BOOL _LT_DINT_(void)
{
    return (_LT_BOOL.IN1 < _LT_BOOL.IN2);
}

#if (DT_LINT_EN > 0)
LT_LINT_S _LT_LINT;
BOOL _LT_LINT_(void)
{
    return (_LT_BOOL.IN1 < _LT_BOOL.IN2);
}
#endif

LT_USINT_S _LT_USINT;
BOOL _LT_USINT_(void)
{
    return (_LT_BOOL.IN1 < _LT_BOOL.IN2);
}

LT_UINT_S _LT_UINT;
BOOL _LT_UINT_(void)
{
    return (_LT_BOOL.IN1 < _LT_BOOL.IN2);
}

LT_UDINT_S _LT_UDINT;
BOOL _LT_UDINT_(void)
{
    return (_LT_BOOL.IN1 < _LT_BOOL.IN2);
}

#if (DT_ULINT_EN > 0)
LT_ULINT_S _LT_ULINT;
BOOL _LT_ULINT_(void)
{
    return (_LT_BOOL.IN1 < _LT_BOOL.IN2);
}
#endif

#if (DT_REAL_EN > 0)
LT_REAL_S _LT_REAL;
BOOL _LT_REAL_(void)
{
    return (_LT_BOOL.IN1 < _LT_BOOL.IN2);
}
#endif

#if (DT_LREAL_EN > 0)
LT_LREAL_S _LT_LREAL;
BOOL _LT_LREAL_(void)
{
    return (_LT_BOOL.IN1 < _LT_BOOL.IN2);
}
#endif

/*
 * =============================================
 * NE
 * =============================================
*/
NE_BOOL_S _NE_BOOL;
BOOL _NE_BOOL_(void)
{
    return (_NE_BOOL.IN1 != _NE_BOOL.IN2);
}

NE_BYTE_S _NE_BYTE;
BOOL _NE_BYTE_(void)
{
    return (_NE_BOOL.IN1 != _NE_BOOL.IN2);
}

NE_WORD_S _NE_WORD;
BOOL _NE_WORD_(void)
{
    return (_NE_BOOL.IN1 != _NE_BOOL.IN2);
}

NE_DWORD_S _NE_DWORD;
BOOL _NE_DWORD_(void)
{
    return (_NE_BOOL.IN1 != _NE_BOOL.IN2);
}

#if (DT_LWORD_EN > 0)
NE_LWORD_S _NE_LWORD;
BOOL _NE_LWORD_(void)
{
    return (_NE_BOOL.IN1 != _NE_BOOL.IN2);
}
#endif

NE_SINT_S _NE_SINT;
BOOL _NE_SINT_(void)
{
    return (_NE_BOOL.IN1 != _NE_BOOL.IN2);
}

NE_INT_S _NE_INT;
BOOL _NE_INT_(void)
{
    return (_NE_BOOL.IN1 != _NE_BOOL.IN2);
}

NE_DINT_S _NE_DINT;
BOOL _NE_DINT_(void)
{
    return (_NE_BOOL.IN1 != _NE_BOOL.IN2);
}

#if (DT_LINT_EN > 0)
NE_LINT_S _NE_LINT;
BOOL _NE_LINT_(void)
{
    return (_NE_BOOL.IN1 != _NE_BOOL.IN2);
}
#endif

NE_USINT_S _NE_USINT;
BOOL _NE_USINT_(void)
{
    return (_NE_BOOL.IN1 != _NE_BOOL.IN2);
}

NE_UINT_S _NE_UINT;
BOOL _NE_UINT_(void)
{
    return (_NE_BOOL.IN1 != _NE_BOOL.IN2);
}

NE_UDINT_S _NE_UDINT;
BOOL _NE_UDINT_(void)
{
    return (_NE_BOOL.IN1 != _NE_BOOL.IN2);
}

#if (DT_ULINT_EN > 0)
NE_ULINT_S _NE_ULINT;
BOOL _NE_ULINT_(void)
{
    return (_NE_BOOL.IN1 != _NE_BOOL.IN2);
}
#endif

#if (DT_REAL_EN > 0)
NE_REAL_S _NE_REAL;
BOOL _NE_REAL_(void)
{
    return (_NE_BOOL.IN1 != _NE_BOOL.IN2);
}
#endif

#if (DT_LREAL_EN > 0)
NE_LREAL_S _NE_LREAL;
BOOL _NE_LREAL_(void)
{
    return (_NE_BOOL.IN1 != _NE_BOOL.IN2);
}
#endif
