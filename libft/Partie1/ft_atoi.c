#include "libft.h"

static int	ft_isspace(char c)
{
	return (c == ' ' || c == '\n' || c == '\t' ||
			c == '\f' || c == '\v' || c == '\r');
}

int			ft_atoi(char const *nptr)
{
	int		res;
	int		sign;

	res = 0;
	sign = 1;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == 0)
		return (0);
	else if (*nptr == '+')
		nptr++;
	else if (*nptr == '-')
	{
		nptr++;
		sign = -1;
	}
	while (ft_isdigit(*nptr))
	{
		res = res * 10 - (*nptr - '0');
		nptr++;
	}
	return (-res * sign);
}