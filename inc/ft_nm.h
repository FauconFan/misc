/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 07:57:27 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/20 12:16:34 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NM_H
# define FT_NM_H

# include "ft_nm_otool.h"
# include <mach-o/loader.h>
# include <mach-o/nlist.h>

typedef struct	s_meta_sect
{
	uint8_t		text_index;
	uint8_t		data_index;
	uint8_t		bss_index;
}				t_meta_sect;

void	ft_meta_sect_init(t_meta_sect *meta);
void	ft_meta_sect_load(
			t_meta_sect *meta,
			char *seg_name,
			char *sect_name,
			uint8_t i);

typedef struct	s_sym
{
	uint64_t	value;
	char		*name;
	char		c;
	t_bool		print_value;
	char		pad[6];
}				t_sym;

void	ft_sym_init1(
			t_sym *sym,
			uint64_t value,
			char *name);

void	ft_sym_init2(
			t_sym *sym,
			t_meta_sect *meta,
			uint8_t n_type,
			uint8_t n_sect);

void	ft_sym_print(t_sym *sym);
void	ft_sym_sort(t_sym *symbols, size_t len);

#endif
