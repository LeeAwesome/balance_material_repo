/*
 * File: Medium_Self_Balance_Vehicle.h
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

#ifndef RTW_HEADER_Medium_Self_Balance_Vehicle_h_
#define RTW_HEADER_Medium_Self_Balance_Vehicle_h_
#include <math.h>
#include <string.h>
#include "Medium_Self_Balance_Vehicle_TIM.h"
#include "Medium_Self_Balance_Vehicle_ADC.h"
#include "STM32_Config.h"
#include "Medium_Self_Balance_Vehicle_External_Functions.h"
#include "Medium_Self_Balance_Vehicle_USART.h"
#ifndef Medium_Self_Balance_Vehicle_COMMON_INCLUDES_
# define Medium_Self_Balance_Vehicle_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Medium_Self_Balance_Vehicle_COMMON_INCLUDES_ */

#include "Medium_Self_Balance_Vehicle_types.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* GPIOB ouput mask value declaration*/
extern uint16_t GPIOB_maskWrite;

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* user code (top of header file) */
#include "delay.h"

/* Block signals (default storage) */
typedef struct {
  real_T ADC_Read;                     /* '<S6>/ADC_Read' */
  real_T GPIO_Read;                    /* '<S10>/GPIO_Read' */
  uint32_T Buff;                       /* '<Root>/MATLAB Function' */
  int32_T Divide;                      /* '<S33>/Divide' */
  int32_T Divide_e;                    /* '<S35>/Divide' */
  uint16_T USART_Send;                 /* '<Root>/USART_Send' */
  uint16_T NbChar;                     /* '<Root>/MATLAB Function' */
  int16_T REG_Access3;                 /* '<S5>/REG_Access3' */
  int16_T REG_Access1;                 /* '<S7>/REG_Access1' */
  int16_T DataStoreRead1;              /* '<S31>/Data Store Read1' */
  int16_T DataStoreRead1_e;            /* '<S34>/Data Store Read1' */
  int16_T DataStoreRead1_f;            /* '<S32>/Data Store Read1' */
  int16_T DataStoreRead1_k;            /* '<S36>/Data Store Read1' */
  int16_T accel[3];                    /* '<S8>/Chart' */
  int16_T Tempera;                     /* '<S8>/Chart' */
  int16_T gyro[3];                     /* '<S8>/Chart' */
} B_Medium_Self_Balance_Vehicle;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Delay_DSTATE;                 /* '<S24>/Delay' */
  real_T UnitDelay_DSTATE;             /* '<S25>/Unit Delay' */
  real_T i;                            /* '<Root>/Chart' */
  int16_T key5_flag;                   /* '<S18>/Data Store Memory' */
  int16_T key5_click;                  /* '<S18>/Data Store Memory1' */
} DW_Medium_Self_Balance_Vehicle;

/* Real-time Model Data Structure */
struct tag_RTM_Medium_Self_Balance_Vehicle {
  const char_T *errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint8_T TID[2];
    } TaskCounters;
  } Timing;
};

/* Block signals (default storage) */
extern B_Medium_Self_Balance_Vehicle Medium_Self_Balance_Vehicle_B;

/* Block states (default storage) */
extern DW_Medium_Self_Balance_Vehicle Medium_Self_Balance_Vehicle_DW;

/*
 * Exported States
 *
 * Note: Exported states are block states with an exported global
 * storage class designation.  Code generation will declare the memory for these
 * states and exports their symbols.
 *
 */
extern real_T LEDflash;                /* '<Root>/Data Store Memory' */
extern real_T Accel_Y;                 /* '<Root>/Data Store Memory10' */
extern real_T Accel_Z;                 /* '<Root>/Data Store Memory11' */
extern real_T Gyro_X;                  /* '<Root>/Data Store Memory12' */
extern real_T Gyro_Y;                  /* '<Root>/Data Store Memory13' */
extern real_T Gyro_Z;                  /* '<Root>/Data Store Memory14' */
extern real_T roll;                    /* '<Root>/Data Store Memory15' */
extern real_T Accel_X;                 /* '<Root>/Data Store Memory16' */
extern real_T yaw;                     /* '<Root>/Data Store Memory17' */
extern real_T pitch;                   /* '<Root>/Data Store Memory18' */
extern real_T Temputure;               /* '<Root>/Data Store Memory19' */
extern real_T acc_roll;                /* '<Root>/Data Store Memory20' */
extern real_T acc_yaw;                 /* '<Root>/Data Store Memory21' */
extern real_T acc_pitch;               /* '<Root>/Data Store Memory22' */
extern real_T moto;                    /* '<Root>/Data Store Memory23' */
extern real_T Ang_moto;                /* '<Root>/Data Store Memory24' */
extern real_T Vel_moto;                /* '<Root>/Data Store Memory25' */
extern real_T Turn_moto;               /* '<Root>/Data Store Memory26' */
extern real_T Tar_turn;                /* '<Root>/Data Store Memory27' */
extern real_T Voltage;                 /* '<Root>/Data Store Memory29' */
extern real_T MotorB;                  /* '<Root>/Data Store Memory3' */
extern real_T Encoder_bias;            /* '<Root>/Data Store Memory30' */
extern real_T MotorA;                  /* '<Root>/Data Store Memory4' */
extern real_T Angle;                   /* '<Root>/Data Store Memory9' */
extern int16_T EncoderB;               /* '<Root>/Data Store Memory1' */
extern int16_T EncoderA;               /* '<Root>/Data Store Memory2' */
extern int16_T motoa;                  /* '<Root>/Data Store Memory5' */
extern int16_T KEY_USER;               /* '<Root>/Data Store Memory6' */
extern int16_T motob;                  /* '<Root>/Data Store Memory7' */
extern int16_T Tar_V;                  /* '<Root>/Data Store Memory8' */
extern boolean_T Flagstop;             /* '<Root>/Data Store Memory28' */

