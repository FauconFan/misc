%include "sys.s"
%define BUFF_SIZE	1024 * 4

section .bss
	buffer:	resb BUFF_SIZE

section .text
	global _ft_cat

_ft_cat:
		push	rbp
		mov		rbp, rsp
		sub		rsp, 16

		mov		[rsp + 0], rdi

	read:
		mov		rdi, [rsp + 0]
		lea		rsi, [rel buffer]
		mov		rdx, BUFF_SIZE
		mov		rax, SYS_READ
		syscall
		jc		end
		mov		[rsp + 8], rax
		cmp		rax, 0
		je		end

	write:
		mov		rdi, STDOUT
		lea		rsi, [rel buffer]
		mov		rdx, [rsp + 8]
		mov		rax, SYS_WRITE
		syscall
		cmp		rax, 0
		jl		end
		jmp		read

	end:
		mov		rsp, rbp
		pop		rbp
		ret
