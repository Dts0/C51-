/*******************创建: 2017年7月8日20:49:30 By赵靖石***********************/
/******************最后修改: 2017年7月31日12:45:32 By赵靖石**********************/
/********************版本号:2.0.0***********************************************/
#ifndef AVOIDANCE_H
#define AVOIDANCE_H
#include "functions.h"

sbit leftLedOut=P3^4;
sbit rightLedOut=P3^5;


uchar leftHasAvoidance();
uchar rightHasAvoidance();

#endif // AVOIDANCE_H
