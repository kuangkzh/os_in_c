__asm__(".code16gcc\n");
#include "biosIO.h"


void start()
{
	char str[12]="helloworld";
	print(str,12,1,0,0x0A);
}
