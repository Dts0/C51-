#include "mode.h"
void main()
{
serialBegin(0xfd);
serialPrintln("start");
chooseMode(1);
}