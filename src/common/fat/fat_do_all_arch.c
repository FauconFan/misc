/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fat_do_all_arch.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 23:00:29 by jpriou            #+#    #+#             */
/*   Updated: 2019/07/01 10:00:38 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

void			fat_do_all_arch(
					t_fat_helper *fat_helper,
					struct fat_header *hdr,
					t_bool doswap)
{
	struct fat_arch	*arch;
	void			*v;
	size_t			offset;
	size_t			i;
	t_ldf			in_file;

	ft_swap_set(doswap);
	offset = sizeof(struct fat_header);
	i = (size_t)-1;
	while (++i < ft_gswap_32(hdr->nfat_arch))
	{
		arch = ft_ldf_jmp(fat_helper->origin, NULL, offset, sizeof(*arch));
		if (arch == NULL || ((v = ft_ldf_jmp(fat_helper->origin,
				(char *)arch + sizeof(*arch),
				ft_gswap_32(arch->offset),
				ft_gswap_32(arch->size))) == NULL))
			return ;
		ft_ldf_init_custom(&in_file, fat_bname_mult_arch(fat_helper, arch),
			v, ft_gswap_32(arch->size));
		in_file.print_name = TRUE;
		fat_helper->fnext(&in_file);
		ft_swap_set(doswap);
		ft_ldf_end(&in_file);
		offset += sizeof(struct fat_arch);
	}
}
