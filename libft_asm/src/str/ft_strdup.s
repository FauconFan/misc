
%include "sys.s"

section .text
	global ft_strdup
	extern malloc
	extern ft_strlen
	extern ft_memcpy

;;	char	*ft_strdup(const char *s);

ft_strdup:
		push	rbp
		mov		rbp, rsp
		sub		rsp, 16

		cmp		rdi, 0
		je		.fail

		mov		[rsp + 8], rdi

		call	ft_strlen
		inc		rax
		mov		[rsp + 0], rax
		mov		rdi, rax
		call	malloc
		test	rax, rax
		je		.fail

		mov		rdi, rax
		mov		rsi, [rsp + 8]
		mov		rdx, [rsp + 0]
		call	ft_memcpy

		jmp		.end

	.fail:
		mov		rax, 0

	.end:
		mov		rsp, rbp
		pop		rbp
		ret
