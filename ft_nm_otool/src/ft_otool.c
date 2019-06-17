/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_otool.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 08:11:09 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/17 09:49:33 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

static void	pretty_print(char *v, uint64_t vm_addr, size_t len)
{
	size_t	i;

	if (len == 0)
		return ;
	ft_put_vm_addr(vm_addr);
	ft_put_str("\t");
	i = 0;
	while (i < 16 && i < len)
	{
		ft_put_hex_char((uint8_t)v[i]);
		ft_put_str(" ");
		++i;
	}
	ft_put_str_ln("");
	if (i != len)
		pretty_print(v + 16, vm_addr + 16, len - 16);
}

static void	handle_section_text(t_ldf *ldf, struct section_64 *sec)
{
	char	*v;

	v = (char *)(ldf->content) + sec->offset;
	ft_put_str_ln("Contents of (__TEXT,__text) section");
	pretty_print(v, sec->addr, sec->size);
}

static void	handle_segment_text(t_ldf *ldf, struct segment_command_64 *seg)
{
	struct section_64	*sec;
	size_t				i;

	(void)ldf;
	i = 0;
	sec = (struct section_64 *)((char *)seg + sizeof(*seg));
	while (i < seg->nsects)
	{
		if (ft_strequ(sec->segname, SEG_TEXT)
			&& ft_strequ(sec->sectname, SECT_TEXT))
		{
			handle_section_text(ldf, sec);
			break ;
		}
		sec++;
		++i;
	}
}

static void	otool_64(t_ldf *ldf)
{
	struct mach_header_64		*h64;
	struct load_command			*lc;
	struct segment_command_64	*seg;
	uint32_t					i;

	h64 = (struct mach_header_64 *)ldf->content;
	i = 0;
	lc = (struct load_command *)
		((char *)ldf->content + sizeof(struct mach_header_64));
	while (i < h64->ncmds)
	{
		if (lc->cmd == LC_SEGMENT_64)
		{
			seg = (struct segment_command_64 *)lc;
			if (ft_strequ(seg->segname, SEG_TEXT)
				|| ft_strequ(seg->segname, ""))
			{
				handle_segment_text(ldf, seg);
				break ;
			}
		}
		++i;
		lc = (struct load_command *)((char *)lc + lc->cmdsize);
	}
}

void		ft_otool(t_ldf *ldf)
{
	uint32_t	magic_number;

	magic_number = *(uint32_t *)ldf->content;
	if (magic_number != MH_MAGIC_64)
	{
		ft_put_str_ln("Not a 64 bit Mach-O");
		return ;
	}
	otool_64(ldf);
}
