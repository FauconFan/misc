/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 10:36:11 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/16 14:14:41 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref,
		int (*cmp)(void *d1, void *d2))
{
	t_list	*item;
	t_list	*tmp;

	item = *begin_list;
	while (item)
	{
		if (cmp(item->data, data_ref) == 0)
		{
			tmp = item->next;
			free(item);
			item = tmp;
		}
		else
			item = item->next;
	}
}
