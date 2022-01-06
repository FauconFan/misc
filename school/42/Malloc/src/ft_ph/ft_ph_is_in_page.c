/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ph_is_in_page.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 13:38:45 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/13 13:53:30 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

t_bool	ft_ph_is_in_page(t_ph *ph, const void *ptr)
{
	unsigned long long	begin;
	unsigned long long	end;
	unsigned long long	cand;

	begin = (unsigned long long)ph;
	end = begin + ph->len_page;
	cand = (unsigned long long)ptr;
	return (cand >= begin && cand < end);
}
