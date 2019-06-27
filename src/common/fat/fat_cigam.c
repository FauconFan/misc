/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fat_cigam.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 08:21:27 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/27 13:53:02 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

static void		do_single_arch(
					t_fat_helper *fat_helper)
{
	struct fat_arch		*arch;
	size_t				offset;
	int					not_nl;
	t_ldf				in_file;
	void				*beg;

	offset = sizeof(struct fat_header);
	arch = ft_ldf_jmp(fat_helper->origin, offset, sizeof(*arch));
	if (arch == NULL
		|| ((not_nl = ft_strnotcpos(fat_helper->origin->name, '\n')) == -1))
		return ;
	if ((beg = ft_ldf_jmp(fat_helper->origin, ft_swap_uint32(arch->offset),
		ft_swap_uint32(arch->size))) == NULL)
		return ;
	ft_ldf_init_custom(&in_file,
		ft_strdup(fat_helper->origin->name + not_nl),
		beg, ft_swap_uint32(arch->size));
	in_file.print_name = TRUE;
	fat_helper->fnext(&in_file);
	ft_ldf_end(&in_file);
}

static t_bool	test_arch(
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
	if (ft_swap_uint32((uint32_t)arch->cputype) == CPU_TYPE_X86_64)
	{
		if ((beg = ft_ldf_jmp(fat_helper->origin, ft_swap_uint32(arch->offset),
			ft_swap_uint32(arch->size))) == NULL)
			return (FALSE);
		ft_ldf_init_custom(&in_file, ft_strdup(fat_helper->origin->name),
			beg, ft_swap_uint32(arch->size));
		in_file.print_name = fat_helper->print_name;
		fat_helper->fnext(&in_file);
		ft_ldf_end(&in_file);
		return (TRUE);
	}
	return (FALSE);
}

static t_bool	test_if_any_arch(
					t_fat_helper *fat_helper,
					struct fat_header *hdr)
{
	size_t			i;
	size_t			nfat;

	i = 0;
	nfat = ft_swap_uint32(hdr->nfat_arch);
	if (nfat == 1)
	{
		do_single_arch(fat_helper);
		return (TRUE);
	}
	while (i < nfat)
	{
		if (test_arch(fat_helper, i))
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
	if (test_if_any_arch(&fat_helper, hdr) == FALSE)
		fat_do_all_arch(&fat_helper, hdr);
}
