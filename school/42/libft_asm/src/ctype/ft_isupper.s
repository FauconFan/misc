
section .text
	global ft_isupper

;;	int		ft_isupper(int c);

ft_isupper:
		mov		eax, 0
		cmp		edi, `A`
		jl		.end
		cmp		edi, `Z`
		jg		.end
		mov		eax, 1

	.end:
		ret
