/*
 * File: Medium_Self_Balance_Vehicle_TIM.c
 *
 * Code generated for Simulink model :Medium_Self_Balance_Vehicle.
 *
 * Model version      : 1.230
 * Simulink Coder version    : 8.14 (R2018a) 06-Feb-2018
 * TLC version       : 8.14 (Feb 22 2018)
 * C/C++ source code generated on  : Wed Dec  4 12:08:31 2019
 *
 * Target selection: stm32.tlc
 * Embedded hardware selection: STMicroelectronics->STM32 32-bit Cortex-M
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

#include "Medium_Self_Balance_Vehicle.h"
#include "Medium_Self_Balance_Vehicle_TIM.h"

uint16_t G_NbTimConf = 0;              /* Number of configured TIMER*/

/* Array of TIMER data information */
TIM_DataLinkTypeDef* G_TIM_Data[4];
TIM_HandleTypeDef* G_TIM_Handler[4];

/* TIM1 data information*/
TIM_DataLinkTypeDef TIM1_DataLink;

/* TIM1 polling timeout value. Number of Solver loop. (can be changed)*/
uint32_t G_TIM1_PollTimeOut = 10;

/* TIM4 data information*/
TIM_DataLinkTypeDef TIM4_DataLink;

/* TIM2 data information*/
TIM_DataLinkTypeDef TIM2_DataLink;

/* TIM3 data information*/
TIM_DataLinkTypeDef TIM3_DataLink;

/*******************************************************************************
 * Function Name  : HAL_TIM_PeriodElapsedCallback
 * Description    : Timer callback for update event
 * Input          : TIM_HandleTypeDef*   TIM IC handle
 *******************************************************************************/
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  uint16_t L_TimHandleIdx = 0;         /* Index to retreive TIM data information */
  TIM_DataLinkTypeDef* pL_TIM_Data = G_TIM_Data[0];/* Pt to the list of TIM data information */
  TIM_HandleTypeDef* pL_TIM_Handler = G_TIM_Handler[0];/* Pt to the list of TIM handler */
  for (L_TimHandleIdx = 0;L_TimHandleIdx < 4;L_TimHandleIdx++) {
    pL_TIM_Handler = G_TIM_Handler[L_TimHandleIdx];
    if (pL_TIM_Handler == htim) {
      pL_TIM_Data = G_TIM_Data[L_TimHandleIdx];
      break;
    }
  }

  if (pL_TIM_Handler == htim) {
    if (pL_TIM_Data->ItUpFcn != NULL) {
      /* Call update function for TIM3 */
      pL_TIM_Data->ItUpFcn();
    }
  }
}

/*******************************************************************************
 * Function Name  : TIM3_ItUpFcn
 * Description    : TIM3 update interrupt
 * Input          : None
 * TIM3_ItUpFcn is called from HAL_TIM_PeriodElapsedCallback function
 * in Medium_Self_Balance_Vehicle_TIM.c file.
 *******************************************************************************/
