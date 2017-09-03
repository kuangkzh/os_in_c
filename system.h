#ifndef _SYSTEM_H_
#define _SYSTEM_H_ 0

typedef struct RegTable
{
	short ax;
	short bx;
	short cx;
	short dx;
	short FLAG;
} RegTable;

int __INTERRUPT1(int eax,int ebx,int ecx,int edx,unsigned char intnum);
int __INTERRUPT2(int eax,int ebx,int ecx,int edx,int esi,int edi,int ebp,unsigned char intnum);

void __INTERRUPT3(int eax,int ebx,int ecx,int edx,RegTable* regs,unsigned char intnum);


void startBeep(short Freq);	//Æô¶¯·äÃùÆ÷ 
void endBeep();

#endif
