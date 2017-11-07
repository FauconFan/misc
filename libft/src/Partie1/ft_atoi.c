/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 09:49:11 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/07 14:41:03 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
