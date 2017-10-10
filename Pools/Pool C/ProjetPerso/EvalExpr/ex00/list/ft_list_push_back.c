/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 18:58:59 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/20 11:13:20 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back(t_list *begin_list, char *data)
{
	if (begin_list == 0)
		return ;
	while (begin_list->next != 0)
		begin_list = begin_list->next;
	begin_list->next = ft_create_elem(data);
}
