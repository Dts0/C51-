/********************创建: 2017年7月7日19:24:15 By赵靖石***********************/
/******************最后修改: 2017年7月7日20:52:56 By赵靖石**********************/
/********************版本号:1.0.0***********************************************/

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "reg52.h"
#define uint unsigned int
#define uchar unsigned char

#define HIGH 1
#define LOW 0

//typedef int sbit;//当使用其他编译环境时使用

//使能位默认为正，所以不定义EN位也可以正常运行
/*
sbit left1_EN=P2^1;//EN1
sbit left2_EN=P2^2;//EN2
sbit right1_EN=P2^3;//EN3
sbit right2_EN=P2^3;//EN4
*/
sbit left1_IN1=P1^0;//IN1
sbit left1_IN2=P1^1;//IN2
sbit left2_IN1=P1^2;//IN3
sbit left2_IN2=P1^3;//IN4
sbit right1_IN1=P1^4;//IN5
sbit right1_IN2=P1^5;//IN6
sbit right2_IN1=P1^6;//IN7
sbit right2_IN2=P1^7;//IN8

#define _LeftMotoGo      {left1_IN1=HIGH;left1_IN2=LOW;left2_IN1=HIGH;left2_IN2=LOW;}    //左边两个电机向前走
#define _LeftMotoBack    {left1_IN1=LOW;left1_IN2=HIGH;left2_IN1=LOW;left2_IN2=HIGH;} 	//左边两个电机向后转
#define _LeftMotoStop    {left1_IN1=LOW;left1_IN2=LOW;left2_IN1=LOW;left2_IN2=LOW;}    //左边两个电机停转
#define _RightMotoGo     {right1_IN1=HIGH;right1_IN2=LOW;right2_IN1=HIGH;right2_IN2=LOW;}	//右边两个电机向前走
#define _RightMotoBack   {right1_IN1=LOW;right1_IN2=HIGH;right2_IN1=LOW;right2_IN2=HIGH;}	//右边两个电机向前走
#define _RightMotoStop   {right1_IN1=LOW;right1_IN2=LOW;right2_IN1=LOW;right2_IN2=LOW;}	//右边两个电机停转

void delay(uint ms);

void goFront();
void goBack();
void turnLeft();
void turnRight();
void stop();


#endif // FUNCTIONS_H
