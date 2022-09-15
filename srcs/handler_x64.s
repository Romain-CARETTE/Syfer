BITS 64

section .text
	global _start
	global main

%define SYS_MPROTECT	10
%define PAGE_SIZE	0X1000
%define SYS_WRITE 0x01
%define SYS_RT_SIGACTION 0x0d
%define SYS_RT_SIGRETURN 0x0f
%define SYS_MPROTECT	10
%define PAGE_SIZE	0X1000
%define SIGTERM 0x0f
%define SIGINT 0x02
%define SIGTRAP	0x05 
%define STDOUT 0x01
%define SA_RESTORER 0x04000000


	LEA r15, [ REL handler ]
	LEA r14, [ REL restorer ]
	JMP _start
handler:
	MOV R10, 7
	CALL mprotect
	MOV RDI, RSP
	ADD RDI, 0XB0
	MOV RDI, [RDI]
	
	XOR RDX, RDX
	XOR RAX, RAX
	MOV RAX, 13
	MOV DX, WORD [RDI]
	MUL RDX

	LEA RSI, [REL DATA_SYFER]
	ADD RSI, RAX
	

	MOV RDI, RSP
	ADD RDI, 0XB0
	MOV RDI, [RDI]
	SUB RDI, 1
	MOV BYTE [RDI], 0X55
	MOV BYTE [RDI+1], 0X48
	MOV BYTE [RDI+2], 0X89
	

	MOV [RSP + 0XB0 ], RDI

	LEA RSI, [REL DATA_SYFER]
	ADD RSI, RAX

	PUSH RDI
	XCHG RDI, RDX
	ADD RDX, 0X03
	ADD RSI, 0X01
	MOV RCX, [RSI]
	ADD RSI, 4
	MOV RDI, 8
	XCHG RDI, RSI
	CALL _rc4
	POP RDI


	JMP END

;;ENCRYPT:
;;	CALL _debug_02
		
END:	
	MOV R10, 5	
	CALL mprotect
	CALL _debug_01
	RET
	


mprotect:
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
	MOV RDX, R10
	MOV RAX, SYS_MPROTECT
	SYSCALL
	RET


restorer:
	MOV RAX, SYS_RT_SIGRETURN
	SYSCALL

_debug_01:
CALL AFTER_DEBUG00
.string db "...End handler...", 0x0A
AFTER_DEBUG00:
MOV RDI, STDOUT
POP RSI
MOV RDX, 18
MOV RAX, SYS_WRITE
SYSCALL
RET

_debug_02:
CALL AFTER_DEBUG02
.string db "...Decrypt...", 0x0A
AFTER_DEBUG02:
MOV RDI, STDOUT
POP RSI
MOV RDX, 14
MOV RAX, SYS_WRITE
SYSCALL
RET

_rc4:
	PUSH RBP
	MOV RBP, RSP
	SUB RSP, 0X188
	MOV R9, RDX
	MOV DWORD R8d, 0X00

j1:
	mov	byte [rsp+r8*1+0x88], r8b
	mov	eax, r8d
	cdq
	idiv	esi
	movsxd	rdx, edx
	movzx	eax, byte [rdi+rdx*1]
	mov	byte [rsp+r8*1-0x78],al
	add	r8, 0x1
	cmp	r8,0x100
	jne	j1
	mov	edx, 0x0
	mov	esi, 0x0
	lea	r8, [rsp-0x78]

j2:
	movzx	edi, byte [rsp+rdx*1+0x88]
	movzx	eax, dil
	add	eax, esi
	movzx	esi, byte [rdx+r8*1]
	add	eax, esi
	mov	esi, eax
	sar	esi, 0x1f
	shr	esi, 0x18
	add	eax, esi
	movzx	eax,al
	sub	eax,esi
	mov	esi, eax
	cdqe
	movzx	r10d, byte [rsp+rax*1+0x88]
	mov	[rsp+rdx*1+0x88], r10b
	mov	[rsp+rax*1+0x88], dil
	add	rdx,0x1
	cmp	rdx,0x100
	jne	j2
	test	ecx,ecx
	jle	j3
	lea	eax, [rcx-0x1]
	lea	rdi, [r9+rax*1+0x1]
	xor	edx, edx
	xor	eax, eax

j4:
	add 	rax, 0x1
	movzx 	eax,al
	movzx 	ecx, byte [rsp+rax*1+0x88]
	add 	edx, ecx
	movzx 	edx,dl
	movzx 	esi, byte [rsp+rdx*1+0x88]
	mov	[rsp+rax*1+0x88], sil
	mov	[rsp+rdx*1+0x88], cl
	add	cl, [rsp+rax*1+0x88]
	xor	[r9],cl
	add	r9, 1
	cmp	rdi,r9
	jne	j4

j3:
	add	rsp,0x188
	leave
	ret

_start:
	PUSH RAX
	PUSH RCX
	PUSH RBX
	PUSH RDX
	PUSH RDI
	PUSH RSI

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
	JMP .data+4
	.data db "", -1, -1, -1, -1
	NOP
	NOP
	NOP
	NOP
	NOP
DATA_SYFER:
	
