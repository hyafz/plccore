/**
  * @file  plc_std_fc.c
  * @brief     PLC标准功能实现文件
  * @author    fengzhou
  */
#include <plc_std_fc.h>

SINT_TO_INT_S _SINT_TO_INT;

INT_TO_SINT_S _INT_TO_SINT;

INT_TO_DINT_S _INT_TO_DINT;

DINT_TO_INT_S _DINT_TO_INT;

#if (DT_LINT_EN > 0)
DINT_TO_LINT_S _DINT_TO_LINT;

LINT_TO_DINT_S _LINT_TO_DINT;
#endif

USINT_TO_UINT_S _USINT_TO_UINT;

UINT_TO_USINT_S _UINT_TO_USINT;

UINT_TO_UDINT_S _UINT_TO_UDINT;

UDINT_TO_UINT_S _UDINT_TO_UINT;

#if (DT_ULINT_EN > 0)
UDINT_TO_ULINT_S _UDINT_TO_ULINT;

ULINT_TO_UDINT_S _ULINT_TO_UDINT;
#endif

USINT_TO_SINT_S _USINT_TO_SINT;

SINT_TO_USINT_S _SINT_TO_USINT;

UINT_TO_INT_S _UINT_TO_INT;

INT_TO_UINT_S _INT_TO_UINT;

UDINT_TO_DINT_S _UDINT_TO_DINT;

DINT_TO_UDINT_S _DINT_TO_UDINT;

#if ((DT_ULINT_EN > 0) && (DT_LINT_EN > 0))
ULINT_TO_LINT_S _ULINT_TO_LINT;

LINT_TO_ULINT_S _LINT_TO_ULINT;
#endif

BOOL_TO_BYTE_S _BOOL_TO_BYTE;

BYTE_TO_BOOL_S _BYTE_TO_BOOL;

BYTE_TO_WORD_S _BYTE_TO_WORD;

WORD_TO_BYTE_S _WORD_TO_BYTE;

WORD_TO_DWORD_S _WORD_TO_DWORD;

DWORD_TO_WORD_S _DWORD_TO_WORD;

#if (DT_LWORD_EN > 0)
DWORD_TO_LWORD_S _DWORD_TO_LWORD;

LWORD_TO_DWORD_S _LWORD_TO_DWORD;
#endif

BYTE_TO_USINT_S _BYTE_TO_USINT;

USINT_TO_BYTE_S _USINT_TO_BYTE;

WORD_TO_UINT_S _WORD_TO_UINT;

UINT_TO_WORD_S _UINT_TO_WORD;

DWORD_TO_UDINT_S _DWORD_TO_UDINT;

UDINT_TO_DWORD_S _UDINT_TO_DWORD;

#if ((DT_ULINT_EN > 0) && (DT_LWORD_EN > 0))
LWORD_TO_ULINT_S _LWORD_TO_ULINT;

ULINT_TO_LWORD_S _ULINT_TO_LWORD;
#endif

#if (DT_REAL_EN > 0)
REAL_TO_DINT_S _REAL_TO_DINT;

DINT_TO_REAL_S _DINT_TO_REAL;
#endif

#if ((DT_LINT_EN > 0) && (DT_LREAL_EN > 0))
LREAL_TO_LINT_S _LREAL_TO_LINT;

LINT_TO_LREAL_S _LINT_TO_LREAL;
#endif

/*
 * =============================================
 * ADD
 * =============================================
*/
ADD_SINT_S _ADD_SINT;

ADD_INT_S _ADD_INT;

ADD_DINT_S _ADD_DINT;

#if (DT_LINT_EN > 0)
ADD_LINT_S _ADD_LINT;
#endif

ADD_USINT_S _ADD_USINT;

ADD_UINT_S _ADD_UINT;

ADD_UDINT_S _ADD_UDINT;

#if (DT_ULINT_EN > 0)
ADD_ULINT_S _ADD_ULINT;
#endif

#if (DT_REAL_EN > 0)
ADD_REAL_S _ADD_REAL;
#endif

#if (DT_LREAL_EN > 0)
ADD_LREAL_S _ADD_LREAL;
#endif

/*
 * =============================================
 * SUB
 * =============================================
*/
SUB_SINT_S _SUB_SINT;

SUB_INT_S _SUB_INT;

SUB_DINT_S _SUB_DINT;

#if (DT_LINT_EN > 0)
SUB_LINT_S _SUB_LINT;
#endif

