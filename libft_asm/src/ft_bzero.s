
section .text
	global _ft_bzero
	extern _ft_memset

_ft_bzero:
	mov		rdx, rsi
	mov		rsi, 0
	call	_ft_memset
	ret

; _ft_bzero:
; loop:
; 	cmp		rsi, 0
; 	je		end
; 	mov		byte [rdi], 0
; 	inc		rdi
; 	dec		rsi
; 	jmp		loop
; end:
; 	ret
