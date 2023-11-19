/*
 * File: Medium_Self_Balance_Vehicle_ADC.c
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
#include "Medium_Self_Balance_Vehicle_ADC.h"

ADC_DataLinkTypeDef* G_ADC_Data;       /* Pointer to ADC data information*/
ADC_HandleTypeDef* G_ADC_Handler;      /* Pointer to ADC handler */

/* ADC1 Regular channel Converted value buffer */
uint16_t ADC1_RegularConvertedValue[1];

/* ADC1 data information*/
ADC_DataLinkTypeDef ADC1_DataLink;

/* ADC1 polling timeout value. Number of Solver loop. (can be changed)*/
uint32_t G_ADC1_PollTimeOut = 10;

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF] Medium_Self_Balance_Vehicle_ADC.c
 */
