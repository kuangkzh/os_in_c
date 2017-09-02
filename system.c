__asm__(".code16gcc\n");

int __INTERRUPT1(int eax,int ebx,int ecx,int edx,unsigned char intnum)
{
	__asm__("\
	movb 0x18(%ebp),%ah\n\
	movb $0xCD,%al\n\
	movw %ax,LFINT1\n\
	movl 0x8(%ebp),%eax\n\
	movl 0xc(%ebp),%ebx\n\
	movl 0x10(%ebp),%ecx\n\
	movl 0x14(%ebp),%edx\n\
LFINT1:\n\
	.space 2,0x90");
}


int __INTERRUPT2(int eax,int ebx,int ecx,int edx,int esi,int edi,int ebp,unsigned char intnum)
{
	__asm__("\
	pushl %ebp\n\
	movb 0x24(%ebp),%ah\n\
	movb $0xCD,%al\n\
	movw %ax,LFINT2\n\
	movl 0x8(%ebp),%eax\n\
	movl 0xc(%ebp),%ebx\n\
	movl 0x10(%ebp),%ecx\n\
	movl 0x14(%ebp),%edx\n\
	movl 0x18(%ebp),%esi\n\
	movl 0x1c(%ebp),%edi\n\
	movl 0x20(%ebp),%ebp\n\
LFINT2:\n\
	.space 2,0x90\n\
	popl %ebp");
}


void startBeep(short Freq)
{
	
	__asm__("\
	movw 0x8(%ebp),%bx\n\
	movw $0x2870,%ax\n\
	movw $0x12,%dx\n\
	divw %bx\n\
	mov %ax,%bx\n\
	in $0x61,%al\n\
	or $0x03,%al\n\
	out %al,$0x61\n\
	mov $0xB6,%al\n\
	out %al,$0x43\n\
	mov %bl,%al\n\
	out %al,$0x42\n\
	mov %bh,%al\n\
	out %al,$0x42");
}


void endBeep()
{
	__asm__("\
	in $0x61,%al\n\
	and $0xFD,%al\n\
	out %al,$0x61");
}
