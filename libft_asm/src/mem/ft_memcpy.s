
section .text
	global ft_memcpy

;;	void	*ft_memcpy(void *dst, const void *src, size_t n);

ft_memcpy:
		push	rbp
		mov		rbp, rsp
		sub		rsp, 16

		mov		[rsp + 0], rdi
		cmp		rdi, 0
		je		.end
		cmp		rsi, 0
		je		.end
		mov		rcx, rdx
		cld
		rep		movsb

	.end:
		mov		rax, [rsp + 0]
		mov		rsp, rbp
		pop		rbp
		ret
