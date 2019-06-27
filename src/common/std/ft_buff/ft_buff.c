/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buff.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 11:37:18 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/27 11:02:57 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

static t_buff		*get_buff(void)
{
	static t_buff buff = {NULL, NULL, TRUE, {0}};

	return (&buff);
}

void				ft_buff_reset(void)
{
	t_buff	*buff;

	buff = get_buff();
	ft_buff_free_recu(buff->head);
	buff->head = NULL;
	buff->last = NULL;
	buff->enable = TRUE;
}

void				ft_buff_disable(void)
{
	get_buff()->enable = FALSE;
}

void				ft_buff_flush(void)
{
	t_buff	*buff;

	buff = get_buff();
	if (buff->enable == FALSE)
		return ;
	ft_buff_print_recu(buff->head);
}

void				ft_buff_put(const char *str)
{
	t_buff	*buff;
	size_t	lstr;

	buff = get_buff();
	if (buff->enable == FALSE)
		return ;
	lstr = ft_strlen(str);
	if (buff->head == NULL)
	{
		if (lstr >= BUFF_INIT_SIZE)
			buff->head = ft_buff_init_custom(str, lstr);
		else
		{
			buff->head = ft_buff_init_default();
			ft_memcpy(buff->head->buff, str, lstr);
			buff->head->len_actu = lstr;
		}
		buff->last = buff->head;
	}
	else
		buff->last = ft_buff_put_last(buff->last, str, lstr);
}
