#include <string.h>
#include <stdlib.h>

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	index;

	index = 0;
	if ((res = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	while (index < len)
	{
		res[index] = s[(size_t)start + index];
		index++;
	}
	res[index] = 0;
	return (res);
}