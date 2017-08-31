__asm__(".code16gcc\n");

void hex(char* src,char* buffer,int length)
{
	int i;
	char hexnum[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	for(i=0;i<length;i++)
	{
		buffer[i*2]=hexnum[src[i]/16];
		buffer[i*2+1]=hexnum[src[i]%16];
	}
}

char scanKeycode()
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

char scanASCIIcode()
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
