
%include "sys.s"

section .text
	global ft_strdup
	extern malloc
	extern ft_strlen
	extern ft_memcpy

ft_strdup:
		push	rbp
		mov		rbp, rsp
		sub		rsp, 32

		mov		[rsp + 16], rdi
		
		call	ft_strlen
		inc		rax
		mov		[rsp + 24], rax
		mov		[rsp + 0], rax
		call	malloc
		test	rax, rax
		je		fail
		mov		[rsp + 8], rax

		mov		rdi, rax
		mov		rsi, [rsp + 16]
		mov		rdx, [rsp + 24]
		call	ft_memcpy

		mov		rax, [rsp + 8]
		jmp		end

	fail:
		mov		rax, 0

	end:
		mov		rsp, rbp
		pop		rbp
		ret
