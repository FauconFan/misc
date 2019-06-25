/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 08:17:31 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/25 14:16:34 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

void		ft_nm(t_ldf *ld)
{
	uint32_t	magic_number;

	magic_number = *(uint32_t *)ld->content;
	if (magic_number == MH_MAGIC_64)
		nm_m64(ld);
	else if (magic_number == FAT_CIGAM)
		fat_cigam(ld, ft_nm, FALSE);
	else if (ld->len >= SARMAG && ft_strncmp(ld->content, ARMAG, SARMAG) == 0)
		archive(ld, ft_nm);
	else
		ft_bput_str_ln(UNKNOWN_FILE);
}
