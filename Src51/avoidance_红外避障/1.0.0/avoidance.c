/********************创建: 2017年7月8日20:49:30 By赵靖石***********************/
/******************最后修改: 2017年7月8日20:49:20 By赵靖石**********************/
/********************版本号:1.0.0***********************************************/
#include "avoidance.h"

uchar d;
uint HasAvoidance(uint pin)
{
    re:
    if(pin==HIGH)
    {
        for(d=0;d<50;d++)
        {
            delay(1);
            if(pin!=HIGH)
                goto re;
        }
        return 0;
    }
    else {
        if(pin==LOW)
        {
            for(d=0;d<50;d++)
            {
                delay(1);
                if(pin!=LOW)
                    goto re;
            }
            return 1;
        }
    }
    return 1;//处于安全性考虑
}
