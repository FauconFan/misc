
section .text
	global ft_strequ
	extern ft_strcmp

;;	int		ft_strequ(const char *s1, const char *s2);

ft_strequ:

		cmp		rdi, 0
		je		.bend
		cmp		rsi, 0
		je		.bend

		call	ft_strcmp
		cmp		rax, 0
		je		.equal
		mov		rax, 0
		jmp		.end

	.bend:
		mov		rax, 0
		jmp		.end

	.equal:
		mov		rax, 1

	.end:
		ret
