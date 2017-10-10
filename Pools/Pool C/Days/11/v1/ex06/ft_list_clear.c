/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 08:26:55 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/16 08:32:30 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	free_element_go_next(t_list *elem)
{
	if (elem == 0)
		return ;
	free_element_go_next(elem->next);
	free(elem);
}

void	ft_list_clear(t_list **begin_list)
{
	free_element_go_next(*begin_list);
	*begin_list = NULL;
}
