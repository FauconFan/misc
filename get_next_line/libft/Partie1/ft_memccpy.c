#include <string.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char	*s1;
	char	*s2;
	size_t	index;

	s1 = (char *)dest;
	s2 = (char *)src;
	index = 0;
	while (index < n)
	{
		s1[index] = s2[index];
		if (s1[index] == (char)c)
			return ((void *)(s1 + index + 1));
		index++;
	}
	return (0);
}