
section .text
	global ft_isalnum
	extern ft_isdigit
	extern ft_isalpha

ft_isalnum:
		call	ft_isalpha
		cmp		eax, 1
		je		end

		call	ft_isdigit

	end:
		ret
