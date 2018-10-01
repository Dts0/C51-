#include "functions.h"
#include "serial.h"
void main()
{
serialBegin(0xfd);
serialPrintln("start");
Buze();
Buze();
while(1) {
goFront();
delay(1000);
turnLeft();
delay(500);
turnRight();
delay(500);
stop();
delay(500);
turnLeftAndGo();
delay(1000);
turnRightAndGo();
delay(1000);
goFront();
delay(500);
goBack();
delay(2000);
	 }
}