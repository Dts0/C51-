#include "mode.h"
#include "range.h"
#include "wifi.h"

extern uchar _serialBegined;

void autoRun();
void findWay();
void wifiControl();

void chooseMode(uchar mode)
{
   switch(mode)
   {
   case _Test:goFront();break;
   case _AutoRun:autoRun();break;
   case _FindWay:findWay();break;
   case _WifiControl:wifiInit();wifiControl();break;
   default:if(_serialBegined)
			   serialPrintln("undefined mode");
   }
  
}


#define _distance 300
#define _dis_goBack 100
#define _check_interval 50
void autoRun()
{
static uint dis=0;
#ifdef _DEBUG
if(_serialBegined=TRUE)
serialPrintln("autoRun");
#endif
	while(1)
	{
		goFront();
		while(1)
		{
		    dis=range();
			while(dis<_distance)
            {				 LEDnumber(dis);
			                 while(dis<_dis_goBack)
							     {LEDnumber(dis);
								 goBack();
								 dis=range();
								 delay(_check_interval);
								 }
							 turnLeft();
							 dis=range();							 
			                 delay(_check_interval);
			}
			goFront();
			LEDnumber(dis);
		}
		
	}
}