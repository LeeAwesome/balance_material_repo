#ifndef __FILTER_H
#define __FILTER_H
  /**************************************************************************
作者：平衡小车之家
我的淘宝小店：http://shop114407458.taobao.com/
**************************************************************************/
extern float angle, angle_dot; 	
void Kalman_Filter(float Accel,float Gyro,float angle);
void Yijielvbo(float angle_m, float gyro_m);
float zj_atan2(float accel_a,float accel_b,float acc_angle);
#endif

