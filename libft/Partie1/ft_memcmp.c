#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*d1;
	char	*d2;
	size_t	index;

	d1 = (char *)s1;
	d2 = (char *)s2;
	index = 0;
	while (*d1 == *d2 && index < n)
	{
		if (*d1 == 0)
			return (0);
		d1++;
		d2++;
		index++;
	}
	if (index == n)
		return (0);
	return (*d1 - *d2);
}