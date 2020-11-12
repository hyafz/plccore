/**
  * @file  plc_std_fc.h
  * @brief     plc_std_fc.c的头文件
  * @author    hyafz
  */

#ifndef _PLC_STANDARD_FC_H_
#define _PLC_STANDARD_FC_H_

#include "plc_type_define.h"
#include "plc_port.h"


typedef struct{
    SINT IN;
}SINT_TO_INT_S;
extern SINT_TO_INT_S _SINT_TO_INT;
INT _SINT_TO_INT_(void);

typedef struct{
    INT IN;
}INT_TO_SINT_S;
extern INT_TO_SINT_S _INT_TO_SINT;
SINT _INT_TO_SINT_(void);


typedef struct{
    INT IN;
}INT_TO_DINT_S;
extern INT_TO_DINT_S _INT_TO_DINT;
DINT _INT_TO_DINT_(void);

typedef struct{
    DINT IN;
}DINT_TO_INT_S;
extern DINT_TO_INT_S _DINT_TO_INT;
INT _DINT_TO_INT_(void);

#if (DT_LINT_EN > 0)
typedef struct{
    DINT IN;
}DINT_TO_LINT_S;
extern DINT_TO_LINT_S _DINT_TO_LINT;
LINT _DINT_TO_LINT_(void);

typedef struct{
    LINT in;
}LINT_TO_DINT_S;
extern LINT_TO_DINT_S _LINT_TO_DINT;
DINT _LINT_TO_DINT_(void);
#endif

typedef struct{
    USINT IN;
}USINT_TO_UINT_S;
extern USINT_TO_UINT_S _USINT_TO_UINT;
UINT _USINT_TO_UINT_(void);

typedef struct{
    UINT IN;
}UINT_TO_USINT_S;
extern UINT_TO_USINT_S _UINT_TO_USINT;
USINT _UINT_TO_USINT_(void);


typedef struct{
    UINT IN;
}UINT_TO_UDINT_S;
extern UINT_TO_UDINT_S _UINT_TO_UDINT;
UDINT _UINT_TO_UDINT_(void);

typedef struct{
    UDINT IN;
}UDINT_TO_UINT_S;
extern UDINT_TO_UINT_S _UDINT_TO_UINT;
UINT _UDINT_TO_UINT_(void);

#if (DT_ULINT_EN > 0)
typedef struct{
    UDINT IN;
}UDINT_TO_ULINT_S;
extern UDINT_TO_ULINT_S _UDINT_TO_ULINT;
ULINT _UDINT_TO_ULINT_(void);

typedef struct{
    ULINT IN;
}ULINT_TO_UDINT_S;
extern ULINT_TO_UDINT_S _ULINT_TO_UDINT;
UDINT _ULINT_TO_UDINT_(void);
#endif

typedef struct{
    USINT IN;
}USINT_TO_SINT_S;
extern USINT_TO_SINT_S _USINT_TO_SINT;
SINT _USINT_TO_SINT_(void);

typedef struct{
    SINT IN;
}SINT_TO_USINT_S;
extern SINT_TO_USINT_S _SINT_TO_USINT;
USINT _SINT_TO_USINT_(void);


typedef struct{
    UINT IN;
}UINT_TO_INT_S;
extern UINT_TO_INT_S _UINT_TO_INT;
INT _UINT_TO_INT_(void);

typedef struct{
    INT IN;
}INT_TO_UINT_S;
extern INT_TO_UINT_S _INT_TO_UINT;
UINT _INT_TO_UINT_(void);


typedef struct{
    UDINT IN;
}UDINT_TO_DINT_S;
extern UDINT_TO_DINT_S _UDINT_TO_DINT;
DINT _UDINT_TO_DINT_(void);

typedef struct{
    DINT IN;
}DINT_TO_UDINT_S;
extern DINT_TO_UDINT_S _DINT_TO_UDINT;
UDINT _DINT_TO_UDINT_(void);

#if ((DT_ULINT_EN > 0) && (DT_LINT_EN > 0))
typedef struct{
    ULINT IN;
}ULINT_TO_LINT_S;
extern ULINT_TO_LINT_S _ULINT_TO_LINT;
LINT _ULINT_TO_LINT_(void);

typedef struct{
    LINT IN;
}LINT_TO_ULINT_S;
extern LINT_TO_ULINT_S _LINT_TO_ULINT;
ULINT _LINT_TO_ULINT_(void);
#endif

typedef struct{
    BOOL IN;
}BOOL_TO_BYTE_S;
extern BOOL_TO_BYTE_S _BOOL_TO_BYTE;
BYTE _BOOL_TO_BYTE_(void);

typedef struct{
    BYTE IN;
}BYTE_TO_BOOL_S;
extern BYTE_TO_BOOL_S _BYTE_TO_BOOL;
BOOL _BYTE_TO_BOOL_(void);


typedef struct{
    BYTE IN;
}BYTE_TO_WORD_S;
extern BYTE_TO_WORD_S _BYTE_TO_WORD;
WORD _BYTE_TO_WORD_(void);

typedef struct{
    WORD IN;
}WORD_TO_BYTE_S;
extern WORD_TO_BYTE_S _WORD_TO_BYTE;
BYTE _WORD_TO_BYTE_(void);


typedef struct{
    WORD IN;
}WORD_TO_DWORD_S;
extern WORD_TO_DWORD_S _WORD_TO_DWORD;
DWORD _WORD_TO_DWORD_(void);

typedef struct{
    DWORD IN;
}DWORD_TO_WORD_S;
extern DWORD_TO_WORD_S _DWORD_TO_WORD;
WORD _DWORD_TO_WORD_(void);

#if (DT_LWORD_EN > 0)
typedef struct{
    DWORD IN;
}DWORD_TO_LWORD_S;
extern DWORD_TO_LWORD_S _DWORD_TO_LWORD;
LWORD _DWORD_TO_LWORD_(void);

typedef struct{
    LWORD IN;
}LWORD_TO_DWORD_S;
extern LWORD_TO_DWORD_S _LWORD_TO_DWORD;
DWORD _LWORD_TO_DWORD_(void);
#endif


typedef struct{
    BYTE IN;
}BYTE_TO_USINT_S;
extern BYTE_TO_USINT_S _BYTE_TO_USINT;
USINT _BYTE_TO_USINT_(void);

typedef struct{
    USINT IN;
}USINT_TO_BYTE_S;
extern USINT_TO_BYTE_S _USINT_TO_BYTE;
BYTE _USINT_TO_BYTE_(void);

