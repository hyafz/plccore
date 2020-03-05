/**
  * @file  plc_port.c
  * @brief  PLC处理器接口相关的实现
  * @author  hyafz
  */
/* includes -----------------------------------------------------------------*/
#include "plc_port.h"
#include "plc_io.h"
#include "plc_comm.h"
#include "plc_timer.h"

/* Private define -----------------------------------------------------------*/
/* Private typedef ----------------------------------------------------------*/
/* Private macro ------------------------------------------------------------*/
/* Variables ----------------------------------------------------------------*/
TIM_HandleTypeDef htim2;

UART_HandleTypeDef huart1;

/**
 * @brief 输入设备控制结构数组
 * @note 第0个数组成员必须为运行开关RUN Switch，然后依次是数字量输入点IX0 ~ IXn
 */
DEV_IN_CTRL_S DevInput[DEV_INPUT_NUM] = \
{
   /* input devices */
    {
    /* gpio                  = */GPIOB,
    /* pin                   = */GPIO_PIN_12,
    /* default_state         = */GPIO_PIN_RESET,
    /* prev_input_state      = */GPIO_PIN_RESET,
    /* state                 = */GPIO_PIN_RESET,
    /* state_debounce_time   = */0,
    /* state_stay_time       = */0,
    },        /* RUN Switch */
    {
    /* gpio                  = */GPIOA,
    /* pin                   = */GPIO_PIN_0,
    /* default_state         = */GPIO_PIN_SET,
    /* prev_input_state      = */GPIO_PIN_SET,
    /* state                 = */GPIO_PIN_SET,
    /* state_debounce_time   = */0,
    /* state_stay_time       = */0,
    },        /* IX0 */
};

/**
 * @brief 输出设备控制结构数组
 * @note 第0个必须为运行状态LED，第1个为错误状态LED，然后依次是数字量输出点QX0 ~ QXn
 */
DEV_OUT_CTRL_S DevOutput[DEV_OUTPUT_NUM] = \
{
    {
    /* gpio           = */GPIOB,
    /* pin            = */GPIO_PIN_0,
    /* off_value      = */GPIO_PIN_SET ,
    /* on_value       = */GPIO_PIN_RESET ,
    /* out_value      = */GPIO_PIN_SET ,
    },        /* LED RUN */
    {
    /* gpio           = */GPIOB,
    /* pin            = */GPIO_PIN_0,
    /* off_value      = */GPIO_PIN_SET ,
    /* on_value       = */GPIO_PIN_RESET ,
    /* out_value      = */GPIO_PIN_SET ,
    },        /* LED ERR */
    {
    /* gpio           = */GPIOD,
    /* pin            = */GPIO_PIN_2,
    /* off_value      = */GPIO_PIN_SET ,
    /* on_value       = */GPIO_PIN_RESET ,
    /* out_value      = */GPIO_PIN_SET,
    },        /* QX0 */
};

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 71;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 1000;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

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
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2, GPIO_PIN_RESET);

  /*Configure GPIO pin : PA0 */
  GPIO_InitStruct.Pin = GPIO_PIN_0;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : PD2 */
  GPIO_InitStruct.Pin = GPIO_PIN_2;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

}

void plcProcessorInit(void)
{
    MX_GPIO_Init();

    MX_USART1_UART_Init();

    MX_TIM2_Init();
}

void devCommRxStart(void)
{
    HAL_UART_Receive_IT(&huart1, (uint8_t *)&CommRxData, 1);
}

void devCommSend(unsigned char* pbuf, unsigned int size)
{
    HAL_UART_Transmit(&huart1, pbuf, size, HAL_MAX_DELAY);
}

/**
  * @brief  Rx Transfer completed callbacks.
  * @param  huart  Pointer to a UART_HandleTypeDef structure that contains
  *                the configuration information for the specified UART module.
  * @retval None
  */
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    if(huart == &huart1)
    {
        dataReceive((unsigned char)CommRxData);
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
    plcTimerHook();
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

void devTimerStart(void)
{
    __HAL_TIM_SET_COUNTER(&htim2, 0);
    HAL_TIM_Base_Start_IT(&htim2);
}

void devTimerStop(void)
{
    HAL_TIM_Base_Stop_IT(&htim2);
}

unsigned int devTimerCountGet(void)
{
    return __HAL_TIM_GET_COUNTER(&htim2);
}

unsigned char devInputPinRead(int id)
{
    return (unsigned char)HAL_GPIO_ReadPin(DevInput[id].gpio, DevInput[id].pin);
}

void devOutputPinWrite(int id)
{
    HAL_GPIO_WritePin(DevOutput[id].gpio, DevOutput[id].pin, DevOutput[id].out_value);
}

void iapModeEnter(void)
{
    HAL_NVIC_SystemReset(); //复位则返回IAP程序入口
}

/* Private function declaration ---------------------------------------------*/
/* Functions ----------------------------------------------------------------*/

