/**
 * @file  plc_std_fb.c
 * @brief     PLC标准功能块实现文件
 * @author    fengzhou
 */

#include "plc_std_fb.h"

void _SR_(SR_S* pParList)
{
    pParList->Q1 = (((~pParList->R) & pParList->Q1) | pParList->S1);
}

void _RS_(RS_S* pParList)
{
    pParList->Q1 = ((pParList->S | pParList->Q1) & (~pParList->R1));
}

void _R_TRIG_(R_TRIG_S* pParList)
{
    pParList->Q = (pParList->CLK & (~pParList->M)) & 0x01;
    pParList->M = pParList->CLK;
}

void _F_TRIG_(F_TRIG_S* pParList)
{
    pParList->Q = ((~pParList->CLK) & (~pParList->M)) & 0x01;
    pParList->M = (~pParList->CLK) & 0x01;
}

void _CTU_(CTU_S* pParList)
{
    if((pParList->R & 0x01) == 1) pParList->CV = 0;
    else if(((pParList->CU & 0x01) == 1) && (pParList->CV < 0x7FFF)){
        pParList->CV++;
    }
    pParList->Q = (pParList->CV >= pParList->PV);
}

void _CTU_DINT_(CTU_DINT_S* pParList)
{
    if((pParList->R & 0x01) == 1) pParList->CV = 0;
    else if(((pParList->CU & 0x01) == 1) && (pParList->CV < 0x7FFFFFFF)){
        pParList->CV++;
    }
    pParList->Q = (pParList->CV >= pParList->PV);
}

#if (DT_LINT_EN)
void _CTU_LINT_(CTU_LINT_S* pParList)
{
    if((pParList->R & 0x01) == 1) pParList->CV = 0;
    else if(((pParList->CU & 0x01) == 1) && (pParList->CV < 0x7FFFFFFFFFFFFFFF)){
        pParList->CV++;
    }
    pParList->Q = (pParList->CV >= pParList->PV);
}
#endif

void _CTU_UDINT_(CTU_UDINT_S* pParList)
{
    if((pParList->R & 0x01) == 1) pParList->CV = 0;
    else if(((pParList->CU & 0x01) == 1) && (pParList->CV < 0xFFFFFFFF)){
        pParList->CV++;
    }
    pParList->Q = (pParList->CV >= pParList->PV);
}

#if (DT_ULINT_EN)
void _CTU_ULINT_(CTU_ULINT_S* pParList)
{
    if((pParList->R & 0x01) == 1) pParList->CV = 0;
    else if(((pParList->CU & 0x01) == 1) && (pParList->CV < 0xFFFFFFFFFFFFFFFF)){
        pParList->CV++;
    }
    pParList->Q = (pParList->CV >= pParList->PV);
}
#endif

void _CTD_(CTD_S* pParList)
{
    if((pParList->LD & 0x01) == 1) pParList->CV = pParList->PV;
    else if(((pParList->CD & 0x01) == 1) && (pParList->CV > 0)){
        pParList->CV--;
    }
    pParList->Q = (pParList->CV >= pParList->PV);
}

void _CTD_DINT_(CTD_DINT_S* pParList)
{
    if((pParList->LD & 0x01) == 1) pParList->CV = pParList->PV;
    else if(((pParList->CD & 0x01) == 1) && (pParList->CV > 0)){
        pParList->CV--;
    }
    pParList->Q = (pParList->CV >= pParList->PV);

}

#if (DT_LINT_EN)
void _CTD_LINT_(CTD_LINT_S* pParList)
{
    if((pParList->LD & 0x01) == 1) pParList->CV = pParList->PV;
    else if(((pParList->CD & 0x01) == 1) && (pParList->CV > 0)){
        pParList->CV--;
    }
    pParList->Q = (pParList->CV >= pParList->PV);
}
#endif

void _CTD_UDINT_(CTD_UDINT_S* pParList)
{
    if((pParList->LD & 0x01) == 1) pParList->CV = pParList->PV;
    else if(((pParList->CD & 0x01) == 1) && (pParList->CV > 0)){
        pParList->CV--;
    }
    pParList->Q = (pParList->CV >= pParList->PV);
}