typedef struct{
    WORD IN;
}WORD_TO_UINT_S;
extern WORD_TO_UINT_S _WORD_TO_UINT;
UINT _WORD_TO_UINT_(void);

typedef struct{
    UINT IN;
}UINT_TO_WORD_S;
extern UINT_TO_WORD_S _UINT_TO_WORD;
WORD _UINT_TO_WORD_(void);

typedef struct{
    DWORD IN;
}DWORD_TO_UDINT_S;
extern DWORD_TO_UDINT_S _DWORD_TO_UDINT;
UDINT _DWORD_TO_UDINT_(void);

typedef struct{
    UDINT IN;
}UDINT_TO_DWORD_S;
extern UDINT_TO_DWORD_S _UDINT_TO_DWORD;
DWORD _UDINT_TO_DWORD_(void);

#if ((DT_ULINT_EN > 0) && (DT_LWORD_EN > 0))
typedef struct{
    LWORD IN;
}LWORD_TO_ULINT_S;
extern LWORD_TO_ULINT_S _LWORD_TO_ULINT;
ULINT _LWORD_TO_ULINT_(void);

typedef struct{
    ULINT IN;
}ULINT_TO_LWORD_S;
extern ULINT_TO_LWORD_S _ULINT_TO_LWORD;
LWORD _ULINT_TO_LWORD_(void);
#endif

#if (DT_REAL_EN > 0)
typedef struct{
    REAL IN;
}REAL_TO_DINT_S;
extern REAL_TO_DINT_S _REAL_TO_DINT;
DINT _REAL_TO_DINT_(void);

typedef struct{
    DINT IN;
}DINT_TO_REAL_S;
extern DINT_TO_REAL_S _DINT_TO_REAL;
REAL _DINT_TO_REAL_(void);
#endif

#if ((DT_LINT_EN > 0) && (DT_LREAL_EN > 0))
typedef struct{
    LREAL IN;
}LREAL_TO_LINT_S;

extern LREAL_TO_LINT_S _LREAL_TO_LINT;
LINT _LREAL_TO_LINT_(void);

typedef struct{
    LINT IN;
}LINT_TO_LREAL_S;
extern LINT_TO_LREAL_S _LINT_TO_LREAL;
LREAL _LINT_TO_LREAL_(void);

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
SINT _ADD_SINT_(void);

typedef struct{
    INT IN1;
    INT IN2;
}ADD_INT_S;
extern ADD_INT_S _ADD_INT;
INT _ADD_INT_(void);

typedef struct{
    DINT IN1;
    DINT IN2;
}ADD_DINT_S;
extern ADD_DINT_S _ADD_DINT;
DINT _ADD_DINT_(void);

#if (DT_LINT_EN > 0)
typedef struct{
    LINT IN1;
    LINT IN2;
}ADD_LINT_S;
extern ADD_LINT_S _ADD_LINT;
LINT _ADD_LINT_(void);
#endif

typedef struct{
    USINT IN1;
    USINT IN2;
}ADD_USINT_S;
extern ADD_USINT_S _ADD_USINT;
USINT _ADD_USINT_(void);

typedef struct{
    UINT IN1;
    UINT IN2;
}ADD_UINT_S;
extern ADD_UINT_S _ADD_UINT;
UINT _ADD_UINT_(void);

typedef struct{
    UDINT IN1;
    UDINT IN2;
}ADD_UDINT_S;
extern ADD_UDINT_S _ADD_UDINT;
UDINT _ADD_UDINT_(void);

#if (DT_LINT_EN > 0)
typedef struct{
    ULINT IN1;
    ULINT IN2;
}ADD_ULINT_S;
extern ADD_ULINT_S _ADD_ULINT;
ULINT _ADD_ULINT_(void);
#endif

#if (DT_REAL_EN > 0)
typedef struct{
    REAL IN1;
    REAL IN2;
}ADD_REAL_S;
extern ADD_REAL_S _ADD_REAL;
REAL _ADD_REAL_(void);
#endif

#if (DT_LREAL_EN > 0)
typedef struct{
    LREAL IN1;
    LREAL IN2;
}ADD_LREAL_S;
extern ADD_LREAL_S _ADD_LREAL;
LREAL _ADD_LREAL_(void);
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
SINT _SUB_SINT_(void);

typedef struct{
    INT IN1;
    INT IN2;
}SUB_INT_S;
extern SUB_INT_S _SUB_INT;
INT _SUB_INT_(void);

typedef struct{
    DINT IN1;
    DINT IN2;
}SUB_DINT_S;
extern SUB_DINT_S _SUB_DINT;
DINT _SUB_DINT_(void);

#if (DT_LINT_EN > 0)
typedef struct{
    LINT IN1;
    LINT IN2;
}SUB_LINT_S;
extern SUB_LINT_S _SUB_LINT;
LINT _SUB_LINT_(void);
#endif

typedef struct{
    USINT IN1;
    USINT IN2;
}SUB_USINT_S;
extern SUB_USINT_S _SUB_USINT;
USINT _SUB_USINT_(void);

typedef struct{
    UINT IN1;
    UINT IN2;
}SUB_UINT_S;
extern SUB_UINT_S _SUB_UINT;
UINT _SUB_UINT_(void);

typedef struct{
    UDINT IN1;
    UDINT IN2;
}SUB_UDINT_S;
extern SUB_UDINT_S _SUB_UDINT;
UDINT _SUB_UDINT_(void);

#if (DT_LINT_EN > 0)
typedef struct{
    ULINT IN1;
    ULINT IN2;
}SUB_ULINT_S;
extern SUB_ULINT_S _SUB_ULINT;
ULINT _SUB_ULINT_(void);
#endif

#if (DT_REAL_EN > 0)
typedef struct{
    REAL IN1;
    REAL IN2;
}SUB_REAL_S;
extern SUB_REAL_S _SUB_REAL;
REAL _SUB_REAL_(void);
#endif

#if (DT_LREAL_EN > 0)
typedef struct{
    LREAL IN1;
    LREAL IN2;
}SUB_LREAL_S;
extern SUB_LREAL_S _SUB_LREAL;
LREAL _SUB_LREAL_(void);
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
SINT _MUL_SINT_(void);

typedef struct{
    INT IN1;
    INT IN2;
}MUL_INT_S;
extern MUL_INT_S _MUL_INT;
INT _MUL_INT_(void);

typedef struct{
    DINT IN1;
    DINT IN2;
}MUL_DINT_S;
extern MUL_DINT_S _MUL_DINT;
DINT _MUL_DINT_(void);

