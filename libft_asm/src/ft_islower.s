
section .text
	global ft_islower

ft_islower:
		mov		eax, 0
		cmp		edi, `a`
		jl		end
		cmp		edi, `z`
		jg		end
		mov		eax, 1

	end:
		ret