#if (DT_ULINT_EN)
void _CTD_ULINT_(CTD_ULINT_S* pParList)
{
    if((pParList->LD & 0x01) == 1) pParList->CV = pParList->PV;
    else if(((pParList->CD & 0x01) == 1) && (pParList->CV > 0)){
        pParList->CV--;
    }
    pParList->Q = (pParList->CV >= pParList->PV);

}
#endif

void _CTUD_(CTUD_S* pParList)
{
    if((pParList->R & 0x01) == 1) pParList->CV = 0;
    else if((pParList->LD & 0x01) == 1) pParList->CV = pParList->PV;
    else{
        if(((pParList->CU & pParList->CD) & 0x01) == 0){
            if(((pParList->CU & 0x01) == 1) && (pParList->CV < 0x7FFF)){
                pParList->CV++;
            }
            else if(((pParList->CD & 0x01) == 1) && (pParList->CV > 0)){
                pParList->CV--;
            }
        }
        pParList->CV++;
    }
    pParList->QU = (pParList->CV >= pParList->PV);
    pParList->QD = (pParList->CV <= 0);
}

void _CTUD_DINT_(CTUD_DINT_S* pParList)
{
    if((pParList->R & 0x01) == 1) pParList->CV = 0;
    else if((pParList->LD & 0x01) == 1) pParList->CV = pParList->PV;
    else{
        if(((pParList->CU & pParList->CD) & 0x01) == 0){
            if(((pParList->CU & 0x01) == 1) && (pParList->CV < 0x7FFFFFFF)){
                pParList->CV++;
            }
            else if(((pParList->CD & 0x01) == 1) && (pParList->CV > 0)){
                pParList->CV--;
            }
        }
        pParList->CV++;
    }
    pParList->QU = (pParList->CV >= pParList->PV);
    pParList->QD = (pParList->CV <= 0);
}

#if (DT_LINT_EN)
void _CTUD_LINT_(CTUD_LINT_S* pParList)
{
    if((pParList->R & 0x01) == 1) pParList->CV = 0;
    else if((pParList->LD & 0x01) == 1) pParList->CV = pParList->PV;
    else{
        if((pParList->CU & pParList->CD) & 0x01 == 0){
            if(((pParList->CU & 0x01) == 1) && (pParList->CV < 0x7FFFFFFFFFFFFFFF)){
                pParList->CV++;
            }
            else if(((pParList->CD & 0x01) == 1) && (pParList->CV > 0)){
                pParList->CV--;
            }
        }
        pParList->CV++;
    }
    pParList->QU = (pParList->CV >= pParList->PV);
    pParList->QD = (pParList->CV <= 0);
}
#endif

void _CTUD_UDINT_(CTUD_UDINT_S* pParList)
{
    if((pParList->R & 0x01) == 1) pParList->CV = 0;
    else if((pParList->LD & 0x01) == 1) pParList->CV = pParList->PV;
    else{
        if(((pParList->CU & pParList->CD) & 0x01) == 0){
            if(((pParList->CU & 0x01) == 1) && (pParList->CV < 0xFFFFFFFF)){
                pParList->CV++;
            }
            else if(((pParList->CD & 0x01) == 1) && (pParList->CV > 0)){
                pParList->CV--;
            }
        }
        pParList->CV++;
    }
    pParList->QU = (pParList->CV >= pParList->PV);
    pParList->QD = (pParList->CV <= 0);
}

#if (DT_ULINT_EN)
void _CTUD_ULINT_(CTUD_ULINT_S* pParList)
{
    if((pParList->R & 0x01) == 1) pParList->CV = 0;
    else if((pParList->LD & 0x01) == 1) pParList->CV = pParList->PV;
    else{
        if((pParList->CU & pParList->CD) & 0x01 == 0){
            if(((pParList->CU & 0x01) == 1) && (pParList->CV < 0xFFFFFFFFFFFFFFFF)){
                pParList->CV++;
            }
            else if(((pParList->CD & 0x01) == 1) && (pParList->CV > 0)){
                pParList->CV--;
            }
        }
        pParList->CV++;
    }
    pParList->QU = (pParList->CV >= pParList->PV);
    pParList->QD = (pParList->CV <= 0);
}
#endif

#if (DT_TIME_EN)
void _TP_(TP_S* pParList)
{

}

void _TON_(TON_S* pParList)
{

}

void _TOF_(TOF_S* pParList)
{

}
#endif