#if (DT_LINT_EN > 0)
typedef struct{
    LINT IN1;
    LINT IN2;
}MUL_LINT_S;
extern MUL_LINT_S _MUL_LINT;
LINT _MUL_LINT_(void);
#endif

typedef struct{
    USINT IN1;
    USINT IN2;
}MUL_USINT_S;
extern MUL_USINT_S _MUL_USINT;
USINT _MUL_USINT_(void);

typedef struct{
    UINT IN1;
    UINT IN2;
}MUL_UINT_S;
extern MUL_UINT_S _MUL_UINT;
UINT _MUL_UINT_(void);

typedef struct{
    UDINT IN1;
    UDINT IN2;
}MUL_UDINT_S;
extern MUL_UDINT_S _MUL_UDINT;
UDINT _MUL_UDINT_(void);

#if (DT_LINT_EN > 0)
typedef struct{
    ULINT IN1;
    ULINT IN2;
}MUL_ULINT_S;
extern MUL_ULINT_S _MUL_ULINT;
ULINT _MUL_ULINT_(void);
#endif

#if (DT_REAL_EN > 0)
typedef struct{
    REAL IN1;
    REAL IN2;
}MUL_REAL_S;
extern MUL_REAL_S _MUL_REAL;
REAL _MUL_REAL_(void);
#endif

#if (DT_LREAL_EN > 0)
typedef struct{
    LREAL IN1;
    LREAL IN2;
}MUL_LREAL_S;
extern MUL_LREAL_S _MUL_LREAL;
LREAL _MUL_LREAL_(void);
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
SINT _DIV_SINT_(void);

typedef struct{
    INT IN1;
    INT IN2;
}DIV_INT_S;
extern DIV_INT_S _DIV_INT;
INT _DIV_INT_(void);

typedef struct{
    DINT IN1;
    DINT IN2;
}DIV_DINT_S;
extern DIV_DINT_S _DIV_DINT;
DINT _DIV_DINT_(void);

#if (DT_LINT_EN > 0)
typedef struct{
    LINT IN1;
    LINT IN2;
}DIV_LINT_S;
extern DIV_LINT_S _DIV_LINT;
LINT _DIV_LINT_(void);
#endif

typedef struct{
    USINT IN1;
    USINT IN2;
}DIV_USINT_S;
extern DIV_USINT_S _DIV_USINT;
USINT _DIV_USINT_(void);

typedef struct{
    UINT IN1;
    UINT IN2;
}DIV_UINT_S;
extern DIV_UINT_S _DIV_UINT;
UINT _DIV_UINT_(void);

typedef struct{
    UDINT IN1;
    UDINT IN2;
}DIV_UDINT_S;
extern DIV_UDINT_S _DIV_UDINT;
UDINT _DIV_UDINT_(void);

#if (DT_LINT_EN > 0)
typedef struct{
    ULINT IN1;
    ULINT IN2;
}DIV_ULINT_S;
extern DIV_ULINT_S _DIV_ULINT;
ULINT _DIV_ULINT_(void);
#endif

#if (DT_REAL_EN > 0)
typedef struct{
    REAL IN1;
    REAL IN2;
}DIV_REAL_S;
extern DIV_REAL_S _DIV_REAL;
REAL _DIV_REAL_(void);
#endif

#if (DT_LREAL_EN > 0)
typedef struct{
    LREAL IN1;
    LREAL IN2;
}DIV_LREAL_S;
extern DIV_LREAL_S _DIV_LREAL;
LREAL _DIV_LREAL_(void);
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
SINT _MOD_SINT_(void);

typedef struct{
    INT IN1;
    INT IN2;
}MOD_INT_S;
extern MOD_INT_S _MOD_INT;
INT _MOD_INT_(void);

typedef struct{
    DINT IN1;
    DINT IN2;
}MOD_DINT_S;
extern MOD_DINT_S _MOD_DINT;
DINT _MOD_DINT_(void);

#if (DT_LINT_EN > 0)
typedef struct{
    LINT IN1;
    LINT IN2;
}MOD_LINT_S;
extern MOD_LINT_S _MOD_LINT;
LINT _MOD_LINT_(void);
#endif

typedef struct{
    USINT IN1;
    USINT IN2;
}MOD_USINT_S;
extern MOD_USINT_S _MOD_USINT;
USINT _MOD_USINT_(void);

typedef struct{
    UINT IN1;
    UINT IN2;
}MOD_UINT_S;
extern MOD_UINT_S _MOD_UINT;
UINT _MOD_UINT_(void);

typedef struct{
    UDINT IN1;
    UDINT IN2;
}MOD_UDINT_S;
extern MOD_UDINT_S _MOD_UDINT;
UDINT _MOD_UDINT_(void);

#if (DT_LINT_EN > 0)
typedef struct{
    ULINT IN1;
    ULINT IN2;
}MOD_ULINT_S;
extern MOD_ULINT_S _MOD_ULINT;
ULINT _MOD_ULINT_(void);
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
REAL _EXPT_REAL_(void);
#endif

#if (DT_LREAL_EN > 0)
typedef struct{
    LREAL IN1;
    LREAL IN2;
}EXPT_LREAL_S;
extern EXPT_LREAL_S _EXPT_LREAL;
LREAL _EXPT_LREAL_(void);
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
BOOL _MOVE_BOOL_(void);

typedef struct{
    BYTE IN;
}MOVE_BYTE_S;
extern MOVE_BYTE_S _MOVE_BYTE;
BYTE _MOVE_BYTE_(void);

typedef struct{
    WORD IN;
}MOVE_WORD_S;
extern MOVE_WORD_S _MOVE_WORD;
WORD _MOVE_WORD_(void);

typedef struct{
    DWORD IN;
}MOVE_DWORD_S;
extern MOVE_DWORD_S _MOVE_DWORD;
DWORD _MOVE_DWORD_(void);

#if (DT_LWORD_EN > 0)
typedef struct{
    LWORD IN;
}MOVE_LWORD_S;
extern MOVE_LWORD_S _MOVE_LWORD;
LWORD _MOVE_LWORD_(void);
#endif

typedef struct{
    SINT IN;
}MOVE_SINT_S;
extern MOVE_SINT_S _MOVE_SINT;
SINT _MOVE_SINT_(void);

typedef struct{
    INT IN;
}MOVE_INT_S;
extern MOVE_INT_S _MOVE_INT;
INT _MOVE_INT_(void);

typedef struct{
    DINT IN;
}MOVE_DINT_S;
extern MOVE_DINT_S _MOVE_DINT;
DINT _MOVE_DINT_(void);

