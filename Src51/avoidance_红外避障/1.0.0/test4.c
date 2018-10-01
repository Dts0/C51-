/********************创建: 2017年7月8日20:49:30 By赵靖石***********************/
/******************最后修改: 2017年7月8日20:49:20 By赵靖石**********************/
/********************版本号:1.0.0***********************************************/
#include "functions.h"
#include "serial.h"
#include "avoidance.h"

void main()
{
    serialBegin(0xfd);
    serialPrintln("start");
    while(1)
    {
        serialPrintln("a s everytime");
        if(HasAvoidance(leftLedOut)==1)
            serialPrintln("Has Avoidance");
        else serialPrintln("Hasn't Avoidance");
        delay(1000);
    }
}
