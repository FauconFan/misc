/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 11:16:19 by dwald             #+#    #+#             */
/*   Updated: 2017/09/15 14:53:25 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_unit_tests.h"

void	my_putnbr_base(long long int n, unsigned int base)
{
	unsigned long long int	nb;
	char					*representation;

	representation = "0123456789ABCDEF";
	nb = n;
	if (base < 2 || base > 16)
	{
		my_putendl("ERROR: my_putnbr_base bad base input");
		return ;
	}
	if (n < 0)
	{
		nb = -n;
		my_putchar('-');
	}
	if (nb >= base)
	{
		my_putnbr_base(nb / base, base);
		my_putchar(representation[nb % base]);
	}
	if (nb < base)
		my_putchar(representation[nb]);
}
