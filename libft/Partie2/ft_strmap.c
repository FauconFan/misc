#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	unsigned int 	index;
	char			*res;

	res = ft_strdup((char *)s);
	index = 0;
	while (s[index])
	{
		res[index] = f(s[index]);
		index++;
	}
	res[index] = 0;
	return (res);
}