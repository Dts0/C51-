/*********************2017年7月7日19:24:15***********************************/
/**************************By 赵靖石*****************************************/
#include "functions.h"
#include "serial.h"
void main()
{
    serialBegin(0xfd);//9600
    while(1)
       {
        serialPrintln("this message will show every time there is a new message received");
        serialPrintln(serialReceivedMsg());
        }
}
//如果无法满足要求可以用如下代码串口输出
/*
TI=1;
printf();
while(!TI);
TI=0;
*/