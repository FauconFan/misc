/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bput_vm_addr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 08:46:37 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/25 15:12:07 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

void	ft_bput_vm_addr64(uint64_t addr)
{
	ft_bput_uint_base(addr, BASE_HEX_LOW, 16, '0');
}

void	ft_bput_vm_addr32(uint64_t addr)
{
	ft_bput_uint_base(addr, BASE_HEX_LOW, 8, '0');
}
