/*********************创建: 2017年7月8日10:28:43 By赵靖石***********************/
/******************最后修改: 2017年7月8日10:28:38 By赵靖石**********************/
/********************版本号:1.0.0*********************************************/
#include "range.h"
delay_20us()
{
uchar bt;
for(bt=0;bt<10;bt++);
}
delay_4us()
{
uchar bt;
for(bt=0;bt<2;bt++);
}
uint range()
{
    uint distance=0;
    trig=LOW;
    delay_4us();
    trig=HIGH;
    delay_20us();
    trig=LOW;

    while(echo==LOW);
    TR0=1;//打开定时器
    while(echo==HIGH);
    TR0=0;//关闭定时器
    distance=TL0+TH0*256;//读取时间
    distance=distance/58;//计算距离 cm
	TH0=0;
	TL0=0;
    return distance;
}
