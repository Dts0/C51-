/********************����: 2017��7��31��11:15:40 By�Ծ�ʯ***********************/
/******************����޸�: 2017��7��31��11:15:44 By�Ծ�ʯ**********************/
/********************�汾��:1.0.0***********************************************/

#include "findWay.h"
#include "functions.h"
#include "avoidance.h"
#include "serial.h"

extern uchar _serialBegined;

void findWay()
{
uchar left,right;
while(1)
{
    left=leftHasAvoidance();
	right=rightHasAvoidance();
    if(left==1&&right==0)
          {
#ifdef _DEBUG
if(_serialBegined=TRUE)
serialPrintln("There is a line in the right");
#endif           
           turnRightAndGo();
           }
    else if(left==0&&right==1)
          {
#ifdef _DEBUG
if(_serialBegined=TRUE)
serialPrintln("There is a line in the left");
#endif          
           turnLeftAndGo();
           }
    else goFront();
    delay(_findWay_interval);
 }
}
