
section .text
	global _ft_toupper

_ft_toupper:
	mov		eax, edi
	cmp		edi, `a`
	jl		end
	cmp		edi, `z`
	jg		end
	sub		eax, `a`
	add		eax, `A`

end:
	ret
