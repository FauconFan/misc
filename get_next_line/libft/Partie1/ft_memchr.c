#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*d;

	d = (char *)s;
	while (n)
	{
		if (*d == (char)c)
			return ((void *)d);
		d++;
		n--;
	}
	return (0);
}