/****************����: 2017��7��28��17:17:00 By�Ծ�ʯ***********************/
/******************����޸�: 2017��7��28��17:17:06 By�Ծ�ʯ**********************/
/********************�汾��:1.0.0***********************************************/

#include "PWM.h"
uint target=6,percent=0;

void initTimer();

void setPWM(uint pwm)//��Ҫ����0-199֮���ֵ
{
target=pwm%200;
initTimer();
}


#define T0_init() {\
TH0=(65536-65)/256;\
TL0=(65536-65)%256;}
//ÿ0.1ms����һ���ж�

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