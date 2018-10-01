/********************创建: 2017年7月7日22:24:13 By赵靖石***********************/
/******************最后修改: 2017年7月7日22:24:20 By赵靖石**********************/
/********************版本号:1.0.0*********************************************/
#include "functions.h"
#include "serial.h"
#include "range.h"
void main()
{
    serialBegin(0xfd);//9600
	serialPrintln("start");
    while(1)
       {
        serialPrintln("this message will show every time there is a new message received");  
        TI=1;
		printf("range start\n");
        printf("%u\n",range());
		printf("range end\n");
        while(!TI);
        TI=0;
        delay(1000);
        }
}
