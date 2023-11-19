/*
 * File: Medium_Self_Balance_Vehicle.c
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
#include "Medium_Self_Balance_Vehicle_private.h"

/* GPIOB ouput mask value definition*/
uint16_t GPIOB_maskWrite;

/* Exported block states */
real_T LEDflash;                       /* '<Root>/Data Store Memory' */
real_T Accel_Y;                        /* '<Root>/Data Store Memory10' */
real_T Accel_Z;                        /* '<Root>/Data Store Memory11' */
real_T Gyro_X;                         /* '<Root>/Data Store Memory12' */
real_T Gyro_Y;                         /* '<Root>/Data Store Memory13' */
real_T Gyro_Z;                         /* '<Root>/Data Store Memory14' */
real_T roll;                           /* '<Root>/Data Store Memory15' */
real_T Accel_X;                        /* '<Root>/Data Store Memory16' */
real_T yaw;                            /* '<Root>/Data Store Memory17' */
real_T pitch;                          /* '<Root>/Data Store Memory18' */
real_T Temputure;                      /* '<Root>/Data Store Memory19' */
real_T acc_roll;                       /* '<Root>/Data Store Memory20' */
real_T acc_yaw;                        /* '<Root>/Data Store Memory21' */
real_T acc_pitch;                      /* '<Root>/Data Store Memory22' */
real_T moto;                           /* '<Root>/Data Store Memory23' */
real_T Ang_moto;                       /* '<Root>/Data Store Memory24' */
real_T Vel_moto;                       /* '<Root>/Data Store Memory25' */
real_T Turn_moto;                      /* '<Root>/Data Store Memory26' */
real_T Tar_turn;                       /* '<Root>/Data Store Memory27' */
real_T Voltage;                        /* '<Root>/Data Store Memory29' */
real_T MotorB;                         /* '<Root>/Data Store Memory3' */
real_T Encoder_bias;                   /* '<Root>/Data Store Memory30' */
real_T MotorA;                         /* '<Root>/Data Store Memory4' */
real_T Angle;                          /* '<Root>/Data Store Memory9' */
int16_T EncoderB;                      /* '<Root>/Data Store Memory1' */
int16_T EncoderA;                      /* '<Root>/Data Store Memory2' */
int16_T motoa;                         /* '<Root>/Data Store Memory5' */
int16_T KEY_USER;                      /* '<Root>/Data Store Memory6' */
int16_T motob;                         /* '<Root>/Data Store Memory7' */
int16_T Tar_V;                         /* '<Root>/Data Store Memory8' */
boolean_T Flagstop;                    /* '<Root>/Data Store Memory28' */

/* Block signals (default storage) */
B_Medium_Self_Balance_Vehicle Medium_Self_Balance_Vehicle_B;

/* Block states (default storage) */
DW_Medium_Self_Balance_Vehicle Medium_Self_Balance_Vehicle_DW;

/* Real-time model */
RT_MODEL_Medium_Self_Balance_Vehicle Medium_Self_Balance_Vehicle_M_;
RT_MODEL_Medium_Self_Balance_Vehicle *const Medium_Self_Balance_Vehicle_M =
  &Medium_Self_Balance_Vehicle_M_;
static void rate_scheduler(void);

/*
 *   This function updates active task flag for each subrate.
 * The function is called at model base rate, hence the
 * generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (Medium_Self_Balance_Vehicle_M->Timing.TaskCounters.TID[1])++;
  if ((Medium_Self_Balance_Vehicle_M->Timing.TaskCounters.TID[1]) > 9) {/* Sample time: [0.05s, 0.0s] */
    Medium_Self_Balance_Vehicle_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Model step function */
