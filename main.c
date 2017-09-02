__asm__(".code16gcc\n");
#include "biosIO.h"
#include "system.h"
#include "GUI.h"


void start()
{
	int a;
	startBeep(1000);
	while(1)
	{
		a++;
	}
}
