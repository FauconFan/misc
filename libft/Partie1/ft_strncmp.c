#include <string.h>

int		ft_strncmp(char const *s1, char const *s2, size_t size)
{
	if (size == 0)
		return (0);
	else if (s1 == 0 && s2 == 0)
		return (0);
	else if (s1 == 0)
		return (0 - *s2);
	else if (s2 == 0)
		return (*s1 - 0);
	else if (*s1 == 0 || *s2 == 0 || *s1 != *s2 || size == 1)
		return (*s1 - *s2);
	return (ft_strncmp((char const *)(s1 + 1), (char const *)(s2 + 1), size - 1));
}