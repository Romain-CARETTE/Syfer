BITS 64


section .text
	global _start
	global main

%define SYS_MMAP	0X09
%define SYS_EXIT	0X3C
%define SYS_MPROTECT	10
%define SYS_GETRANDOM	0X13E
%define SYS_READ	0x00
%define PAGE_SIZE	0X1000
%define SYS_WRITE 0x01
%define SYS_OPEN	0X02
%define SYS_LSEEK	0X08
%define SYS_RT_SIGACTION 0x0d
%define SYS_RT_SIGRETURN 0x0f
%define SYS_MPROTECT	10
%define SIGTERM 0x0f
%define SIGINT 0x02
%define SIGTRAP	0x05
%define STDOUT 0x01
%define SA_RESTORER 0x04000000
%define	O_RDONLY	0X00
%define SEEK_SET	0X00

BEGIN:
	JMP _start

handler:
END:	
	RET
	KEY: db "", -1, -1, -1, -1, -1, -1, -1, -1, 0X00
	ROUND: db "", 0X00

restorer:
	MOV RAX, SYS_RT_SIGRETURN
	SYSCALL

_debug_00:
CALL AFTER_DEBUG00
.string db "...Syfer...", 0x0A
AFTER_DEBUG00:
MOV RDI, STDOUT
POP RSI
MOV RDX, 12
MOV RAX, SYS_WRITE
SYSCALL
RET

__sy_get_the_virtual_address:			;
	PUSH RBP				;
	MOV RBP, RSP				;
	SUB RSP, 0X10				;
	MOV RAX, RDI				;
	MOV QWORD [RBP-0X10], RAX		;
	MOV EDX, PAGE_SIZE			;
	MOVSXD RCX, EDX				;
	XOR RDX, RDX				;
	DIV RCX					;
	MOV RAX, RDX				;
	NEG RAX					;
	ADD QWORD [RBP-0x10], RAX		;
	MOV RDI, QWORD [RBP-0x10]		;
	LEAVE					;
	RET					;


_xor:						;
        PUSH   RBP				;
        MOV    RBP,RSP				;
     	MOV    QWORD  [ RBP-0X8 ],  RDI		;
      	mov    DWORD  [ RBP-0XC ],  ESI		;
    	mov    QWORD  [ RBP-0X18 ], RDX		;
	mov    DWORD  [ RBP-0X1C ], 0X0		;
.L1:						;
       	MOV    EAX,DWORD  [ RBP-0x1C ]		;
        CMP    EAX,DWORD  [ RBP-0xC ]		;
   	JAE    .L2				;
        MOV    RAX,QWORD  [ RBP-0X8 ]		;
        MOV    ECX,DWORD  [ RBP-0X1C ]		;
        MOV    EDX,ECX				;
        MOVZX  ECX,BYTE  [ RAX+RDX*1 ]		;
       	MOV    RAX,QWORD  [ RBP-0x18 ]		; ** Xor encryption algorithm **
       	MOV    ESI,DWORD [ RBP-0x1C ]		; ** See https://fr.wikipedia.org/wiki/Fonction_OU_exclusif **
        MOV    EDX,ESI				;
 	AND    RDX,0x7				;
     	MOVZX  ESI,BYTE [ RAX+RDX*1 ]		;
        XOR    ECX,ESI				;
        MOV    RAX,QWORD [ RBP-0x8 ]		;
       	MOV    ESI,DWORD [ RBP-0x1C ]		;
        MOV    EDX,ESI				;
        MOV    BYTE [ RAX+RDX*1 ],CL		;
        MOV    EAX,DWORD [ RBP-0x1C ]		;
        ADD    EAX,0x1				;
        MOV    DWORD [ RBP-0x1C ],EAX		;
      	JMP    .L1				;
	.L2:					;
        POP    RBP				;
	RET					;

_start:
	PUSH RAX
	PUSH RCX
	PUSH RBX
	PUSH RDX
	PUSH RDI
	PUSH RSI
	
	CALL _debug_00
	LEA RDI, [ rel BEGIN ]
	NOP					;
	NOP					;
	NOP					;
	NOP					; ** The "NOP" instructions will be replaced by the "SUB" instruction. ** 
	NOP					; ** By executing the sub instruction, we will get the address where the original binary starts. **
	NOP					;
	NOP					;
	PUSH RDI
	CALL __sy_get_the_virtual_address
	
	XOR RSI, RSI
	NOP					;
	NOP					;
	NOP					;
	NOP					; ** Enable memory wrinting. **
	NOP					;
	MOV RDX, 7				;
	MOV RAX, SYS_MPROTECT			;
	SYSCALL					;


	POP RDI					; ** Get the address saved on the stack where the execution starts ** 					
	LEA RDX, [ REL KEY ]			;
	NOP					;
	NOP					;
	NOP					;
	NOP					;
	NOP					; ** Activate the routine that will decipher **
	PUSH RBP				;
	MOV RBP, RSP				;
	SUB RSP, 0X70				;
	CALL _xor				;
	ADD RSP, 0x70				;
	POP RBP					;

	PUSH RBP
	MOV RBP, RSP
	SUB RSP, 512

	LEA RDI, [ REL handler ]
	LEA RSI, [ REL restorer ]
	MOV QWORD [RSP], RDI
	MOV QWORD [RSP+8], DWORD SA_RESTORER
	MOV QWORD [RSP+16], RSI
	
	MOV RAX, SYS_RT_SIGACTION
	MOV RDI, SIGTRAP
	MOV RSI, RSP
	XOR RDX, RDX
	MOV R10, 0X08
	SYSCALL
	
	LEAVE

	POP RSI
	POP RDI
	POP RDX
	POP RBX
	POP RCX
	POP RAX
	NOP
	NOP
	NOP
	NOP
	NOP
