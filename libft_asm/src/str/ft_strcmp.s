
section .text
	global ft_strcmp

;;	int		ft_strcmp(const char *s1, const char *s2);

ft_strcmp:
		xor		rax, rax
		xor		rbx, rbx

		cmp		rdi, 0
		je		.end
		cmp		rsi, 0
		je		.end

	.loop:
		mov		al, byte [rdi]
		mov		bl, byte [rsi]

		cmp		al, 0
		je		.gend
		cmp		bl, 0
		je		.gend
		cmp		al, bl
		jne		.gend

		inc		rdi
		inc		rsi

		jmp		.loop

	.bend:
		mov		rax, 0
		jmp		.end

	.gend:
		sub		rax, rbx
	
	.end:
		ret
