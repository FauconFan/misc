#include <string.h>

int		ft_strncmp(char *s1, char *s2, size_t size)
{
	if (*s1 == 0 || *s2 == 0 || *s1 != *s2 || size == 1)
		return (*s1 - *s2);
	return (ft_strncmp(s1 + 1, s2 + 1, size - 1));
}