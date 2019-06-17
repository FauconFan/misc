/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_m64.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 10:59:35 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/17 12:20:04 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

static void	print_symbols(
				void *v,
				uint32_t nsyms,
				uint32_t symoff,
				uint32_t stroff)
{
	uint32_t		i;
	char			*stringtable;
	struct nlist_64	*array;
	char			*name;

	array = (struct nlist_64 *)((char *)v + symoff);
	stringtable = (char *)((char *)v + stroff);
	i = 0;
	while (i < nsyms)
	{
		name = stringtable + array[i].n_un.n_strx;
		ft_put_str_ln(name);
		++i;
	}
}

void		nm_m64(t_ldf *ldf)
{
	struct mach_header_64	*h64;
	struct load_command		*lc;
	struct symtab_command	*sym;
	uint32_t				i;

	h64 = (struct mach_header_64 *)ldf->content;
	i = 0;
	lc = (struct load_command *)
		((char *)ldf->content + sizeof(struct mach_header_64));
	while (i < h64->ncmds)
	{
		if (lc->cmd == LC_SYMTAB)
		{
			sym = (struct symtab_command *)lc;
			ft_put_str("Number of symbols : ");
			ft_put_uint_ln(sym->nsyms);
			ft_put_str_ln("");
			print_symbols(ldf->content, sym->nsyms, sym->symoff, sym->stroff);
			break ;
		}
		++i;
		lc = (struct load_command *)((char *)lc + lc->cmdsize);
	}
}
