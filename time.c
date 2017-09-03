__asm__(".code16gcc\n");
#include "system.h"
#include "time.h"

int getTime(BIOSTime* t)
{
	RegTable regs;
	__INTERRUPT3(0x0200,0,0,0,&regs,0x1A);

	t->hour=(regs.cx&0xFF00)>>8;
	t->hour=(t->hour/16)*10+t->hour%16;
	t->minute=(regs.cx&0x00FF);
	t->minute=(t->minute/16)*10+t->minute%16;
	t->second=(regs.dx&0xFF00)>>8;
	t->second=(t->second/16)*10+t->second%16;
	t->summertime=(regs.dx&0x00FF);
	t->summertime=(t->summertime/16)*10+t->summertime%16;

	if(regs.FLAG&0x1>0) return 1;
	else return 0;
}

int getDate(BIOSDate* t)
{
	RegTable regs;
	__INTERRUPT3(0x0400,0,0,0,&regs,0x1A);
	
	t->year=regs.cx/4096*1000;
	regs.cx%=4096;
	t->year+=regs.cx/256*100;
	regs.cx%=256;
	t->year+=regs.cx/16*10+regs.cx%16;
	t->month=(regs.dx&0xFF00)>>8;
	t->month=(t->month/16)*10+t->month%16;
	t->day=(regs.dx&0x00FF);
	t->day=(t->day/16)*10+t->day%16;

	if(regs.FLAG&0x1>0) return 1;
	else return 0;
}

