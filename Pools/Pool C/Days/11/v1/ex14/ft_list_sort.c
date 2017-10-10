/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 10:48:57 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/16 14:13:11 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_sort(t_list **begin_list, int (*cmp)(void *d1, void *d2))
{
	t_list	*tmp0;
	t_list	*parcours;
	void	*tmp;

	if (*begin_list == 0)
		return ;
	tmp0 = *begin_list;
	parcours = tmp0->next;
	while (parcours)
	{
		if (cmp(tmp0->data, parcours->data) > 0)
		{
			tmp0 = parcours;
		}
		parcours = parcours->next;
	}
	tmp = tmp0->data;
	tmp0->data = (*begin_list)->data;
	(*begin_list)->data = tmp;
	ft_list_sort(&((*begin_list)->next), cmp);
}
