/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bput_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 08:50:26 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/20 12:01:52 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

void	ft_bput_hex_8(uint8_t val)
{
	ft_bput_uint_base(val, BASE_HEX_LOW, 2, '0');
}

void	ft_bput_hex_16(uint16_t val)
{
	ft_bput_uint_base(val, BASE_HEX_LOW, 4, '0');
}

void	ft_bput_hex_32(uint32_t val)
{
	ft_bput_uint_base(val, BASE_HEX_LOW, 8, '0');
}
