/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 09:02:41 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/19 09:17:18 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

int32_t	ft_swap_int32(int32_t val)
{
	uint32_t	v;
	int32_t		sign;

	sign = (val >= 0) ? 1 : -1;
	v = (uint32_t)(val >= 0 ? val : -val);
	v = ((v << 24) & 0xFF000000)
		| ((v << 8) & 0x00FF0000)
		| ((v >> 8) & 0x0000FF00)
		| ((v >> 24) & 0x000000FF);
	return ((int32_t)v * sign);
}

int64_t	ft_swap_int64(int64_t val)
{
	return (val);
}
