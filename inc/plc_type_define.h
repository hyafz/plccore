/**
  * @file  plc_type_define.h
  * @brief     通用数据类型定义
  * @author    fengzhou
  */
#ifndef _PLC_TYPE_DEFINE_H_
#define _PLC_TYPE_DEFINE_H_

/* Basic Data Type typedef --------------------------------------------------*/
/*8 bits*/
typedef unsigned char                BOOL;
typedef unsigned char                BYTE;
typedef signed char                  SINT;
typedef unsigned char                USINT;
/*16 bits*/
typedef unsigned short               WORD;
typedef signed short                 INT;
typedef unsigned short               UINT;
/*32 bits*/
typedef unsigned int                 DWORD;
typedef signed int                   DINT;
typedef unsigned int                 UDINT;
typedef float                        REAL;
/* 
  间隔时长
  以ms为单位，最大4294967295ms. 
*/
typedef unsigned int                 TIME;
/* 
  日期
  从XXXX年XX月XX日起始的天数(最大4294967295天)，起始日期是一个常量. 
*/
typedef unsigned int                 DATE;
/* 
  时刻
  低20位为从0时0分0秒计时的总秒数(最大86399秒)，
  高12位为当前毫秒数(最大999ms). 
*/
typedef unsigned int                 TIME_OF_DAY; 
typedef TIME_OF_DAY                  TOD;
/* 
  日期和时刻
  高15位为从XXXX年XX月XX日起始的天数（最大32767天），
  低17位为当前时刻距当天0时0分0秒所经过的秒数（最大86399秒）。
  如果需要更精确的或更大范围的时间日期（年-月-日 时:分:秒:毫秒），
  使用DATE和TOD的组合. 
*/
typedef unsigned int                 DATE_AND_TIME;  
typedef DATE_AND_TIME                DT;

/*64 bits*/
typedef unsigned long                LWORD;
typedef signed long                  LINT;
typedef unsigned long                ULINT;
typedef double                       LREAL;

/* data type in bit numbers */
typedef unsigned char                UINT8;
typedef unsigned short               UINT16;
typedef unsigned int                 UINT32;
typedef unsigned long long           UINT64;

/* 各种数据类型变量的默认初始值 */
#define _BOOL_DEFAULT                0
#define _BYTE_DEFAULT                0
#define _SINT_DEFAULT                0
#define _USINT_DEFAULT              0

#define _WORD_DEFAULT                0
#define _INT_DEFAULT                0
#define _UINT_DEFAULT                0

#define _DWORD_DEFAULT                0
#define _DINT_DEFAULT                0
#define _UDINT_DEFAULT                0
#define _REAL_DEFAULT                0
#define _TIME_DEFAULT                0
#define _DATE_DEFAULT                0
#define _TIME_OF_DAY_DEFAULT         0
#define _TOD_DEFAULT                0
#define _DATE_AND_TIME_DEFAULT      0
#define _DT_DEFAULT                0
#define _LWORD_DEFAULT                0
#define _LINT_DEFAULT                0
#define _ULINT_DEFAULT                0
#define _LREAL_DEFAULT                0
#define _UINT8_DEFAULT                0
#define _UINT16_DEFAULT                0
#define _UINT32_DEFAULT                0
#define _UINT64_DEFAULT                0


#endif








