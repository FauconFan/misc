/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 13:50:10 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/17 15:50:19 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	list_insert(t_list **begin_list, void *data,
		int (*cmp)(void *d1, void *d2))
{
	t_list	*tmp;

	if (begin_list == 0 || *begin_list == 0)
		return ;
	if ((*begin_list)->next == 0)
	{
		(*begin_list)->next = ft_create_elem(data);
		return ;
	}
	if (cmp((*begin_list)->next->data, data) > 0)
	{
		tmp = ft_create_elem(data);
		tmp->next = (*begin_list);
		*begin_list = tmp;
	}
	else
	{
		list_insert(&((*begin_list)->next), data, cmp);
	}
}

void	ft_sorted_list_insert(t_list **begin_list, void *data,
		int (*cmp)(void *d1, void *d2))
{
	t_list	*tmp;

	if (begin_list == 0)
		return ;
	if (*begin_list == 0)
	{
		*begin_list = ft_create_elem(data);
		return ;
	}
	if (cmp((*begin_list)->data, data) > 0)
	{
		tmp = ft_create_elem(data);
		tmp->next = (*begin_list);
		*begin_list = tmp;
		return ;
	}
	else
	{
		list_insert(begin_list, data, cmp);
	}
}
