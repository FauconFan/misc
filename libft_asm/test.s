%define SYS_MACHO(nb)		0x2000000 | nb
%define SYS_WRITE			SYS_MACHO(4)
%define STDOUT				1

section .data
	msg1:		db 'Hello World', 10
	msg1_len:	equ $ - msg1
	msg2:		db 'Hello Two, 10
	msg2_len:	equ $ - msg2

section .text
	global _main
	extern _ft_strlen

_main:
	mov al, 'H'

	mov rdi, STDOUT
	mov rsi, msg1
	mov rdx, msg1_len
	mov rax, SYS_WRITE
	mov rax, dword[rdi]
	syscall
	mov rax, 0
	ret
