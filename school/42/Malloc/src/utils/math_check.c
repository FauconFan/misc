/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 08:25:21 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/13 09:01:29 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

t_bool			do_mult_overflow(size_t a, size_t b)
{
	size_t	c;

	if (a == 0 || b == 0)
		return (FALSE);
	c = a * b;
	return (c / a != b);
}