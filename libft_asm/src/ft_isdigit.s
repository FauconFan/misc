
section .text
	global _ft_isdigit

_ft_isdigit:
	mov		eax, 0
	cmp		edi, `0`
	jl		end
	cmp		edi, `9`
	jg		end
	mov		eax, 1

end:
	ret
