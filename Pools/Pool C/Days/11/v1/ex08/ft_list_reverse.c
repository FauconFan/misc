/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 11:58:02 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/16 13:08:33 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	reverse_recu(t_list *elem1, t_list *elem2)
{
	if (elem2->next != 0)
		reverse_recu(elem2, elem2->next);
	elem2->next = elem1;
}

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*last;

	if (begin_list == 0 && (*begin_list) == 0)
		return ;
	last = *begin_list;
	while (last->next != 0)
		last = last->next;
	reverse_recu(*begin_list, (*begin_list)->next);
	(*begin_list)->next = 0;
	*begin_list = last;
}
