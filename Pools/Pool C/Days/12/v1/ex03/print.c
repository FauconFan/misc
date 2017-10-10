/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 12:55:50 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/18 14:20:29 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

void	print_nonprintable(char buffer[SIZE_BUF])
{
	int		index;

	index = 0;
	while (index < SIZE_BUF)
	{
		if (buffer[index] < 32)
			ft_putchar('.');
		else
			ft_putchar(buffer[index]);
		index++;
	}
}

void	ft_printbuffer(unsigned long addr, char *buffer, int length)
{
	int		index;

	index = 0;
	ft_putnbr_addr(addr);
	ft_putstr("  ");
	while (index < length)
	{
		ft_putnbr_value(buffer[index]);
		ft_putchar(' ');
		if (index == 7)
			ft_putchar(' ');
		index++;
	}
	if (index < 8)
		ft_putchar(' ');
	while (index < 16)
	{
		ft_putstr("   ");
		index++;
	}
	ft_putchar(' ');
	ft_putchar('|');
	print_nonprintable(buffer);
	ft_putchar('|');
	ft_putchar('\n');
}
