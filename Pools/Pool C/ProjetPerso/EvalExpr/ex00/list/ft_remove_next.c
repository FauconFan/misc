/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_next.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 08:48:52 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/20 09:38:31 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_remove_next(t_list *actu)
{
	t_list	*tmp;

	if (actu == 0 || actu->next == 0)
		return ;
	tmp = actu->next;
	actu->next = actu->next->next;
	free(tmp);
}

void	ft_remove_nextn(t_list *actu, int n)
{
	while (n > 0)
	{
		ft_remove_next(actu);
		n--;
	}
}
