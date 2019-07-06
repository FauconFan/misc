
section .data
hello:
	.string	db "hello", 10

section .text
	global start
	global main
	extern printf

start:
	call main
	ret

main:
	push	rbp
	mov		rbp, rsp
	sub		rsp, 16

	lea		rdi, [rel hello.string]
	call	printf

	mov		rax, 0
	mov		rsp, rbp
	pop		rbp
	ret
