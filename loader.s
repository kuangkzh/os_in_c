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
	movw $0x0,%bx	#载入到es:bx=0x1000H 
	movw $0x0236,%ax	#载入0x36个扇区 
	movw $0x2,%cx	#从二号扇区开始 
	movw $0x80,%dx	#第一个硬盘 
	int $0x13
	calll 0x1000

	.org 0x1AC
