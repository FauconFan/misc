/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 23:40:04 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/05 18:25:30 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		get_int_from_char(char c)
{
	return (c - '0');
}

int		atoi_read(char *str)
{
	int		res;
	char	c;
	int		index;

	res = 0;
	c = str[0];
	index = 0;
	while (c >= '0' && c <= '9')
	{
		res *= 10;
		res -= get_int_from_char(c);
		index++;
		c = str[index];
	}
	return (res);
}

int		ft_atoi(char *str)
{
	if (str[0] == '-')
		return (atoi_read(str + 1));
	if (str[0] >= '0' && str[0] <= '9')
		return (-(atoi_read(str)));
	return (0);
}
