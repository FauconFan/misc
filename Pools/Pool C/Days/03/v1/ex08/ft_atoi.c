/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 23:40:04 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/04 14:33:14 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		get_int_from_char(char c)
{
	if (c == '1')
		return (1);
	else if (c == '2')
		return (2);
	else if (c == '3')
		return (3);
	else if (c == '4')
		return (4);
	else if (c == '5')
		return (5);
	else if (c == '6')
		return (6);
	else if (c == '7')
		return (7);
	else if (c == '8')
		return (8);
	else if (c == '9')
		return (9);
	return (0);
}

int		ft_atoi(char *str)
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
		res += get_int_from_char(c);
		index++;
		c = str[index];
	}
	return (res);
}
