/********************创建: 2017年7月7日19:24:15 By赵靖石***********************/
/******************最后修改: 2017年7月27日10:42:03 By赵靖石**********************/
/********************版本号:2.0.0***********************************************/


#include "functions.h"
#include "serial.h"

extern uchar _serialBegined;

void delay(uint ms)
{
    uint x,y;
    for(x=ms;x>0;x--)
        for(y=110;y>0;y--);
}

void goFront()
{
    _LeftMotoGo;
    _RightMotoGo;
#ifdef _DEBUG
    if(_serialBegined)
       serialPrintln("goFront");
#endif
}
void goBack()
{
    _LeftMotoBack;
    _RightMotoBack;
#ifdef _DEBUG
if(_serialBegined)
    serialPrintln("goBack");
#endif
}
void stop()
{
    _LeftMotoStop;
    _RightMotoStop;
#ifdef _DEBUG
if(_serialBegined)
    serialPrintln("stop");
#endif
}
void turnLeft()
{
    _LeftMotoBack;
    _RightMotoGo;
#ifdef _DEBUG
if(_serialBegined)
    serialPrintln("turnLeft");
#endif
}
void turnRight()
{
    _LeftMotoGo;
    _RightMotoBack;
#ifdef _DEBUG
if(_serialBegined)
    serialPrintln("turnRight");
#endif
}
void turnLeftAndGo()
{
    _LeftMotoStop;
    _RightMotoGo;
#ifdef _DEBUG
if(_serialBegined)
    serialPrintln("turnLeftAndGo");
#endif
}
void turnRightAndGo()
{
    _LeftMotoGo;
    _RightMotoStop;
#ifdef _DEBUG
if(_serialBegined)
    serialPrintln("turnRightAndGo");
#endif
}

uint SPK_time=100;
void Buze()
{
    SPK=0;
    delay(SPK_time);
    SPK=1;
    delay(SPK_time);    
}


sbit Base0=P2^0;
sbit Base1=P2^1;
sbit Base2=P2^2;
sbit Base3=P2^3;
#define numPort P0
uchar code table[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};
//对应0-9
void LEDnumber(uint num)
{
uchar time=0;
while(time<110){
    Base0=0;Base1=1;Base2=1;Base3=1;
    numPort=table[num%1000/100];
    Base0=1;Base1=0;Base2=1;Base3=1;   
    delay(1);
    numPort=table[num%100/10];
    Base0=1;Base1=1;Base2=0;Base3=1;   
    delay(1);
    numPort=table[num%10];
    Base0=1;Base1=1;Base2=1;Base3=0;  
    delay(1);
    numPort=table[num/1000];
    Base0=1;Base1=1;Base2=1;Base3=1;
    delay(1);
    ++time;
    }
}

#undef numPort
