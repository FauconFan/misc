#include <string.h>

int		ft_strnequ(const char *s1, const char *s2, size_t n)
{
	size_t	index;

	index = 0;
	while (s1[index] == s2[index] && index < n)
	{
		if (s1[index] == 0)
			return (1);
		index++;
	}
	return (0);
}