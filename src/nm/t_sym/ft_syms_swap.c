/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syms_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 13:29:24 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/27 13:30:03 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

void		ft_syms_swap(t_sym *symbols, size_t i, size_t j)
{
	t_sym	tmp;

	if (i == j)
		return ;
	ft_memcpy(&tmp, symbols + i, sizeof(t_sym));
	ft_memcpy(symbols + i, symbols + j, sizeof(t_sym));
	ft_memcpy(symbols + j, &tmp, sizeof(t_sym));
}
