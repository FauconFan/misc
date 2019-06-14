/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 13:27:24 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/14 16:46:44 by jpriou           ###   ########.fr       */
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

static void	nm_64(void *v)
{
	struct mach_header_64	*h64;
	struct load_command		*lc;
	struct symtab_command	*sym;
	uint32_t				i;

	h64 = (struct mach_header_64 *)v;
	i = 0;
	lc = (struct load_command *)((char *)v + sizeof(struct mach_header_64));
	while (i < h64->ncmds)
	{
		if (lc->cmd == LC_SYMTAB)
		{
			sym = (struct symtab_command *)lc;
			ft_put_str("Number of symbols : ");
			ft_put_uint_ln(sym->nsyms);
			ft_put_str_ln("");
			print_symbols(v, sym->nsyms, sym->symoff, sym->stroff);
			break ;
		}
		++i;
		lc = (struct load_command *)((char *)lc + lc->cmdsize);
	}
}

static void	nm_stuff(void *v)
{
	uint32_t	magic_number;

	magic_number = *(uint32_t *)v;
	if (magic_number != MH_MAGIC_64)
	{
		ft_put_str_ln("Not a 64 bit Mach-O");
		return ;
	}
	nm_64(v);
}

int			main(int argc, char **argv)
{
	t_ldf	ld;
	int		i;

	i = 1;
	while (i < argc)
	{
		if (ft_ldf_init(&ld, argv[i]) == FALSE)
			continue ;
		ft_put_str_ln(ld.filepath);
		nm_stuff(ld.content);
		if (ft_ldf_end(&ld) == FALSE)
			continue ;
		++i;
	}
	return (0);
}
