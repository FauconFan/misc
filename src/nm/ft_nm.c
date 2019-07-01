/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 08:17:31 by jpriou            #+#    #+#             */
/*   Updated: 2019/07/01 09:47:29 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

void		ft_nm(t_ldf *ld)
{
	uint32_t	magic_number;

	magic_number = *(uint32_t *)ld->content;
	if (magic_number == MH_MAGIC_64 || magic_number == MH_CIGAM_64)
		nm_m64(ld, magic_number == MH_CIGAM_64);
	else if (magic_number == MH_MAGIC || magic_number == MH_CIGAM)
		nm_m32(ld, magic_number == MH_CIGAM);
	else if (magic_number == FAT_MAGIC || magic_number == FAT_CIGAM)
		fat(ld, ft_nm, FALSE, magic_number == FAT_CIGAM);
	else if (ld->len >= SARMAG && ft_strncmp(ld->content, ARMAG, SARMAG) == 0)
		archive(ld, ft_nm);
	else
		ft_bput_str_ln(UNKNOWN_FILE);
}
