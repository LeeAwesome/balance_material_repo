#include "timer.h"
/**************************************************************************
函数功能：定时中断初始化
入口参数：arr：自动重装值  psc：时钟预分频数 
返回  值：无
**************************************************************************/
void Timer1_Init(u16 arr,u16 psc)  
{  
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;       //定义结构TIM_TimeBaseStructure
	NVIC_InitTypeDef NVIC_InitStructure;									 //定义结构NVIC_InitStructure 
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1,ENABLE);  //使能定时器1时钟
 	TIM_TimeBaseStructure.TIM_Period = arr;    //设置在下一个更新事件装入活动的自动重装载寄存器周期的值	 
  TIM_TimeBaseStructure.TIM_Prescaler = psc; //设置用来作为TIMx时钟频率除数的预分频值  不分频
	TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure);//根据TIM_TimeBaseInitStruct中指定的参数初始化TIMx的时间基数单位

	TIM_ARRPreloadConfig(TIM1, ENABLE);      //使能自动装载允许位  
	TIM_Cmd(TIM1, ENABLE);   //启动定时器TIM1
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);  	  //======设置中断优先级分组2
	NVIC_InitStructure.NVIC_IRQChannel = TIM1_UP_IRQn ;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=1 ;//抢占优先级1
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;		//子优先级3
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQ通道使能
	NVIC_Init(&NVIC_InitStructure);	//根据指定的参数初始化VIC寄存器
}  
