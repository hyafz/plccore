/**
 * @file plc_port.h
 * @brief 资源处理器接口相关选项设置，制造商通过修改本文件对自己的处理器进行裁剪定制。
 * @author fengzhou
 */

#ifndef PLC_PORT_H
#define PLC_PORT_H

#include <rtthread.h>
#ifdef RT_USING_DEVICE
#define PLC_UART_NAME          "uart1"      /* 串口设备名称 */
#define PLC_HWTIMER_DEV_NAME   "timer3"     /* 定时器设备名称 */
#endif

/* 输入-输出管脚相关宏定义 */
/* 输入设备 */
#define RUN_SW_PIN      GET_PIN(A, 0)
#define IX0_PIN         GET_PIN(B, 0)
#define IX1_PIN         GET_PIN(A, 7)
#define IX2_PIN         GET_PIN(A, 6)
#define IX3_PIN         GET_PIN(A, 5)
#define IX4_PIN         GET_PIN(A, 4)
#define IX5_PIN         GET_PIN(A, 3)
#define IX6_PIN         GET_PIN(A, 2)
#define IX7_PIN         GET_PIN(A, 1)

#define DI_INIT_INFO \
{ /*    pin, default_state, prev_input_state, state, state_debounce_time, state_stay_time*/ \
    { RUN_SW_PIN,   1,   1,   1,   0,  0}, /* RUN Switch */ \
    { IX0_PIN,      1,   1,   1,   0,  0}, /* IX0_PIN */ \
    { IX1_PIN,      1,   1,   1,   0,  0}, /* IX1_PIN */ \
    { IX2_PIN,      1,   1,   1,   0,  0}, /* IX2_PIN */ \
    { IX3_PIN,      1,   1,   1,   0,  0}, /* IX3_PIN */ \
    { IX4_PIN,      1,   1,   1,   0,  0}, /* IX4_PIN */ \
    { IX5_PIN,      1,   1,   1,   0,  0}, /* IX5_PIN */ \
    { IX6_PIN,      1,   1,   1,   0,  0}, /* IX6_PIN */ \
    { IX7_PIN,      1,   1,   1,   0,  0}, /* IX7_PIN */ \
}

/* 输出设备 */
#define LED_RUN_PIN     GET_PIN(C, 15)
#define LED_STOP_PIN    GET_PIN(C, 14)
#define LED_ERR_PIN     GET_PIN(C, 13)
#define QX0_PIN         GET_PIN(A, 15)
#define QX1_PIN         GET_PIN(B, 3)
#define QX2_PIN         GET_PIN(B, 4)
#define QX3_PIN         GET_PIN(B, 5)
#define QX4_PIN         GET_PIN(B, 6)
#define QX5_PIN         GET_PIN(B, 7)
#define DO_INIT_INFO \
{ /* pin, off_value, on_value, out_value */ \
    { LED_RUN_PIN,   0 , 1 , 0 }, /* LED RUN */ \
    { LED_STOP_PIN,  0 , 1 , 0 }, /* LED STOP */ \
    { LED_ERR_PIN,   0 , 1 , 0 }, /* LED ERR */ \
    { QX0_PIN,       0 , 1 , 0 }, /* QX0 */ \
    { QX1_PIN,       0 , 1 , 0 }, /* QX1 */ \
    { QX2_PIN,       0 , 1 , 0 }, /* QX2 */ \
    { QX3_PIN,       0 , 1 , 0 }, /* QX3 */ \
    { QX4_PIN,       0 , 1 , 0 }, /* QX4 */ \
    { QX5_PIN,       0 , 1 , 0 }, /* QX5 */ \
}

#define MAX_I_RANGE             256         /**< 输入映像区字节数 */
#define MAX_Q_RANGE             256         /**< 输出映像区字节数 */
#define MAX_M_RANGE             256         /**< 内存映像区字节数 */

#define LOC_DI_NUM              8           /**< 本地8点数字量输入 */
#define LOC_DQ_NUM              6           /**< 本地6点数字量输出 */

#define LOC_AI_NUM              1
#define LOC_AQ_NUM              1

#define LOC_PWM_NUM             2           /**< 本地PWM输出通道数目 */
#define LOC_PWM_CTRL_BASE       248         /**< 本地PWM输出控制参数在Q区的起始映射地址，控制参数区占用4字节：
                                                 Byte 1 ~ 2: PWM周期，单位us，为0则停止输出
                                                 Byte 3    : PWM占空比 0 ~ 100，为0则停止输出
                                                 Byte 4    : PWM模式 */

/**
  * @brief 支持的数据类型使能选项
  <pre>
  下列基本数据类型可以配置是否支持,其它基本数据类型默认支持。
	LINT
	ULINT
	REAL
	LREAL
	LWORD
	STRING
	WSTRING
	TIME
	DATE
	TOD
	DT
  导出数据类型可以配置是否支持
  </pre>
  */
#define DT_REAL_EN                     1

#define DT_64BIT_EN                    0  /**< 支持64位长度数据类型的选项(0: 不支持, 1: 支持) */
#if (DT_64BIT_EN > 0)
#define DT_LINT_EN                     0
#define DT_ULINT_EN                    0
#define DT_LREAL_EN                    0
#define DT_LWORD_EN                    0
#else
#define DT_LINT_EN                     0
#define DT_ULINT_EN                    0
#define DT_LREAL_EN                    0
#define DT_LWORD_EN                    0
#endif

#define DT_STRING_EN                   0
#define DT_WSTRING_EN                  0
#define DT_TIME_EN                     1
#define DT_DATE_EN                     0
#define DT_TOD_EN                      0
#define DT_DT_EN                       0

#define DT_DVD_EN                      0  /**< 支持导出数据类型的选项(0: 不支持, 1: 支持) ，目前必须为0*/

/*与配置相关的选项*/

/*与资源相关的选项*/
#define MAX_TASK_NUM_PER_RSC            4   /**< 每个资源中允许的最大任务数目*/
#define PLC_TASK_RUN_TASK_STK_SIZE      512
#define PLC_TASK_HIGHEST_PRIORITY       2
#define PLC_TASK_LOWEST_PRIORITY        30
/*与POU相关的选项*/

/* 与数据类型相关的选项 */

/* 与编程语言相关的选项 */

/* 与IL语言相关的选项 */

/* 与LD语言相关的选项 */

/* 其它选项 */

#endif /* PLC_PORT_H */