#if (DT_LINT_EN > 0)
typedef struct{
    LINT IN;
}MOVE_LINT_S;
extern MOVE_LINT_S _MOVE_LINT;
LINT _MOVE_LINT_(void);
#endif

typedef struct{
    USINT IN;
}MOVE_USINT_S;
extern MOVE_USINT_S _MOVE_USINT;
USINT _MOVE_USINT_(void);

typedef struct{
    UINT IN;
}MOVE_UINT_S;
extern MOVE_UINT_S _MOVE_UINT;
UINT _MOVE_UINT_(void);

typedef struct{
    UDINT IN;
}MOVE_UDINT_S;
extern MOVE_UDINT_S _MOVE_UDINT;
UDINT _MOVE_UDINT_(void);

#if (DT_LINT_EN > 0)
typedef struct{
    ULINT IN;
}MOVE_ULINT_S;
extern MOVE_ULINT_S _MOVE_ULINT;
ULINT _MOVE_ULINT_(void);
#endif

#if (DT_REAL_EN > 0)
typedef struct{
    REAL IN;
}MOVE_REAL_S;
extern MOVE_REAL_S _MOVE_REAL;
REAL _MOVE_REAL_(void);
#endif

#if (DT_LREAL_EN > 0)
typedef struct{
    LREAL IN;
}MOVE_LREAL_S;
extern MOVE_LREAL_S _MOVE_LREAL;
LREAL _MOVE_LREAL_(void);
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
SINT _ABS_SINT_(void);

typedef struct{
    INT IN;
}ABS_INT_S;
extern ABS_INT_S _ABS_INT;
INT _ABS_INT_(void);

typedef struct{
    DINT IN;
}ABS_DINT_S;
extern ABS_DINT_S _ABS_DINT;
DINT _ABS_DINT_(void);

#if (DT_LINT_EN > 0)
typedef struct{
    LINT IN;
}ABS_LINT_S;
extern ABS_LINT_S _ABS_LINT;
LINT _ABS_LINT_(void);
#endif

typedef struct{
    USINT IN;
}ABS_USINT_S;
extern ABS_USINT_S _ABS_USINT;
USINT _ABS_USINT_(void);

typedef struct{
    UINT IN;
}ABS_UINT_S;
extern ABS_UINT_S _ABS_UINT;
UINT _ABS_UINT_(void);

typedef struct{
    UDINT IN;
}ABS_UDINT_S;
extern ABS_UDINT_S _ABS_UDINT;
UDINT _ABS_UDINT_(void);

#if (DT_LINT_EN > 0)
typedef struct{
    ULINT IN;
}ABS_ULINT_S;
extern ABS_ULINT_S _ABS_ULINT;
ULINT _ABS_ULINT_(void);
#endif

#if (DT_REAL_EN > 0)
typedef struct{
    REAL IN;
}ABS_REAL_S;
extern ABS_REAL_S _ABS_REAL;
REAL _ABS_REAL_(void);
#endif

#if (DT_LREAL_EN > 0)
typedef struct{
    LREAL IN;
}ABS_LREAL_S;
extern ABS_LREAL_S _ABS_LREAL;
LREAL _ABS_LREAL_(void);
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
REAL _SQRT_REAL_(void);
#endif

#if (DT_LREAL_EN > 0)
typedef struct{
    LREAL IN;
}SQRT_LREAL_S;
extern SQRT_LREAL_S _SQRT_LREAL;
LREAL _SQRT_LREAL_(void);
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
REAL _LN_REAL_(void);
#endif

#if (DT_LREAL_EN > 0)
typedef struct{
    LREAL IN;
}LN_LREAL_S;
extern LN_LREAL_S _LN_LREAL;
LREAL _LN_LREAL_(void);
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
REAL _LOG_REAL_(void);
#endif

#if (DT_LREAL_EN > 0)
typedef struct{
    LREAL IN;
}LOG_LREAL_S;
extern LOG_LREAL_S _LOG_LREAL;
LREAL _LOG_LREAL_(void);
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
REAL _EXP_REAL_(void);
#endif

#if (DT_LREAL_EN > 0)
typedef struct{
    LREAL IN;
}EXP_LREAL_S;
extern EXP_LREAL_S _EXP_LREAL;
LREAL _EXP_LREAL_(void);
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
REAL _SIN_REAL_(void);
#endif

#if (DT_LREAL_EN > 0)
typedef struct{
    LREAL IN;
}SIN_LREAL_S;
extern SIN_LREAL_S _SIN_LREAL;
LREAL _SIN_LREAL_(void);
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
REAL _COS_REAL_(void);
#endif

#if (DT_LREAL_EN > 0)
typedef struct{
    LREAL IN;
}COS_LREAL_S;
extern COS_LREAL_S _COS_LREAL;
LREAL _COS_LREAL_(void);
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
REAL _TAN_REAL_(void);
#endif

#if (DT_LREAL_EN > 0)
typedef struct{
    LREAL IN;
}TAN_LREAL_S;
extern TAN_LREAL_S _TAN_LREAL;
LREAL _TAN_LREAL_(void);
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
REAL _ASIN_REAL_(void);
#endif

#if (DT_LREAL_EN > 0)
typedef struct{
    LREAL IN;
}ASIN_LREAL_S;
extern ASIN_LREAL_S _ASIN_LREAL;
LREAL _ASIN_LREAL_(void);
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
REAL _ACOS_REAL_(void);
#endif

#if (DT_LREAL_EN > 0)
typedef struct{
    LREAL IN;
}ACOS_LREAL_S;
extern ACOS_LREAL_S _ACOS_LREAL;
LREAL _ACOS_LREAL_(void);
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
REAL _ATAN_REAL_(void);
#endif

#if (DT_LREAL_EN > 0)
typedef struct{
    LREAL IN;
}ATAN_LREAL_S;
extern ATAN_LREAL_S _ATAN_LREAL;
LREAL _ATAN_LREAL_(void);
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
BYTE _SHL_BYTE_(void);

typedef struct{
    WORD IN;
    DINT N;
}SHL_WORD_S;
extern SHL_WORD_S _SHL_WORD;
WORD _SHL_WORD_(void);

typedef struct{
    DWORD IN;
    DINT N;
}SHL_DWORD_S;
extern SHL_DWORD_S _SHL_DWORD;
DWORD _SHL_DWORD_(void);

