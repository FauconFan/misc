/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_m32.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 11:00:48 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/25 15:21:42 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

static void		pretty_print(char *v, uint64_t vm_addr, size_t len)
{
	size_t	i;

	if (len == 0)
		return ;
	ft_bput_vm_addr32(vm_addr);
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

static void		handle_section_text(t_ldf *ldf, struct section *sec)
{
	char	*v;

	v = (char *)ft_ldf_jmp(ldf, sec->offset, sec->size);
	if (v == NULL)
		return ;
	ft_bput_str_ln("Contents of (__TEXT,__text) section");
	pretty_print(v, sec->addr, sec->size);
}

static t_bool	handle_segment_text(
					t_ldf *ldf,
					size_t offset,
					struct segment_command *seg)
{
	struct section		*sec;
	size_t				i;

	i = 0;
	offset += sizeof(struct segment_command);
	sec = (struct section *)ft_ldf_jmp(ldf, offset, sizeof(*sec));
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
		offset += sizeof(struct section);
		sec = (struct section *)ft_ldf_jmp(ldf, offset, sizeof(*sec));
		if (sec == NULL)
			return (FALSE);
		++i;
	}
	return (TRUE);
}

void			otool_m32(t_ldf *ldf)
{
	struct mach_header			*h32;
	struct load_command			*lc;
	struct segment_command		*seg;
	uint32_t					i;
	size_t						offset;

	ft_ldf_print_name(ldf);
	offset = sizeof(struct mach_header);
	if ((h32 = ft_ldf_jmp(ldf, 0, sizeof(*h32))) == NULL
		|| (lc = ft_ldf_jmp(ldf, offset, sizeof(*lc))) == NULL)
		return ;
	i = 0;
	while (i++ < h32->ncmds)
	{
		if (lc->cmd == LC_SEGMENT)
		{
			seg = (struct segment_command *)lc;
			if (handle_segment_text(ldf, offset, seg) == FALSE)
				break ;
		}
		offset += lc->cmdsize;
		lc = ft_ldf_jmp(ldf, offset, sizeof(*lc));
		if (lc == NULL)
			return ;
	}
}
