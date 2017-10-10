/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 18:58:59 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/16 17:15:07 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*tmp;

	if (begin_list == 0)
		return ;
	if (*begin_list == 0)
	{
		*begin_list = ft_create_elem(data);
		return ;
	}
	tmp = *begin_list;
	while (tmp->next != 0)
		tmp = tmp->next;
	tmp->next = ft_create_elem(data);
}
