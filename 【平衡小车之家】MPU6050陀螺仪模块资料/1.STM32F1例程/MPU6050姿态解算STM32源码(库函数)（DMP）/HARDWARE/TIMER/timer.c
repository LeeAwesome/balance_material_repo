#include "timer.h"
/**************************************************************************
�������ܣ���ʱ�жϳ�ʼ��
��ڲ�����arr���Զ���װֵ  psc��ʱ��Ԥ��Ƶ�� 
����  ֵ����
**************************************************************************/
void Timer1_Init(u16 arr,u16 psc)  
{  
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;       //����ṹTIM_TimeBaseStructure
	NVIC_InitTypeDef NVIC_InitStructure;									 //����ṹNVIC_InitStructure 
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1,ENABLE);  //ʹ�ܶ�ʱ��1ʱ��
 	TIM_TimeBaseStructure.TIM_Period = arr;    //��������һ�������¼�װ�����Զ���װ�ؼĴ������ڵ�ֵ	 
  TIM_TimeBaseStructure.TIM_Prescaler = psc; //����������ΪTIMxʱ��Ƶ�ʳ�����Ԥ��Ƶֵ  ����Ƶ
	TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure);//����TIM_TimeBaseInitStruct��ָ���Ĳ�����ʼ��TIMx��ʱ�������λ

	TIM_ARRPreloadConfig(TIM1, ENABLE);      //ʹ���Զ�װ������λ  
	TIM_Cmd(TIM1, ENABLE);   //������ʱ��TIM1
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);  	  //======�����ж����ȼ�����2
	NVIC_InitStructure.NVIC_IRQChannel = TIM1_UP_IRQn ;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=1 ;//��ռ���ȼ�1
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;		//�����ȼ�3
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQͨ��ʹ��
	NVIC_Init(&NVIC_InitStructure);	//����ָ���Ĳ�����ʼ��VIC�Ĵ���
}  
