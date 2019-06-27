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

static void		real_print_8(
					t_pprint_help *pphelp,
					uint8_t *v,
					void (*p_vm_addr)(uint64_t))
{
	size_t			i;

	while (42)
	{
		if (pphelp->len == 0)
			break ;
		p_vm_addr(pphelp->vm_addr);
		ft_bput_str("\t");
		i = 0;
		while (i < 16 && i < pphelp->len)
		{
			ft_bput_hex_8(v[i]);
			++i;
			ft_bput_str(" ");
		}
		ft_bput_str_ln("");
		if (i == pphelp->len)
			break ;
		v += 16;
		pphelp->vm_addr += 16;
		pphelp->len -= 16;
	}
}

static void		real_print_16(
					t_pprint_help *pphelp,
					uint16_t *v,
					void (*p_vm_addr)(uint64_t))
{
	size_t			i;

	while (42)
	{
		if (pphelp->len == 0)
			break ;
		p_vm_addr(pphelp->vm_addr);
		ft_bput_str("\t");
		i = 0;
		while (i < 8 && 2 * i < pphelp->len)
		{
			ft_bput_hex_16(ft_gswap_16(v[i]));
			++i;
			ft_bput_str(" ");
		}
		ft_bput_str_ln("");
		if (i == pphelp->len)
			break ;
		v += 8;
		pphelp->vm_addr += 16;
		pphelp->len -= 16;
	}
}

static void		real_print_32(
					t_pprint_help *pphelp,
					uint32_t *v,
					void (*p_vm_addr)(uint64_t))
{
	size_t			i;

	while (42)
	{
		if (pphelp->len == 0)
			break ;
		p_vm_addr(pphelp->vm_addr);
		ft_bput_str("\t");
		i = 0;
		while (i < 4 && 4 * i < pphelp->len)
		{
			ft_bput_hex_32(ft_gswap_32(v[i]));
			++i;
			ft_bput_str(" ");
		}
		ft_bput_str_ln("");
		if (i == pphelp->len)
			break ;
		v += 4;
		pphelp->vm_addr += 16;
		pphelp->len -= 16;
	}
}

void			otool_pretty_print(t_pprint_help *pphelp)
{
	void			(*p_vm_addr)(uint64_t);

	p_vm_addr = pphelp->is64 ? ft_bput_vm_addr64 : ft_bput_vm_addr32;
	ft_bput_str_ln("Contents of (__TEXT,__text) section");
	if (pphelp->cputype == CPU_TYPE_I386 || pphelp->cputype == CPU_TYPE_X86_64)
		real_print_8(pphelp, (uint8_t *)pphelp->v, p_vm_addr);
	else if (pphelp->cputype == CPU_TYPE_MC680x0)
		real_print_16(pphelp, (uint16_t *)pphelp->v, p_vm_addr);
	else
		real_print_32(pphelp, (uint32_t *)pphelp->v, p_vm_addr);
}
