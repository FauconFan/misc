/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buff.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 11:37:18 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/20 11:56:42 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

static t_buff_str	*get_buff(void)
{
	static t_buff_str buff = {{0}, 0};

	return (&buff);
}

void				ft_buff_flush(void)
{
	t_buff_str	*buff;

	buff = get_buff();
	write(1, buff->buff, buff->len);
	buff->len = 0;
}

void				ft_buff_put(const char *str)
{
	t_buff_str	*buff;
	size_t		lstr;

	buff = get_buff();
	lstr = ft_strlen(str);
	if (buff->len + lstr >= BUFF_SIZE)
		ft_buff_flush();
	if (lstr >= BUFF_SIZE)
		write(1, str, lstr);
	else
	{
		ft_memcpy(buff->buff + buff->len, str, lstr);
		buff->len += lstr;
	}
}
