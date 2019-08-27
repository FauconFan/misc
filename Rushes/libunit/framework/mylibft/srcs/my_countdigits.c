/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_countdigits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 18:58:09 by dwald             #+#    #+#             */
/*   Updated: 2016/12/15 21:15:43 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_unit_tests.h"

int		my_countdigits(int n)
{
	unsigned int len;
	unsigned int nb;

	nb = n;
	len = 1;
	if (n < 0)
	{
		len++;
		nb = -n;
	}
	while (nb > 9)
	{
		len++;
		nb = nb / 10;
	}
	return (len);
}
