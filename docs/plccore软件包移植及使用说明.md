plccore软件包移植及使用说明
=========================

本软件包适用于RT-Thread nano，也适用于RT-Thread完整版，移植方式略有不同。
使用RTT完整版本移植更方便，可以很容易地整合RTT平台的各种驱动程序与软件包。但是相比nano版本，占用ROM与RAM空间更大，执行效率较低，任务实时性也较差。请用户根据需求进行权衡取舍。
本软件包目前仅针对意法半导体的STM32系列MCU进行了测试验证。
推荐使用RT-Thread Studio + Stm32CubeMX两款软件进行移植，操作方便，文档教程详细，即使是新手也很容易上手。
移植过程参考了RT-Thread官方提供的STM32系列BSP制作教程：https://github.com/RT-Thread/rt-thread/blob/master/bsp/stm32/docs/STM32%E7%B3%BB%E5%88%97BSP%E5%88%B6%E4%BD%9C%E6%95%99%E7%A8%8B.md 。

---
## 1. 准备

1. RT-Thread Studio软件（下载地址：https://www.rt-thread.org/page/studio.html）
2. Stm32CubeMX软件（下载地址：https://www.st.com/content/st_com/zh/products/development-tools/software-development-tools/stm32-software-development-tools/stm32-configurators-and-code-generators/stm32cubemx.html）
3. PLC组态及控制逻辑编程软件PLC IDE（电子邮件联系 401190549@qq.com 索取）
4. 获取plccore软件包
- 基于RT-Thread nano
方式一：从github下载：https://github.com/hyafz/plccore
方式二：从码云下载：https://gitee.com/hyafz/plccore
- 基于RT-Thread完整版
在RT-Thread Studio的配置中心添加plccore软件包。

---
## 2. 硬件要求
- 必须使用一个检测输入状态的GPIO作为运行开关状态检测；
- 必须使用一个GPIO控制一个LED亮灭作为运行状态显示灯（运行时亮，停止时灭）；
- 建议使用一个GPIO控制一个LED亮灭作为停止状态显示灯（运行时灭，停止时亮），如果没有，可定义一个空闲的管脚；
- 建议使用一个GPIO控制一个LED亮灭作为错误状态显示灯（正常时灭，错误时常亮或闪烁），如果没有，可定义一个空闲的管脚；
- 必须具备一个与上位机通信的串口；
- 必须具备一个作为PLC主定时器的硬件定时器；

---
## 3. 使用RT-Thread Studio + Stm32CubeMX生成目标板的BSP工程

### 新建RT-Thread工程
- 启动RT-Thread Studio，新建RT-Thread工程
- 输入工程名称
- 选择工程文件存放路径
- 选择基于芯片
- 选择RT-Thread版本
- 选择对应的芯片型号
- 选择控制台串口，必须与PLC专用串口不同
- 选择调试口（JTAG or SWD）
- 点击“完成”等待工程生成

![新建RTT工程配置](images/new_rtt_project_config.png)

### 配置RT-Thread工程
- 在RT-Thread Settings中使能消息队列
- 如果 **不使用控制台串口** ，在RT-Thread Settings中禁止“为rt_kprintf使用控制台”。
- 如果 **使用RTT完整版** ，在RT-Thread Settings中添加plccore软件包，并使能HWTIMER设备驱动程序。

### 使用Stm32CubeMX生成目标板配置工程

> ***不要与BSP工程放在同一目录下!***
> ***需要检查STM32CubeMX使用的固件库与RTT使用的版本是否一致***

- 配置RCC时钟
- 配置与上位机通信的专属串口（如果使用控制台串口，必须不同！）
波特率115200、8位数据位、1位停止位、无校验
启动对应串口全局中断，设置中断优先级。
- 配置PLC专属硬件定时器
分频后时钟为1MHz，定时值1000，即1ms中断一次。
启动对应定时器全局中断，设置中断优先级。
- 配置管脚属性（翻转速率、上下拉等）
  - 运行开关
  - 运行指示灯
  - 停止指示灯
  - 错误指示灯
  - 本地输入、输出管脚等
- 保存工程并生成代码

### 复制stm32f1xx_hal_conf.h文件

从Stm32CubeMX生成工程的inc目录下复制stm32f1xx_hal_conf.h文件至BSP工程drivers目录

