/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 11:16:19 by dwald             #+#    #+#             */
/*   Updated: 2017/09/15 15:03:39 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_unit_tests.h"

void	my_putnbr_fd(int n, int fd)
{
	unsigned int	nb;

	nb = n;
	if (n < 0)
	{
		nb = -n;
		my_putchar_fd('-', fd);
	}
	if (nb >= 10)
	{
		my_putnbr_fd(nb / 10, fd);
		my_putchar_fd(nb % 10 + '0', fd);
	}
	if (nb < 10)
		my_putchar_fd(nb + '0', fd);
}
