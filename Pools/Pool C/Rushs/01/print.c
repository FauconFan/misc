/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 09:29:59 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/13 12:33:14 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include <unistd.h>

void	print_str(char *str)
{
	int		length;
	char	*cpy;

	cpy = str;
	length = 0;
	while (*(cpy))
	{
		cpy++;
		length++;
	}
	write(1, str, length);
}

void	print_digit(int digit)
{
	char	c;

	c = digit + '0';
	write(1, &c, 1);
}

void	print_tab(int **tab)
{
	int		index[2];

	index[0] = 0;
	while (index[0] < 9)
	{
		index[1] = 0;
		while (index[1] < 9)
		{
			print_digit(tab[index[0]][index[1]]);
			if (index[1] != 8)
			{
				write(1, " ", 1);
			}
			index[1]++;
		}
		write(1, "\n", 1);
		index[0]++;
	}
}
