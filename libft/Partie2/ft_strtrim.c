#include <stdlib.h>
#include <string.h>

static int	is_blank(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

static int	check_only_blank(char *tmp)
{
	while (*tmp)
	{
		if (is_blank(*tmp) == 0)
			return (1);
		tmp++;
	}
	return (0);
}

char		*ft_strtrim(const char *s)
{
	char	*tmp;
	char	*res;
	size_t	real_size;
	size_t	index;

	tmp = (char *)s;
	res = 0;
	real_size = 0;
	index = 0;
	if (check_only_blank((char *)s) == 0)
		return (NULL);
	while (is_blank(*tmp))
		tmp++;
	while (tmp[real_size])
		real_size++;
	real_size--;
	while (is_blank(tmp[real_size]))
		real_size--;
	real_size++;
	if ((res = (char *)malloc(sizeof(char) * (real_size + 1))) == NULL)
		return (NULL);
	while (index < real_size)
	{
		res[index] = tmp[index];
		index++;
	}
	res[index] = 0;
	return (res);
}