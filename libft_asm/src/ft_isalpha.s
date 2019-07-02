
section .text
	global _ft_isalpha

_ft_isalpha:
	mov		eax, 0
	cmp		edi, `A`
	jl		next
	cmp		edi, `Z`
	jg		next
	mov		eax, 1
	jmp		end

next:
	cmp		edi, `a`
	jl		end
	cmp		edi, `z`
	jg		end
	mov		eax, 1

end:
	ret
