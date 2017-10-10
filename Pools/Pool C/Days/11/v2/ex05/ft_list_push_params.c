/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 08:46:26 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/16 17:28:12 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_push_params(int ac, char **av)
{
	t_list	*res;
	t_list	*tmp;
	int		index;

	if (ac == 0)
		return (0);
	tmp = 0;
	res = 0;
	index = 0;
	while (index < ac)
	{
		tmp = res;
		res = ft_create_elem(av[index]);
		res->next = tmp;
		index++;
	}
	return (res);
}
