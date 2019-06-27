/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buff_put_last.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 10:20:04 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/27 11:11:57 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

t_buff_inner	*ft_buff_put_last(
					t_buff_inner *last,
					const char *str,
					size_t lstr)
{
	size_t	decal;

	if (lstr >= BUFF_INIT_SIZE)
	{
		last->next = ft_buff_init_custom(str, lstr);
		if (last->next == NULL)
			return (last);
		return (last->next);
	}
	if (last->len_actu + lstr >= last->len_max)
	{
		decal = last->len_max - last->len_actu;
		ft_memcpy(last->buff + last->len_actu, str, decal);
		last->len_actu += decal;
		str += decal;
		lstr -= decal;
		if ((last->next = ft_buff_init_default()) == NULL)
			return (last);
		last = last->next;
	}
	if (lstr == 0)
		return (last);
	ft_memcpy(last->buff + last->len_actu, str, lstr);
	last->len_actu += lstr;
	return (last);
}
