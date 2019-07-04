
section .text
	global _ft_islower

_ft_islower:
	mov		eax, 0
	cmp		edi, `a`
	jl		end
	cmp		edi, `z`
	jg		end
	mov		eax, 1

end:
	ret
