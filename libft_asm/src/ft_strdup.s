%include "sys.s"

section .text
	global _ft_strdup
	extern _malloc
	extern _ft_strlen
	extern _ft_memcpy

_ft_strdup:
		push	rbp
		mov		rbp, rsp
		sub		rsp, 32

		mov		[rsp + 16], rdi
		
		call	_ft_strlen
		inc		rax
		mov		[rsp + 24], rax
		mov		[rsp + 0], rax
		call	_malloc
		test	rax, rax
		je		fail
		mov		[rsp + 8], rax

		mov		rdi, rax
		mov		rsi, [rsp + 16]
		mov		rdx, [rsp + 24]
		call	_ft_memcpy

		mov		rax, [rsp + 8]
		jmp		end

	fail:
		mov		rax, 0

	end:
		mov		rsp, rbp
		pop		rbp
		ret
