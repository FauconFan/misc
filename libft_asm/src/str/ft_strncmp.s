
section .text
	global ft_strncmp
	extern ft_memcmp

;;	int		ft_strncmp(const char *s1, const char *s2, size_t n);

ft_strncmp:
		call		ft_memcmp
		ret
