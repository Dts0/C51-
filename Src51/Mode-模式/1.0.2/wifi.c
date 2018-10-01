/*******************创建: 2017年7月30日17:43:02 By赵靖石***********************/
/******************最后修改: 2017年7月30日17:43:07 By赵靖石**********************/
/********************版本号:1.0.0***********************************************/

#include "wifi.h"
#include "functions.h"
#include "serial.h"
#include "mode.h"

uchar *cmd="";

void wifiInit()
{
    serialBegin(0xfd);
	serialPrintln("AT+CIPMUX=0");
	delay(100);
	serialPrintln("AT+CIPSTART=\"TCP\",\"10.78.106.146\",5000");
	delay(5000);
	serialPrintln("AT+CIPMODE=1");
	Buze();
}
void wifiControl()
{
    while(1)
    {
     cmd="";
     cmd=wifiReceivedMsg();
     if(cmd!=""&&cmd[0]=='#'&&cmd[0]!='\0')
     {
           switch(cmd[1])
           {
            case 'f':goFront();break;
			case 'b':goBack();break;
			case 'l':turnLeft();break;
			case 'r':turnRight();break;
			case 'e':turnLeftAndGo();break;
			case 'i':turnRightAndGo();break;
			case 's':stop();break;
			case 'u':Buze();break;
			case 'a':chooseMode(1);break;

            }
      }
     }
}

