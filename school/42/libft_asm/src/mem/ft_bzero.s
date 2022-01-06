
section .text
	global ft_bzero
	extern ft_memset

;;	void	ft_bzero(void *v, size_t n);

ft_bzero:
		mov		rdx, rsi
		mov		rsi, 0
		call	ft_memset
		ret
