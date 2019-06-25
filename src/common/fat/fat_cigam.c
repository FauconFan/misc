/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fat_cigam.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 08:21:27 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/25 14:53:56 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

static void		do_all_arch(
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
		ft_ldf_init_custom(&in_file, ft_strdup(fat_helper->origin->name),
			v, ft_swap_uint32(arch->size));
		in_file.print_name = fat_helper->print_name;
		fat_helper->fnext(&in_file);
		offset += sizeof(struct fat_arch);
		++i;
	}
}

static t_bool	do_arch(
					t_fat_helper *fat_helper,
					size_t i)
{
	struct fat_arch		*arch;
	size_t				offset;
	t_ldf				in_file;
	void				*beg;

	offset = sizeof(struct fat_header) + i * sizeof(*arch);
	arch = ft_ldf_jmp(fat_helper->origin, offset, sizeof(*arch));
	if (arch == NULL)
		return (FALSE);
	if (ft_swap_int32(arch->cputype) == CPU_TYPE_X86_64)
	{
		if ((beg = ft_ldf_jmp(fat_helper->origin, ft_swap_uint32(arch->offset),
			ft_swap_uint32(arch->size))) == NULL)
			return (FALSE);
		ft_ldf_init_custom(&in_file, ft_strdup(fat_helper->origin->name),
			beg, ft_swap_uint32(arch->size));
		in_file.print_name = fat_helper->print_name;
		fat_helper->fnext(&in_file);
		return (TRUE);
	}
	return (FALSE);
}

static t_bool	test_arch(
					t_fat_helper *fat_helper,
					struct fat_header *hdr)
{
	size_t			i;

	i = 0;
	while (i < ft_swap_uint32(hdr->nfat_arch))
	{
		if (do_arch(fat_helper, i))
			return (TRUE);
		++i;
	}
	return (FALSE);
}

void			fat_cigam(t_ldf *ldf, void (*f)(t_ldf *ldf), t_bool print_name)
{
	t_fat_helper		fat_helper;
	struct fat_header	*hdr;

	fat_helper.origin = ldf;
	fat_helper.fnext = f;
	fat_helper.print_name = print_name;
	if ((hdr = ft_ldf_jmp(ldf, 0, sizeof(*hdr))) == NULL)
		return ;
	if (test_arch(&fat_helper, hdr) == FALSE)
	{
		ft_bput_str_ln("All print");
		do_all_arch(&fat_helper, hdr);
	}
}
