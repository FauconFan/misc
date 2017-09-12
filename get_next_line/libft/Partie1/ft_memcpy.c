#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*d1;
	char	*d2;
	size_t	index;

	index = 0;
	d1 = (char *)dest;
	d2 = (char *)src;
	while (index < n)
	{
		d1[index] = d2[index];
		index++;
	}
	return (dest);
}