SUB_USINT_S _SUB_USINT;

SUB_UINT_S _SUB_UINT;

SUB_UDINT_S _SUB_UDINT;

#if (DT_ULINT_EN > 0)
SUB_ULINT_S _SUB_ULINT;
#endif

#if (DT_REAL_EN > 0)
SUB_REAL_S _SUB_REAL;
#endif

#if (DT_LREAL_EN > 0)
SUB_LREAL_S _SUB_LREAL;
#endif

/*
 * =============================================
 * MUL
 * =============================================
*/
MUL_SINT_S _MUL_SINT;

MUL_INT_S _MUL_INT;

MUL_DINT_S _MUL_DINT;

#if (DT_LINT_EN > 0)
MUL_LINT_S _MUL_LINT;
#endif

MUL_USINT_S _MUL_USINT;

MUL_UINT_S _MUL_UINT;

MUL_UDINT_S _MUL_UDINT;

#if (DT_ULINT_EN > 0)
MUL_ULINT_S _MUL_ULINT;
#endif

#if (DT_REAL_EN > 0)
MUL_REAL_S _MUL_REAL;
#endif

#if (DT_LREAL_EN > 0)
MUL_LREAL_S _MUL_LREAL;
#endif

/*
 * =============================================
 * DIV
 * =============================================
*/
DIV_SINT_S _DIV_SINT;

DIV_INT_S _DIV_INT;

DIV_DINT_S _DIV_DINT;

#if (DT_LINT_EN > 0)
DIV_LINT_S _DIV_LINT;
#endif

DIV_USINT_S _DIV_USINT;

DIV_UINT_S _DIV_UINT;

DIV_UDINT_S _DIV_UDINT;

#if (DT_ULINT_EN > 0)
DIV_ULINT_S _DIV_ULINT;
#endif

#if (DT_REAL_EN > 0)
DIV_REAL_S _DIV_REAL;
#endif

#if (DT_LREAL_EN > 0)
DIV_LREAL_S _DIV_LREAL;
#endif

/*
 * =============================================
 * MOD
 * =============================================
*/
MOD_SINT_S _MOD_SINT;

MOD_INT_S _MOD_INT;

MOD_DINT_S _MOD_DINT;

#if (DT_LINT_EN > 0)
MOD_LINT_S _MOD_LINT;
#endif

MOD_USINT_S _MOD_USINT;

MOD_UINT_S _MOD_UINT;

MOD_UDINT_S _MOD_UDINT;

#if (DT_ULINT_EN > 0)
MOD_ULINT_S _MOD_ULINT;
#endif

/*
 * =============================================
 * EXPT
 * =============================================
*/

#if (DT_REAL_EN > 0)
EXPT_REAL_S _EXPT_REAL;
#endif

#if (DT_LREAL_EN > 0)
EXPT_LREAL_S _EXPT_LREAL;
#endif

/*
 * =============================================
 * MOVE
 * =============================================
*/
MOVE_BOOL_S _MOVE_BOOL;

MOVE_BYTE_S _MOVE_BYTE;

MOVE_WORD_S _MOVE_WORD;

MOVE_DWORD_S _MOVE_DWORD;

#if (DT_LWORD_EN > 0)
MOVE_LWORD_S _MOVE_LWORD;
#endif

MOVE_SINT_S _MOVE_SINT;

MOVE_INT_S _MOVE_INT;

MOVE_DINT_S _MOVE_DINT;

#if (DT_LINT_EN > 0)
MOVE_LINT_S _MOVE_LINT;
#endif

MOVE_USINT_S _MOVE_USINT;

MOVE_UINT_S _MOVE_UINT;

MOVE_UDINT_S _MOVE_UDINT;

#if (DT_ULINT_EN > 0)
MOVE_ULINT_S _MOVE_ULINT;
#endif

#if (DT_REAL_EN > 0)
MOVE_REAL_S _MOVE_REAL;
#endif

#if (DT_LREAL_EN > 0)
MOVE_LREAL_S _MOVE_LREAL;
#endif

/*
 * =============================================
 * ABS
 * =============================================
*/

ABS_SINT_S _ABS_SINT;

ABS_INT_S _ABS_INT;

ABS_DINT_S _ABS_DINT;

#if (DT_LINT_EN > 0)
ABS_LINT_S _ABS_LINT;
#endif

ABS_USINT_S _ABS_USINT;

