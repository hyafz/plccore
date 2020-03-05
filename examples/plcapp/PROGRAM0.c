/*------------------------------------------------
 自动生成代码，请勿修改！
------------------------------------------------*/
#include "plc_mem.h"
#include "plc_cr.h"
#include "pou.h"

void _PROGRAM0_(PROGRAM0_S* pParList)
{

	CR_Init(PROGRAM0_STK_DEPTH);
	CR_BOOL_LD(~QX(0));

	QX_SET(0,  CR_BOOL);

_POU_Return:
	return;
	goto _POU_Return;
_Error_Return:
	return;
	goto _Error_Return;
}

