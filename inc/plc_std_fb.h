/**
  * @file  plc_std_fb.h
  * @brief     plc_std_fb.c的头文件
  * @author    fengzhou
  */

#ifndef _PLC_STANDARD_FB_H_
#define _PLC_STANDARD_FB_H_

#include "plc_type_define.h"

typedef struct{
    BOOL S1;
    BOOL R;
    BOOL Q1;
}SR_S;
void _SR_(SR_S* pParList);

typedef struct{
    BOOL S;
    BOOL R1;
    BOOL Q1;
}RS_S;
void _RS_(RS_S* pParList);

typedef struct{
    BOOL CLK;
    BOOL Q;
    BOOL M;
}R_TRIG_S;
void _R_TRIG_(R_TRIG_S* pParList);

typedef struct{
    BOOL CLK;
    BOOL Q;
    BOOL M;
}F_TRIG_S;
void _F_TRIG_(F_TRIG_S* pParList);

typedef struct{
    BOOL CU;
    BOOL R;
    BOOL Q;
    BOOL reserved;
    INT  PV;
    INT  CV;
}CTU_S;
void _CTU_(CTU_S* pParList);

typedef struct{
    BOOL CU;
    BOOL R;
    BOOL Q;
    BOOL reserved;
    DINT  PV;
    DINT  CV;
}CTU_DINT_S;
void _CTU_DINT_(CTU_DINT_S* pParList);

#if (DT_LINT_EN)
typedef struct{
    BOOL CU;
    BOOL R;
    BOOL Q;
    BOOL reserved;
    LINT  PV;
    LINT  CV;
}CTU_LINT_S;
void _CTU_LINT_(CTU_LINT_S* pParList);
#endif

typedef struct{
    BOOL CU;
    BOOL R;
    BOOL Q;
    BOOL reserved;
    UDINT  PV;
    UDINT  CV;
}CTU_UDINT_S;
void _CTU_UDINT_(CTU_UDINT_S* pParList);

#if (DT_ULINT_EN)
typedef struct{
    BOOL CU;
    BOOL R;
    BOOL Q;
    BOOL reserved;
    ULINT  PV;
    ULINT  CV;
}CTU_ULINT_S;
void _CTU_ULINT_(CTU_ULINT_S* pParList);
#endif

typedef struct{
    BOOL CD;
    BOOL LD;
    BOOL Q;
    BOOL reserved;
    INT  PV;
    INT  CV;
}CTD_S;
void _CTD_(CTD_S* pParList);

typedef struct{
    BOOL CD;
    BOOL LD;
    BOOL Q;
    BOOL reserved;
    DINT  PV;
    DINT  CV;
}CTD_DINT_S;
void _CTD_DINT_(CTD_DINT_S* pParList);

#if (DT_LINT_EN)
typedef struct{
    BOOL CD;
    BOOL LD;
    BOOL Q;
    BOOL reserved;
    LINT  PV;
    LINT  CV;
}CTD_LINT_S;
void _CTD_LINT_(CTD_LINT_S* pParList);
#endif

typedef struct{
    BOOL CD;
    BOOL LD;
    BOOL Q;
    BOOL reserved;
    UDINT  PV;
    UDINT  CV;
}CTD_UDINT_S;
void _CTD_UDINT_(CTD_UDINT_S* pParList);

#if (DT_ULINT_EN)
typedef struct{
    BOOL CD;
    BOOL LD;
    BOOL Q;
    BOOL reserved;
    ULINT  PV;
    ULINT  CV;
}CTD_ULINT_S;
void _CTD_ULINT_(CTD_ULINT_S* pParList);
#endif

typedef struct{
    BOOL CU;
    BOOL CD;
    BOOL R;
    BOOL LD;
    BOOL QU;
    BOOL QD;
    BOOL reserved[2];
    INT  PV;
    INT  CV;
}CTUD_S;
void _CTUD_(CTUD_S* pParList);

typedef struct{
    BOOL CU;
    BOOL CD;
    BOOL R;
    BOOL LD;
    BOOL QU;
    BOOL QD;
    BOOL reserved[2];
    DINT  PV;
    DINT  CV;
}CTUD_DINT_S;
void _CTUD_DINT_(CTUD_DINT_S* pParList);

#if (DT_LINT_EN)
typedef struct{
    BOOL CU;
    BOOL CD;
    BOOL R;
    BOOL LD;
    BOOL QU;
    BOOL QD;
    BOOL reserved[2];
    LINT  PV;
    LINT  CV;
}CTUD_LINT_S;
void _CTUD_LINT_(CTUD_LINT_S* pParList);
#endif

typedef struct{
    BOOL CU;
    BOOL CD;
    BOOL R;
    BOOL LD;
    BOOL QU;
    BOOL QD;
    BOOL reserved[2];
    UDINT  PV;
    UDINT  CV;
}CTUD_UDINT_S;
void _CTUD_UDINT_(CTUD_UDINT_S* pParList);

#if (DT_ULINT_EN)
typedef struct{
    BOOL CU;
    BOOL CD;
    BOOL R;
    BOOL LD;
    BOOL QU;
    BOOL QD;
    BOOL reserved[2];
    ULINT  PV;
    ULINT  CV;
}CTUD_ULINT_S;
void _CTUD_ULINT_(CTUD_ULINT_S* pParList);
#endif

typedef struct{
    BOOL IN;
    BOOL Q;
    TIME PT;
    TIME ET;
}TP_S;
void _TP_(TP_S* pParList);

typedef struct{
    BOOL IN;
    BOOL Q;
    TIME PT;
    TIME ET;
}TON_S;
void _TON_(TON_S* pParList);

typedef struct{
    BOOL IN;
    BOOL Q;
    TIME PT;
    TIME ET;
}TOF_S;
void _TOF_(TOF_S* pParList);

#endif