ABS_UINT_S _ABS_UINT;

ABS_UDINT_S _ABS_UDINT;

#if (DT_ULINT_EN > 0)
ABS_ULINT_S _ABS_ULINT;
#endif

#if (DT_REAL_EN > 0)
ABS_REAL_S _ABS_REAL;
#endif

#if (DT_LREAL_EN > 0)
ABS_LREAL_S _ABS_LREAL;
#endif

/*
 * =============================================
 * SQRT
 * =============================================
*/
#if (DT_REAL_EN > 0)
SQRT_REAL_S _SQRT_REAL;
#endif

#if (DT_LREAL_EN > 0)
SQRT_LREAL_S _SQRT_LREAL;
#endif

/*
 * =============================================
 * LN
 * =============================================
*/
#if (DT_REAL_EN > 0)
LN_REAL_S _LN_REAL;
#endif

#if (DT_LREAL_EN > 0)
LN_LREAL_S _LN_LREAL;
#endif

/*
 * =============================================
 * LOG
 * =============================================
*/
#if (DT_REAL_EN > 0)
LOG_REAL_S _LOG_REAL;
#endif

#if (DT_LREAL_EN > 0)
LOG_LREAL_S _LOG_LREAL;
#endif

/*
 * =============================================
 * EXP
 * =============================================
*/
#if (DT_REAL_EN > 0)
EXP_REAL_S _EXP_REAL;
#endif

#if (DT_LREAL_EN > 0)
EXP_LREAL_S _EXP_LREAL;
#endif

/*
 * =============================================
 * SIN
 * =============================================
*/
#if (DT_REAL_EN > 0)
SIN_REAL_S _SIN_REAL;
#endif

#if (DT_LREAL_EN > 0)
SIN_LREAL_S _SIN_LREAL;
#endif

/*
 * =============================================
 * COS
 * =============================================
*/
#if (DT_REAL_EN > 0)
COS_REAL_S _COS_REAL;
#endif

#if (DT_LREAL_EN > 0)
COS_LREAL_S _COS_LREAL;
#endif

/*
 * =============================================
 * TAN
 * =============================================
*/
#if (DT_REAL_EN > 0)
TAN_REAL_S _TAN_REAL;
#endif

#if (DT_LREAL_EN > 0)
TAN_LREAL_S _TAN_LREAL;
#endif

/*
 * =============================================
 * ASIN
 * =============================================
*/
#if (DT_REAL_EN > 0)
ASIN_REAL_S _ASIN_REAL;
#endif

#if (DT_LREAL_EN > 0)
ASIN_LREAL_S _ASIN_LREAL;
#endif

/*
 * =============================================
 * ACOS
 * =============================================
*/
#if (DT_REAL_EN > 0)
ACOS_REAL_S _ACOS_REAL;
#endif

#if (DT_LREAL_EN > 0)
ACOS_LREAL_S _ACOS_LREAL;
#endif

/*
 * =============================================
 * ATAN
 * =============================================
*/
#if (DT_REAL_EN > 0)
ATAN_REAL_S _ATAN_REAL;
#endif

#if (DT_LREAL_EN > 0)
ATAN_LREAL_S _ATAN_LREAL;
#endif

/*
 * =============================================
 * SHL
 * =============================================
*/
SHL_BYTE_S _SHL_BYTE;

SHL_WORD_S _SHL_WORD;

SHL_DWORD_S _SHL_DWORD;

#if (DT_LWORD_EN > 0)
SHL_LWORD_S _SHL_LWORD;
#endif

/*
 * =============================================
 * SHR
 * =============================================
*/
SHR_BYTE_S _SHR_BYTE;

SHR_WORD_S _SHR_WORD;

SHR_DWORD_S _SHR_DWORD;

#if (DT_LWORD_EN > 0)
SHR_LWORD_S _SHR_LWORD;
#endif

/*
 * =============================================
 * ROR
 * =============================================
*/
ROR_BYTE_S _ROR_BYTE;

ROR_WORD_S _ROR_WORD;

ROR_DWORD_S _ROR_DWORD;

#if (DT_LWORD_EN > 0)
ROR_LWORD_S _ROR_LWORD;
#endif

/*
 * =============================================
 * ROL
 * =============================================
*/
ROL_BYTE_S _ROL_BYTE;

ROL_WORD_S _ROL_WORD;

ROL_DWORD_S _ROL_DWORD;

