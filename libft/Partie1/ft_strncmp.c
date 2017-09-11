#include <string.h>

int		ft_strncmp(const char *s1, const char *s2, size_t size)
{

	if (size == 0)
		return (0);

	while (*(unsigned char *)s1 == *(unsigned char *)s2)
	{
		if (*(unsigned char *)s1 == 0)
			return (0);
		if (size == 1)
			return (*s1 - *s2);
		s1++;
		s2++;
		size--;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}