#if (DT_LWORD_EN > 0)
typedef struct{
    LWORD IN;
    DINT N;
}SHL_LWORD_S;
extern SHL_LWORD_S _SHL_LWORD;
LWORD _SHL_LWORD_(void);
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
BYTE _SHR_BYTE_(void);

typedef struct{
    WORD IN;
    DINT N;
}SHR_WORD_S;
extern SHR_WORD_S _SHR_WORD;
WORD _SHR_WORD_(void);

typedef struct{
    DWORD IN;
    DINT N;
}SHR_DWORD_S;
extern SHR_DWORD_S _SHR_DWORD;
DWORD _SHR_DWORD_(void);

#if (DT_LWORD_EN > 0)
typedef struct{
    LWORD IN;
    DINT N;
}SHR_LWORD_S;
extern SHR_LWORD_S _SHR_LWORD;
LWORD _SHR_LWORD_(void);
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
BYTE _ROR_BYTE_(void);

typedef struct{
    WORD IN;
    DINT N;
}ROR_WORD_S;
extern ROR_WORD_S _ROR_WORD;
WORD _ROR_WORD_(void);

typedef struct{
    DWORD IN;
    DINT N;
}ROR_DWORD_S;
extern ROR_DWORD_S _ROR_DWORD;
DWORD _ROR_DWORD_(void);

#if (DT_LWORD_EN > 0)
typedef struct{
    LWORD IN;
    DINT N;
}ROR_LWORD_S;
extern ROR_LWORD_S _ROR_LWORD;
LWORD _ROR_LWORD_(void);
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
BYTE _ROL_BYTE_(void);

typedef struct{
    WORD IN;
    DINT N;
}ROL_WORD_S;
extern ROL_WORD_S _ROL_WORD;
WORD _ROL_WORD_(void);

typedef struct{
    DWORD IN;
    DINT N;
}ROL_DWORD_S;
extern ROL_DWORD_S _ROL_DWORD;
DWORD _ROL_DWORD_(void);

#if (DT_LWORD_EN > 0)
typedef struct{
    LWORD IN;
    DINT N;
}ROL_LWORD_S;
extern ROL_LWORD_S _ROL_LWORD;
LWORD _ROL_LWORD_(void);
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
BOOL _AND_BOOL_(void);

typedef struct{
    BYTE IN1;
    BYTE IN2;
}AND_BYTE_S;
extern AND_BYTE_S _AND_BYTE;
BYTE _AND_BYTE_(void);

typedef struct{
    WORD IN1;
    WORD IN2;
}AND_WORD_S;
extern AND_WORD_S _AND_WORD;
WORD _AND_WORD_(void);

typedef struct{
    DWORD IN1;
    DWORD IN2;
}AND_DWORD_S;
extern AND_DWORD_S _AND_DWORD;
DWORD _AND_DWORD_(void);

#if (DT_LWORD_EN > 0)
typedef struct{
    LWORD IN1;
    LWORD IN2;
}AND_LWORD_S;
extern AND_LWORD_S _AND_LWORD;
LWORD _AND_LWORD_(void);
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
BOOL _OR_BOOL_(void);

typedef struct{
    BYTE IN1;
    BYTE IN2;
}OR_BYTE_S;
extern OR_BYTE_S _OR_BYTE;
BYTE _OR_BYTE_(void);

typedef struct{
    WORD IN1;
    WORD IN2;
}OR_WORD_S;
extern OR_WORD_S _OR_WORD;
WORD _OR_WORD_(void);

typedef struct{
    DWORD IN1;
    DWORD IN2;
}OR_DWORD_S;
extern OR_DWORD_S _OR_DWORD;
DWORD _OR_DWORD_(void);

#if (DT_LWORD_EN > 0)
typedef struct{
    LWORD IN1;
    LWORD IN2;
}OR_LWORD_S;
extern OR_LWORD_S _OR_LWORD;
LWORD _OR_LWORD_(void);
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
BOOL _XOR_BOOL_(void);

typedef struct{
    BYTE IN1;
    BYTE IN2;
}XOR_BYTE_S;
extern XOR_BYTE_S _XOR_BYTE;
BYTE _XOR_BYTE_(void);

typedef struct{
    WORD IN1;
    WORD IN2;
}XOR_WORD_S;
extern XOR_WORD_S _XOR_WORD;
WORD _XOR_WORD_(void);

typedef struct{
    DWORD IN1;
    DWORD IN2;
}XOR_DWORD_S;
extern XOR_DWORD_S _XOR_DWORD;
DWORD _XOR_DWORD_(void);

#if (DT_LWORD_EN > 0)
typedef struct{
    LWORD IN1;
    LWORD IN2;
}XOR_LWORD_S;
extern XOR_LWORD_S _XOR_LWORD;
LWORD _XOR_LWORD_(void);
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
BOOL _NOT_BOOL_(void);

typedef struct{
    BYTE IN1;
}NOT_BYTE_S;
extern NOT_BYTE_S _NOT_BYTE;
BYTE _NOT_BYTE_(void);

typedef struct{
    WORD IN1;
}NOT_WORD_S;
extern NOT_WORD_S _NOT_WORD;
WORD _NOT_WORD_(void);

typedef struct{
    DWORD IN1;
}NOT_DWORD_S;
extern NOT_DWORD_S _NOT_DWORD;
DWORD _NOT_DWORD_(void);

#if (DT_LWORD_EN > 0)
typedef struct{
    LWORD IN1;
}NOT_LWORD_S;
extern NOT_LWORD_S _NOT_LWORD;
LWORD _NOT_LWORD_(void);
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
BOOL _SEL_BOOL_(void);

typedef struct{
    BOOL G;
    BYTE IN0;
    BYTE IN1;
}SEL_BYTE_S;
extern SEL_BYTE_S _SEL_BYTE;
BYTE _SEL_BYTE_(void);

typedef struct{
    BOOL G;
    WORD IN0;
    WORD IN1;
}SEL_WORD_S;
extern SEL_WORD_S _SEL_WORD;
WORD _SEL_WORD_(void);

typedef struct{
    BOOL G;
    DWORD IN0;
    DWORD IN1;
}SEL_DWORD_S;
extern SEL_DWORD_S _SEL_DWORD;
DWORD _SEL_DWORD_(void);

#if (DT_LWORD_EN > 0)
typedef struct{
    BOOL G;
    LWORD IN0;
    LWORD IN1;
}SEL_LWORD_S;
extern SEL_LWORD_S _SEL_LWORD;
LWORD _SEL_LWORD_(void);
#endif

