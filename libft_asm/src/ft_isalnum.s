
section .text
	global _ft_isalnum
	extern _ft_isdigit
	extern _ft_isalpha

_ft_isalnum:
	call	_ft_isalpha
	cmp		eax, 1
	je		end

	call	_ft_isdigit

end:
	ret
