/********************创建: 2017年7月8日20:49:30 By赵靖石***********************/
/******************最后修改: 2017年7月8日20:49:20 By赵靖石**********************/
/********************版本号:1.0.0***********************************************/
#ifndef AVOIDANCE_H
#define AVOIDANCE_H
#include "functions.h"

sbit leftLedOut=P2^3;
sbit rightLedOut=P2^4;


uint HasAvoidance(uint pin);

#endif // AVOIDANCE_H
