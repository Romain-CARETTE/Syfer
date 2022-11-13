BITS 64
%define SYS_MPROTECT	10
%define PAGE_SIZE	0X1000
section .text
	global _start
	global main


_start:
main:
	push 0
	push 127
	push 128
	push 2147483647
	push 65537
	mov rax, 0X07eb036a026a016a
	jmp -9
	mov rax, 0X02eb066a056a046a
	mov rax, 0X02eb096a086a076a
	mov rax, 0X90900c6a0b6a0a6a
	xor rdx, rdx
	mov rcx, 0X05eb0f6a0e6a0d6a
	jmp -9

	mov rcx, 0X05eb036a026a016a
	jmp -9
	ret
