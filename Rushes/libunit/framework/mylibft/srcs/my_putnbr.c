/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 11:16:19 by dwald             #+#    #+#             */
/*   Updated: 2017/09/15 15:02:58 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_unit_tests.h"

void	my_putnbr(int n)
{
	unsigned int	nb;

	nb = n;
	if (n < 0)
	{
		nb = -n;
		my_putchar('-');
	}
	if (nb >= 10)
	{
		my_putnbr(nb / 10);
		my_putchar(nb % 10 + '0');
	}
	if (nb < 10)
		my_putchar(nb + '0');
}
