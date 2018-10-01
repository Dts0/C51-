#include "functions.h"
#include "pwm.h"
#include "serial.h"
uint deg=5;
void main()
{
Buze();
serialBegin(0xfd) ;
serialPrintln("start");
while(1)
{
setPWM(deg);
LEDnumber(deg);
++deg;
if(deg==26)
deg=5;
delay(100);
}
}