
section .text
	global ft_memcpy

ft_memcpy:
		push	rbp
		mov		rbp, rsp
		sub		rsp, 16

		mov		[rsp + 8], rdi
		mov		rcx, rdx
		cld
		rep		movsb

		mov		rax, [rsp + 8]
		mov		rsp, rbp
		pop		rbp
		ret
