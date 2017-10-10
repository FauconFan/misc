/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 08:13:09 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/09 09:46:23 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		my_strlen(char *s)
{
	int		length;

	length = 0;
	while (s[length])
		length++;
	return (length);
}

int		place_in_str(char c, char *s)
{
	int		index;

	index = 0;
	while (s[index])
	{
		if (s[index] == c)
		{
			return (index);
		}
		index++;
	}
	return (-1);
}

int		build_number_deci(char *nbr, char *base_from, int length_base)
{
	int		index;
	int		sign;
	int		nb;

	nb = 0;
	index = 0;
	sign = (*nbr == '-') ? 1 : 0;
	if (*nbr == '-' || *nbr == '+')
		nbr++;
	while (nbr[index])
	{
		nb *= length_base;
		nb -= place_in_str(nbr[index], base_from);
		index++;
	}
	if (sign == 0)
		nb *= -1;
	return (nb);
}

int		get_length_number_in_base(int nb, int length_base)
{
	int		length;

	length = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
		nb = -nb;
	while (nb != 0)
	{
		length++;
		nb = nb / length_base;
	}
	return (length);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		length[3];
	int		nb;
	int		limit;
	int		tmp;
	char	*res;

	length[0] = my_strlen(base_from);
	length[1] = my_strlen(base_to);
	limit = 0;
	nb = build_number_deci(nbr, base_from, length[0]);
	length[2] = get_length_number_in_base(nb, length[1]);
	if (*nbr == '-' && *nbr == '+')
		nbr++;
	res = (char *)malloc(sizeof(*res) * (length[2] + 1));
	if (*nbr == '-')
	{
		length[2]++;
		limit = 1;
		res[0] = '-';
	}
	res[length[2]] = '\0';
	while (--length[2] >= limit)
	{
		tmp = nb % length[1];
		res[length[2]] = base_to[(tmp < 0) ? -tmp : tmp];
		nb = nb / length[1];
	}
	return (res);
}

int		main()
{
	printf("STARTED\n");
	printf("%s\n", ft_convert_base("-2A", "0123456789ABCDEF", "01"));
}
