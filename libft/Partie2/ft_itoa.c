#include <stdlib.h>
#include <string.h>

static size_t		ft_log_pos(int n)
{
	if (n == 0)
		return (0);
	return (1 + ft_log_pos(n / 10));
}

static size_t		ft_log(int n)
{
	if (n == 0)
		return (1);
	else if (n < 0)
		return (1 + ft_log_pos(-n));
	return (ft_log_pos(n));
}

char				*ft_itoa(int n)
{
	char	*res;
	int		index;
	size_t	len;

	len = ft_log(n);
	index = 0;
	if ((res = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	if (n == 0)
	{
		res[0] = '0';
		res[1] = 0;
		return (res);
	}
	else if (n < 0)
		res[0] = '-';
	index = (int)len - 1;
	while (n)
	{
		res[index] = (n % 10) * ((n < 0) ? -1 : 1) + '0';
		index--;
		n /= 10;
	}
	res[len] = 0;
	return (res);
}