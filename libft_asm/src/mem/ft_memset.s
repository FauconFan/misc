
section .text
	global ft_memset

;;	void	*ft_memset(void *v, int c, size_t n);

ft_memset:
		push	rbp
		mov		rbp, rsp
		sub		rsp, 16

		mov		[rsp + 0], rdi
		cmp		rdi, 0
		je		.end
		mov		rcx, rdx
		mov		rax, rsi

		cld
		rep		stosb

	.end:
		mov		rax, [rsp + 0]
		mov		rsp, rbp
		pop		rbp
		ret
