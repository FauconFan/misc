
section .data
fmt:
	.string	db "fmt"

section .text
	global main
	extern dprintf

main:
		push	rbp
		mov		rbp, rsp
		sub		rsp, 16

		; Get the code of the current program
		mov		rdi, 1
		lea		rsi, [rel fmt.string]
		call	dprintf

		mov		rax, 0
		mov		rsp, rbp
		pop		rbp
		ret
