/********************创建: 2017年7月8日20:49:30 By赵靖石***********************/
/******************最后修改: 2017年7月31日11:13:58 By赵靖石**********************/
/********************版本号:1.1.0***********************************************/
#ifndef AVOIDANCE_H
#define AVOIDANCE_H
#include "functions.h"

sbit leftLedOut=P3^4;
sbit rightLedOut=P3^5;


uchar HasAvoidance(uint pin);

#endif // AVOIDANCE_H
