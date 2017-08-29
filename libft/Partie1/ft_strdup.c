#include <stdlib.h>

char	*strdup(const char *s)
{
	unsigned int	len;
	char			*res;

	len = 0;
	res = 0;
	while (s[len])
		len++;
	res = (char *)malloc(sizeof(char) * (len + 1));
	len = 0;
	while (s[len])
	{
		res[len] = s[len];
		len++;
	}
	res[len] = 0;
	return (res);
}