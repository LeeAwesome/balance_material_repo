/*
 * File: XszTest_TIM.c
 *
 * Code generated for Simulink model :XszTest.
 *
 * Model version      : 1.2
 * Simulink Coder version    : 9.3 (R2020a) 18-Nov-2019
 * TLC version       : 9.3 (Jan 23 2020)
 * C/C++ source code generated on  : Wed Aug  4 08:43:07 2021
 *
 * Target selection: stm32.tlc
 * Embedded hardware selection: STM32CortexM
 * Code generation objectives: Unspecified
 * Validation result: Not run
 *
 *
 *
 * ******************************************************************************
 * * attention
 * *
 * * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
 * * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
 * * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
 * * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
 * * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
 * * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
 * *
 * ******************************************************************************
 */

#include "XszTest.h"
#include "XszTest_TIM.h"

/* Number of configured TIMER. */
uint16_t G_TIM_Count = 0;

/* Array of TIMER information. */
TIM_ConfTypeDef* G_TIM_Conf[1];
TIM_HandleTypeDef* G_TIM_Handler[1];

/* TIM2 informations. */
TIM_ConfTypeDef TIM2_Conf;

/*******************************************************************************
 * Function Name  : TIM_PeriodElapsedCustomCallback
 * Description    : Timer callback for update event
 * Input          : TIM_HandleTypeDef*   TIM IC handle
 *******************************************************************************/
void TIM_PeriodElapsedCustomCallback(TIM_HandleTypeDef *htim)
{
  TIM_ConfTypeDef * pConf = G_TIM_Conf[0];
  TIM_HandleTypeDef* pHandler = G_TIM_Handler[0];
  if (pHandler == htim) {
    if (pConf->ItUpFcn != NULL) {
      /* Call update function for TIM2. */
      pConf->ItUpFcn();
    }
  }
}

/**
 * @brief  Period elapsed callback in non blocking mode
 * @param  htim TIM handle
 * @retval None
 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  extern void TIM_PeriodElapsedCustomCallback(TIM_HandleTypeDef *htim);

  /* Handle this event from model side. */
  TIM_PeriodElapsedCustomCallback(htim);
}

/*******************************************************************************
 * Function Name  : TIM2_ItUpFcn
 * Description    : TIM2 update interrupt
 * Input          : None
 * TIM2_ItUpFcn is called from TIM_PeriodElapsedCustomCallback function
 * in XszTest_TIM.c file.
 *******************************************************************************/
void TIM2_ItUpFcn()
{
  {
    /* Output and update for function-call system: '<Root>/Function-Call Subsystem1' */
    {
      HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_0);
    }
  }
}

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF] XszTest_TIM.c
 */
