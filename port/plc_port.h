/**
 * @file plc_port.h
 * @brief 资源处理器接口相关选项设置，制造商通过修改本文件对自己的处理器进行裁剪定制。
 * @author hyafz
 */

#ifndef PLC_PORT_H
#define PLC_PORT_H

#define MAX_I_RANGE         256         /**< 输入映像区字节数 */
#define MAX_Q_RANGE         256         /**< 输出映像区字节数 */
#define MAX_M_RANGE         256         /**< 内存映像区字节数 */

#define LOC_DI_NUM          8           /**< 本地8点数字量输入 */
#define LOC_DQ_NUM          6           /**< 本地6点数字量输出 */

#define LOC_AI_NUM          1
#define LOC_AQ_NUM          1

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
#define MAX_TASK_NUM_PER_RSC           4   /**< 每个资源中允许的最大任务数目*/
#define PLC_TASK_RUN_TASK_STK_SIZE		512
#define PLC_TASK_HIGHEST_PRIORITY           1
#define PLC_TASK_LOWEST_PRIORITY        30
/*与POU相关的选项*/

/* 与数据类型相关的选项 */

/* 与编程语言相关的选项 */

/* 与IL语言相关的选项 */

/* 与LD语言相关的选项 */

/* 其它选项 */

#endif /* PLC_PORT_H */
