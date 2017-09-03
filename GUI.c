__asm__(".code16gcc\n");
#include "system.h"

void setDisplayMode(int mode)
{
	__INTERRUPT1(0x00FF&mode,0,0,0,0x10);
}


void setCursorPosition(int page,unsigned char row,unsigned char col)
{
	__INTERRUPT1(0x0200,page,0,0x100*row+col,0x10);
}


void setPixel(int page,unsigned short x,unsigned short y,unsigned char color)
{
	__INTERRUPT1(0x0C00+color,0x100*page,x,y,0x10);
}

void setBackground(unsigned char color)
{
	__INTERRUPT1(0x0B00,0x00FF&color,0,0,0x10);
}

void setPalette(unsigned char palette)
{
	__INTERRUPT1(0x0B00,0x00FF&palette+0x0100,0,0,0x10);
}
