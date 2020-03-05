/**
  * @file  plc_mem.c
  * @brief  PLC用户存储映像区相关的实现
  * @author  hyafz
  */
#include "plc_mem.h"
#include <string.h>

BYTE I[MAX_I_RANGE];	/**< 输入映像区 */
BYTE Q[MAX_Q_RANGE];	/**< 输出映像区 */
BYTE M[MAX_M_RANGE];	/**< 存储映像区 */

/**
  * @brief PLC输入、输出、存储映像区初始化
  */
void plcMemInit(void)
{
	memset((void*)I, 0, sizeof(I));
	memset((void*)Q, 0, sizeof(Q));
	memset((void*)M, 0, sizeof(M));
}



