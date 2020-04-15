plccore软件包移植及使用说明
=========================

本软件包目前仅支持意法半导体的STM32系列MCU，同时也仅针对RT-Thread nano v3.1.3进行了测试验证。推荐使用RT-Thread Studio + Stm32CubeMX两款软件进行移植，操作方便，文档教程详细，即使是新手也很容易上手。
移植过程参考了RT-Thread官方提供的STM32系列BSP制作教程：https://github.com/RT-Thread/rt-thread/blob/master/bsp/stm32/docs/STM32%E7%B3%BB%E5%88%97BSP%E5%88%B6%E4%BD%9C%E6%95%99%E7%A8%8B.md 。

---
## 1. 准备

1. RT-Thread Studio软件（下载地址：https://www.rt-thread.org/page/studio.html）
2. Stm32CubeMX软件（下载地址：https://www.st.com/content/st_com/zh/products/development-tools/software-development-tools/stm32-software-development-tools/stm32-configurators-and-code-generators/stm32cubemx.html）
3. PLC组态及控制逻辑编程软件PLC IDE（电子邮件联系 401190549@qq.com 索取）
4. 获取plccore软件包
方式一：从github下载：https://github.com/hyafz/plccore
方式二：从码云下载：https://gitee.com/hyafz/plccore

---
## 2. 硬件要求
- 必须具备一个检测输入状态的GPIO作为运行开关状态检测；
- 必须具备一个控制LED亮灭的GPIO作为运行状态显示灯（运行时亮，停止时灭）；
- 必须具备一个控制LED亮灭的GPIO作为错误状态显示灯（正常时灭，错误时亮）；
- 必须具备一个与上位机通信的串口；
- 必须具备一个作为PLC主定时器的硬件定时器；

---
## 3. 使用RT-Thread Studio + Stm32CubeMX生成目标板的BSP工程

### 新建RT-Thread工程
- 启动RT-Thread Studio，新建RT-Thread工程
- 输入工程名称
- 选择工程文件存放路径
- 选择基于芯片
- 选择nano版本
- 选择对应的芯片型号
- 选择控制台串口
- 选择调试口（JTAG or SWD）
- 点击“完成”等待工程生成
- 在RT-Thread Settings中使能消息队列
- 在RT-Thread Settings中禁用互斥量
- 在RT-Thread Settings中禁用邮箱
- 如果 **不使用控制台串口** ，在RT-Thread Settings中禁止“为rt_kprintf使用控制台”，推荐不使用控制台串口。

![新建RTT工程配置](images/new_rtt_project_config.png)

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

> ***注意：如果使用控制台串口，需要执行本步骤，否则跳过。***

因为drv_usart.c中已经实现了HAL_UART_MspInit()，不能重复定义，所以需要将stm32f1xx_hal_msp.c文件中的
```
void HAL_UART_MspInit(UART_HandleTypeDef* huart)
```
修改为
```
void HAL_UART_MspInitEx(UART_HandleTypeDef* huart)
```

### 修改drv_usart.c

> ***注意：如果使用控制台串口，需要执行本步骤，否则跳过。***

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
配置I映像区大小
配置Q映像区大小
配置M映像区大小
...

### 修改plccore/port/plc_port.c文件

- 从Stm32CubeMX生成工程的src目录下的main.c文件中复制片上外设配置函数至plc_port.c，例如：
```
static void MX_TIM2_Init(void)
{
    ...
}

static void MX_USART1_UART_Init(void)
{
    ...
}

static void MX_GPIO_Init(void)
{
    ...
}

```
- 复制中断处理相关函数至plc_port.c，例如：
```

/**
  * @brief  Rx Transfer completed callbacks.
  * @param  huart  Pointer to a UART_HandleTypeDef structure that contains
  *                the configuration information for the specified UART module.
  * @retval None
  */
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    if(huart == &huart1)  //根据配置的专属USART修改
    {
        dataReceive((unsigned char)CommRxData); //调用数据接收函数接口
    }
}

/**
  * @brief This function handles USART1 global interrupt.
  */
void USART1_IRQHandler(void)
{
  /* USER CODE BEGIN USART1_IRQn 0 */

  /* USER CODE END USART1_IRQn 0 */
  HAL_UART_IRQHandler(&huart1);
  /* USER CODE BEGIN USART1_IRQn 1 */

  /* USER CODE END USART1_IRQn 1 */
}

/**
  * @brief  Period elapsed callback in non-blocking mode
  * @param  htim TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if(htim == &htim2)  //根据配置的专属硬件定时器修改
    {
      plcTimerHook();   //调用PLC定时器处理函数接口
    }
}

/**
  * @brief This function handles TIM2 global interrupt.
  */
void TIM2_IRQHandler(void)
{
  /* USER CODE BEGIN TIM2_IRQn 0 */

  /* USER CODE END TIM2_IRQn 0 */
  HAL_TIM_IRQHandler(&htim2);
  /* USER CODE BEGIN TIM2_IRQn 1 */

  /* USER CODE END TIM2_IRQn 1 */
}
```
- 修改 DevInput[] 与 DevOutput[] 数组的配置
- 根据实际外设使用情况修改plc_port.c中其它函数的实现

### 从examples/目录下 剪切 main.c，替换RT-Thread Studio工程自动生成的main.c文件
> 注意是剪切，不能在工程里保留两个main.c文件。

main.c
```
/*
 * Copyright (c) 2006-2019, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2019-09-09     RT-Thread    first version
 */

#include <rtthread.h>

#define DBG_TAG "main"
#define DBG_LVL DBG_LOG
#include <rtdbg.h>

extern void plcMain(void);

int main(void)
{
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

移植完成后，将RT-Thread Studio工程文件夹整体复制至PLC IDE执行目录下的processors目录中，这样就可以作为一种新的PLC处理器使用。
在PLC IDE中，用户可以建立PLC应用工程，使用PLC编程语言，比如指令表、梯形图等实现用户逻辑，然后直接编译、连接，再下载至目标板，即可实现逻辑控制。

### 关于PLC IDE

PLC IDE是一款可编程控制器的集成开发环境，实现了符合IEC61131-3标准的软件模型和编程模型，编程简单、配置灵活、系统扩展性好。支持标准的指令表（IL）、结构化文本（ST）、梯形图（LD）等PLC编程语言，能够将PLC用户逻辑代码编译为目标硬件的二进制目标代码，实现编译型PLC。相比于传统的解释型PLC，指令执行效率更高，存储密度更高，且具有更高的可靠性。

---
## 结束