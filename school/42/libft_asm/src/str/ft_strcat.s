
section .text
	global ft_strcat
	extern ft_strlen

;;	char	*ft_strcat(char *s1, const char *s2);

ft_strcat:
		push	rbp
		mov		rbp, rsp
		sub		rsp, 32

		mov		[rsp + 0], rdi
		cmp		rdi, 0
		je		.end
		cmp		rsi, 0
		je		.end

		mov		ecx, -1
		xor		al, al
		cld
		repne	scasb

		dec		rdi

		mov		[rsp + 0x8], rdi
		mov		[rsp + 0x10], rsi
		mov		rdi, rsi
		call	ft_strlen

		mov		rcx, rax
		mov		rdi, [rsp + 0x8]
		mov		rsi, [rsp + 0x10]
		cld
		rep		movsb

		mov		byte [rdi], 0

	.end:
		mov		rax, [rsp + 0]
		mov		rsp, rbp
		pop		rbp
		ret
