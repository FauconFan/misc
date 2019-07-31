
section .text
	global ft_memchr

;;	void	*ft_memchr(const void *s, int c, size_t n);

ft_memchr:
		cmp		rdi, 0
		je		.fail

		mov		rbx, rdi
		mov		ecx, edx
		mov		ax, si
		cld
		repne	scasb

		cmp		ecx, 0
		je		.fail
		inc		ecx
		mov		rax, rbx
		add		rax, rdx
		sub		rax, rcx
		; mov		rax, rbx + edx - ecx

		jmp .end

	.fail:
		mov		rax, qword 0

	.end:
		ret
