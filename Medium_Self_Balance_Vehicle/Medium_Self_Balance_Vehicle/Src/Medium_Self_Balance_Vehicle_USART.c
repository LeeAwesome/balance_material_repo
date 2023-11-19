/*
 * File: Medium_Self_Balance_Vehicle_USART.c
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
#include "Medium_Self_Balance_Vehicle_USART.h"

struct USART_TxDataLinkTypeDef* G_Usart_TxData;/* Pointer to USART/UART send data information*/
void* G_Usart_TxHandler;               /* Pointer to USART/UART handler configured for send*/

/* USART1 ring data send buffer*/
uint8_t G_USART1_TxDataBuffer[56];

/* USART1 send data structure information*/
struct USART_TxDataLinkTypeDef USART1_TxDataLink;

/*******************************************************************************
 * Function Name  : HAL_UART_TxCpltCallback
 * Description    : Tx Transfer completed callbacks.
 * Input          : UART handle
 *******************************************************************************/
void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
{
  struct USART_TxDataLinkTypeDef* pL_UART_TxData = G_Usart_TxData;/* Pt to UART data information */
  UART_HandleTypeDef* pL_UART_Handler = (UART_HandleTypeDef*)G_Usart_TxHandler;/* Pt to UART handler */
  if (pL_UART_Handler == huart) {
    pL_UART_TxData->txStatus = USART_TX_OK;
    pL_UART_TxData->pt_Tx_R += pL_UART_TxData->nbSent;
    if (pL_UART_TxData->pt_Tx_R >= pL_UART_TxData->pt_EndTx_Buff) {
      pL_UART_TxData->pt_Tx_R = pL_UART_TxData->pt_StartTx_Buff;
    }

    if (pL_UART_TxData->txLock == 0) {
      pL_UART_TxData->nb2Send -= pL_UART_TxData->nbSent;
    } else {
      pL_UART_TxData->txLock = 2;
    }
  }
}

/*******************************************************************************
 * Function Name  : USART1_Tx_Initialization
 * Description    : Send Initialization of USART1
 * Input          : -
 *******************************************************************************/
void USART1_Tx_Initialization(void)
{
  /*Store USART1 send data information and its handler */
  G_Usart_TxData = &USART1_TxDataLink;
  G_Usart_TxHandler = (void*)&huart1;

  /* Initialize ring buffer information */
  USART1_TxDataLink.nb2Send = 0;
  USART1_TxDataLink.nbSent = 0;
  USART1_TxDataLink.nbMsgLost = 0;
  USART1_TxDataLink.buffSize = 56;
  USART1_TxDataLink.pt_StartTx_Buff = G_USART1_TxDataBuffer;
  USART1_TxDataLink.pt_EndTx_Buff = &G_USART1_TxDataBuffer[56];
  USART1_TxDataLink.pt_Tx_W = G_USART1_TxDataBuffer;
  USART1_TxDataLink.pt_Tx_R = G_USART1_TxDataBuffer;
  USART1_TxDataLink.CopyDataFcn = USART1_CopyDataFcn;
  USART1_TxDataLink.SendDataFcn = USART1_SendDataFcn;
  USART1_TxDataLink.txStatus = USART_TX_OFF;
  USART1_TxDataLink.txLock = 0;
}

/*******************************************************************************
 * Function Name  : USART1_CopyDataFcn
 * Description    : USART1 copy msg to send to ring buffer (if possible)
 * Input          : pointer to data to send , lengh(number) of data to send and
 *                  ring buffer info
 *******************************************************************************/
void USART1_CopyDataFcn(uint8_t* ptSrc, uint16_t DataLength, struct
  USART_TxDataLinkTypeDef* ptInfo)
{
  uint16_t L_sizeMsg;
  uint16_t L_idx;

  /* Copy msg to send to ring buffer */
  L_sizeMsg = 0;
  for (L_idx=0;L_idx<DataLength;L_idx++) {
    if ((((uint32_t)ptInfo->pt_Tx_W == (uint32_t)ptInfo->pt_Tx_R)&&
         ptInfo->nb2Send!=0))
      break;                           //Ring Buffer is full.
    *(char*)ptInfo->pt_Tx_W++ = *(char*)ptSrc++;
    L_sizeMsg++;
    if (ptInfo->pt_Tx_W == ptInfo->pt_Tx_R)
      break;                           //Ring Buffer is full.
    if (ptInfo->pt_Tx_W == ptInfo->pt_EndTx_Buff) {
      //Revolve buffer
      ptInfo->pt_Tx_W = ptInfo->pt_StartTx_Buff;
    }
  }

  /* update nb of data to send */
  ptInfo->txLock = 1;                  //Access locked
  ptInfo->nb2Send += L_sizeMsg;
  if (ptInfo->txLock == 2)             //If end of send interrupt mode arrived during last instruction
    ptInfo->nb2Send -= ptInfo->nbSent;
  ptInfo->txLock = 0;                  //Unlock access
  if (L_sizeMsg < DataLength)
    ptInfo->nbMsgLost++;               //Message not all sent
}

/*******************************************************************************
 * Function Name  : USART1_SendDataFcn
 * Description    : USART1 Send ring buffer management
 * Input          : Ring buffer info
 *******************************************************************************/
void USART1_SendDataFcn(struct USART_TxDataLinkTypeDef* ptInfo)
{
  uint16_t L_sizeMsg;

  /* If USART is not already running and data to send */
  if (ptInfo->txStatus != USART_TX_ON && ptInfo->nb2Send) {
    ptInfo->txStatus = USART_TX_ON;
    L_sizeMsg = (uint32_t)ptInfo->pt_EndTx_Buff - (uint32_t)ptInfo->pt_Tx_R;

    /* Send all msg or end of ring buffer */
    if (ptInfo->nb2Send <= L_sizeMsg) {
      ptInfo->nbSent = ptInfo->nb2Send;

      /* USART1 interrupt send mode*/
      HAL_UART_Transmit_IT(&huart1, ptInfo->pt_Tx_R, ptInfo->nb2Send);
    } else {
      ptInfo->nbSent = L_sizeMsg;

      /* USART1 interrupt send mode*/
      HAL_UART_Transmit_IT(&huart1, ptInfo->pt_Tx_R, L_sizeMsg);
    }
  }
}

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF] Medium_Self_Balance_Vehicle_USART.c
 */
