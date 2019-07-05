
section .text
	global ft_memset

ft_memset:
		mov		rcx, rdx
		mov		rax, rsi

		cld
		rep		stosb

		ret
