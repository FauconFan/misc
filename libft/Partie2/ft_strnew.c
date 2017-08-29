#include <stdlib.h>
#include <string.h>

char	*ft_strnew(size_t size)
{
	char	*s;
	size_t	index;

	index = 0;
	s = (char *)malloc(sizeof(size));
	if (s == NULL)
		return (NULL);
	while (index < size)
	{
		s[index] = 0;
		index++;
	}
	return (s);
}