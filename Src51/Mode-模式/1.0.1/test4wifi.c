#include "functions.h"
#include "serial.h"
#include "mode.h"



void main()
{
serialBegin(0xfd);
chooseMode(_WifiControl);
}

