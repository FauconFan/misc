
section .text
	global ft_toupper

;;	int		ft_toupper(int c);

ft_toupper:
		mov		eax, edi
		cmp		edi, `a`
		jl		.end
		cmp		edi, `z`
		jg		.end
		sub		eax, `a`
		add		eax, `A`

	.end:
		ret
