/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bput_uint_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 08:37:38 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/20 12:01:29 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

static void		handle_prefix(size_t width, size_t l, char c)
{
	char	buff[33];
	size_t	i;

	if (l >= width)
		return ;
	i = 0;
	while (i < width - l)
	{
		buff[i] = c;
		++i;
	}
	buff[i] = 0;
	ft_buff_put(buff);
}

static size_t	handle_base_length(const char *base)
{
	size_t	lbase;

	lbase = 0;
	while (base[lbase] != 0)
		++lbase;
	if ((lbase > 1 && lbase <= 16))
		return (lbase);
	return (0);
}

/*
**	We assume that len of base is no greater than 16 and greater than 1
**	We also assume that width is no greater than 32
*/

void			ft_bput_uint_base(
					unsigned long int nb,
					const char *base,
					size_t width,
					char width_padded)
{
	size_t	lbase;
	size_t	l;
	size_t	t;
	char	buff[42];

	t = 0;
	while (t < 42)
		buff[t++] = 0;
	if ((lbase = handle_base_length(base)) == 0 || width > 32)
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
	handle_prefix(width, l, width_padded);
	buff[l] = 0;
	ft_buff_put(buff);
}
