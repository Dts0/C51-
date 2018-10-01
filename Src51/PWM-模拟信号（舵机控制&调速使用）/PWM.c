/****************创建: 2017年7月28日17:17:00 By赵靖石***********************/
/******************最后修改: 2017年7月28日17:17:06 By赵靖石**********************/
/********************版本号:1.0.0***********************************************/

#include "PWM.h"
uint target=6,percent=0;

void initTimer();

void setPWM(uint pwm)//需要输入0-199之间的值
{
target=pwm%200;
initTimer();
}


#define T0_init() {\
TH0=(65536-65)/256;\
TL0=(65536-65)%256;}
//每0.1ms产生一次中断

void timer0() interrupt 1 using 0
{
    percent+=1;
    if(percent>=200)
    {
       percent=0;
       pwmPin=HIGH;
    }
    if(percent==target)
    {
       pwmPin=LOW;
    }
    T0_init();
}
void initTimer()
{
    EA=1;
    ET0=1;
    TMOD=0x01;
    T0_init();
    TR0=1;
}