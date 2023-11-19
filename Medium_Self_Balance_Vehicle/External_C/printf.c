#include "printf.h"	
#include "usart.h"

 
//重定义fputc函数 
//int fputc(int ch, FILE *f)
//{
//  HAL_UART_Transmit(&huart1, (uint8_t *)&ch, 1, 0xffff);
//  return ch;
//}


int fputc(int ch, FILE *f)
{      
	while((USART1->SR&0X40)==0);// 
	USART1->DR = (u8) ch;      
	return ch;
}




int fgetc(FILE * f)
{
  uint8_t ch = 0;
  HAL_UART_Receive(&huart1,&ch, 1, 0xffff);
  return ch;
}


