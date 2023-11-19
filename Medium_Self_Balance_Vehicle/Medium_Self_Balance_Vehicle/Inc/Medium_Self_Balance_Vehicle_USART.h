/*
 * File: Medium_Self_Balance_Vehicle_USART.h
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

#ifndef RTW_HEADER_Medium_Self_Balance_Vehicle_USART_h_
#define RTW_HEADER_Medium_Self_Balance_Vehicle_USART_h_

//RP MODIF #include "Medium_Self_Balance_Vehicle_STM32.h"
#include "STM32_Config.h"

/**
 * @brief USART Tx State structures definition
 */
typedef enum {
  USART_TX_ON = 0x00,                  /*!< Tx usart communication start   */
  USART_TX_OK = 0x01,                  /*!< Tx usart communication terminated.*/
  USART_TX_OFF = 0x02                  /*!< Tx usart communication stop */
} USART_TxStatusTypeDef;

/**
 * @brief  USART data information
 */
struct USART_TxDataLinkTypeDef {
  uint16_t nb2Send;                    /*!< Nb of char to send*/
  uint16_t nbSent;                     /*!< Nb sent char*/
  uint16_t nbMsgLost;                  /*!< Nb lost msg (not enought space in ring buffer)*/
  uint16_t buffSize;                   /*!< Size of send ring buffer*/
  uint8_t* pt_StartTx_Buff;            /*!< point to ring buffer*/
  uint8_t* pt_EndTx_Buff;              /*!< point to end ring buffer*/
  uint8_t* pt_Tx_W;                    /*!< point to free space*/
  uint8_t* pt_Tx_R;                    /*!< point to char to send*/
  void (* CopyDataFcn)(uint8_t* ptSrc, uint16_t DataLength, struct
                       USART_TxDataLinkTypeDef* ptInfo);
  void (* SendDataFcn)(struct USART_TxDataLinkTypeDef* ptInfo);
  __IO USART_TxStatusTypeDef txStatus; /*!< Usart send communication status.*/
  uint8_t txLock;                      /*!< lock data access */
};

void USART1_CopyDataFcn (uint8_t*, uint16_t , struct USART_TxDataLinkTypeDef* );
void USART1_SendDataFcn (struct USART_TxDataLinkTypeDef* );

/* USART1 handler */
extern UART_HandleTypeDef huart1;

/* USART1 send data structure information*/
extern struct USART_TxDataLinkTypeDef USART1_TxDataLink;

/* USART1 data buffer send*/
extern uint8_t G_USART1_TxDataBuffer[];

/* USART1_Tx_Initialization prototyping */
void USART1_Tx_Initialization(void);

#endif                                 /* RTW_HEADER_Medium_Self_Balance_Vehicle_USART_h_ */

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF] Medium_Self_Balance_Vehicle_USART.h
 */
