
section .text
	global ft_tolower

;;	int		ft_tolower(int c);

ft_tolower:
		mov		eax, edi
		cmp		edi, `A`
		jl		.end
		cmp		edi, `Z`
		jg		.end
		add		eax, `a`
		sub		eax, `A`

	.end:
		ret
