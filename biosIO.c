__asm__(".code16gcc\n");

void str2hex(unsigned char* src,unsigned char* buffer,int length,char split)
{
	int i,j;
	unsigned char hexnum[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	for(i=0,j=0;i<length;i++)
	{
		buffer[j++]=hexnum[src[i]/16];
		buffer[j++]=hexnum[src[i]%16];
		if(split!=0)
		{
			buffer[j++]=split;
		}
	}
}

unsigned char scanKeycode()
{
	__asm__("\n\
	movw $0x0,%ax\n\
	inc %al\n\
	int $0x16\n\
	jne LFexist1\n\
	movb $0,%ah\n\
LFexist1:\n\
	movb %ah,%al");
}

unsigned char scanASCIIcode()
{
	__asm__("\n\
	movw $0x0,%ax\n\
	inc %al\n\
	int $0x16\n\
	jne LFexist2\n\
	movb $0,%al\n\
LFexist2:");
}

void print(char* str,int length,int row,int col,int attr)
{
	__asm__("\n\
	movl 0xc(%ebp),%ecx\n\
	movb 0x10(%ebp),%dh\n\
	movb 0x14(%ebp),%dl\n\
	movb $0x0,%bh\n\
	movb 0x18(%ebp),%bl\n\
	movw 0x8(%ebp),%bp\n\
	movw $0x1301,%ax\n\
	int $0x10");
}

int readDisk(int start,int length,int disk,char* buffer)
{
	__asm__("\
	movw 0x8(%ebp),%ax\n\
	movw 0xA(%ebp),%dx\n\
	movw $0x3EC1,%bx\n\
	divw %bx\n\
	movw %ax,%bx\n\
	movw %dx,%ax\n\
	movb $0x3F,%cl\n\
	divb %cl\n\
	movb %al,%dh\n\
	movb %ah,%cl\n\
	movb %bl,%ch\n\
	shr $2,%bx\n\
	and $0xc0,%bl\n\
	or %bl,%cl\n\
	\
	movb 0x10(%ebp),%dl\n\
	movw 0x14(%ebp),%bx\n\
	movb 0xc(%ebp),%al\n\
	movb $0x02,%ah\n\
	\
	int $0x13");
}



int writeDisk(int start,int length,int disk,char* buffer)
{
	__asm__("\
	movw 0x8(%ebp),%ax\n\
	movw 0xA(%ebp),%dx\n\
	movw $0x3EC1,%bx\n\
	divw %bx\n\
	movw %ax,%bx\n\
	movw %dx,%ax\n\
	movb $0x3F,%cl\n\
	divb %cl\n\
	movb %al,%dh\n\
	movb %ah,%cl\n\
	movb %bl,%ch\n\
	shr $2,%bx\n\
	and $0xc0,%bl\n\
	or %bl,%cl\n\
	\
	movb 0x10(%ebp),%dl\n\
	movw 0x14(%ebp),%bx\n\
	movb 0xc(%ebp),%al\n\
	movb $0x03,%ah\n\
	\
	int $0x13");
}

