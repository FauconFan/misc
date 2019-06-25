/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_m32.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 10:59:35 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/25 15:16:32 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

static void		print_symbols(
					t_ldf *ldf,
					struct symtab_command *sym,
					t_meta_sect *meta)
{
	uint32_t		i;
	struct nlist	*tab;
	t_sym			*symbols;
	char			*name;
	size_t			offset_str;

	tab = ft_ldf_jmp(ldf, sym->symoff, sizeof(*tab) * sym->nsyms);
	if (tab == NULL || (symbols = malloc(sizeof(t_sym) * sym->nsyms)) == NULL)
		return ;
	i = 0;
	while (i < sym->nsyms)
	{
		offset_str = sym->stroff + tab[i].n_un.n_strx;
		if ((name = ft_ldf_jmp_str(ldf, offset_str)) == NULL)
			return ;
		ft_sym_init1(symbols + i, tab[i].n_value, name);
		ft_sym_init2(symbols + i, meta, tab[i].n_type, tab[i].n_sect);
		++i;
	}
	ft_sym_sort(symbols, sym->nsyms);
	i = 0;
	while (i < sym->nsyms)
		ft_sym_print_32(symbols + i++);
	free(symbols);
}

static size_t	loff(size_t offset, uint32_t index)
{
	offset += sizeof(struct segment_command);
	offset += index * sizeof(struct section);
	return (offset);
}

static t_bool	charge_meta(
					t_ldf *ld,
					t_meta_sect *meta,
					size_t off,
					uint32_t ncmds)
{
	struct load_command			*lc;
	struct section				*se;
	uint32_t					i;
	uint32_t					j;
	uint8_t						isect;

	i = 0;
	isect = 1;
	while (i++ < ncmds)
	{
		if ((lc = ft_ldf_jmp(ld, off, sizeof(*lc))) == NULL)
			return (FALSE);
		if (lc->cmd == LC_SEGMENT)
		{
			j = 0;
			while (j < ((struct segment_command *)lc)->nsects)
			{
				if ((se = ft_ldf_jmp(ld, loff(off, j++), sizeof(*se))) == NULL)
					return (FALSE);
				ft_meta_sect_load(meta, se->segname, se->sectname, isect++);
			}
		}
		off += lc->cmdsize;
	}
	return (TRUE);
}

void			nm_m32(t_ldf *ldf)
{
	struct mach_header		*h32;
	struct load_command		*lc;
	uint32_t				i;
	size_t					offset;
	t_meta_sect				meta;

	ft_ldf_print_name(ldf);
	offset = sizeof(struct mach_header);
	ft_meta_sect_init(&meta);
	if ((h32 = ft_ldf_jmp(ldf, 0, sizeof(*h32))) == NULL
		|| (lc = ft_ldf_jmp(ldf, offset, sizeof(*lc))) == NULL
		|| charge_meta(ldf, &meta, offset, h32->ncmds) == FALSE)
		return ;
	i = 0;
	while (i++ < h32->ncmds)
	{
		if (lc->cmd == LC_SYMTAB)
		{
			print_symbols(ldf, (struct symtab_command *)lc, &meta);
			break ;
		}
		offset += lc->cmdsize;
		if ((lc = ft_ldf_jmp(ldf, offset, sizeof(*lc))) == NULL)
			return ;
	}
}
