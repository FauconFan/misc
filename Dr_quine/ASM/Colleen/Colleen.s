
section .data
hello:
	.string	db "%3$csection .data%3$chello:%3$c%2$c.string%2$cdb %4$c%1$s%4$c%3$c%3$csection .text%3$c%2$cglobal main%3$c%2$cextern printf%3$c%3$cget_str:%3$c%2$c%2$clea%2$c%2$crax, [rel hello.string]%3$c%2$c%2$cret%3$c%3$cmain:%3$c%2$c%2$cpush%2$crbp%3$c%2$c%2$cmov%2$c%2$crbp, rsp%3$c%2$c%2$csub%2$c%2$crsp, 16%3$c%3$c%2$c%2$ccall%2$cget_str%3$c%2$c%2$cmov%2$c%2$crdi, rax%3$c%2$c%2$cmov%2$c%2$crsi, rax%3$c%2$c%2$cmov%2$c%2$crdx, 9%3$c%2$c%2$cmov%2$c%2$crcx, 10%3$c%2$c%2$cmov%2$c%2$cr8, 34%3$c%2$c%2$ccall%2$cprintf%3$c%3$c%2$c%2$cmov%2$c%2$crax, 0%3$c%2$c%2$cmov%2$c%2$crsp, rbp%3$c%2$c%2$cpop%2$c%2$crbp%3$c%2$c%2$cret%3$c"

section .text
	global main
	extern printf

get_str:
		lea		rax, [rel hello.string]
		ret

main:
		push	rbp
		mov		rbp, rsp
		sub		rsp, 16

		call	get_str
		mov		rdi, rax
		mov		rsi, rax
		mov		rdx, 9
		mov		rcx, 10
		mov		r8, 34
		call	printf

		mov		rax, 0
		mov		rsp, rbp
		pop		rbp
		ret
