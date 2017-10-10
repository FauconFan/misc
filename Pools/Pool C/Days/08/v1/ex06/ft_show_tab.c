/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 08:49:00 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/10 16:22:59 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_par.h"

void				putnbrpos(int n)
{
	if (n == 0)
		return ;
	putnbrpos(n / 10);
	ft_putchar(n % 10 + '0');
}

void				putstr(char *str)
{
	int		index;

	index = 0;
	while (str[index])
		ft_putchar(str[index++]);
	ft_putchar('\n');
}

void				ft_show_tab(struct s_stock_par *par)
{
	int		index;
	int		word;

	index = 0;
	while ((par + index)->str != 0)
	{
		putstr((par + index)->str);
		putnbrpos((par + index)->size_param);
		ft_putchar('\n');
		putstr((par + index)->copy);
		word = 0;
		while (((par + index)->tab)[word])
		{
			putstr((((par + index)->tab))[word]);
			word++;
		}
		index++;
	}
}
