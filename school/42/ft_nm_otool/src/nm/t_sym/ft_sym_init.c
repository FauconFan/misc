/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sym_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 07:55:31 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/27 17:52:27 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

void		ft_sym_init1(
				t_sym *sym,
				uint64_t value,
				char *name,
				size_t len)
{
	sym->value = value;
	sym->c = '?';
	sym->print_value = TRUE;
	sym->name = ft_strndup(name, len);
}

static void	handle_sect(t_sym *sym, t_meta_sect *meta, uint8_t n_sect)
{
	if (n_sect == meta->text_index)
		sym->c = 't';
	else if (n_sect == meta->bss_index)
		sym->c = 'b';
	else if (n_sect == meta->data_index)
		sym->c = 'd';
	else
		sym->c = 's';
}

void		ft_sym_init2(
				t_sym *sym,
				t_meta_sect *meta,
				uint8_t n_type,
				uint8_t n_sect)
{
	uint8_t	type;

	if (n_type & N_STAB)
		return ;
	type = n_type & N_TYPE;
	if (type == N_UNDF)
	{
		if (n_type & N_PEXT || sym->value != 0)
			sym->c = 'c';
		else
		{
			sym->c = 'u';
			sym->print_value = FALSE;
		}
	}
	else if (type == N_ABS)
		sym->c = 'a';
	else if (type == N_SECT)
		handle_sect(sym, meta, n_sect);
	else if (type == N_INDR)
		sym->c = 'i';
	if (n_type & N_EXT)
		sym->c = ft_toupper(sym->c);
}