### 复制stm32f1xx_hal_msp.c文件

从Stm32CubeMX生成工程的src目录下复制stm32f1xx_hal_msp.c文件至BSP工程drivers目录

### 修改stm32f1xx_hal_msp.c包含的头文件

将
```
#include "main.h"
```
修改为：
```
#include "board.h"
```

### 修改stm32f1xx_hal_msp.c中的HAL_UART_MspInit()函数

> ***注意：本步骤只适用于nano版本的移植***
> ***如果使用控制台串口，需要执行本步骤，否则跳过。***

因为drv_usart.c中已经实现了HAL_UART_MspInit()，不能重复定义，所以需要将stm32f1xx_hal_msp.c文件中的
```
void HAL_UART_MspInit(UART_HandleTypeDef* huart)
```
修改为
```
void HAL_UART_MspInitEx(UART_HandleTypeDef* huart)
```

### 修改drv_usart.c

> ***注意：本步骤只适用于nano版本的移植***
> ***如果使用控制台串口，需要执行本步骤，否则跳过。***

RTT Studio为nano生成的drv_usart.c文件的实现有点问题，需要修改后才能支持多个串口设备。

将
```
void HAL_UART_MspInit(UART_HandleTypeDef *huart)
```
移至
```
#endif /* RT_USING_CONSOLONE */
```
行之后，并修改成如下：

```
#endif /* RT_USING_CONSLONE */

void HAL_UART_MspInit(UART_HandleTypeDef *huart)
{
#ifdef RT_USING_CONSOLE
    /* if this uart is shell function */
    if(huart == &handle)
    {
        stm32_gpio_configure(_uart_config);
        return;
    }
#endif
    extern void HAL_UART_MspInitEx(UART_HandleTypeDef *huart);
    HAL_UART_MspInitEx(huart);
}
```
### 修改board.h

> ***注意：本步骤只适用于RTT完整版本的移植***

使能PLC专用串口及相关管脚配置，例如使用USART1作为PLC专用串口：
```
#define BSP_USING_UART1
#if defined(BSP_USING_UART1)
#define UART1_TX_PORT       GPIOA
#define UART1_RX_PORT       GPIOA
#define UART1_TX_PIN        GPIO_PIN_9
#define UART1_RX_PIN        GPIO_PIN_10
#endif
```
使能PLC专用硬件定时器，例如使用TIM3作为PLC专用硬件定时器：
```
#define BSP_USING_TIM
#ifdef BSP_USING_TIM
#define BSP_USING_TIM3
#endif
```

### 修改board.c中的时钟配置函数

RT-Thread Studio生成的工程默认使用HSI时钟，实际如果使用了HSE、LSE时钟，应该修改时钟配置，可以在CubeMX中配置好后，将生成的main.c中的SystemClock_Config()函数覆盖board.c中的SystemClock_Config()函数。
```
/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}
```
### 在board.c中增加中断向量表配置函数

> ***注意：如果想使用IAP程序通过串口下载程序至目标机，需要执行此步。如果使用JLINK、ST-Link下载程序，跳过此步。***

```
#define VECT_TAB_OFFSET  0x00006000U /*!< Vector Table base offset field.
                                  This value must be a multiple of 0x200. */
void VectorTable_Config(void)
{
#ifdef VECT_TAB_SRAM
  SCB->VTOR = SRAM_BASE | VECT_TAB_OFFSET; /* Vector Table Relocation in Internal SRAM. */
#else
  SCB->VTOR = FLASH_BASE | VECT_TAB_OFFSET; /* Vector Table Relocation in Internal FLASH. */
#endif
}
```

### 修改drv_common.c

> ***注意：如果想使用IAP程序通过串口下载程序至目标机，需要执行此步。如果使用JLINK、ST-Link下载程序，跳过此步。***

在函数rt_hw_board_init()中调用SystemClock_Config()之后增加下述代码：
```
    extern void VectorTable_Config(void);
    VectorTable_Config();
```
即：
```
    ...
    /* enable interrupt */
    __set_PRIMASK(0);
    /* System clock initialization */
    SystemClock_Config();

    /* NVIC Vector table config */
    extern void VectorTable_Config(void);
    VectorTable_Config();

    /* disbale interrupt */
    __set_PRIMASK(1);
    ...
```

