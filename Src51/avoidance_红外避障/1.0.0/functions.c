/*********************����: 2017��7��7��19:24:15 By�Ծ�ʯ***********************/
/******************����޸�: 2017��7��7��20:52:56 By�Ծ�ʯ**********************/
/********************�汾��:1.0.0***********************************************/

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