#if (DT_LWORD_EN > 0)
ROL_LWORD_S _ROL_LWORD;
#endif

/*
 * =============================================
 * AND
 * =============================================
*/
AND_BOOL_S _AND_BOOL;

AND_BYTE_S _AND_BYTE;

AND_WORD_S _AND_WORD;

AND_DWORD_S _AND_DWORD;

#if (DT_LWORD_EN > 0)
AND_LWORD_S _AND_LWORD;
#endif

/*
 * =============================================
 * OR
 * =============================================
*/
OR_BOOL_S _OR_BOOL;

OR_BYTE_S _OR_BYTE;

OR_WORD_S _OR_WORD;

OR_DWORD_S _OR_DWORD;

#if (DT_LWORD_EN > 0)
OR_LWORD_S _OR_LWORD;
#endif

/*
 * =============================================
 * XOR
 * =============================================
*/
XOR_BOOL_S _XOR_BOOL;

XOR_BYTE_S _XOR_BYTE;

XOR_WORD_S _XOR_WORD;

XOR_DWORD_S _XOR_DWORD;

#if (DT_LWORD_EN > 0)
XOR_LWORD_S _XOR_LWORD;
#endif

/*
 * =============================================
 * NOT
 * =============================================
*/
NOT_BOOL_S _NOT_BOOL;

NOT_BYTE_S _NOT_BYTE;

NOT_WORD_S _NOT_WORD;

NOT_DWORD_S _NOT_DWORD;

#if (DT_LWORD_EN > 0)
NOT_LWORD_S _NOT_LWORD;
#endif

/*
 * =============================================
 * SEL
 * =============================================
*/
SEL_BOOL_S _SEL_BOOL;

SEL_BYTE_S _SEL_BYTE;

SEL_WORD_S _SEL_WORD;

SEL_DWORD_S _SEL_DWORD;

#if (DT_LWORD_EN > 0)
SEL_LWORD_S _SEL_LWORD;
#endif

SEL_SINT_S _SEL_SINT;

SEL_INT_S _SEL_INT;

SEL_DINT_S _SEL_DINT;

#if (DT_LINT_EN > 0)
SEL_LINT_S _SEL_LINT;
#endif

SEL_USINT_S _SEL_USINT;

SEL_UINT_S _SEL_UINT;

SEL_UDINT_S _SEL_UDINT;

#if (DT_ULINT_EN > 0)
SEL_ULINT_S _SEL_ULINT;
#endif

#if (DT_REAL_EN > 0)
SEL_REAL_S _SEL_REAL;
#endif

#if (DT_LREAL_EN > 0)
SEL_LREAL_S _SEL_LREAL;
#endif

/*
 * =============================================
 * GT
 * =============================================
*/
GT_BOOL_S _GT_BOOL;

GT_BYTE_S _GT_BYTE;

GT_WORD_S _GT_WORD;

GT_DWORD_S _GT_DWORD;

#if (DT_LWORD_EN > 0)
GT_LWORD_S _GT_LWORD;
#endif

GT_SINT_S _GT_SINT;

GT_INT_S _GT_INT;

GT_DINT_S _GT_DINT;

#if (DT_LINT_EN > 0)
GT_LINT_S _GT_LINT;
#endif

GT_USINT_S _GT_USINT;

GT_UINT_S _GT_UINT;

GT_UDINT_S _GT_UDINT;

#if (DT_ULINT_EN > 0)
GT_ULINT_S _GT_ULINT;
#endif

#if (DT_REAL_EN > 0)
GT_REAL_S _GT_REAL;
#endif

#if (DT_LREAL_EN > 0)
GT_LREAL_S _GT_LREAL;
#endif

/*
 * =============================================
 * GE
 * =============================================
*/
GE_BOOL_S _GE_BOOL;

GE_BYTE_S _GE_BYTE;

GE_WORD_S _GE_WORD;

GE_DWORD_S _GE_DWORD;

#if (DT_LWORD_EN > 0)
GE_LWORD_S _GE_LWORD;
#endif

GE_SINT_S _GE_SINT;

GE_INT_S _GE_INT;

GE_DINT_S _GE_DINT;

#if (DT_LINT_EN > 0)
GE_LINT_S _GE_LINT;
#endif

GE_USINT_S _GE_USINT;

GE_UINT_S _GE_UINT;

GE_UDINT_S _GE_UDINT;

