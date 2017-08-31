	.code16gcc
	.text
	.global _main
	.org 0

_main:
	movw $0x100,%ax
	movw %ax,%ds
	movw %ax,%ss
	movw %ax,%es
	movw $0xF800,%sp

	calll _start
x:
	jmpl *x
