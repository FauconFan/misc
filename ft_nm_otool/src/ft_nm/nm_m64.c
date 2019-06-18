/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_m64.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 10:59:35 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/18 09:56:24 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

static void	print_symbols(
				void *v,
				struct symtab_command *sym,
				t_meta_sect *meta)
{
	uint32_t		i;
	char			*stringtable;
	struct nlist_64	*array;
	t_sym			*symbols;

	array = (struct nlist_64 *)((char *)v + sym->symoff);
	stringtable = (char *)((char *)v + sym->stroff);
	if ((symbols = malloc(sizeof(t_sym) * sym->nsyms)) == NULL)
		return ;
	i = 0;
	while (i < sym->nsyms)
	{
		ft_sym_init1(symbols + i, array[i].n_value,
			stringtable + array[i].n_un.n_strx);
		ft_sym_init2(symbols + i, meta, array[i].n_type, array[i].n_sect);
		++i;
	}
	ft_sym_sort_by_name(symbols, sym->nsyms);
	i = 0;
	while (i < sym->nsyms)
	{
		ft_sym_print(symbols + i);
		++i;
	}
	free(symbols);
}

static void	charge_meta(
				t_meta_sect *meta,
				struct load_command *lc,
				uint32_t ncmds)
{
	struct segment_command_64	*seg;
	struct section_64			*sec;
	uint32_t					i;
	uint32_t					j;
	uint8_t						isect;

	ft_meta_sect_init(meta);
	i = 0;
	isect = 1;
	while (i < ncmds)
	{
		if (lc->cmd == LC_SEGMENT_64)
		{
			seg = (struct segment_command_64 *)lc;
			sec = (struct section_64 *)((char *)seg + sizeof(*seg));
			j = 0;
			while (j++ < seg->nsects)
			{
				ft_meta_sect_load(meta, sec->segname, sec->sectname, isect++);
				sec++;
			}
		}
		++i;
		lc = (struct load_command *)((char *)lc + lc->cmdsize);
	}
}

void		nm_m64(t_ldf *ldf)
{
	struct mach_header_64	*h64;
	struct load_command		*lc;
	struct symtab_command	*sym;
	uint32_t				i;
	t_meta_sect				meta;

	h64 = (struct mach_header_64 *)ldf->content;
	i = 0;
	lc = (struct load_command *)
		((char *)ldf->content + sizeof(struct mach_header_64));
	charge_meta(&meta, lc, h64->ncmds);
	while (i < h64->ncmds)
	{
		if (lc->cmd == LC_SYMTAB)
		{
			sym = (struct symtab_command *)lc;
			print_symbols(ldf->content, sym, &meta);
			break ;
		}
		++i;
		lc = (struct load_command *)((char *)lc + lc->cmdsize);
	}
}
