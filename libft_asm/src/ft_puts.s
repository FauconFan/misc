%define SYS_MACHO(nb)		0x2000000 | nb
%define SYS_WRITE			SYS_MACHO(4)
%define STDOUT				1

section .data
	nl:			db 10

section .text
	global _ft_puts
	extern _ft_strlen

_ft_puts:
	push	rbp
	mov		rbp, rsp
	sub		rsp, 16

	mov		[rbp - 8], rdi ;saving pointer
	
	call	_ft_strlen

	mov		rdi, STDOUT
	mov		rsi, [rbp - 8]
	mov		rdx, rax
	mov		rax, SYS_WRITE
	syscall ; printing given string

	cmp		rax, 0
	jl		bad_end

	mov		rdi, STDOUT
	lea		rsi, [rel nl]
	mov		rdx, 1
	mov		rax, SYS_WRITE
	syscall ; print new line

	cmp		rax, 0
	jl		bad_end

	mov		rax, 1
	jmp		end

bad_end:
	mov		rax, 0

end:
	mov		rsp, rbp
	pop		rbp
	ret
