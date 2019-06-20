/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_m64.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 11:00:48 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/20 12:06:09 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

static void		pretty_print(char *v, uint64_t vm_addr, size_t len)
{
	size_t	i;

	if (len == 0)
		return ;
	ft_bput_vm_addr(vm_addr);
	ft_bput_str("\t");
	i = 0;
	while (i < 16 && i < len)
	{
		ft_bput_hex_char((uint8_t)v[i]);
		ft_bput_str(" ");
		++i;
	}
	ft_bput_str_ln("");
	if (i != len)
		pretty_print(v + 16, vm_addr + 16, len - 16);
}

static void		handle_section_text(t_ldf *ldf, struct section_64 *sec)
{
	char	*v;

	v = (char *)ft_ldf_jmp(ldf, sec->offset, sec->size);
	if (v == NULL)
		return ;
	ft_bput_str_ln("Contents of (__TEXT,__text) section");
	pretty_print(v, sec->addr, sec->size);
}

static t_bool		handle_segment_text(
						t_ldf *ldf,
						size_t offset,
						struct segment_command_64 *seg)
{
	struct section_64	*sec;
	size_t				i;

	i = 0;
	offset += sizeof(struct segment_command_64);
	sec = (struct section_64 *)ft_ldf_jmp(ldf, offset, sizeof(*sec));
	if (sec == NULL)
		return (FALSE);
	while (i < seg->nsects)
	{
		if (ft_strequ(sec->segname, SEG_TEXT)
			&& ft_strequ(sec->sectname, SECT_TEXT))
		{
			handle_section_text(ldf, sec);
			return (FALSE);
		}
		offset += sizeof(struct section_64);
		sec = (struct section_64 *)ft_ldf_jmp(ldf, offset, sizeof(*sec));
		if (sec == NULL)
			return (FALSE);
		++i;
	}
	return (TRUE);
}

void		otool_m64(t_ldf *ldf)
{
	struct mach_header_64		*h64;
	struct load_command			*lc;
	struct segment_command_64	*seg;
	uint32_t					i;
	size_t						offset;

	h64 = ft_ldf_jmp(ldf, 0, sizeof(*h64));
	offset = sizeof(struct mach_header_64);
	lc = ft_ldf_jmp(ldf, offset, sizeof(*lc));
	if (h64 == NULL || lc == NULL)
		return ;
	i = 0;
	while (i++ < h64->ncmds)
	{
		if (lc->cmd == LC_SEGMENT_64)
		{
			seg = (struct segment_command_64 *)lc;
			if (handle_segment_text(ldf, offset, seg) == FALSE)
				break ;
		}
		offset += lc->cmdsize;
		lc = ft_ldf_jmp(ldf, offset, sizeof(*lc));
		if (lc == NULL)
			return ;
	}
}
