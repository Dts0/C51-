/********************����: 2017��7��31��11:15:40 By�Ծ�ʯ***********************/
/******************����޸�: 2017��7��31��11:15:44 By�Ծ�ʯ**********************/
/********************�汾��:1.0.0***********************************************/

#include "findWay.h"
#include "functions.h"
#include "avoidance.h"

void findWay()
{
uchar left,right;
while(1)
{
    left=HasAvoidance(leftLedOut);
    right=HasAvoidance(rightLedOut);
    if(left==1&&right==0)
          turnRightAndGo();
    else if(left==0&&right==1)
          turnLeftAndGo();
    else goFront();
    delay(_findWay_interval);
 }
}
