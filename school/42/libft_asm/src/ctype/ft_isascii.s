
section .text
	global ft_isascii

;;	int		ft_isascii(int c);

ft_isascii:
		mov		eax, 0
		cmp		edi, 0
		jl		.end
		cmp		edi, 127
		jg		.end
		mov		eax, 1

	.end:
		ret
