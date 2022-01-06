/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sym_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 09:09:16 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/27 17:07:48 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

static void	sym_print(t_sym *sym, void (*p)(uint64_t), char *fill)
{
	char	middle[4];

	if (sym->c == '?')
		return ;
	if (sym->print_value)
		p(sym->value);
	else
		ft_bput_str(fill);
	middle[0] = ' ';
	middle[1] = sym->c;
	middle[2] = ' ';
	middle[3] = 0;
	ft_bput_str(middle);
	ft_bput_str_ln(sym->name);
}

void		ft_sym_print_64(t_sym *sym)
{
	sym_print(sym, ft_bput_vm_addr64, "                ");
}

void		ft_sym_print_32(t_sym *sym)
{
	sym_print(sym, ft_bput_vm_addr32, "        ");
}
