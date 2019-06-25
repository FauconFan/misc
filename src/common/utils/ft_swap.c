/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 18:04:06 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/25 18:27:04 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

static t_bool	*get_local_swap(void)
{
	static t_bool	value = FALSE;

	return (&value);
}

void			ft_swap_set(t_bool value)
{
	*get_local_swap() = value;
}

uint64_t		ft_gswap_64(uint64_t val)
{
	if (*get_local_swap())
		return (ft_swap_uint64(val));
	return (val);
}

uint32_t		ft_gswap_32(uint32_t val)
{
	if (*get_local_swap())
		return (ft_swap_uint32(val));
	return (val);
}