typedef struct{
    BOOL G;
    SINT IN0;
    SINT IN1;
}SEL_SINT_S;
extern SEL_SINT_S _SEL_SINT;
SINT _SEL_SINT_(void);

typedef struct{
    BOOL G;
    INT IN0;
    INT IN1;
}SEL_INT_S;
extern SEL_INT_S _SEL_INT;
INT _SEL_INT_(void);

typedef struct{
    BOOL G;
    DINT IN0;
    DINT IN1;
}SEL_DINT_S;
extern SEL_DINT_S _SEL_DINT;
DINT _SEL_DINT_(void);

#if (DT_LINT_EN > 0)
typedef struct{
    BOOL G;
    LINT IN0;
    BOOL IN1;
}SEL_LINT_S;
extern SEL_LINT_S _SEL_LINT;
LINT _SEL_LINT_(void);
#endif

typedef struct{
    BOOL G;
    USINT IN0;
    USINT IN1;
}SEL_USINT_S;
extern SEL_USINT_S _SEL_USINT;
USINT _SEL_USINT_(void);

typedef struct{
    BOOL G;
    UINT IN0;
    UINT IN1;
}SEL_UINT_S;
extern SEL_UINT_S _SEL_UINT;
UINT _SEL_UINT_(void);

typedef struct{
    BOOL G;
    UDINT IN0;
    UDINT IN1;
}SEL_UDINT_S;
extern SEL_UDINT_S _SEL_UDINT;
UDINT _SEL_UDINT_(void);

#if (DT_LINT_EN > 0)
typedef struct{
    BOOL G;
    ULINT IN0;
    ULINT IN1;
}SEL_ULINT_S;
extern SEL_ULINT_S _SEL_ULINT;
ULINT _SEL_ULINT_(void);
#endif

#if (DT_REAL_EN > 0)
typedef struct{
    BOOL G;
    REAL IN0;
    REAL IN1;
}SEL_REAL_S;
extern SEL_REAL_S _SEL_REAL;
REAL _SEL_REAL_(void);
#endif

#if (DT_LREAL_EN > 0)
typedef struct{
    BOOL G;
    LREAL IN0;
    LREAL IN1;
}SEL_LREAL_S;
extern SEL_LREAL_S _SEL_LREAL;
LREAL _SEL_LREAL_(void);
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
BOOL _GT_BOOL_(void);

typedef struct{
    BYTE IN1;
    BYTE IN2;
}GT_BYTE_S;
extern GT_BYTE_S _GT_BYTE;
BOOL _GT_BYTE_(void);

typedef struct{
    WORD IN1;
    WORD IN2;
}GT_WORD_S;
extern GT_WORD_S _GT_WORD;
BOOL _GT_WORD_(void);

typedef struct{
    DWORD IN0;
    DWORD IN1;
}GT_DWORD_S;
extern GT_DWORD_S _GT_DWORD;
BOOL _GT_DWORD_(void);

#if (DT_LWORD_EN > 0)
typedef struct{
    LWORD IN1;
    LWORD IN2;
}GT_LWORD_S;
extern GT_LWORD_S _GT_LWORD;
BOOL _GT_LWORD_(void);
#endif

typedef struct{
    SINT IN1;
    SINT IN2;
}GT_SINT_S;
extern GT_SINT_S _GT_SINT;
BOOL _GT_SINT_(void);

typedef struct{
    INT IN1;
    INT IN2;
}GT_INT_S;
extern GT_INT_S _GT_INT;
BOOL _GT_INT_(void);

typedef struct{
    DINT IN1;
    DINT IN2;
}GT_DINT_S;
extern GT_DINT_S _GT_DINT;
BOOL _GT_DINT_(void);

#if (DT_LINT_EN > 0)
typedef struct{
    LINT IN1;
    BOOL IN2;
}GT_LINT_S;
extern GT_LINT_S _GT_LINT;
BOOL _GT_LINT_(void);
#endif

typedef struct{
    USINT IN1;
    USINT IN2;
}GT_USINT_S;
extern GT_USINT_S _GT_USINT;
BOOL _GT_USINT_(void);

typedef struct{
    UINT IN1;
    UINT IN2;
}GT_UINT_S;
extern GT_UINT_S _GT_UINT;
BOOL _GT_UINT_(void);

typedef struct{
    UDINT IN1;
    UDINT IN2;
}GT_UDINT_S;
extern GT_UDINT_S _GT_UDINT;
BOOL _GT_UDINT_(void);

#if (DT_LINT_EN > 0)
typedef struct{
    ULINT IN1;
    ULINT IN2;
}GT_ULINT_S;
extern GT_ULINT_S _GT_ULINT;
BOOL _GT_ULINT_(void);
#endif

#if (DT_REAL_EN > 0)
typedef struct{
    REAL IN1;
    REAL IN2;
}GT_REAL_S;
extern GT_REAL_S _GT_REAL;
BOOL _GT_REAL_(void);
#endif

#if (DT_LREAL_EN > 0)
typedef struct{
    LREAL IN1;
    LREAL IN2;
}GT_LREAL_S;
extern GT_LREAL_S _GT_LREAL;
BOOL _GT_LREAL_(void);
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
BOOL _GE_BOOL_(void);

typedef struct{
    BYTE IN1;
    BYTE IN2;
}GE_BYTE_S;
extern GE_BYTE_S _GE_BYTE;
BOOL _GE_BYTE_(void);

typedef struct{
    WORD IN1;
    WORD IN2;
}GE_WORD_S;
extern GE_WORD_S _GE_WORD;
BOOL _GE_WORD_(void);

typedef struct{
    DWORD IN0;
    DWORD IN1;
}GE_DWORD_S;
extern GE_DWORD_S _GE_DWORD;
BOOL _GE_DWORD_(void);

#if (DT_LWORD_EN > 0)
typedef struct{
    LWORD IN1;
    LWORD IN2;
}GE_LWORD_S;
extern GE_LWORD_S _GE_LWORD;
BOOL _GE_LWORD_(void);
#endif

typedef struct{
    SINT IN1;
    SINT IN2;
}GE_SINT_S;
extern GE_SINT_S _GE_SINT;
BOOL _GE_SINT_(void);

typedef struct{
    INT IN1;
    INT IN2;
}GE_INT_S;
extern GE_INT_S _GE_INT;
BOOL _GE_INT_(void);

typedef struct{
    DINT IN1;
    DINT IN2;
}GE_DINT_S;
extern GE_DINT_S _GE_DINT;
BOOL _GE_DINT_(void);

