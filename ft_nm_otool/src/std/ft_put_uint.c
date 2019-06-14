/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_uint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:43:39 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/14 13:31:36 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

/*
**	We assume that len of base is no greater than 16 and greater than 1
*/

static void		ft_put_uint_base(unsigned long int nb, char *base)
{
	size_t	lbase;
	size_t	l;
	size_t	t;
	char	buff[42];

	t = 0;
	while (t < 42)
		buff[t++] = 0;
	lbase = 0;
	while (base[lbase] != 0)
		++lbase;
	if ((lbase > 1 && lbase <= 16) == 0)
		return ;
	l = 1;
	t = nb;
	while (t /= lbase)
		++l;
	t = l;
	buff[l] = '\0';
	while (t--)
	{
		buff[t] = base[nb % lbase];
		nb /= lbase;
	}
	write(1, buff, l);
}

void			ft_put_uint(unsigned long int nb)
{
	ft_put_uint_base(nb, "0123456789");
}

void			ft_put_uint16(unsigned long int nb)
{
	ft_put_uint_base(nb, "0123456789ABCDEF");
}

void			ft_put_uint_ln(unsigned long int nb)
{
	ft_put_uint(nb);
	write(1, "\n", 1);
}

void			ft_put_uint16_ln(unsigned long int nb)
{
	ft_put_uint16(nb);
	write(1, "\n", 1);
}
