	.code16
	.text
	.global _main
	.org 0

_main:
	movw %cs,%ax
	movw %ax,%ds
	movw %ax,%ss
	movw %ax,%es
	movw $0,%sp

_loaddisk:
	movw $0x100,%ax
	movw %ax,%es
	movw $0x0,%bx	#���뵽es:bx=0x1000H 
	movw $0x0236,%ax	#����0x36������ 
	movw $0x2,%cx	#�Ӷ���������ʼ 
	movw $0x80,%dx	#��һ��Ӳ�� 
	int $0x13
	calll 0x1000

	.org 0x1AC
