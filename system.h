#ifndef _SYSTEM_H_
#define _SYSTEM_H_ 0

int __INTERRUPT1(int eax,int ebx,int ecx,int edx,unsigned char intnum);
int __INTERRUPT2(int eax,int ebx,int ecx,int edx,int esi,int edi,int ebp,unsigned char intnum);
void startBeep(short Freq);
void endBeep();

#endif
