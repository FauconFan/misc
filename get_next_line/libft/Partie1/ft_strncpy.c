#include <string.h>

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	index;

	index = 0;
	while (src[index] && index < n)
	{
		dest[index] = src[index];
		index++;
	}
	while (index < n)
	{
		dest[index] = 0;
		index++;
	}
	dest[index] = 0;
	return (dest);
}