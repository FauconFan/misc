/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sym_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 09:09:16 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/18 10:59:56 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

void	ft_sym_print(t_sym *sym)
{
	char	middle[4];

	if (sym->c == '?')
		return ;
	if (sym->print_value)
		ft_put_vm_addr(sym->value);
	else
		ft_put_str("                ");
	middle[0] = ' ';
	middle[1] = sym->c;
	middle[2] = ' ';
	middle[3] = 0;
	ft_put_str(middle);
	ft_put_str_ln(sym->name);
}
