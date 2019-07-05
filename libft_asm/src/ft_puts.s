
%include "sys.s"

section .data
null_st:
	.string			db "(null)"
	.len			equ $ - null_st.string

nl:
	.string			db 10
	.len			equ $ - nl.string

section .text
	global ft_puts
	extern ft_strlen

ft_puts:
		push	rbp
		mov		rbp, rsp
		sub		rsp, 16

		cmp		rdi, 0
		jnz		normal

	null:
		lea		rsi, [rel null_st.string]
		mov		rdx, null_st.len
		jmp		print

	normal:
		mov		[rsp + 0], rdi

		call	ft_strlen
		mov		rsi, [rsp + 0]
		mov		rdx, rax

	print:
		mov		rdi, STDOUT
		mov		rax, SYS_WRITE
		syscall ; printing given string

		cmp		rax, 0
		jl		bad_end

		mov		rdi, STDOUT
		lea		rsi, [rel nl.string]
		mov		rdx, nl.len
		mov		rax, SYS_WRITE
		syscall ; print new line

		cmp		rax, 0
		jl		bad_end

		mov		rax, 10
		jmp		end

	bad_end:
		mov		rax, 0

	end:
		mov		rsp, rbp
		pop		rbp
		ret
