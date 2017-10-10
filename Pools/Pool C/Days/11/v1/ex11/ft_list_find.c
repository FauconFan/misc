/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 09:25:46 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/16 10:42:01 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_find(t_list *begin_list, void *data_ref,
		int (*cmp)(void *d1, void *d2))
{
	while (begin_list)
	{
		if (cmp(data_ref, begin_list->data) == 0)
			return (begin_list);
		begin_list = begin_list->next;
	}
	return (0);
}
