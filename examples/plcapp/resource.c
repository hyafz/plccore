/*------------------------------------------------
 自动生成代码，请勿修改！
------------------------------------------------*/
#include "configuration.h"
#include "resource.h"
#include "plc_mem.h"

BOOL _task_TASK0_single_get_(void)
{
	BOOL ret = 0;
	return ret;
}

TIME _task_TASK0_interval_get_(void)
{
	TIME ret = 0;
	ret = 500;
	return ret;
}

void _task_TASK0_run_(void)
{
	void* pParList;

	pParList = (void *)&(CONFIGURATION0.RESOURCE0.PROGRAM_INSTANCE0);


	_PROGRAM0_((PROGRAM0_S*)pParList);

}

void _task_default_run_(void)
{
	void* pParList;

}

void _resource_init_(RSC_CB_S* pRscCB)
{
	TASK_CB_S* pTaskCB;

	pRscCB->taskNum = 1;

	pTaskCB = &(pRscCB->taskCB[0]);
	pTaskCB->priority = 0;
	pTaskCB->singleGet = _task_TASK0_single_get_;
	pTaskCB->intervalGet = _task_TASK0_interval_get_;
	pTaskCB->taskRun = _task_TASK0_run_;

	pTaskCB = &(pRscCB->taskDefaultCB);
	pTaskCB->priority = PLC_TASK_LOWEST_PRIORITY;
	pTaskCB->taskRun = _task_default_run_;

}
