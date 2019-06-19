/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fat_cigam.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 08:21:27 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/19 17:34:35 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

static void		do_all_arch(
					t_ldf *ldf,
					void (*f)(t_ldf *ldf),
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
		if ((arch = ft_ldf_jmp(ldf, offset, sizeof(*arch))) == NULL
			|| ((v = ft_ldf_jmp(ldf,
				ft_swap_uint32(arch->offset),
				ft_swap_uint32(arch->size))) == NULL))
			return ;
		in_file.filepath = NULL;
		in_file.content = v;
		in_file.len = ft_swap_uint32(arch->size);
		f(&in_file);
		offset += sizeof(struct fat_arch);
		++i;
	}
}

static t_bool	do_arch(
					t_ldf *ldf,
					void (*f)(t_ldf *ldf),
					const NXArchInfo *local,
					size_t i)
{
	struct fat_arch		*arch;
	size_t				offset;
	t_ldf				in_file;
	void				*beg;

	offset = sizeof(struct fat_header) + i * sizeof(*arch);
	arch = ft_ldf_jmp(ldf, offset, sizeof(*arch));
	if (arch == NULL)
		return (FALSE);
	if ((ft_swap_int32(arch->cputype) & 0xFFFFFF) == local->cputype)
	{
		if ((beg = ft_ldf_jmp(ldf, ft_swap_uint32(arch->offset),
			ft_swap_uint32(arch->size))) == NULL)
		{
			return (FALSE);
		}
		in_file.filepath = NULL;
		in_file.content = beg;
		in_file.len = ft_swap_uint32(arch->size);
		f(&in_file);
		return (TRUE);
	}
	return (FALSE);
}

static t_bool	test_arch(
					t_ldf *ldf,
					void (*f)(t_ldf *ldf),
					const NXArchInfo *local,
					struct fat_header *hdr)
{
	size_t			i;

	i = 0;
	while (i < ft_swap_uint32(hdr->nfat_arch))
	{
		if (do_arch(ldf, f, local, i))
			return (TRUE);
		++i;
	}
	return (FALSE);
}

void			fat_cigam(t_ldf *ldf, void (*f)(t_ldf *ldf))
{
	const NXArchInfo	*local = NXGetLocalArchInfo();
	struct fat_header	*hdr;

	if (local == NULL)
	{
		ft_put_str_ln(ARCHI_MSG);
		return ;
	}
	if ((hdr = ft_ldf_jmp(ldf, 0, sizeof(*hdr))) == NULL)
		return ;
	if (test_arch(ldf, f, local, hdr) == FALSE)
	{
		ft_put_str_ln("All print");
		do_all_arch(ldf, f, hdr);
	}
}
