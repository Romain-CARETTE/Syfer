BITS 64
%define SYS_MPROTECT	10
%define PAGE_SIZE	0X1000
section .text
	global start
	global main


start:
main:
CALL SYFER_00
SYFER_00:
	MOV RAX, [RSP]
	MOV RCX, PAGE_SIZE
	MOV RDX, 0X00
	DIV RCX
	MOV RAX, RDX
	neg RAX
	ADD [RSP], RAX
	POP RDI
	
	MOV RSI, PAGE_SIZE
	MOV RDX, 7
	MOV RAX, SYS_MPROTECT
	SYSCALL
	NOP
	NOP
	NOP
	NOP
	NOP
