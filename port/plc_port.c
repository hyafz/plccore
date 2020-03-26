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
TIM_HandleTypeDef htim4;

UART_HandleTypeDef huart1;

/**
 * @brief 输入设备控制结构数组
 * @note 第0个数组成员必须为运行开关RUN Switch，然后依次是数字量输入点IX0 ~ IXn
 */
DEV_IN_CTRL_S DevInput[DEV_INPUT_NUM] = \
{
   /* input devices */
    {
    /* gpio                  = */GPIOA,
    /* pin                   = */GPIO_PIN_0,
    /* default_state         = */GPIO_PIN_SET,
    /* prev_input_state      = */GPIO_PIN_SET,
    /* state                 = */GPIO_PIN_SET,
    /* state_debounce_time   = */0,
    /* state_stay_time       = */0,
    },        /* RUN Switch */
    {
    /* gpio                  = */GPIOB,
    /* pin                   = */GPIO_PIN_0,
    /* default_state         = */GPIO_PIN_SET,
    /* prev_input_state      = */GPIO_PIN_SET,
    /* state                 = */GPIO_PIN_SET,
    /* state_debounce_time   = */0,
    /* state_stay_time       = */0,
    },        /* IX0 */
    {
    /* gpio                  = */GPIOA,
    /* pin                   = */GPIO_PIN_7,
    /* default_state         = */GPIO_PIN_SET,
    /* prev_input_state      = */GPIO_PIN_SET,
    /* state                 = */GPIO_PIN_SET,
    /* state_debounce_time   = */0,
    /* state_stay_time       = */0,
    },        /* IX1 */
    {
    /* gpio                  = */GPIOA,
    /* pin                   = */GPIO_PIN_6,
    /* default_state         = */GPIO_PIN_SET,
    /* prev_input_state      = */GPIO_PIN_SET,
    /* state                 = */GPIO_PIN_SET,
    /* state_debounce_time   = */0,
    /* state_stay_time       = */0,
    },        /* IX2 */
    {
    /* gpio                  = */GPIOA,
    /* pin                   = */GPIO_PIN_5,
    /* default_state         = */GPIO_PIN_SET,
    /* prev_input_state      = */GPIO_PIN_SET,
    /* state                 = */GPIO_PIN_SET,
    /* state_debounce_time   = */0,
    /* state_stay_time       = */0,
    },        /* IX3 */
    {
    /* gpio                  = */GPIOA,
    /* pin                   = */GPIO_PIN_4,
    /* default_state         = */GPIO_PIN_SET,
    /* prev_input_state      = */GPIO_PIN_SET,
    /* state                 = */GPIO_PIN_SET,
    /* state_debounce_time   = */0,
    /* state_stay_time       = */0,
    },        /* IX4 */
    {
    /* gpio                  = */GPIOA,
    /* pin                   = */GPIO_PIN_3,
    /* default_state         = */GPIO_PIN_SET,
    /* prev_input_state      = */GPIO_PIN_SET,
    /* state                 = */GPIO_PIN_SET,
    /* state_debounce_time   = */0,
    /* state_stay_time       = */0,
    },        /* IX5 */
    {
    /* gpio                  = */GPIOA,
    /* pin                   = */GPIO_PIN_2,
    /* default_state         = */GPIO_PIN_SET,
    /* prev_input_state      = */GPIO_PIN_SET,
    /* state                 = */GPIO_PIN_SET,
    /* state_debounce_time   = */0,
    /* state_stay_time       = */0,
    },        /* IX6 */
    {
    /* gpio                  = */GPIOA,
    /* pin                   = */GPIO_PIN_1,
    /* default_state         = */GPIO_PIN_SET,
    /* prev_input_state      = */GPIO_PIN_SET,
    /* state                 = */GPIO_PIN_SET,
    /* state_debounce_time   = */0,
    /* state_stay_time       = */0,
    },        /* IX7 */
};

/**
 * @brief 输出设备控制结构数组
 * @note 第0个必须为运行状态LED，第1个为错误状态LED，然后依次是数字量输出点QX0 ~ QXn
 */
