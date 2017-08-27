#include <string.h>

size_t	ft_strlen(char const *s)
{
	size_t	size;

	size = 0;
	while (s[size])
		size++;
	return (size);
}