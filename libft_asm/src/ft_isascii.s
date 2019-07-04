
section .text
	global _ft_isascii

_ft_isascii:
		mov		eax, 0
		cmp		edi, 0
		jl		end
		cmp		edi, 127
		jg		end
		mov		eax, 1

	end:
		ret
