#ifndef __MYFILE__
#define __MYFILE__
//#include "stm32f1xx_hal.h"

static unsigned char  fac_us=0;							//us��ʱ������			   
static unsigned short fac_ms=0;							//ms��ʱ������

void delay_init(void);
void delay_us(unsigned long nus);
void delay_ms(unsigned short nms);
void IIC_Init(void);
void MPU6050_initialize(void);
void DMP_Init(void);
void Read_DMP(void);
void MPU6050ReadDATA(float accel[],float Tempera,float gyro[]);
void Kalman_Filter(float Accel,float Gyro,float angle);
#endif

