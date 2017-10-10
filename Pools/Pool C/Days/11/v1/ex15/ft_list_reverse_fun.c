/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 13:16:01 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/16 13:30:55 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	reverse_recu(t_list *elem_next, t_list *elem)
{
	t_list	*next_next;

	next_next = elem->next;
	elem->next = elem_next;
	if (next_next != 0)
		reverse_recu(elem, next_next);
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	reverse_recu(0, begin_list);
}
