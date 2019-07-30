
section .text
	global ft_abs

;;	unsigned int	ft_abs(int a)

ft_abs:
		mov		eax, edi
		cdq
		xor		eax, edx
		sub		eax, edx
		ret
