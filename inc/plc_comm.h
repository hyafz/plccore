/**
  * @file  plc_comm.h
  * @brief     PLC通信功能头文件
  * @author    hyafz     
  */

#ifndef _PLC_COMM_H
#define _PLC_COMM_H

/* define -------------------------------------------------------------------*/
/* 定义通信命令码 */
#define CMD_NONE            0x00
#define CMD_ENTER_IAP_MODE  0xC0
#define CMD_PROGRAM_READY   0xC1
#define CMD_PROGRAMMING     0xC2
#define CMD_PROGRAM_OVER    0xC3
#define CMD_JUMP_TO_APP     0xC4
#define CMD_M_OUTPUT        0xD0
#define CMD_DEBUG           0xDD
#define CMD_STAT_OUTPUT     0xDE
#define CMD_RESPONSE_ERR    0xEE

#define RX_DATA_BUF_SIZE    126

/* typedef ------------------------------------------------------------------*/
/* Export variables declaration ---------------------------------------------*/
extern unsigned char CommRxBuf[RX_DATA_BUF_SIZE];
extern unsigned int CommRxCnt;

void plcCommDataReceived();
void plcCommDataFrameSend(unsigned char cmd, unsigned char* data, int length);
void plcCommInit(void);
void plcCommRxTimeoutCheck(void);

#endif

