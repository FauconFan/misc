#include <stdlib.h>
#include <string.h>

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	unsigned int 	index;
	char			*res;

	index = 0;
	while (s[index])
		index++;
	if ((res = (char *)malloc(sizeof(char) * (index + 1))) == NULL)
		return (NULL);
	index = 0;
	while (s[index])
	{
		res[index] = f(index, s[index]);
		index++;
	}
	res[index] = 0;
	return (res);
}