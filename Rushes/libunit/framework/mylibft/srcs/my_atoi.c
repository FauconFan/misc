/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 12:01:24 by dwald             #+#    #+#             */
/*   Updated: 2017/01/10 18:18:13 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_unit_tests.h"

int		my_atoi(const char *str)
{
	int	i;
	int result;
	int negative;

	i = 0;
	negative = 1;
	result = 0;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == '\v' ||
			str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		negative = (str[i] == '-') ? -1 : 1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10;
		result = str[i] - 48 + result;
		i++;
	}
	return (result * negative);
}
