BITS 64
%define SYS_WRITE	0x01
%define SYS_FORK	0X39
%define SYS_EXECVE	0X3B
%define SYS_EXIT	0X3C
%define SYS_WAIT4	0X3D
%define SYS_CLOSE	0X03

%define STDOUT 0x01
global _start

section .text

_start:
	JMP _main
	PUSH SYS_FORK			; ** Fork the process **
	POP RAX				;
	SYSCALL				;
	
	CMP RAX, 0x00			;
	JS __sy_exit			; ** No execution if an error occurs with the syscall fork ** 
	JNE _main

	
	__sy_father:
		PUSH RBP		; ** Wait for the child process to finish **
		MOV RBP, RSP		;
		SUB RSP, 0X08		;
		MOV RDI, RAX		;
		PUSH 0X00		;
		POP R10			;
		XOR RDX, RDX		;
		MOV RSI, RSP		;
		MOV RAX, SYS_WAIT4	;
		SYSCALL			;
		LEAVE			;
		NOP
		JMP __sy_exit		;
		
_main:
	NOP
	NOP
	MOV RCX, 0XFF	
	CMP RCX, 0XFF
	JE .L2
	.L1:				; ** Close stdout and error output before executing the command **
		PUSH RCX		;
		POP RDI			;
		PUSH SYS_CLOSE		; 
		POP RAX			;
		PUSH RCX		;
		SYSCALL			;
		POP RCX			;
		LOOP .L1		;
	.L2:
	PUSH 0X00

	NOP
	NOP
	NOP
	;; ** PUSH 0X00
	;; ** MOV RBX, 0X736C2F2F6E69622F // --> /bin//sh
	;; ** PUSH RBX
	
	CLD
	NOP
	NOP
	NOP
	NOP
	 ;; ** Code to add if there are parameters to the shell command ** ;;
	 ;; ** This code must be duplicated if there are several parameters. ** ;;
	 ;; ** PUSH 0x00
	 ;; ** MOV RCX, 0X6c2D
	 ;; ** PUSH RCX
	 ;; ** MOV RCX, RSP
	 ;; ** push rcx

	MOV RBX, RSP
	PUSH 0X00
	NOP
	NOP
	NOP
	NOP
	NOP
	MOV RCX, 0X00
	CMP RCX, 0X00
	JE .L4	
	PUSH 0X00
	POP RDX
	.L3:
	ADD RBX, RDX
	ADD RDX, 0X18
	PUSH QWORD [ RBX ]
	LOOP .L3
	.L4:
	PUSH RDI

	MOV RSI, RSP

	PUSH 0x00
	POP RDX

	PUSH SYS_EXECVE
	POP RAX
	SYSCALL

__sy_exit:
	NOP
	NOP
	NOP
	NOP
	NOP
