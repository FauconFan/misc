/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 10:36:11 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/17 08:24:25 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	list_remove_if(t_list **begin_list, void *data_ref,
		int (*cmp)(void *d1, void *d2))
{
	t_list	*tmp;

	if (begin_list == 0 || *begin_list == 0)
		return ;
	while ((*begin_list) != 0 && (*begin_list)->next != 0 &&
			cmp((*begin_list)->next->data, data_ref) == 0)
	{
		tmp = (*begin_list)->next;
		(*begin_list)->next = tmp->next;
		free(tmp);
	}
	if ((*begin_list)->next != 0)
		list_remove_if(&((*begin_list)->next), data_ref, cmp);
}

void	ft_list_remove_if(t_list **begin_list, void *data_ref,
		int (*cmp)(void *d1, void *d2))
{
	if (begin_list == 0 || (*begin_list == 0))
		return ;
	while ((*begin_list) != 0 && cmp((*begin_list)->data, data_ref) == 0)
	{
		*begin_list = (*begin_list)->next;
	}
	if (*begin_list != 0)
		list_remove_if(begin_list, data_ref, cmp);
}
