
section .text
	global _ft_strlen

_ft_strlen:
	push	rbp
	mov		rbp, rsp
	sub		rsp, 8

	mov		ecx, -1
	xor		al, al
	cld
	repne	scasb
	not		ecx
	dec		ecx
	mov		eax, ecx

	mov		rsp, rbp
	pop		rbp
	ret
