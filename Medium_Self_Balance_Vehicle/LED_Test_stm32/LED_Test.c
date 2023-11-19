/*
 * File: LED_Test.c
 *
 * Code generated for Simulink model :LED_Test.
 *
 * Model version      : 1.2
 * Simulink Coder version    : 9.3 (R2020a) 18-Nov-2019
 * TLC version       : 9.3 (Jan 23 2020)
 * C/C++ source code generated on  : Tue Aug  3 09:24:59 2021
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

#include "LED_Test.h"
#include "LED_Test_private.h"

/* Real-time model */
RT_MODEL_LED_Test LED_Test_M_;
RT_MODEL_LED_Test *const LED_Test_M = &LED_Test_M_;

/* Model step function */
void LED_Test_step(void)
{
  {
  }
}

/* Model initialize function */
void LED_Test_initialize(void)
{
  {
    /* user code (Start function Header) */
    {
      /* TIM2 initialization. */
      /* Store TIM2 informations and its handler. */
      G_TIM_Conf[G_TIM_Count] = &TIM2_Conf;
      G_TIM_Handler[G_TIM_Count] = &htim2;

      /* Store TIM information. */
      TIM2_Conf.TIM_Prescaler = 1999;
      TIM2_Conf.TIM_APBClock = 72000000;
      TIM2_Conf.TIM_ARR = 36000 - 1;
      TIM2_Conf.TIM_Clock = 36000.0;
      TIM2_Conf.TIM_Freq = 1.0;
      TIM2_Conf.CH1_duty = 0.0;
      TIM2_Conf.CH2_duty = 0.0;
      TIM2_Conf.CH3_duty = 0.0;
      TIM2_Conf.CH4_duty = 0.0;
      TIM2_Conf.CH1_type = UNKNOWN;
      TIM2_Conf.CH2_type = UNKNOWN;
      TIM2_Conf.CH3_type = UNKNOWN;
      TIM2_Conf.CH4_type = UNKNOWN;

      /* Interrupt handler default initialization. */
      TIM2_Conf.ItUpFcn = NULL;
      TIM2_Conf.ItTrgFcn = NULL;
      TIM2_Conf.ItComFcn = NULL;
      TIM2_Conf.ItBrkFcn = NULL;
      TIM2_Conf.ItCcFcn = NULL;

      /* Update interrupt function. */
      TIM2_Conf.ItUpFcn = TIM2_ItUpFcn;

      /* Auto-reload preload enable */
      /*****Bugzilla 63376 *****/
      /*SET_BIT((&htim2)->Instance->CR1,TIM_CR1_ARPE);*/

      /* Update register value with blockset value. */
      /* Prescaler. */
      __HAL_TIM_SET_PRESCALER(&htim2,TIM2_Conf.TIM_Prescaler);

      /* Autoreload: ARR. */
      __HAL_TIM_SET_AUTORELOAD(&htim2,36000 - 1);

      /* Update registers before start operation to come. */
      HAL_TIM_GenerateEvent(&htim2,TIM_EVENTSOURCE_UPDATE);
    }

    /* user code (Start function Body) */
    {
      /* TIM2 Start. */
      /* Starts the TIM Base generation in interrupt mode. */
      HAL_TIM_Base_Start_IT(&htim2);

      /* Start interrupt for Update event*/
      HAL_TIM_Base_Start_IT(&htim2);
    }
  }
}

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF] LED_Test.c
 */
