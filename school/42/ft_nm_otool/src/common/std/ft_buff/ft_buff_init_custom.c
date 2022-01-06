/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buff_init_custom.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 10:01:09 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/27 10:09:20 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

t_buff_inner	*ft_buff_init_custom(const char *content, size_t len)
{
	t_buff_inner	*res;

	if ((res = malloc(sizeof(t_buff_inner))) == NULL)
		return (NULL);
	if ((res->buff = ft_strdup(content)) == NULL)
	{
		free(res);
		return (NULL);
	}
	res->len_actu = len;
	res->len_max = len;
	res->next = NULL;
	return (res);
}
