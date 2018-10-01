/*********************创建: 2017年7月7日19:24:15 By赵靖石***********************/
/******************最后修改: 2017年7月26日11:24:43 By赵靖石**********************/
/********************版本号:1.1.0***********************************************/


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