/* Model entry point functions */
extern void Medium_Self_Balance_Vehicle_initialize(void);
extern void Medium_Self_Balance_Vehicle_step(void);

/* Real-time Model object */
extern RT_MODEL_Medium_Self_Balance_Vehicle *const Medium_Self_Balance_Vehicle_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S25>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S13>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S13>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<Root>/Rate Transition' : Eliminated since input and output rates are identical
 * Block '<Root>/Rate Transition1' : Eliminated since input and output rates are identical
 */

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
 * '<Root>' : 'Medium_Self_Balance_Vehicle'
 * '<S1>'   : 'Medium_Self_Balance_Vehicle/Chart'
 * '<S2>'   : 'Medium_Self_Balance_Vehicle/Function-Call Subsystem'
 * '<S3>'   : 'Medium_Self_Balance_Vehicle/MATLAB Function'
 * '<S4>'   : 'Medium_Self_Balance_Vehicle/Function-Call Subsystem/Subsystem'
 * '<S5>'   : 'Medium_Self_Balance_Vehicle/Function-Call Subsystem/Subsystem1'
 * '<S6>'   : 'Medium_Self_Balance_Vehicle/Function-Call Subsystem/Subsystem10'
 * '<S7>'   : 'Medium_Self_Balance_Vehicle/Function-Call Subsystem/Subsystem2'
 * '<S8>'   : 'Medium_Self_Balance_Vehicle/Function-Call Subsystem/Subsystem3'
 * '<S9>'   : 'Medium_Self_Balance_Vehicle/Function-Call Subsystem/Subsystem4'
 * '<S10>'  : 'Medium_Self_Balance_Vehicle/Function-Call Subsystem/Subsystem5'
 * '<S11>'  : 'Medium_Self_Balance_Vehicle/Function-Call Subsystem/Subsystem6'
 * '<S12>'  : 'Medium_Self_Balance_Vehicle/Function-Call Subsystem/Subsystem7'
 * '<S13>'  : 'Medium_Self_Balance_Vehicle/Function-Call Subsystem/Subsystem8'
 * '<S14>'  : 'Medium_Self_Balance_Vehicle/Function-Call Subsystem/Subsystem9'
 * '<S15>'  : 'Medium_Self_Balance_Vehicle/Function-Call Subsystem/Subsystem/If Action Subsystem'
 * '<S16>'  : 'Medium_Self_Balance_Vehicle/Function-Call Subsystem/Subsystem10/For Iterator Subsystem1'
 * '<S17>'  : 'Medium_Self_Balance_Vehicle/Function-Call Subsystem/Subsystem3/Chart'
 * '<S18>'  : 'Medium_Self_Balance_Vehicle/Function-Call Subsystem/Subsystem5/Atomic Subsystem'
 * '<S19>'  : 'Medium_Self_Balance_Vehicle/Function-Call Subsystem/Subsystem5/If Action Subsystem'
 * '<S20>'  : 'Medium_Self_Balance_Vehicle/Function-Call Subsystem/Subsystem5/Atomic Subsystem/If Action Subsystem'
 * '<S21>'  : 'Medium_Self_Balance_Vehicle/Function-Call Subsystem/Subsystem5/Atomic Subsystem/If Action Subsystem1'
 * '<S22>'  : 'Medium_Self_Balance_Vehicle/Function-Call Subsystem/Subsystem5/Atomic Subsystem/If Action Subsystem1/If Action Subsystem'
 * '<S23>'  : 'Medium_Self_Balance_Vehicle/Function-Call Subsystem/Subsystem5/Atomic Subsystem/If Action Subsystem1/If Action Subsystem1'
 * '<S24>'  : 'Medium_Self_Balance_Vehicle/Function-Call Subsystem/Subsystem6/Filter'
 * '<S25>'  : 'Medium_Self_Balance_Vehicle/Function-Call Subsystem/Subsystem6/PI controller'
 * '<S26>'  : 'Medium_Self_Balance_Vehicle/Function-Call Subsystem/Subsystem6/Subsystem'
 * '<S27>'  : 'Medium_Self_Balance_Vehicle/Function-Call Subsystem/Subsystem6/Subsystem1'
 * '<S28>'  : 'Medium_Self_Balance_Vehicle/Function-Call Subsystem/Subsystem7/If Action Subsystem'
 * '<S29>'  : 'Medium_Self_Balance_Vehicle/Function-Call Subsystem/Subsystem7/If Action Subsystem1'
 * '<S30>'  : 'Medium_Self_Balance_Vehicle/Function-Call Subsystem/Subsystem7/If Action Subsystem2'
 * '<S31>'  : 'Medium_Self_Balance_Vehicle/Function-Call Subsystem/Subsystem9/If Action Subsystem1'
 * '<S32>'  : 'Medium_Self_Balance_Vehicle/Function-Call Subsystem/Subsystem9/If Action Subsystem2'
 * '<S33>'  : 'Medium_Self_Balance_Vehicle/Function-Call Subsystem/Subsystem9/If Action Subsystem3'
 * '<S34>'  : 'Medium_Self_Balance_Vehicle/Function-Call Subsystem/Subsystem9/If Action Subsystem4'
 * '<S35>'  : 'Medium_Self_Balance_Vehicle/Function-Call Subsystem/Subsystem9/If Action Subsystem5'
 * '<S36>'  : 'Medium_Self_Balance_Vehicle/Function-Call Subsystem/Subsystem9/If Action Subsystem6'
 */
#endif                                 /* RTW_HEADER_Medium_Self_Balance_Vehicle_h_ */

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF] Medium_Self_Balance_Vehicle.h
 */
