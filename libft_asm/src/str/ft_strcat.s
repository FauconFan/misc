
section .text
	global ft_strcat
	extern ft_strlen

ft_strcat:
		push	rbp
		mov		rbp, rsp
		sub		rsp, 32

		mov		[rsp + 8], rdi

		mov		ecx, -1
		xor		al, al
		cld
		repne	scasb

		dec		rdi

		mov		[rsp + 16], rdi
		mov		[rsp + 24], rsi
		mov		rdi, rsi
		call	ft_strlen

		mov		rcx, rax
		mov		rdi, [rsp + 16]
		mov		rsi, [rsp + 24]
		cld
		rep		movsb

		mov		byte [rdi], 0

		mov		rax, [rsp + 8]
		mov		rsp, rbp
		pop		rbp
		ret
