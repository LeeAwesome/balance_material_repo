/*
 * File: XszTest.h
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

#ifndef RTW_HEADER_XszTest_h_
#define RTW_HEADER_XszTest_h_
#include "STM32_Config.h"
#include "XszTest_External_Functions.h"
#include "XszTest_TIM.h"
#ifndef XszTest_COMMON_INCLUDES_
# define XszTest_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* XszTest_COMMON_INCLUDES_ */

#include "XszTest_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Real-time Model Data Structure */
struct tag_RTM_XszTest {
  const char_T *errorStatus;
};

/* Model entry point functions */
extern void XszTest_initialize(void);
extern void XszTest_step(void);

/* Real-time Model object */
extern RT_MODEL_XszTest *const XszTest_M;

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
 * '<Root>' : 'XszTest'
 * '<S1>'   : 'XszTest/Function-Call Subsystem1'
 * '<S2>'   : 'XszTest/Function-Call Subsystem1/Subsystem'
 */
#endif                                 /* RTW_HEADER_XszTest_h_ */

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF] XszTest.h
 */
