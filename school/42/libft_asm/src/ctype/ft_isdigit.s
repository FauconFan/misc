
section .text
	global ft_isdigit

;;	int		ft_isdigit(int c);

ft_isdigit:
		mov		eax, 0
		cmp		edi, `0`
		jl		.end
		cmp		edi, `9`
		jg		.end
		mov		eax, 1

	.end:
		ret
