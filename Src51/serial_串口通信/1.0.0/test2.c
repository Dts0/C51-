/*********************2017年7月7日19:24:15***********************************/
/**************************By 赵靖石*****************************************/
#include "functions.h"
#include "serial.h"
void main()
{
    serialBegin(0xfd);//9600
    while(1)
       {sendMsg("I Get it");
        serialPrintln("this message will show 1 time every second");
    delay(1000);}
}