DEV_OUT_CTRL_S DevOutput[DEV_OUTPUT_NUM] = \
{
    {
    /* gpio           = */GPIOC,
    /* pin            = */GPIO_PIN_15,
    /* off_value      = */GPIO_PIN_RESET ,
    /* on_value       = */GPIO_PIN_SET ,
    /* out_value      = */GPIO_PIN_RESET ,
    },        /* LED RUN */
    {
    /* gpio           = */GPIOC,
    /* pin            = */GPIO_PIN_14,
    /* off_value      = */GPIO_PIN_RESET ,
    /* on_value       = */GPIO_PIN_SET ,
    /* out_value      = */GPIO_PIN_RESET ,
    },        /* LED STOP */
    {
    /* gpio           = */GPIOC,
    /* pin            = */GPIO_PIN_13,
    /* off_value      = */GPIO_PIN_RESET ,
    /* on_value       = */GPIO_PIN_SET ,
    /* out_value      = */GPIO_PIN_RESET ,
    },        /* LED ERR */
    {
    /* gpio           = */GPIOA,
    /* pin            = */GPIO_PIN_15,
    /* off_value      = */GPIO_PIN_RESET ,
    /* on_value       = */GPIO_PIN_SET ,
    /* out_value      = */GPIO_PIN_RESET,
    },        /* QX0 */
    {
    /* gpio           = */GPIOB,
    /* pin            = */GPIO_PIN_3,
    /* off_value      = */GPIO_PIN_RESET ,
    /* on_value       = */GPIO_PIN_SET ,
    /* out_value      = */GPIO_PIN_RESET,
    },        /* QX1 */
    {
    /* gpio           = */GPIOB,
    /* pin            = */GPIO_PIN_4,
    /* off_value      = */GPIO_PIN_RESET ,
    /* on_value       = */GPIO_PIN_SET ,
    /* out_value      = */GPIO_PIN_RESET,
    },        /* QX2 */
    {
    /* gpio           = */GPIOB,
    /* pin            = */GPIO_PIN_5,
    /* off_value      = */GPIO_PIN_RESET ,
    /* on_value       = */GPIO_PIN_SET ,
    /* out_value      = */GPIO_PIN_RESET,
    },        /* QX3 */
    {
    /* gpio           = */GPIOB,
    /* pin            = */GPIO_PIN_6,
    /* off_value      = */GPIO_PIN_RESET ,
    /* on_value       = */GPIO_PIN_SET ,
    /* out_value      = */GPIO_PIN_RESET,
    },        /* QX4 */
    {
    /* gpio           = */GPIOB,
    /* pin            = */GPIO_PIN_7,
    /* off_value      = */GPIO_PIN_RESET ,
    /* on_value       = */GPIO_PIN_SET ,
    /* out_value      = */GPIO_PIN_RESET,
    },        /* QX5 */
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
  htim2.Init.Prescaler = 83;
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
  * @brief TIM4 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM4_Init(void)
{

  /* USER CODE BEGIN TIM4_Init 0 */

  /* USER CODE END TIM4_Init 0 */

  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};

  /* USER CODE BEGIN TIM4_Init 1 */

  /* USER CODE END TIM4_Init 1 */
  htim4.Instance = TIM4;
  htim4.Init.Prescaler = 0;
  htim4.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim4.Init.Period = 0;
  htim4.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim4.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_PWM_Init(&htim4) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim4, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim4, &sConfigOC, TIM_CHANNEL_3) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_ConfigChannel(&htim4, &sConfigOC, TIM_CHANNEL_4) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM4_Init 2 */

  /* USER CODE END TIM4_Init 2 */
  HAL_TIM_MspPostInit(&htim4);

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

/**
  * @brief This function handles TIM4 global interrupt.
  */
void TIM4_IRQHandler(void)
{
  /* USER CODE BEGIN TIM4_IRQn 0 */

  /* USER CODE END TIM4_IRQn 0 */
  HAL_TIM_IRQHandler(&htim4);
  /* USER CODE BEGIN TIM4_IRQn 1 */

  /* USER CODE END TIM4_IRQn 1 */
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

