/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 13:16:01 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/17 15:51:43 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	if (nbr == 0)
		return (begin_list);
	if (begin_list == 0)
		return (0);
	return (ft_list_at(begin_list->next, nbr - 1));
}

int		ft_list_size(t_list *begin_list)
{
	if (begin_list == 0)
		return (0);
	if (begin_list->next != 0)
		return (1 + ft_list_size(begin_list->next));
	return (1);
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	int		length;
	void	*data;
	int		index;
	t_list	*elem1;
	t_list	*elem2;

	if (begin_list == 0)
		return ;
	length = ft_list_size(begin_list);
	if (length <= 1)
		return ;
	index = 0;
	while (index < length / 2)
	{
		elem1 = ft_list_at(begin_list, index);
		elem2 = ft_list_at(begin_list, length - 1 - index);
		data = elem1->data;
		elem1->data = elem2->data;
		elem2->data = data;
		index++;
	}
}
