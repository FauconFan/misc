
section .text
	global ft_isalnum
	extern ft_isdigit
	extern ft_isalpha

;;	int		ft_isalnum(int c);

ft_isalnum:
		call	ft_isalpha
		cmp		eax, 1
		je		.end

		call	ft_isdigit

	.end:
		ret
