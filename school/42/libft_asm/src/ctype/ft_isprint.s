
section .text
	global ft_isprint

;;	int		ft_isprint(int c);

ft_isprint:
		mov		eax, 0
		cmp		edi, ` `
		jl		.end
		cmp		edi, `~`
		jg		.end
		mov		eax, 1

	.end:
		ret