#if (DT_LINT_EN > 0)
typedef struct{
    LINT IN1;
    BOOL IN2;
}GE_LINT_S;
extern GE_LINT_S _GE_LINT;
BOOL _GE_LINT_(void);
#endif

typedef struct{
    USINT IN1;
    USINT IN2;
}GE_USINT_S;
extern GE_USINT_S _GE_USINT;
BOOL _GE_USINT_(void);

typedef struct{
    UINT IN1;
    UINT IN2;
}GE_UINT_S;
extern GE_UINT_S _GE_UINT;
BOOL _GE_UINT_(void);

typedef struct{
    UDINT IN1;
    UDINT IN2;
}GE_UDINT_S;
extern GE_UDINT_S _GE_UDINT;
BOOL _GE_UDINT_(void);

#if (DT_LINT_EN > 0)
typedef struct{
    ULINT IN1;
    ULINT IN2;
}GE_ULINT_S;
extern GE_ULINT_S _GE_ULINT;
BOOL _GE_ULINT_(void);
#endif

#if (DT_REAL_EN > 0)
typedef struct{
    REAL IN1;
    REAL IN2;
}GE_REAL_S;
extern GE_REAL_S _GE_REAL;
BOOL _GE_REAL_(void);
#endif

#if (DT_LREAL_EN > 0)
typedef struct{
    LREAL IN1;
    LREAL IN2;
}GE_LREAL_S;
extern GE_LREAL_S _GE_LREAL;
BOOL _GE_LREAL_(void);
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
BOOL _EQ_BOOL_(void);

typedef struct{
    BYTE IN1;
    BYTE IN2;
}EQ_BYTE_S;
extern EQ_BYTE_S _EQ_BYTE;
BOOL _EQ_BYTE_(void);

typedef struct{
    WORD IN1;
    WORD IN2;
}EQ_WORD_S;
extern EQ_WORD_S _EQ_WORD;
BOOL _EQ_WORD_(void);

typedef struct{
    DWORD IN0;
    DWORD IN1;
}EQ_DWORD_S;
extern EQ_DWORD_S _EQ_DWORD;
BOOL _EQ_DWORD_(void);

#if (DT_LWORD_EN > 0)
typedef struct{
    LWORD IN1;
    LWORD IN2;
}EQ_LWORD_S;
extern EQ_LWORD_S _EQ_LWORD;
BOOL _EQ_LWORD_(void);
#endif

typedef struct{
    SINT IN1;
    SINT IN2;
}EQ_SINT_S;
extern EQ_SINT_S _EQ_SINT;
BOOL _EQ_SINT_(void);

typedef struct{
    INT IN1;
    INT IN2;
}EQ_INT_S;
extern EQ_INT_S _EQ_INT;
BOOL _EQ_INT_(void);

typedef struct{
    DINT IN1;
    DINT IN2;
}EQ_DINT_S;
extern EQ_DINT_S _EQ_DINT;
BOOL _EQ_DINT_(void);

#if (DT_LINT_EN > 0)
typedef struct{
    LINT IN1;
    BOOL IN2;
}EQ_LINT_S;
extern EQ_LINT_S _EQ_LINT;
BOOL _EQ_LINT_(void);
#endif

typedef struct{
    USINT IN1;
    USINT IN2;
}EQ_USINT_S;
extern EQ_USINT_S _EQ_USINT;
BOOL _EQ_USINT_(void);

typedef struct{
    UINT IN1;
    UINT IN2;
}EQ_UINT_S;
extern EQ_UINT_S _EQ_UINT;
BOOL _EQ_UINT_(void);

typedef struct{
    UDINT IN1;
    UDINT IN2;
}EQ_UDINT_S;
extern EQ_UDINT_S _EQ_UDINT;
BOOL _EQ_UDINT_(void);

#if (DT_LINT_EN > 0)
typedef struct{
    ULINT IN1;
    ULINT IN2;
}EQ_ULINT_S;
extern EQ_ULINT_S _EQ_ULINT;
BOOL _EQ_ULINT_(void);
#endif

#if (DT_REAL_EN > 0)
typedef struct{
    REAL IN1;
    REAL IN2;
}EQ_REAL_S;
extern EQ_REAL_S _EQ_REAL;
BOOL _EQ_REAL_(void);
#endif

#if (DT_LREAL_EN > 0)
typedef struct{
    LREAL IN1;
    LREAL IN2;
}EQ_LREAL_S;
extern EQ_LREAL_S _EQ_LREAL;
BOOL _EQ_LREAL_(void);
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
BOOL _LE_BOOL_(void);

typedef struct{
    BYTE IN1;
    BYTE IN2;
}LE_BYTE_S;
extern LE_BYTE_S _LE_BYTE;
BOOL _LE_BYTE_(void);

typedef struct{
    WORD IN1;
    WORD IN2;
}LE_WORD_S;
extern LE_WORD_S _LE_WORD;
BOOL _LE_WORD_(void);

typedef struct{
    DWORD IN0;
    DWORD IN1;
}LE_DWORD_S;
extern LE_DWORD_S _LE_DWORD;
BOOL _LE_DWORD_(void);

#if (DT_LWORD_EN > 0)
typedef struct{
    LWORD IN1;
    LWORD IN2;
}LE_LWORD_S;
extern LE_LWORD_S _LE_LWORD;
BOOL _LE_LWORD_(void);
#endif

typedef struct{
    SINT IN1;
    SINT IN2;
}LE_SINT_S;
extern LE_SINT_S _LE_SINT;
BOOL _LE_SINT_(void);

typedef struct{
    INT IN1;
    INT IN2;
}LE_INT_S;
extern LE_INT_S _LE_INT;
BOOL _LE_INT_(void);

typedef struct{
    DINT IN1;
    DINT IN2;
}LE_DINT_S;
extern LE_DINT_S _LE_DINT;
BOOL _LE_DINT_(void);

#if (DT_LINT_EN > 0)
typedef struct{
    LINT IN1;
    BOOL IN2;
}LE_LINT_S;
extern LE_LINT_S _LE_LINT;
BOOL _LE_LINT_(void);
#endif

typedef struct{
    USINT IN1;
    USINT IN2;
}LE_USINT_S;
extern LE_USINT_S _LE_USINT;
BOOL _LE_USINT_(void);

typedef struct{
    UINT IN1;
    UINT IN2;
}LE_UINT_S;
extern LE_UINT_S _LE_UINT;
BOOL _LE_UINT_(void);

typedef struct{
    UDINT IN1;
    UDINT IN2;
}LE_UDINT_S;
extern LE_UDINT_S _LE_UDINT;
BOOL _LE_UDINT_(void);

