/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   framework_auxiliary_functions.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 16:47:59 by dwald             #+#    #+#             */
/*   Updated: 2017/11/26 15:59:35 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework.h"

t_test	*ft_new_node(int (*fptr)(), char *name_test)
{
	t_test		*new_elem;

	if ((new_elem = (t_test*)malloc(sizeof(t_test))) == 0)
		exit(1);
	new_elem->success = INT_MAX;
	new_elem->signal = 0;
	new_elem->next = 0;
	new_elem->fptr = fptr;
	new_elem->name_single_test = name_test;
	return (new_elem);
}

void	ft_add_node(t_test *alst, t_test *new)
{
	if (alst == 0)
		return ;
	if (alst->next != 0)
	{
		ft_add_node(alst->next, new);
		return ;
	}
	alst->next = new;
}
