﻿/*****************创建: 2017年7月7日19:24:15 By赵靖石***********************/
/******************最后修改: 2017年7月27日10:42:03 By赵靖石**********************/
/********************版本号:2.0.0***********************************************/

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "reg52.h"
#ifndef uchar
#define uint unsigned int
#define uchar unsigned char
#endif

#define HIGH 1
#define LOW 0

#define TRUE 1
#define FALSE 0

#define _DEBUG//调试标志,开启调试

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

sbit SPK=P3^6;//嗡鸣器
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
void turnLeftAndGo();
void turnRightAndGo();
void stop();

void Buze();//嗡鸣器，参数可在functions.c中调
void LEDnumber(uint num);//显示十进制数字

#endif // FUNCTIONS_H
