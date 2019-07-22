
section .text
	global ft_bzero
	extern ft_memset

ft_bzero:
		mov		rdx, rsi
		mov		rsi, 0
		call	ft_memset
		ret

; ft_bzero:
; loop:
; 	cmp		rsi, 0
; 	je		end
; 	mov		byte [rdi], 0
; 	inc		rdi
; 	dec		rsi
; 	jmp		loop
; end:
; 	ret
