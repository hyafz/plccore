/**
  * @file  plc_mem.h
  * @brief     PLC存储区相关定义及操作宏头文件
  * @author    fengzhou 
  */
#ifndef _PLC_MEM_H_
#define _PLC_MEM_H_

#include "plc_type_define.h"
#include "plc_port.h"

extern BYTE I[MAX_I_RANGE];
extern BYTE Q[MAX_Q_RANGE];
extern BYTE M[MAX_M_RANGE];

#define IX(id)    ((I[(id) >> 3] >> ((id) & 0x07)) & 0x01)
#define IB(id)    (I[(id)])
#define IW(id)    (*(WORD*)&I[(id) << 1])
#define ID(id)    (*(DWORD*)&I[(id) << 2])
#define IL(id)    (*(LWORD*)&I[(id)] << 3)

#define QX(id)    ((Q[(id) >> 3] >> ((id) & 0x07)) & 0x01)
#define QB(id)    (Q[(id)])
#define QW(id)    (*(WORD*)&Q[(id) << 1])
#define QD(id)    (*(DWORD*)&Q[(id) << 2])
#define QL(id)    (*(LWORD*)&Q[(id) << 3])

#define MX(id)    ((M[(id) >> 3] >> ((id) & 0x07)) & 0x01)
#define MB(id)    (M[(id)])
#define MW(id)    (*(WORD*)&M[(id) << 1])
#define MD(id)    (*(DWORD*)&M[(id) << 2])
#define ML(id)    (*(LWORD*)&M[(id) << 3])

#define IX_ADDR(id)    ((BOOL*)&I[(id) >> 3])
#define IB_ADDR(id)    ((BYTE*)&I[(id)])
#define IW_ADDR(id)    ((WORD*)&I[(id) << 1])
#define ID_ADDR(id)    ((DWORD*)&I[(id) << 2])
#define IL_ADDR(id)    ((LWORD*)&I[(id) << 3])

#define QX_ADDR(id)    ((BOOL*)&Q[(id) >> 3])
#define QB_ADDR(id)    ((BYTE*)&Q[(id)])
#define QW_ADDR(id)    ((WORD*)&Q[(id) << 1])
#define QD_ADDR(id)    ((DWORD*)&Q[(id) << 2])
#define QL_ADDR(id)    ((LWORD*)&Q[(id) << 3])

#define MX_ADDR(id)    ((BOOL*)&M[(id) >> 3])
#define MB_ADDR(id)    ((BYTE*)&M[(id)])
#define MW_ADDR(id)    ((WORD*)&M[(id) << 1])
#define MD_ADDR(id)    ((DWORD*)&M[(id) << 2])
#define ML_ADDR(id)    ((LWORD*)&M[(id) << 3])

#define IX_SET(id, val)	do{	if(((val) & 0x01) == 0) I[id >> 3] &= ~(1 << (id & 0x07));	\
							else I[id >> 3] |= (1 << (id & 0x07));	\
							}while(0)
#define IB_SET(id, val)    (IB(id)  = val)
#define IW_SET(id, val)    (IW(id)  = val)
#define ID_SET(id, val)   (ID(id) = val)
#define IL_SET(id, val)   (IL(id) = val)
                                            
#define QX_SET(id, val)	do{	if(((val) & 0x01) == 0)	Q[id >> 3] &= ~(1 << (id & 0x07));	\
	                        else	Q[id >> 3] |= (1 << (id & 0x07));	\
                        }while(0)
#define QB_SET(id, val)    (QB(id)  = val)
#define QW_SET(id, val)    (QW(id)  = val)
#define QD_SET(id, val)   (QD(id) = val)
#define QL_SET(id, val)   (QL(id) = val)
                                            
#define MX_SET(id, val)	do{	if(((val) & 0x01) == 0)	M[id >> 3] &= ~(1 << (id & 0x07));	\
							else	M[id >> 3] |= (1 << (id & 0x07));	\
						}while(0)
#define MB_SET(id, val)    (MB(id)  = val)
#define MW_SET(id, val)    (MW(id)  = val)
#define MD_SET(id, val)   (MD(id) = val)
#define ML_SET(id, val)   (ML(id) = val)

void plcMemInit(void);


#endif
