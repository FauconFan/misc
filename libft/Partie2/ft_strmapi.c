#include <stdlib.h>
#include <string.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
		res[index] = f(res[index], index);
		index++;
	}
	res[index] = 0;
	return (res);
}