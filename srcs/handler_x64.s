BITS 64

section .text
	global _start
	global main

%define SYS_MMAP	0X09
%define SYS_MPROTECT	10
%define SYS_READ	0x00
%define PAGE_SIZE	0X2000
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
	LEA r15, [ REL handler ]
	LEA r14, [ REL restorer ]
	JMP _start
handler:
	MOV RDI, RSP
	ADD RDI, 0XB0
	MOV RDI, [RDI]
	PUSH RDI
	MOV R10, 0X07
	CALL CHANGE_PERMISSION_OF_ADDRESS
	POP RDI

	MOV RDI, RSP
	ADD RDI, 0XB0
	MOV RDI, [RDI]

	XOR RDX, RDX
	XOR RAX, RAX
	MOV RAX, 27
	MOV DX, WORD [RDI]
	MUL RDX
	LEA RSI, [REL DATA ]
	MOV RSI, [RSI]
	ADD RSI, RAX

	ADD RDI, 2
	PUSH RBP
	MOV RBP, RSP
	SUB RSP, 0X70
	MOV RAX, RSI
	XOR RSI, RSI
	MOV RSI, QWORD [RAX+3]
	MOV RDX, RAX
	ADD RDX, 19

	CALL _xor
	


	ADD RSP, 0x70
	POP RBP
	
	
	SUB RDI, 3
	MOV BYTE [RDI], 0X55
	MOV BYTE [RDI + 0X01], 0X48
	MOV BYTE [RDI + 0X02], 0X89
	

	MOV [RSP + 0XB0 ], RDI


	JMP END

END:	
	CALL _debug_01
	RET

_xor:
               	push   rbp
             	mov    rbp,rsp
     	mov    QWORD  [rbp-0x8],rdi
      	mov    DWORD  [rbp-0xc],esi
    	mov    QWORD  [rbp-0x18],rdx
mov    DWORD [rbp-0x1c],0x0
.L1:
          	mov    eax,DWORD  [rbp-0x1c]
           	cmp    eax,DWORD  [rbp-0xc]
   	jae    .L2
        	mov    rax,QWORD  [rbp-0x8]
         	mov    ecx,DWORD  [rbp-0x1c]
          	mov    edx,ecx
         	movzx  ecx,BYTE  [rax+rdx*1]
        	mov    rax,QWORD  [rbp-0x18]
       	mov    esi,DWORD [rbp-0x1c]
           	mov    edx,esi
 	and    rdx,0x7
     	movzx  esi,BYTE [rax+rdx*1]
        	xor    ecx,esi
         	mov    rax,QWORD [rbp-0x8]
        	mov    esi,DWORD [rbp-0x1c]
         	mov    edx,esi
          	mov    BYTE [rax+rdx*1],cl
         	mov    eax,DWORD [rbp-0x1c]
            	add    eax,0x1
             	mov    DWORD [rbp-0x1c],eax
      	jmp    .L1
	.L2:
                  	pop    rbp
	ret


CHANGE_PERMISSION_OF_ADDRESS:
	PUSH RBP
	MOV RBP, RSP
	SUB RSP, 0X10

	MOV RAX, RDI
	MOV QWORD [RBP-0X10], RAX
	MOV EDX, PAGE_SIZE
	MOVSXD RCX, EDX
	XOR RDX, RDX
	DIV RCX
	MOV RAX, RDX
	NEG RAX
	ADD QWORD [RBP-0x10], RAX
	MOV RDI, QWORD [RBP-0x10]
	
	
	MOV RSI, PAGE_SIZE
	MOV RDX, R10
	MOV RAX, SYS_MPROTECT
	SYSCALL
	LEAVE
	RET


restorer:
	MOV RAX, SYS_RT_SIGRETURN
	SYSCALL

_debug_01:
CALL AFTER_DEBUG01
.string db "...End handler...", 0x0A
AFTER_DEBUG01:
MOV RDI, STDOUT
POP RSI
MOV RDX, 18
MOV RAX, SYS_WRITE
SYSCALL
RET


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

_GLOBAL_ENCRYPTION:
	LEA RDI, [REL BEGIN]
	STC
	STC
	STC
	STC
	STC
	STC
	STC

	STC
	STC
	STC
	STC
	STC
	STC
	STC

	MOV RDX, 7
	MOV RAX, SYS_MPROTECT
	SYSCALL

	

	
	
	RET

_start:
	PUSH RAX
	PUSH RCX
	PUSH RBX
	PUSH RDX
	PUSH RDI
	PUSH RSI

	MOV RDI, [RSP + 0X38 ]
	MOV RSI, O_RDONLY
	MOV RAX, SYS_OPEN
	SYSCALL

	PUSH RBP
	MOV RBP, RSP
	SUB RSP, 0X10
	MOV [RSP], RAX

	MOV RDI, RAX
	MOV RAX, SYS_LSEEK
	CLD
	CLD
	CLD
	CLD
	CLD
	MOV RDX, SEEK_SET
	SYSCALL

	MOV RAX, SYS_MMAP
	XOR RDI, RDI
	CLD
	CLD
	CLD
	CLD
	CLD
	MOV RDX, 0X03
	MOV R10, 0X22
	MOV R8, -1
	XOR R9, R9
	SYSCALL
	MOV [RSP+0x08], RAX

	MOV RDI, [RSP]
	MOV RSI, [RSP+8]
	CLD
	CLD
	CLD
	CLD
	CLD
	MOV RAX, SYS_READ
	SYSCALL

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

	LEA RBX, [REL DATA ]
	MOV RDX, [RSP + 0X08]
	MOV [RBX], RDX

	MOV RDX, 5
	MOV RAX, SYS_MPROTECT
	SYSCALL
	ADD RSP, 0X10
	POP RBP	

	CALL _debug_00

	PUSH RBP
	MOV RBP, RSP
	SUB RSP, 512

	MOV QWORD [RSP], R15
	MOV QWORD [RSP+8], DWORD SA_RESTORER
	MOV QWORD [RSP+16], R14
	
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
	JMP DATA+8
	DATA: db "", -1, -1, -1, -1, -1, -1, -1, -1
	NOP
	NOP
	NOP
	NOP
	NOP
DATA_SYFER:
	
