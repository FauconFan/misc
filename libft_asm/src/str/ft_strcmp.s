
section .text
	global ft_strcmp

;;	int		ft_strcmp(const char *s1, const char *s2);

ft_strcmp:
		xor		rax, rax
		xor		rbx, rbx

	.loop:
		mov		al, byte [rdi]
		mov		bl, byte [rsi]

		cmp		al, 0
		je		.end
		cmp		bl, 0
		je		.end
		cmp		al, bl
		jne		.end

		inc		rdi
		inc		rsi

		jmp		.loop

	.end:
		sub		rax, rbx
		ret
