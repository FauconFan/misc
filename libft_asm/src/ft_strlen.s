
section .text
	global ft_strlen

ft_strlen:
		mov		ecx, -1
		xor		al, al
		cld
		repne	scasb
		not		ecx
		dec		ecx

		mov		eax, ecx

		ret
