
section .text
	global ft_isalpha
	extern ft_isupper
	extern ft_islower

;;	int		ft_isalpha(int c);

ft_isalpha:
		call	ft_isupper
		cmp		eax, 1
		je		.end

		call	ft_islower

	.end:
		ret
