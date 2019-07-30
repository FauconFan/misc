
section .text
	global	ft_getrandom

;;	void			ft_getrandom(void *mem, size_t n);

ft_getrandom:

	.8loop:
		cmp		rsi, 8
		jl		.1loop
		rdrand	rax
		mov		[rdi], rax
		add		rdi, 8
		sub		rsi, 8
		jmp		.8loop

	.1loop:
		cmp		rsi, 0
		je		.end
		rdrand	rax
		mov		byte [rdi], al
		inc		rdi
		dec		rsi
		jmp		.1loop

	.end:
		ret
