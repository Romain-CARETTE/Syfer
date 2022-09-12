BITS 64
section .text
	global _start
	global main


_start:
main:
	PUSH R14
	NOP
	NOP
	NOP
	NOP
	NOP
	NOP
	INT3
	POP R14
	JMP main

