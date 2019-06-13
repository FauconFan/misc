/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ph_munmap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 09:17:41 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/13 09:19:05 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void	ft_ph_munmap(t_ph *ph, t_bool recu)
{
	t_ph	*next;

	if (ph == NULL)
		return ;
	next = ph->next_page;
	munmap(ph, ph->len_page);
	if (recu)
		ft_ph_munmap(next, recu);
}