void Medium_Self_Balance_Vehicle_step(void)
{
  uint8_T buffer[32];
  uint8_T y[27];
  static const char_T b[16] = { 'u', '1', '=', ' ', '%', '5', 'd', ',', 'u', '2',
    '=', ' ', '%', '5', 'd', '\x00' };

  char_T b_0[16];
  int32_T i;
  if (Medium_Self_Balance_Vehicle_M->Timing.TaskCounters.TID[1] == 0) {
    /* S-Function Block: <Root>/STM32_Config */

    /*  i */
    if (Medium_Self_Balance_Vehicle_DW.i < 1.0) {
      IIC_Init();
      MPU6050_initialize();
      Medium_Self_Balance_Vehicle_DW.i++;
    }

    for (i = 0; i < 16; i++) {
      b_0[i] = b[i];
    }

    sprintf(buffer, b_0, (int32_T)EncoderA, (int32_T)EncoderB);
    for (i = 0; i < 24; i++) {
      y[i] = buffer[i];
    }

    y[24] = 13U;
    y[25] = 10U;
    y[26] = 0U;
    Medium_Self_Balance_Vehicle_B.Buff = getBuffPtr(y);
    Medium_Self_Balance_Vehicle_B.NbChar = 27U;

    /* S-Function Block: <Root>/USART_Send */
    if (Medium_Self_Balance_Vehicle_B.NbChar != 0) {
      /* Wait for end of current send data*/
      /* Copy data to send */
      USART1_CopyDataFcn((uint8_t*)Medium_Self_Balance_Vehicle_B.Buff, (uint16_t)
                         Medium_Self_Balance_Vehicle_B.NbChar,
                         &USART1_TxDataLink);
    }

    if (USART1_TxDataLink.nb2Send) {
      Medium_Self_Balance_Vehicle_B.USART_Send = 0;
      USART1_SendDataFcn(&USART1_TxDataLink);
    }

    if (USART1_TxDataLink.txStatus != USART_TX_ON) {
      Medium_Self_Balance_Vehicle_B.USART_Send = USART1_TxDataLink.nbSent;
    }
  }

  if (Medium_Self_Balance_Vehicle_M->Timing.TaskCounters.TID[1] == 0) {
  }

  rate_scheduler();
}

