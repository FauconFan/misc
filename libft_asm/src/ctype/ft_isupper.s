
section .text
	global ft_isupper

ft_isupper:
		mov		eax, 0
		cmp		edi, `A`
		jl		.end
		cmp		edi, `Z`
		jg		.end
		mov		eax, 1

	.end:
		ret
