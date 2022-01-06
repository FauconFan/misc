/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buff_init_default.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 09:59:01 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/27 17:41:36 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

t_buff_inner	*ft_buff_init_default(void)
{
	t_buff_inner	*res;

	if ((res = malloc(sizeof(t_buff_inner))) == NULL)
		return (NULL);
	if ((res->buff = malloc(BUFF_INIT_SIZE)) == NULL)
	{
		free(res);
		return (NULL);
	}
	res->len_actu = 0;
	res->len_max = BUFF_INIT_SIZE;
	res->next = NULL;
	return (res);
}
