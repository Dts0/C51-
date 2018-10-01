/*********************创建: 2017年7月7日19:24:15 By赵靖石***********************/
/******************最后修改: 2017年7月7日20:52:56 By赵靖石**********************/
/********************版本号:1.0.0***********************************************/

#include "functions.h"
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
}
void goBack()
{
    _LeftMotoBack;
    _RightMotoBack;
}
void stop()
{
    _LeftMotoStop;
    _RightMotoStop;
}
void turnLeft()
{
    _LeftMotoBack;
    _RightMotoGo;
}
void turnRight()
{
    _LeftMotoGo;
    _RightMotoBack;
}
