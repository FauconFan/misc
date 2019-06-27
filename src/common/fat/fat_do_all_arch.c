/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fat_do_all_arch.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 23:00:29 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/27 11:14:48 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

void			fat_do_all_arch(
					t_fat_helper *fat_helper,
					struct fat_header *hdr)
{
	struct fat_arch	*arch;
	void			*v;
	size_t			offset;
	size_t			i;
	t_ldf			in_file;

	offset = sizeof(struct fat_header);
	i = 0;
	while (i < ft_swap_uint32(hdr->nfat_arch))
	{
		arch = ft_ldf_jmp(fat_helper->origin, offset, sizeof(*arch));
		if (arch == NULL || ((v = ft_ldf_jmp(fat_helper->origin,
				ft_swap_uint32(arch->offset),
				ft_swap_uint32(arch->size))) == NULL))
			return ;
		ft_ldf_init_custom(&in_file, fat_bname_mult_arch(fat_helper, arch),
			v, ft_swap_uint32(arch->size));
		in_file.print_name = TRUE;
		fat_helper->fnext(&in_file);
		ft_ldf_end(&in_file);
		offset += sizeof(struct fat_arch);
		++i;
	}
}
