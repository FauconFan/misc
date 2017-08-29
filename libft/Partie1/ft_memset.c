#include <string.h>

void	*ft_memset(void *s, int c, size_t n)
{
	char	*d;
	size_t	index;

	index = 0;
	d = (char *)s;
	while (index < n)
	{
		d[index] = (char)c;
		index++;
	}
	return (s);
}