### 修改link.lds

> ***注意：如果想使用IAP程序通过串口下载程序至目标机，需要执行此步。如果使用JLINK、ST-Link下载程序，跳过此步。***

ROM 的ORIGIN由0x8000000修改为0x8006000。LENGTH根据MCU实际ROM大小填写。

```
/* Program Entry, set to mark it as "used" and avoid gc */
MEMORY
{
    ROM (rx) : ORIGIN = 0x8006000, LENGTH =  232K /* 232K flash */
    RAM (rw) : ORIGIN = 0x20000000, LENGTH =  48k /* 48K sram */
}
```

---
## 4. 复制并修改plccore代码

### 将plccore文件夹复制至RTT Studio工程目录下

### 修改plccore/port/plc_port.h各选项配置

根据目标板及实际需求进行配置：
- 配置PLC专用串口设备名称（仅用于完整版移植）
- 配置PLC专用定时器设备名称（仅用于完整版移植）
- 配置输入管脚
- 配置输出管脚
- 配置I映像区大小
- 配置Q映像区大小
- 配置M映像区大小
- 配置支持的数据类型
- ...

例如：
```
/**
 * @file plc_port.h
 * @brief 资源处理器接口相关选项设置，制造商通过修改本文件对自己的处理器进行裁剪定制。
 * @author hyafz
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

```

### 修改plccore/port/plc_port.c文件
> ***本文件基本上都是nano版本移植才需要修改***

从Stm32CubeMX生成工程的src目录下的main.c文件中复制片上外设配置函数至plc_port.c，并实现各硬件相关的函数接口。例如：
```
/**
  * @file  plc_port.c
  * @brief  PLC处理器接口相关的实现
  * @author  hyafz
  */
#include "board.h"
#include "plc_port.h"

#ifndef RT_USING_DEVICE
#include "plc_comm.h"
#include "plc_timer.h"
#include "plc_io.h"

TIM_HandleTypeDef htim3;
UART_HandleTypeDef huart1;

/**
  * @brief TIM3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM3_Init(void)
{

  /* USER CODE BEGIN TIM3_Init 0 */

  /* USER CODE END TIM3_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM3_Init 1 */

  /* USER CODE END TIM3_Init 1 */
  htim3.Instance = TIM3;
  htim3.Init.Prescaler = 83;
  htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim3.Init.Period = 1000;
  htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim3) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim3, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM3_Init 2 */

  /* USER CODE END TIM3_Init 2 */

}

/**
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 115200;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6
                          |GPIO_PIN_7, GPIO_PIN_RESET);

  /*Configure GPIO pins : PC13 PC14 PC15 */
  GPIO_InitStruct.Pin = GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : PA0 PA1 PA2 PA3
                           PA4 PA5 PA6 PA7 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3
                          |GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : PB0 */
  GPIO_InitStruct.Pin = GPIO_PIN_0;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : PA15 */
  GPIO_InitStruct.Pin = GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PB3 PB4 PB5 PB6
                           PB7 */
  GPIO_InitStruct.Pin = GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6
                          |GPIO_PIN_7;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/**
  * @brief This function handles USART1 global interrupt.
  */
void USART1_IRQHandler(void)
{
  /* USER CODE BEGIN USART1_IRQn 0 */
  uint16_t rxCnt = huart1.RxXferCount;
  /* USER CODE END USART1_IRQn 0 */
  HAL_UART_IRQHandler(&huart1);
  /* USER CODE BEGIN USART1_IRQn 1 */
  if(rxCnt != huart1.RxXferCount){
      plcCommDataReceived();
  }
  /* USER CODE END USART1_IRQn 1 */
}

/**
  * @brief  Period elapsed callback in non-blocking mode
  * @param  htim TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if(htim == &htim3){
        plcTimeoutCallback();
    }
}

/**
  * @brief This function handles TIM2 global interrupt.
  */
void TIM3_IRQHandler(void)
{
  /* USER CODE BEGIN TIM2_IRQn 0 */

  /* USER CODE END TIM2_IRQn 0 */
  HAL_TIM_IRQHandler(&htim3);
  /* USER CODE BEGIN TIM2_IRQn 1 */

  /* USER CODE END TIM2_IRQn 1 */
}

void devCommInit(void)
{
    MX_USART1_UART_Init();
}

void devCommRxStart(void)
{
    HAL_UART_AbortReceive_IT(&huart1);
    CommRxCnt = 0;
    HAL_UART_Receive_IT(&huart1, CommRxBuf, RX_DATA_BUF_SIZE);
}

void devCommSend(unsigned char* pbuf, unsigned int size)
{
    HAL_UART_Transmit(&huart1, pbuf, size, 100);
}

void devTimerInit(void)
{
    MX_TIM3_Init();
}

void devTimerStart(void)
{
    __HAL_TIM_SET_COUNTER(&htim3, 0);
    HAL_TIM_Base_Start_IT(&htim3);
}

void devTimerStop(void)
{
    HAL_TIM_Base_Stop_IT(&htim3);
}

unsigned int devTimerCountGet(void)
{
    return __HAL_TIM_GET_COUNTER(&htim3);
}

void devIOInit(void)
{
    MX_GPIO_Init();
}

#define GPIO_PORT(pin)      ((GPIO_TypeDef *) (GPIOA_BASE + ((pin) / 16) * 0x0400UL))
#define GPIO_PIN(pin)       ((uint16_t)(0x0001 << ((pin) % 16)))
unsigned char devInputPinRead(unsigned int pin)
{
    return (unsigned char)HAL_GPIO_ReadPin(GPIO_PORT(pin), GPIO_PIN(pin));
}

void devOutputPinWrite(unsigned int pin, unsigned int val)
{
    HAL_GPIO_WritePin(GPIO_PORT(pin), GPIO_PIN(pin), val);
}

#endif

void iapModeEnter(void)
{
    HAL_NVIC_SystemReset(); //复位则返回IAP程序入口
}

```

