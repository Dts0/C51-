/*******************创建: 2017年7月8日10:28:43 By赵靖石***********************/
/******************最后修改: 2017年7月28日12:10:04 By赵靖石**********************/
/********************版本号:1.0.1*********************************************/
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
uint range()//函数最终返回值为mm
{
    uint flag=0;
    uint distance=0;
    trig=LOW;
    delay_4us();
    trig=HIGH;
    delay_20us();
    trig=LOW;

    while(echo==LOW);
    TR0=1;//打开定时器
    while(echo==HIGH){
	++flag;
	if(flag>30000) {TR0=0;TH0=0;TL0=0;return 1500;}
	}
    TR0=0;//关闭定时器
    distance=TL0+TH0*256;//读取时间
    distance=distance/58;
	TH0=0;
	TL0=0;
    return 1.4*distance;
}
