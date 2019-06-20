/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bput_uint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:43:39 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/20 12:02:18 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

void			ft_bput_uint(unsigned long int nb)
{
	ft_bput_uint_base(nb, BASE_DEC, 0, 0);
}

void			ft_bput_uint16(unsigned long int nb)
{
	ft_bput_uint_base(nb, BASE_HEX_UP, 0, 0);
}

void			ft_bput_uint_ln(unsigned long int nb)
{
	ft_bput_uint(nb);
	ft_buff_put("\n");
}

void			ft_bput_uint16_ln(unsigned long int nb)
{
	ft_bput_uint16(nb);
	ft_buff_put("\n");
}