### 修改main.c文件

在main函数中添加如下代码：
```c
int main(void)
{
    extern void plcMain(void);
    plcMain();

    while (1)
    {
        rt_thread_mdelay(1000);
    }

    return RT_EOK;
}

```

### 从examples/目录下剪切plcapp文件夹，粘贴到RT-Thread Studio工程目录下
> 注意是剪切！

plcapp存放了PLC集成开发环境软件根据用户逻辑程序（梯形图、指令表）生成的C语言代码文件，将其复制至RT-Thread Studio工程目录然后在RT-Thread Studio界面刷新项目树。

### 设置包含路径

在RT-Thread Studio主菜单“项目”->“属性”->“C/C++常规”->“路径和符号”中添加plccore、plctapp的包含路径。

### 修改目标文件名

在RT-Thread Studio主菜单“项目”->“属性”->“C/C++构建”->“设置”->“构建工件”->“Artifact name:”中写入新的名字。

### 编译RT-Thread Studio工程

编译成功则移植完成。

---
## 5. 与PLC IDE结合使用
PLC IDE分为社区版与标准版，目前仅提供社区版免费使用，标准版正在开发中。
- 社区版
  - 在PLC IDE中，用户可以建立PLC应用工程，使用PLC编程语言，比如指令表、梯形图等实现用户逻辑，然后生成C语言源代码文件，保存在工程目录的plctoc_output子目录中。
  - 将plctoc_output目录中的所有.c/.h文件复制至RTT移植工程的plcapp目录下，注意只复制文件，不复制目录结构。
  - 刷新RTT移植工程，然后编译生成目标代码，下载至目标板，即可实现用户逻辑控制。

- 标准版
  - 移植完成后，将RT-Thread Studio工程文件夹整体复制至PLC IDE执行目录下的processors目录中，这样就可以作为一种新的PLC处理器使用。
  - 在PLC IDE中，用户可以建立PLC应用工程，使用PLC编程语言，比如指令表、梯形图等实现用户逻辑，然后直接编译、连接，再下载至目标板，即可实现逻辑控制。

### 关于PLC IDE

PLC IDE是一款可编程控制器的集成开发环境，实现了符合IEC61131-3标准的软件模型和编程模型，编程简单、配置灵活、系统扩展性好。支持标准的指令表（IL）、结构化文本（ST）、梯形图（LD）等PLC编程语言，能够将PLC用户逻辑代码编译为目标硬件的二进制目标代码，实现编译型PLC。相比于传统的解释型PLC，指令执行效率更高，存储密度更高，且具有更高的可靠性。

---
## 结束