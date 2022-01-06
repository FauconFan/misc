
section .text
	global ft_memcmp

;;	int		ft_memcmp(const void *s1, const void *s2, size_t n);

ft_memcmp:
		xor		rax, rax
		xor		rbx, rbx

		cmp		rdi, 0
		je		.end
		cmp		rsi, 0
		je		.end

	.loop:
		cmp		rdx, 0
		je		.gend

		mov		al, byte [rdi]
		mov		bl, byte [rsi]
		cmp		al, bl
		jne		.bend

		dec		rdx
		inc		rdi
		inc		rsi

		jmp		.loop

	.bend:
		sub		rax, rbx
		jmp		.end

	.gend:
		mov		rax, 0

	.end:
		ret
