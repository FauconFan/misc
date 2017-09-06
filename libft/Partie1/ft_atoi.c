#include "libft.h"

int		ft_atoi(char const *nptr)
{
	int		res;
	int		sign;

	res = 0;
	sign = 1;
	while (*nptr == ' ' || *nptr == '\n' || *nptr == '\t'
		|| *nptr == '\f' || *nptr == '\v' || *nptr == '\r')
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
	return (res * -sign);
}