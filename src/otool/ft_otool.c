/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_otool.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 08:11:09 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/25 22:12:18 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"

void		ft_otool(t_ldf *ld)
{
	uint32_t	magic_number;

	magic_number = *(uint32_t *)ld->content;
	if (magic_number == MH_MAGIC_64 || magic_number == MH_CIGAM_64)
		otool_m64(ld, magic_number == MH_CIGAM_64);
	else if (magic_number == MH_MAGIC || magic_number == MH_CIGAM)
		otool_m32(ld, magic_number == MH_CIGAM);
	else if (magic_number == FAT_CIGAM)
		fat_cigam(ld, ft_otool, TRUE);
	else if (ld->len >= SARMAG && ft_strncmp(ld->content, ARMAG, SARMAG) == 0)
	{
		ft_bput_str("Archive : ");
		ft_bput_str_ln(ld->name);
		archive(ld, ft_otool);
	}
	else
		ft_bput_str_ln(UNKNOWN_FILE);
}