void TIM3_ItUpFcn()
{
  {
    /* Output and update for function-call system: '<Root>/Function-Call Subsystem' */
    {
      real_T rtb_Gain1_h;
      int32_T s16_iter;
      rtb_Gain1_h = LEDflash + 1.0;
      LEDflash++;
      if (rtb_Gain1_h > 200.0) {
        LEDflash = 0.0;

        /* S-Function Block: <S15>/GPIO_Write */

        //
        HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_4);
      }

      /* S-Function Block: <S5>/REG_Access3 */
      Medium_Self_Balance_Vehicle_B.REG_Access3 = ADC1->CNT;
      EncoderB = Medium_Self_Balance_Vehicle_B.REG_Access3;

      /* S-Function Block: <S5>/REG_Access2 */
      ADC1->CNT = 0;

      /* S-Function Block: <S7>/REG_Access1 */
      Medium_Self_Balance_Vehicle_B.REG_Access1 = ADC1->CNT;
      EncoderA = Medium_Self_Balance_Vehicle_B.REG_Access1;

      /* S-Function Block: <S7>/REG_Access */
      ADC1->CNT = 0;
      MPU6050ReadDATA(Medium_Self_Balance_Vehicle_B.accel,
                      Medium_Self_Balance_Vehicle_B.Tempera,
                      Medium_Self_Balance_Vehicle_B.gyro);
      Temputure = 0.0294 * (real_T)Medium_Self_Balance_Vehicle_B.Tempera + 365.3;
      Accel_X = Medium_Self_Balance_Vehicle_B.accel[0];
      Accel_Y = Medium_Self_Balance_Vehicle_B.accel[1];
      Accel_Z = Medium_Self_Balance_Vehicle_B.accel[2];
      rtb_Gain1_h = Medium_Self_Balance_Vehicle_B.gyro[1];
      Gyro_Y = 0.061 * rtb_Gain1_h;
      rtb_Gain1_h = Medium_Self_Balance_Vehicle_B.gyro[0];
      Gyro_X = 0.061 * rtb_Gain1_h;
      rtb_Gain1_h = Medium_Self_Balance_Vehicle_B.gyro[2];
      Gyro_Z = 0.061 * rtb_Gain1_h;
      acc_pitch = atan(Accel_Y / Accel_Z) * 57.3;
      pitch = (0.005 * Gyro_Y + pitch) * 0.98 + 0.02 * acc_pitch;
      Angle = pitch;

      /* S-Function Block: <S6>/ADC_Read */

      /* Read regular ADC1 value */
      for (uint16_t i=0;i<1;i++)
        if (HAL_ADC_PollForConversion(&hadc1, G_ADC1_PollTimeOut) == HAL_OK) {
          ADC1_RegularConvertedValue[i] = (uint16_t)HAL_ADC_GetValue(&hadc1);
        }

      /* Get regular rank1 output value from ADC1 regular value buffer */
      Medium_Self_Balance_Vehicle_B.ADC_Read = (uint16_t)
        ADC1_RegularConvertedValue[0];

      /* Re-Start ADC1 conversion */
      HAL_ADC_Start(&hadc1);
      rtb_Gain1_h = 0.0;
      for (s16_iter = 0; s16_iter < 10; s16_iter++) {
        rtb_Gain1_h += Medium_Self_Balance_Vehicle_B.ADC_Read;
      }

      Voltage = 0.1 * rtb_Gain1_h * 0.00886;

      /* S-Function Block: <S10>/GPIO_Read */
      Medium_Self_Balance_Vehicle_B.GPIO_Read = (boolean_T)HAL_GPIO_ReadPin
        (GPIOA, GPIO_PIN_5);
      if (Medium_Self_Balance_Vehicle_B.GPIO_Read == 0.0) {
        Medium_Self_Balance_Vehicle_DW.key5_flag++;
      } else if (Medium_Self_Balance_Vehicle_DW.key5_flag >= 2) {
        Medium_Self_Balance_Vehicle_DW.key5_click = 1;
        Medium_Self_Balance_Vehicle_DW.key5_flag = 0;
      } else {
        Medium_Self_Balance_Vehicle_DW.key5_click = 0;
        Medium_Self_Balance_Vehicle_DW.key5_flag = 0;
      }

      KEY_USER = Medium_Self_Balance_Vehicle_DW.key5_click;
      if (KEY_USER == 1) {
        Flagstop = !Flagstop;
      }

      Ang_moto = 300.0 * Angle + Gyro_Y * 25.0;
      Medium_Self_Balance_Vehicle_DW.Delay_DSTATE = (real_T)(int16_T)((int16_T)
        (EncoderA + EncoderB) - Tar_V) * 0.2 + 0.8 *
        Medium_Self_Balance_Vehicle_DW.Delay_DSTATE;
      Encoder_bias = Medium_Self_Balance_Vehicle_DW.Delay_DSTATE;
      Medium_Self_Balance_Vehicle_DW.UnitDelay_DSTATE += Encoder_bias;
      if (Medium_Self_Balance_Vehicle_DW.UnitDelay_DSTATE > 10000.0) {
        rtb_Gain1_h = 10000.0;
      } else if (Medium_Self_Balance_Vehicle_DW.UnitDelay_DSTATE < -10000.0) {
        rtb_Gain1_h = -10000.0;
      } else {
        rtb_Gain1_h = Medium_Self_Balance_Vehicle_DW.UnitDelay_DSTATE;
      }

      Vel_moto = 400.0 * Encoder_bias + 1.3 * rtb_Gain1_h;
      Turn_moto = 10.0 * Tar_turn + Gyro_Z * -5.0;
      rtb_Gain1_h = Ang_moto + Vel_moto;
      MotorA = rtb_Gain1_h - Turn_moto;
      MotorB = rtb_Gain1_h + Turn_moto;
      if ((Angle > 40.0) || (Angle < -40.0)) {
        Flagstop = true;
      }

      if (Flagstop) {
        MotorA = 0.0;
        MotorB = 0.0;
      }

      if (MotorA > 6900.0) {
        rtb_Gain1_h = 6900.0;
      } else if (MotorA < -6900.0) {
        rtb_Gain1_h = -6900.0;
      } else {
        rtb_Gain1_h = MotorA;
      }

      rtb_Gain1_h = floor(0.0139 * rtb_Gain1_h);
      if (rtIsNaN(rtb_Gain1_h)) {
        rtb_Gain1_h = 0.0;
      } else {
        rtb_Gain1_h = fmod(rtb_Gain1_h, 65536.0);
      }

      motoa = (int16_T)(rtb_Gain1_h < 0.0 ? (int32_T)(int16_T)-(int16_T)
                        (uint16_T)-rtb_Gain1_h : (int32_T)(int16_T)(uint16_T)
                        rtb_Gain1_h);
      if (MotorB > 6900.0) {
        rtb_Gain1_h = 6900.0;
      } else if (MotorB < -6900.0) {
        rtb_Gain1_h = -6900.0;
      } else {
        rtb_Gain1_h = MotorB;
      }

      rtb_Gain1_h = floor(0.0139 * rtb_Gain1_h);
      if (rtIsNaN(rtb_Gain1_h)) {
        rtb_Gain1_h = 0.0;
      } else {
        rtb_Gain1_h = fmod(rtb_Gain1_h, 65536.0);
      }

      motob = (int16_T)(rtb_Gain1_h < 0.0 ? (int32_T)(int16_T)-(int16_T)
                        (uint16_T)-rtb_Gain1_h : (int32_T)(int16_T)(uint16_T)
                        rtb_Gain1_h);
      if (motob > 0) {
        /* S-Function Block: <S36>/GPIO_Write1 */

        /* Set GPIOB ouput mask value */
        GPIOB_maskWrite = GPIOB->ODR;
        GPIOB_maskWrite &= 0xCFFF ;
        GPIOB_maskWrite |= (uint16_t)1.0 << 12;
        GPIOB_maskWrite |= (uint16_t)0.0 << 13;

        /* Write GPIOB input value */
        GPIOB->ODR = (uint16_t)GPIOB_maskWrite;
        Medium_Self_Balance_Vehicle_B.DataStoreRead1_k = motob;
        if (Medium_Self_Balance_Vehicle_B.DataStoreRead1_k !=
            TIM1_DataLink.CH4_duty) {
          TIM1_DataLink.CH4_duty =
            Medium_Self_Balance_Vehicle_B.DataStoreRead1_k;
          if (Medium_Self_Balance_Vehicle_B.DataStoreRead1_k >= 0) {
            // Channe4 duty cycle is an input port
            __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_4, (uint32_t)
                                 (Medium_Self_Balance_Vehicle_B.DataStoreRead1_k
                                  * (&htim1)->Instance->ARR / 100));
          }
        }
      } else if (motob == 0) {
        /* S-Function Block: <S32>/GPIO_Write1 */

        /* Set GPIOB ouput mask value */
        GPIOB_maskWrite = GPIOB->ODR;
        GPIOB_maskWrite &= 0xCFFF ;
        GPIOB_maskWrite |= (uint16_t)0.0 << 12;
        GPIOB_maskWrite |= (uint16_t)0.0 << 13;

        /* Write GPIOB input value */
        GPIOB->ODR = (uint16_t)GPIOB_maskWrite;
        Medium_Self_Balance_Vehicle_B.DataStoreRead1_f = motob;
        if (Medium_Self_Balance_Vehicle_B.DataStoreRead1_f !=
            TIM1_DataLink.CH4_duty) {
          TIM1_DataLink.CH4_duty =
            Medium_Self_Balance_Vehicle_B.DataStoreRead1_f;
          if (Medium_Self_Balance_Vehicle_B.DataStoreRead1_f >= 0) {
            // Channe4 duty cycle is an input port
            __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_4, (uint32_t)
                                 (Medium_Self_Balance_Vehicle_B.DataStoreRead1_f
                                  * (&htim1)->Instance->ARR / 100));
          }
        }
      } else {
        Medium_Self_Balance_Vehicle_B.Divide_e = -motob;

        /* S-Function Block: <S35>/GPIO_Write3 */

        /* Set GPIOB ouput mask value */
        GPIOB_maskWrite = GPIOB->ODR;
        GPIOB_maskWrite &= 0xCFFF ;
        GPIOB_maskWrite |= (uint16_t)0.0 << 12;
        GPIOB_maskWrite |= (uint16_t)1.0 << 13;

        /* Write GPIOB input value */
        GPIOB->ODR = (uint16_t)GPIOB_maskWrite;
        if (Medium_Self_Balance_Vehicle_B.Divide_e != TIM1_DataLink.CH4_duty) {
          TIM1_DataLink.CH4_duty = Medium_Self_Balance_Vehicle_B.Divide_e;
          if (Medium_Self_Balance_Vehicle_B.Divide_e >= 0) {
            // Channe4 duty cycle is an input port
            __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_4, (uint32_t)
                                 (Medium_Self_Balance_Vehicle_B.Divide_e *
                                  (&htim1)->Instance->ARR / 100));
          }
        }
      }

      if (motoa > 0) {
        /* S-Function Block: <S34>/GPIO_Write1 */

        /* Set GPIOB ouput mask value */
        GPIOB_maskWrite = GPIOB->ODR;
        GPIOB_maskWrite &= 0x3FFF ;
        GPIOB_maskWrite |= (uint16_t)1.0 << 14;
        GPIOB_maskWrite |= (uint16_t)0.0 << 15;

        /* Write GPIOB input value */
        GPIOB->ODR = (uint16_t)GPIOB_maskWrite;
        Medium_Self_Balance_Vehicle_B.DataStoreRead1_e = motoa;
        if (Medium_Self_Balance_Vehicle_B.DataStoreRead1_e !=
            TIM1_DataLink.CH1_duty) {
          TIM1_DataLink.CH1_duty =
            Medium_Self_Balance_Vehicle_B.DataStoreRead1_e;
          if (Medium_Self_Balance_Vehicle_B.DataStoreRead1_e >= 0) {
            // Channel1 duty cycle is an input port
            __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_1, (uint32_t)
                                 (Medium_Self_Balance_Vehicle_B.DataStoreRead1_e
                                  * (&htim1)->Instance->ARR / 100));
          }
        }
      } else if (motoa == 0) {
        /* S-Function Block: <S31>/GPIO_Write1 */

        /* Set GPIOB ouput mask value */
        GPIOB_maskWrite = GPIOB->ODR;
        GPIOB_maskWrite &= 0x3FFF ;
        GPIOB_maskWrite |= (uint16_t)0.0 << 14;
        GPIOB_maskWrite |= (uint16_t)0.0 << 15;

        /* Write GPIOB input value */
        GPIOB->ODR = (uint16_t)GPIOB_maskWrite;
        Medium_Self_Balance_Vehicle_B.DataStoreRead1 = motoa;
        if (Medium_Self_Balance_Vehicle_B.DataStoreRead1 !=
            TIM1_DataLink.CH1_duty) {
          TIM1_DataLink.CH1_duty = Medium_Self_Balance_Vehicle_B.DataStoreRead1;
          if (Medium_Self_Balance_Vehicle_B.DataStoreRead1 >= 0) {
            // Channel1 duty cycle is an input port
            __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_1, (uint32_t)
                                 (Medium_Self_Balance_Vehicle_B.DataStoreRead1 *
                                  (&htim1)->Instance->ARR / 100));
          }
        }
      } else {
        Medium_Self_Balance_Vehicle_B.Divide = -motoa;

        /* S-Function Block: <S33>/GPIO_Write3 */

        /* Set GPIOB ouput mask value */
        GPIOB_maskWrite = GPIOB->ODR;
        GPIOB_maskWrite &= 0x3FFF ;
        GPIOB_maskWrite |= (uint16_t)0.0 << 14;
        GPIOB_maskWrite |= (uint16_t)1.0 << 15;

        /* Write GPIOB input value */
        GPIOB->ODR = (uint16_t)GPIOB_maskWrite;
        if (Medium_Self_Balance_Vehicle_B.Divide != TIM1_DataLink.CH1_duty) {
          TIM1_DataLink.CH1_duty = Medium_Self_Balance_Vehicle_B.Divide;
          if (Medium_Self_Balance_Vehicle_B.Divide >= 0) {
            // Channel1 duty cycle is an input port
            __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_1, (uint32_t)
                                 (Medium_Self_Balance_Vehicle_B.Divide * (&htim1)
                                  ->Instance->ARR / 100));
          }
        }
      }
    }
  }
}

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF] Medium_Self_Balance_Vehicle_TIM.c
 */
