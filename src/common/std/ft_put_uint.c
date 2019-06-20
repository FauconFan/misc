/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_uint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:43:39 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/17 08:52:40 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

void			ft_put_uint(unsigned long int nb)
{
	ft_put_uint_base(nb, BASE_DEC, 0, 0);
}

void			ft_put_uint16(unsigned long int nb)
{
	ft_put_uint_base(nb, BASE_HEX_UP, 0, 0);
}

void			ft_put_uint_ln(unsigned long int nb)
{
	ft_put_uint(nb);
	write(1, "\n", 1);
}

void			ft_put_uint16_ln(unsigned long int nb)
{
	ft_put_uint16(nb);
	write(1, "\n", 1);
}