#if (DT_LINT_EN > 0)
typedef struct{
    ULINT IN1;
    ULINT IN2;
}LE_ULINT_S;
extern LE_ULINT_S _LE_ULINT;
BOOL _LE_ULINT_(void);
#endif

#if (DT_REAL_EN > 0)
typedef struct{
    REAL IN1;
    REAL IN2;
}LE_REAL_S;
extern LE_REAL_S _LE_REAL;
BOOL _LE_REAL_(void);
#endif

#if (DT_LREAL_EN > 0)
typedef struct{
    LREAL IN1;
    LREAL IN2;
}LE_LREAL_S;
extern LE_LREAL_S _LE_LREAL;
BOOL _LE_LREAL_(void);
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
BOOL _LT_BOOL_(void);

typedef struct{
    BYTE IN1;
    BYTE IN2;
}LT_BYTE_S;
extern LT_BYTE_S _LT_BYTE;
BOOL _LT_BYTE_(void);

typedef struct{
    WORD IN1;
    WORD IN2;
}LT_WORD_S;
extern LT_WORD_S _LT_WORD;
BOOL _LT_WORD_(void);

typedef struct{
    DWORD IN0;
    DWORD IN1;
}LT_DWORD_S;
extern LT_DWORD_S _LT_DWORD;
BOOL _LT_DWORD_(void);

#if (DT_LWORD_EN > 0)
typedef struct{
    LWORD IN1;
    LWORD IN2;
}LT_LWORD_S;
extern LT_LWORD_S _LT_LWORD;
BOOL _LT_LWORD_(void);
#endif

typedef struct{
    SINT IN1;
    SINT IN2;
}LT_SINT_S;
extern LT_SINT_S _LT_SINT;
BOOL _LT_SINT_(void);

typedef struct{
    INT IN1;
    INT IN2;
}LT_INT_S;
extern LT_INT_S _LT_INT;
BOOL _LT_INT_(void);

typedef struct{
    DINT IN1;
    DINT IN2;
}LT_DINT_S;
extern LT_DINT_S _LT_DINT;
BOOL _LT_DINT_(void);

#if (DT_LINT_EN > 0)
typedef struct{
    LINT IN1;
    BOOL IN2;
}LT_LINT_S;
extern LT_LINT_S _LT_LINT;
BOOL _LT_LINT_(void);
#endif

typedef struct{
    USINT IN1;
    USINT IN2;
}LT_USINT_S;
extern LT_USINT_S _LT_USINT;
BOOL _LT_USINT_(void);

typedef struct{
    UINT IN1;
    UINT IN2;
}LT_UINT_S;
extern LT_UINT_S _LT_UINT;
BOOL _LT_UINT_(void);

typedef struct{
    UDINT IN1;
    UDINT IN2;
}LT_UDINT_S;
extern LT_UDINT_S _LT_UDINT;
BOOL _LT_UDINT_(void);

#if (DT_LINT_EN > 0)
typedef struct{
    ULINT IN1;
    ULINT IN2;
}LT_ULINT_S;
extern LT_ULINT_S _LT_ULINT;
BOOL _LT_ULINT_(void);
#endif

#if (DT_REAL_EN > 0)
typedef struct{
    REAL IN1;
    REAL IN2;
}LT_REAL_S;
extern LT_REAL_S _LT_REAL;
BOOL _LT_REAL_(void);
#endif

#if (DT_LREAL_EN > 0)
typedef struct{
    LREAL IN1;
    LREAL IN2;
}LT_LREAL_S;
extern LT_LREAL_S _LT_LREAL;
BOOL _LT_LREAL_(void);
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
BOOL _NE_BOOL_(void);

typedef struct{
    BYTE IN1;
    BYTE IN2;
}NE_BYTE_S;
extern NE_BYTE_S _NE_BYTE;
BOOL _NE_BYTE_(void);

typedef struct{
    WORD IN1;
    WORD IN2;
}NE_WORD_S;
extern NE_WORD_S _NE_WORD;
BOOL _NE_WORD_(void);

typedef struct{
    DWORD IN0;
    DWORD IN1;
}NE_DWORD_S;
extern NE_DWORD_S _NE_DWORD;
BOOL _NE_DWORD_(void);

#if (DT_LWORD_EN > 0)
typedef struct{
    LWORD IN1;
    LWORD IN2;
}NE_LWORD_S;
extern NE_LWORD_S _NE_LWORD;
BOOL _NE_LWORD_(void);
#endif

typedef struct{
    SINT IN1;
    SINT IN2;
}NE_SINT_S;
extern NE_SINT_S _NE_SINT;
BOOL _NE_SINT_(void);

typedef struct{
    INT IN1;
    INT IN2;
}NE_INT_S;
extern NE_INT_S _NE_INT;
BOOL _NE_INT_(void);

typedef struct{
    DINT IN1;
    DINT IN2;
}NE_DINT_S;
extern NE_DINT_S _NE_DINT;
BOOL _NE_DINT_(void);

#if (DT_LINT_EN > 0)
typedef struct{
    LINT IN1;
    BOOL IN2;
}NE_LINT_S;
extern NE_LINT_S _NE_LINT;
BOOL _NE_LINT_(void);
#endif

typedef struct{
    USINT IN1;
    USINT IN2;
}NE_USINT_S;
extern NE_USINT_S _NE_USINT;
BOOL _NE_USINT_(void);

typedef struct{
    UINT IN1;
    UINT IN2;
}NE_UINT_S;
extern NE_UINT_S _NE_UINT;
BOOL _NE_UINT_(void);

typedef struct{
    UDINT IN1;
    UDINT IN2;
}NE_UDINT_S;
extern NE_UDINT_S _NE_UDINT;
BOOL _NE_UDINT_(void);

#if (DT_LINT_EN > 0)
typedef struct{
    ULINT IN1;
    ULINT IN2;
}NE_ULINT_S;
extern NE_ULINT_S _NE_ULINT;
BOOL _NE_ULINT_(void);
#endif

#if (DT_REAL_EN > 0)
typedef struct{
    REAL IN1;
    REAL IN2;
}NE_REAL_S;
extern NE_REAL_S _NE_REAL;
BOOL _NE_REAL_(void);
#endif

#if (DT_LREAL_EN > 0)
typedef struct{
    LREAL IN1;
    LREAL IN2;
}NE_LREAL_S;
extern NE_LREAL_S _NE_LREAL;
BOOL _NE_LREAL_(void);
#endif






#endif

