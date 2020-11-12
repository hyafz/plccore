/**
  * @file  plc_io.h
  * @brief     plc_io.c的头文件
  * @author    hyafz
  */

#ifndef _PLC_IO_H
#define _PLC_IO_H

#include <rtthread.h>
#include "board.h"
#include "plc_port.h"

/* define -------------------------------------------------------------------*/

#define PLC_SW_STOP             0    /* PLC开关处于停机状态 */
#define PLC_SW_RUN              1    /* PLC开关处于运行状态 */

#define DEV_OUTPUT_OFF          0
#define DEV_OUTPUT_ON           1

#define DEV_INPUT_NUM           (1 + LOC_DI_NUM)
#define DEV_OUTPUT_NUM          (3 + LOC_DQ_NUM)

/* Input/Output Device IDs */
#define DEV_RUN_SW_ID           0
#define DEV_IX0_ID              1

#define DEV_LED_RUN_ID          0
#define DEV_LED_STOP_ID         1
#define DEV_LED_ERR_ID          2
#define DEV_QX0_ID              3

#define DEV_FIRST_OUTPUT_ID     DEV_LED_RUN_ID
#define DEV_LAST_OUTPUT_ID      (DEV_QX0_ID + LOC_DQ_NUM - 1)

extern unsigned char devInputGet(unsigned int x);
extern void devOutputSet(int8_t dev_id, uint8_t sw);

#define LED_RUN_ON()            devOutputSet(DEV_LED_RUN_ID, DEV_OUTPUT_ON)
#define LED_RUN_OFF()           devOutputSet(DEV_LED_RUN_ID, DEV_OUTPUT_OFF)
#define LED_STOP_ON()           devOutputSet(DEV_LED_STOP_ID, DEV_OUTPUT_ON)
#define LED_STOP_OFF()          devOutputSet(DEV_LED_STOP_ID, DEV_OUTPUT_OFF)
#define LED_ERR_ON()            devOutputSet(DEV_LED_ERR_ID, DEV_OUTPUT_ON)
#define LED_ERR_OFF()           devOutputSet(DEV_LED_ERR_ID, DEV_OUTPUT_OFF)

/* typedef ------------------------------------------------------------------*/
/**
  * @struct Device Input_Control_Struct
  * @brief 输入设备控制结构体类型定义
  */
typedef struct Device_Input_Control_Struct{
    rt_base_t           pin;                      /**< 设备对应的PIN */
    int                 default_state;            /**< 输入设备的默认状态 */
    int                 prev_input_state;         /**< 上一次输入检测状态 */
    int                 state;                    /**< 设备当前有效状态 */
    uint8_t             state_debounce_time;      /**< 切换状态去抖计数 */
    uint32_t            state_stay_time;          /**< 当前状态保持时间 */
}DEV_IN_CTRL_S;

/**
  * @struct Device Output_Control_Struct
  * @brief 输出设备控制结构体类型定义
  */
typedef struct Device_Output_Control_Struct{
    rt_base_t           pin;                      /**< 设备对应的PIN */
    int                 off_value;                /**< 输出关闭时GPIO PIN状态 */
    int                 on_value;                 /**< 输出打开时GPIO PIN状态 */
    int                 out_value;                /**< 当前输出GPIO PIN状态 */
}DEV_OUT_CTRL_S;

/**
 * @struct PWM输出控制结构体类型
 */
typedef struct PWM_Output_Control_Struct{
    uint16_t            period;                 /**< 周期，单位us */
    uint8_t             duty;                   /**< 占空比 */
    uint8_t             mode;                   /**< 模式 */
}PWM_OUT_CTRL_S;

/* Export variables declaration ---------------------------------------------*/
/* Export function declaration ----------------------------------------------*/
void plcIOInit(void);
void plcInputScan(void);
int8_t isRunMode(void);
int8_t isRunModeSwitched(void);
void plcLocalDiRefresh(void);
void plcLocalDqRefresh(void);
void plcLocalDqOutputWhenStopped(void);
void plcLocalAiRefresh(void);
void plcLocalAqRefresh(void);
void plcLocalPwmOutputWhenStopped(void);
void plcLocalPwmOutputRefresh(void);
#endif

