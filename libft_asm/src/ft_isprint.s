
section .text
	global ft_isprint

ft_isprint:
		mov		eax, 0
		cmp		edi, ` `
		jl		end
		cmp		edi, `~`
		jg		end
		mov		eax, 1

	end:
		ret
