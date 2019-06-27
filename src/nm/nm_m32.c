/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_m32.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 10:59:35 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/27 16:01:37 by jpriou           ###   ########.fr       */
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
	size_t			lstr;

	tab = ft_ldf_jmp(ldf,
		ft_gswap_32(sym->symoff), sizeof(*tab) * ft_gswap_32(sym->nsyms));
	if (tab == NULL
		|| (symbols = ft_syms_new(ft_gswap_32(sym->nsyms))) == NULL)
		return ;
	i = (uint32_t)-1;
	while (++i < ft_gswap_32(sym->nsyms))
	{
		if ((name = ft_ldf_jmp_str(ldf, ft_gswap_32(sym->stroff)
			+ ft_gswap_32(tab[i].n_un.n_strx), &lstr)) == NULL)
			return ;
		ft_sym_init1(symbols + i, ft_gswap_32(tab[i].n_value), name, lstr);
		ft_sym_init2(symbols + i, meta, tab[i].n_type, tab[i].n_sect);
	}
	ft_syms_good_print(symbols, ft_gswap_32(sym->nsyms), ft_sym_print_32);
	ft_syms_free(symbols, ft_gswap_32(sym->nsyms));
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
		if (ft_gswap_32(lc->cmd) == LC_SEGMENT)
		{
			j = 0;
			while (j < ft_gswap_32(((struct segment_command *)lc)->nsects))
			{
				if ((se = ft_ldf_jmp(ld, loff(off, j++), sizeof(*se))) == NULL)
					return (FALSE);
				ft_meta_sect_load(meta, se->segname, se->sectname, isect++);
			}
		}
		off += ft_gswap_32(lc->cmdsize);
	}
	return (TRUE);
}

void			nm_m32(t_ldf *ldf, t_bool doswap)
{
	struct mach_header		*h32;
	struct load_command		*lc;
	uint32_t				i;
	size_t					loff;
	t_meta_sect				meta;

	ft_swap_set(doswap);
	ft_ldf_print_name(ldf);
	loff = sizeof(struct mach_header);
	ft_meta_sect_init(&meta);
	if ((h32 = ft_ldf_jmp(ldf, 0, sizeof(*h32))) == NULL
		|| charge_meta(ldf, &meta, loff, ft_gswap_32(h32->ncmds)) == FALSE)
		return ;
	i = 0;
	while (i++ < ft_gswap_32(h32->ncmds)
			&& (lc = ft_ldf_jmp(ldf, loff, sizeof(*lc))) != NULL)
	{
		if (ft_gswap_32(lc->cmd) == LC_SYMTAB)
		{
			print_symbols(ldf, (struct symtab_command *)lc, &meta);
			break ;
		}
		loff += ft_gswap_32(lc->cmdsize);
	}
}
