/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_pretty_print.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 22:09:11 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/25 23:32:47 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"

static void		real_print(t_pprint_help *pphelp, size_t continuous)
{
	size_t			i;
	void			(*p_vm_addr)(uint64_t);

	p_vm_addr = pphelp->is64 ? ft_bput_vm_addr64 : ft_bput_vm_addr32;
	while (42)
	{
		if (pphelp->len == 0)
			break ;
		p_vm_addr(pphelp->vm_addr);
		ft_bput_str("\t");
		i = 0;
		while (i < 16 && i < pphelp->len)
		{
			ft_bput_hex_char((uint8_t)pphelp->v[i]);
			++i;
			if (i % continuous == 0)
				ft_bput_str(" ");
		}
		ft_bput_str_ln("");
		if (i == pphelp->len)
			break ;
		pphelp->v += 16;
		pphelp->vm_addr += 16;
		pphelp->len -= 16;
	}
}

static size_t	get_continuous_from_cputype(cpu_type_t cputype)
{
	if (cputype == CPU_TYPE_I386 || cputype == CPU_TYPE_X86_64)
		return (1);
	else if (cputype == CPU_TYPE_MC680x0)
		return (2);
	return (4);
}

void			otool_pretty_print(t_pprint_help *pphelp)
{
	ft_bput_str_ln("Contents of (__TEXT,__text) section");
	real_print(pphelp, get_continuous_from_cputype(pphelp->cputype));
}
