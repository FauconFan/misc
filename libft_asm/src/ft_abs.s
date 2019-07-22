
section .text
	global ft_abs

ft_abs:
		mov		eax, edi
		cdq
		xor		eax, edx
		sub		eax, edx
		ret