#if (DT_ULINT_EN > 0)
GE_ULINT_S _GE_ULINT;
#endif

#if (DT_REAL_EN > 0)
GE_REAL_S _GE_REAL;
#endif

#if (DT_LREAL_EN > 0)
GE_LREAL_S _GE_LREAL;
#endif

/*
 * =============================================
 * EQ
 * =============================================
*/
EQ_BOOL_S _EQ_BOOL;

EQ_BYTE_S _EQ_BYTE;

EQ_WORD_S _EQ_WORD;

EQ_DWORD_S _EQ_DWORD;

#if (DT_LWORD_EN > 0)
EQ_LWORD_S _EQ_LWORD;
#endif

EQ_SINT_S _EQ_SINT;

EQ_INT_S _EQ_INT;

EQ_DINT_S _EQ_DINT;

#if (DT_LINT_EN > 0)
EQ_LINT_S _EQ_LINT;
#endif

EQ_USINT_S _EQ_USINT;

EQ_UINT_S _EQ_UINT;

EQ_UDINT_S _EQ_UDINT;

#if (DT_ULINT_EN > 0)
EQ_ULINT_S _EQ_ULINT;
#endif

#if (DT_REAL_EN > 0)
EQ_REAL_S _EQ_REAL;
#endif

#if (DT_LREAL_EN > 0)
EQ_LREAL_S _EQ_LREAL;
#endif

/*
 * =============================================
 * LE
 * =============================================
*/
LE_BOOL_S _LE_BOOL;

LE_BYTE_S _LE_BYTE;

LE_WORD_S _LE_WORD;

LE_DWORD_S _LE_DWORD;

#if (DT_LWORD_EN > 0)
LE_LWORD_S _LE_LWORD;
#endif

LE_SINT_S _LE_SINT;

LE_INT_S _LE_INT;

LE_DINT_S _LE_DINT;

#if (DT_LINT_EN > 0)
LE_LINT_S _LE_LINT;
#endif

LE_USINT_S _LE_USINT;

LE_UINT_S _LE_UINT;

LE_UDINT_S _LE_UDINT;

#if (DT_ULINT_EN > 0)
LE_ULINT_S _LE_ULINT;
#endif

#if (DT_REAL_EN > 0)
LE_REAL_S _LE_REAL;
#endif

#if (DT_LREAL_EN > 0)
LE_LREAL_S _LE_LREAL;
#endif

/*
 * =============================================
 * LT
 * =============================================
*/
LT_BOOL_S _LT_BOOL;

LT_BYTE_S _LT_BYTE;

LT_WORD_S _LT_WORD;

LT_DWORD_S _LT_DWORD;

#if (DT_LWORD_EN > 0)
LT_LWORD_S _LT_LWORD;
#endif

LT_SINT_S _LT_SINT;

LT_INT_S _LT_INT;

LT_DINT_S _LT_DINT;

#if (DT_LINT_EN > 0)
LT_LINT_S _LT_LINT;
#endif

LT_USINT_S _LT_USINT;

LT_UINT_S _LT_UINT;

LT_UDINT_S _LT_UDINT;

#if (DT_ULINT_EN > 0)
LT_ULINT_S _LT_ULINT;
#endif

#if (DT_REAL_EN > 0)
LT_REAL_S _LT_REAL;
#endif

#if (DT_LREAL_EN > 0)
LT_LREAL_S _LT_LREAL;
#endif

/*
 * =============================================
 * NE
 * =============================================
*/
NE_BOOL_S _NE_BOOL;

NE_BYTE_S _NE_BYTE;

NE_WORD_S _NE_WORD;

NE_DWORD_S _NE_DWORD;

#if (DT_LWORD_EN > 0)
NE_LWORD_S _NE_LWORD;
#endif

NE_SINT_S _NE_SINT;

NE_INT_S _NE_INT;

NE_DINT_S _NE_DINT;

#if (DT_LINT_EN > 0)
NE_LINT_S _NE_LINT;
#endif

NE_USINT_S _NE_USINT;

NE_UINT_S _NE_UINT;

NE_UDINT_S _NE_UDINT;

#if (DT_ULINT_EN > 0)
NE_ULINT_S _NE_ULINT;
#endif

#if (DT_REAL_EN > 0)
NE_REAL_S _NE_REAL;
#endif

#if (DT_LREAL_EN > 0)
NE_LREAL_S _NE_LREAL;
#endif
