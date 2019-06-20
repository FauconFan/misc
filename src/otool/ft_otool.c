/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_otool.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 08:11:09 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/20 18:08:56 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

void		ft_otool(t_ldf *ld)
{
	uint32_t	magic_number;

	magic_number = *(uint32_t *)ld->content;
	if (magic_number == MH_MAGIC_64)
		otool_m64(ld);
	else if (magic_number == FAT_CIGAM)
		fat_cigam(ld, ft_otool);
	else if (ld->len >= SARMAG && ft_strncmp(ld->content, ARMAG, SARMAG) == 0)
		archive(ld, ft_otool);
	else
		ft_bput_str_ln(UNKNOWN_FILE);
}
