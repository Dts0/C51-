/******************创建: 2017年7月8日20:49:30 By赵靖石***********************/
/******************最后修改: 2017年7月31日12:45:32 By赵靖石**********************/
/********************版本号:2.0.0***********************************************/
#include "avoidance.h"

uchar d;

uchar leftHasAvoidance()
{
	   re:
    if(leftLedOut==HIGH)
    {
        for(d=0;d<50;d++)
        {
            delay(1);
            if(leftLedOut!=HIGH)
                goto re;
        }
        return 0;
    }
    else {
        if(leftLedOut==LOW)
        {
            for(d=0;d<50;d++)
            {
                delay(1);
                if(leftLedOut!=LOW)
                    goto re;
            }
            return 1;
        }
    }
    return 1;//处于安全性考虑
}
uchar rightHasAvoidance()
{
   re:
    if(rightLedOut==HIGH)
    {
        for(d=0;d<50;d++)
        {
            delay(1);
            if(rightLedOut!=HIGH)
                goto re;
        }
        return 0;
    }
    else {
        if(rightLedOut==LOW)
        {
            for(d=0;d<50;d++)
            {
                delay(1);
                if(rightLedOut!=LOW)
                    goto re;
            }
            return 1;
        }
    }
    return 1;//处于安全性考虑
}
