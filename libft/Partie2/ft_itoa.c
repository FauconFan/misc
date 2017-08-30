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

static int			get_higher_rank(int n)
{
	if (n < 10)
		return (n);
	return (get_higher_rank(n / 10));
}

static int			get_next(int n)
{
	int		tmp;
	size_t	log;

	log = 1;
	tmp = n;
	while (tmp >= 10)
	{
		tmp = tmp / 10;
		log++;
	}
	tmp = get_higher_rank(n);
	while (log != 1)
	{
		tmp *= 10;
		log--;
	}
	return (n - tmp);
}

char				*ft_itoa(int n)
{
	char	*res;
	size_t	index;
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
	{
		res[0] = '-';
		index++;
		n *= -1;
	}
	while (n)
	{
		res[index] = get_higher_rank(n) + '0';
		index++;
		n = get_next(n);
	}
	return (res);
}