/* Model initialize function */
void Medium_Self_Balance_Vehicle_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Medium_Self_Balance_Vehicle_M, 0,
                sizeof(RT_MODEL_Medium_Self_Balance_Vehicle));

  /* block I/O */
  (void) memset(((void *) &Medium_Self_Balance_Vehicle_B), 0,
                sizeof(B_Medium_Self_Balance_Vehicle));

  /* states (dwork) */
  (void) memset((void *)&Medium_Self_Balance_Vehicle_DW, 0,
                sizeof(DW_Medium_Self_Balance_Vehicle));

  /* exported global states */
  LEDflash = 0.0;
  Accel_Y = 0.0;
  Accel_Z = 0.0;
  Gyro_X = 0.0;
  Gyro_Y = 0.0;
  Gyro_Z = 0.0;
  roll = 0.0;
  Accel_X = 0.0;
  yaw = 0.0;
  pitch = 0.0;
  Temputure = 0.0;
  acc_roll = 0.0;
  acc_yaw = 0.0;
  acc_pitch = 0.0;
  moto = 0.0;
  Ang_moto = 0.0;
  Vel_moto = 0.0;
  Turn_moto = 0.0;
  Tar_turn = 0.0;
  Voltage = 0.0;
  MotorB = 0.0;
  Encoder_bias = 0.0;
  MotorA = 0.0;
  Angle = 0.0;
  EncoderB = 0;
  EncoderA = 0;
  motoa = 0;
  KEY_USER = 0;
  motob = 0;
  Tar_V = 0;
  Flagstop = false;

  /* user code (Start function Body) */

  /*Store TIM4 data information and its handler */
  G_TIM_Data[G_NbTimConf] = &TIM4_DataLink;
  G_TIM_Handler[G_NbTimConf] = &htim4;
  G_NbTimConf++;                       /*Inc number of configured TIM */

  /*Store TIM information */
  TIM4_DataLink.TIM_Prescaler = 0;
  TIM4_DataLink.TIM_APBClock = 72000000;
  TIM4_DataLink.TIM_ARR = 65536 - 1;
  TIM4_DataLink.TIM_Clock = 7.2E+7;
  TIM4_DataLink.TIM_Freq = 1098.63;
  TIM4_DataLink.CH1_duty = 0.0;
  TIM4_DataLink.CH2_duty = 0.0;
  TIM4_DataLink.CH3_duty = 0.0;
  TIM4_DataLink.CH4_duty = 0.0;
  TIM4_DataLink.CH1_type = INPUT_ENCODER;
  TIM4_DataLink.CH2_type = INPUT_ENCODER;
  TIM4_DataLink.CH3_type = UNKNOWN;
  TIM4_DataLink.CH4_type = UNKNOWN;

  /* Interrupt vector initialization */
  TIM4_DataLink.ItUpFcn = NULL;
  TIM4_DataLink.ItTrgFcn = NULL;
  TIM4_DataLink.ItComFcn = NULL;
  TIM4_DataLink.ItBrkFcn = NULL;
  TIM4_DataLink.ItCcFcn = NULL;

  /* Auto-reload preload enable */
  SET_BIT((&htim4)->Instance->CR1, TIM_CR1_ARPE);

  /*Update register value with blocset value*/
  /*Prescaler*/
  __HAL_TIM_SET_PRESCALER(&htim4,TIM4_DataLink.TIM_Prescaler);

  /*Autoreload: ARR */
  __HAL_TIM_SetAutoreload(&htim4, 65536 - 1);
  HAL_TIM_Encoder_Start_IT(&htim4, TIM_CHANNEL_ALL);

  /* Wait for htim4 State READY */
  while ((&htim4)->State == HAL_TIM_STATE_BUSY) {
  }

  /* Wait for htim4 State READY */
  while ((&htim4)->State == HAL_TIM_STATE_BUSY) {
  }

  /*Store TIM2 data information and its handler */
  G_TIM_Data[G_NbTimConf] = &TIM2_DataLink;
  G_TIM_Handler[G_NbTimConf] = &htim2;
  G_NbTimConf++;                       /*Inc number of configured TIM */

  /*Store TIM information */
  TIM2_DataLink.TIM_Prescaler = 0;
  TIM2_DataLink.TIM_APBClock = 72000000;
  TIM2_DataLink.TIM_ARR = 65536 - 1;
  TIM2_DataLink.TIM_Clock = 7.2E+7;
  TIM2_DataLink.TIM_Freq = 1098.63;
  TIM2_DataLink.CH1_duty = 0.0;
  TIM2_DataLink.CH2_duty = 0.0;
  TIM2_DataLink.CH3_duty = 0.0;
  TIM2_DataLink.CH4_duty = 0.0;
  TIM2_DataLink.CH1_type = INPUT_ENCODER;
  TIM2_DataLink.CH2_type = INPUT_ENCODER;
  TIM2_DataLink.CH3_type = UNKNOWN;
  TIM2_DataLink.CH4_type = UNKNOWN;

  /* Interrupt vector initialization */
  TIM2_DataLink.ItUpFcn = NULL;
  TIM2_DataLink.ItTrgFcn = NULL;
  TIM2_DataLink.ItComFcn = NULL;
  TIM2_DataLink.ItBrkFcn = NULL;
  TIM2_DataLink.ItCcFcn = NULL;

  /* Auto-reload preload enable */
  SET_BIT((&htim2)->Instance->CR1, TIM_CR1_ARPE);

  /*Update register value with blocset value*/
  /*Prescaler*/
  __HAL_TIM_SET_PRESCALER(&htim2,TIM2_DataLink.TIM_Prescaler);

  /*Autoreload: ARR */
  __HAL_TIM_SetAutoreload(&htim2, 65536 - 1);
  HAL_TIM_Encoder_Start_IT(&htim2, TIM_CHANNEL_ALL);

  /* Wait for htim2 State READY */
  while ((&htim2)->State == HAL_TIM_STATE_BUSY) {
  }

  /* Wait for htim2 State READY */
  while ((&htim2)->State == HAL_TIM_STATE_BUSY) {
  }

  /* ADC1 initialization */
  /*Store ADC1 data information and its handler */
  G_ADC_Data = &ADC1_DataLink;
  G_ADC_Handler = &hadc1;
  ADC1_DataLink.RegularValueBuffer = ADC1_RegularConvertedValue;
  ADC1_DataLink.RegularCurrentRank = 0;
  ADC1_DataLink.nbRegChannel = 1;
  ADC1_DataLink.InjectedValueBuffer = NULL;
  ADC1_DataLink.InjectedCurrentRank = ADC_INJECTED_RANK_1;
  ADC1_DataLink.nbInjChannel = 0;

  /* Interrupt vector initialization */
  ADC1_DataLink.ItEOCFcn = NULL;
  ADC1_DataLink.ItJEOCFcn = NULL;
  ADC1_DataLink.ItAWDFcn = NULL;
  ADC1_DataLink.ItOVRFcn = NULL;
  ADC1_DataLink.ItDMAFullFcn = NULL;
  ADC1_DataLink.ItDMAHalfFullFcn = NULL;

  /* Force data alignment to Right */
  hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;

  /* DMA not used */
  ADC1_DataLink.useDMA = false;

  /* EOC/JEOC at end of single channel conversion */
  ADC1_DataLink.IntEndOfAllConv = false;

  /* Start ADC1 conversion */
  HAL_ADC_Start(&hadc1);

  /*Store TIM1 data information and its handler */
  G_TIM_Data[G_NbTimConf] = &TIM1_DataLink;
  G_TIM_Handler[G_NbTimConf] = &htim1;
  G_NbTimConf++;                       /*Inc number of configured TIM */

  /*Store TIM information */
  TIM1_DataLink.TIM_Prescaler = 0;
  TIM1_DataLink.TIM_APBClock = 72000000;
  TIM1_DataLink.TIM_ARR = 7200 - 1;
  TIM1_DataLink.TIM_Clock = 7.2E+7;
  TIM1_DataLink.TIM_Freq = 10000.0;
  TIM1_DataLink.CH1_duty = 0.0;
  TIM1_DataLink.CH2_duty = 0.0;
  TIM1_DataLink.CH3_duty = 0.0;
  TIM1_DataLink.CH4_duty = 0.0;
  TIM1_DataLink.CH1_type = OUTPUT_PWM;
  TIM1_DataLink.CH2_type = UNKNOWN;
  TIM1_DataLink.CH3_type = UNKNOWN;
  TIM1_DataLink.CH4_type = OUTPUT_PWM;

  /* Interrupt vector initialization */
  TIM1_DataLink.ItUpFcn = NULL;
  TIM1_DataLink.ItTrgFcn = NULL;
  TIM1_DataLink.ItComFcn = NULL;
  TIM1_DataLink.ItBrkFcn = NULL;
  TIM1_DataLink.ItCcFcn = NULL;

  /* Auto-reload preload enable */
  SET_BIT((&htim1)->Instance->CR1, TIM_CR1_ARPE);

  /*Update register value with blocset value*/
  /*Prescaler*/
  __HAL_TIM_SET_PRESCALER(&htim1,TIM1_DataLink.TIM_Prescaler);

  /*Autoreload: ARR */
  __HAL_TIM_SetAutoreload(&htim1, 7200 - 1);

  /*Set CH1 Pulse value*/
  __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_1, (uint32_t)((7200 - 1)/2));

  /*Set CH4 Pulse value*/
  __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_4, (uint32_t)((7200 - 1)/2));

  /* Wait for htim1 State READY */
  while ((&htim1)->State == HAL_TIM_STATE_BUSY) {
  }

  HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);

  /* Wait for htim1 State READY */
  while ((&htim1)->State == HAL_TIM_STATE_BUSY) {
  }

  HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_4);

  /*Store TIM3 data information and its handler */
  G_TIM_Data[G_NbTimConf] = &TIM3_DataLink;
  G_TIM_Handler[G_NbTimConf] = &htim3;
  G_NbTimConf++;                       /*Inc number of configured TIM */

  /*Store TIM information */
  TIM3_DataLink.TIM_Prescaler = 0;
  TIM3_DataLink.TIM_APBClock = 72000000;
  TIM3_DataLink.TIM_ARR = 49 - 1;
  TIM3_DataLink.TIM_Clock = 7.2E+7;
  TIM3_DataLink.TIM_Freq = 1.46938776E+6;
  TIM3_DataLink.CH1_duty = 0.0;
  TIM3_DataLink.CH2_duty = 0.0;
  TIM3_DataLink.CH3_duty = 0.0;
  TIM3_DataLink.CH4_duty = 0.0;
  TIM3_DataLink.CH1_type = UNKNOWN;
  TIM3_DataLink.CH2_type = UNKNOWN;
  TIM3_DataLink.CH3_type = UNKNOWN;
  TIM3_DataLink.CH4_type = UNKNOWN;

  /* Interrupt vector initialization */
  TIM3_DataLink.ItUpFcn = NULL;
  TIM3_DataLink.ItTrgFcn = NULL;
  TIM3_DataLink.ItComFcn = NULL;
  TIM3_DataLink.ItBrkFcn = NULL;
  TIM3_DataLink.ItCcFcn = NULL;

  /* Auto-reload preload enable */
  SET_BIT((&htim3)->Instance->CR1, TIM_CR1_ARPE);

  /*Update register value with blocset value*/
  /*Prescaler*/
  __HAL_TIM_SET_PRESCALER(&htim3,TIM3_DataLink.TIM_Prescaler);

  /*Autoreload: ARR */
  __HAL_TIM_SetAutoreload(&htim3, 49 - 1);

  /* Update interrupt function */
  TIM3_DataLink.ItUpFcn = TIM3_ItUpFcn;

  /* Start interrupt for Update event*/
  HAL_TIM_Base_Start_IT(&htim3);

  /* USART1 initialization for send*/
  USART1_Tx_Initialization();

  /* Start for function-call system: '<Root>/Function-Call Subsystem' */
  ;
  ;
  ;
  ;
  ;
  ;
  ;
  ;
  ;
  ;
  ;
  ;
  ;
  ;
  ;
  ;
  Flagstop = true;
  Medium_Self_Balance_Vehicle_DW.i = 0.0;

  /* System initialize for function-call system: '<Root>/Function-Call Subsystem' */
  Medium_Self_Balance_Vehicle_B.Tempera = 0;
  Medium_Self_Balance_Vehicle_B.accel[0] = 0;
  Medium_Self_Balance_Vehicle_B.gyro[0] = 0;
  Medium_Self_Balance_Vehicle_B.accel[1] = 0;
  Medium_Self_Balance_Vehicle_B.gyro[1] = 0;
  Medium_Self_Balance_Vehicle_B.accel[2] = 0;
  Medium_Self_Balance_Vehicle_B.gyro[2] = 0;
}

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF] Medium_Self_Balance_Vehicle.c
 */
