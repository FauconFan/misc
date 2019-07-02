
section .text
	global _ft_isprint

_ft_isprint:
	mov		eax, 0
	cmp		edi, ` `
	jl		end
	cmp		edi, `~`
	jg		end
	mov		eax, 1

end:
	ret
