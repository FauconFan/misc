
section .text
	global _ft_tolower

_ft_tolower:
	mov		eax, edi
	cmp		edi, `A`
	jl		end
	cmp		edi, `Z`
	jg		end
	add		eax, `a`
	sub		eax, `A`

end:
	ret
