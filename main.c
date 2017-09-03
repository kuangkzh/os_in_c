__asm__(".code16gcc\n");
#include "biosIO.h"
#include "system.h"
#include "GUI.h"
#include "time.h"


void start()
{
	BIOSTime t;
	BIOSDate d;
	char str1[11]="hello world",str2[15]="date:    :  :  ",str3[13]="time:  :  :  ";
	getTime(&t);
	getDate(&d);
	print(str1,11,1,0,0x0A);
	print(str2,15,2,0,0x0A);
	print(str3,13,3,0,0x0A);
	printInt(d.year,2,5,0x0A);
	printInt(d.month,2,10,0x0A);
	printInt(d.day,2,13,0x0A);
	printInt(t.hour,3,5,0x0A);
	printInt(t.minute,3,8,0x0A);
	printInt(t.second,3,11,0x0A);
}
