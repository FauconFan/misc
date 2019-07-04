
section .text
	global _ft_strlen

_ft_strlen:
		mov		ecx, -1
		xor		al, al
		cld
		repne	scasb
		not		ecx
		dec		ecx

		mov		eax, ecx

		ret
