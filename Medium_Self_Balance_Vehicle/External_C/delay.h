#ifndef __DELAY_H
#define __DELAY_H 			   
  /**************************************************************************
作者：平衡小车之家
我的淘宝小店：http://shop114407458.taobao.com/
**************************************************************************/
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;



#include "stm32f1xx_hal.h"

#include "printf.h"
#include "ioi2c.h"
#include "MPU6050.h"
#include "filter.h"

#include "inv_mpu.h"
#include "inv_mpu_dmp_motion_driver.h"
#include "dmpKey.h"
#include "dmpmap.h"

#include <string.h> 
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>



void delay_init(void);
void delay_ms(u16 nms);
void delay_us(u32 nus);
void I2C_Delay(void);

#endif





























