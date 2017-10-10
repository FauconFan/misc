/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 08:30:11 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/09 14:52:59 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		place_in_str(char c, char *s)
{
	int		index;

	index = 0;
	while (s[index])
	{
		if (c == s[index])
		{
			return (index);
		}
		index++;
	}
	return (-1);
}

char	*adapt_str(char *str)
{
	int		index;
	char	c;

	index = 0;
	c = *str;
	while (c != '\0')
	{
		if (c != ' ' && c != '\t' && c != '\v' && c != '\f')
		{
			if (c != '\n' && c != '\r')
			{
				break ;
			}
		}
		index++;
		c = str[index];
	}
	return (str + index);
}

int		atoi_read(char *str, char *base)
{
	int		res;
	char	c;
	int		index;
	int		length_base;

	length_base = 0;
	res = 0;
	c = str[0];
	index = 0;
	while (base[length_base])
		length_base++;
	while (place_in_str(c, base) > -1)
	{
		printf("%d\n", res);
		res *= length_base;
		res -= (place_in_str(c, base));
		index++;
		c = str[index];
	}
	printf("%d\n", res);
	return (res);
}

int		respect_norme_and_length_base(char *s, char *str)
{
	int		index[3];
	int		is_okay;
	char	c;

	index[0] = 0;
	index[1] = 0;
	//	printf("DEBUG\n");
	while (s[index[0]])
	{
	//	printf("DEBUG + %s OUI  \n", s + index[0]);
		c = s[index[0]];
		if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%')
			return (0);
		index[2] = 0;
		is_okay = 0;
	//	printf("DEBUG + %s NON \n", str + index[2]);
		while (str[index[2]])
		{
		//	printf("%s : %s \n", s + index[0], str + index[2]);
		//	printf("%s : \n", ((str[index[0]] == c) ? "TRUE\n" : "FALSE\n"));
			if (str[index[2]] == c)
				is_okay = 1;
	//		printf("%d \n", is_okay);
			index[2]++;
		}
		if (is_okay == 0)
			return (0);
		index[1] = index[0] + 1;
		while (s[index[1]])
		{
			if (s[index[1]] == s[index[0]])
			{
				return (0);
			}
			index[1]++;
		}
	//	printf("DEBUG\n");
		index[0]++;
	}
	return ((index[0] <= 1) ? 0 : index[0]);
}

int		ft_atoi_base(char *str, char *base)
{
	int		length_base;

	str = adapt_str(str);
	length_base = respect_norme_and_length_base(base, str);
	if (length_base == 0)
		return (0);
	if (str[0] == '-')
		return (atoi_read(str + 1, base));
	if (str[0] == '+')
		return (-(atoi_read(str + 1, base)));
	if (place_in_str(str[0], base) > -1)
		return (-(atoi_read(str, base)));
	return (0);
}

int		main(void)
{
	printf("%d\n", ft_atoi_base("2A", "0123456789ABCDEF"));
}
