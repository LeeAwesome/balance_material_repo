/*
 * File: LED_Test.h
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

#ifndef RTW_HEADER_LED_Test_h_
#define RTW_HEADER_LED_Test_h_
#include "STM32_Config.h"
#include "LED_Test_External_Functions.h"
#include "LED_Test_TIM.h"
#ifndef LED_Test_COMMON_INCLUDES_
# define LED_Test_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* LED_Test_COMMON_INCLUDES_ */

#include "LED_Test_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Real-time Model Data Structure */
struct tag_RTM_LED_Test {
  const char_T *errorStatus;
};

/* Model entry point functions */
extern void LED_Test_initialize(void);
extern void LED_Test_step(void);

/* Real-time Model object */
extern RT_MODEL_LED_Test *const LED_Test_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'LED_Test'
 * '<S1>'   : 'LED_Test/Function-Call Subsystem'
 */
#endif                                 /* RTW_HEADER_LED_Test_h_ */

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF] LED_Test.h
 */
