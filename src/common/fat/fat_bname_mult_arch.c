/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fat_bname_mult_arch.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 22:59:24 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/25 23:00:07 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

char			*fat_bname_mult_arch(
					t_fat_helper *fat_helper,
					struct fat_arch *arch)
{
	const NXArchInfo	*archinfo;
	const char			*archname;
	const char			*format;
	char				*res;

	archinfo = NXGetArchInfoFromCpuType(
					ft_swap_uint32((uint32_t)arch->cputype),
					ft_swap_uint32((uint32_t)arch->cpusubtype));
	archname = (archinfo) ? archinfo->name : "";
	format = (fat_helper->print_name)
				? "% (architecture %)" : "% (for architecture %)";
	res = ft_strformat2(format,
		fat_helper->origin->name,
		archname);
	return (res);
}
