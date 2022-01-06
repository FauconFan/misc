/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_m32.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 11:00:48 by jpriou            #+#    #+#             */
/*   Updated: 2019/07/01 09:29:51 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"

static void		handle_section_text(
					t_ldf *ldf,
					struct section *sec,
					cpu_type_t cputype)
{
	char			*v;
	t_pprint_help	pprint_help;
	size_t			len;

	len = ft_gswap_32(sec->size);
	v = NULL;
	if (len == 0
		|| (v = ft_ldf_jmp(ldf, sec, ft_gswap_32(sec->offset), len)) != NULL)
	{
		pprint_help.v = v;
		pprint_help.len = ft_gswap_32(sec->size);
		pprint_help.vm_addr = ft_gswap_32(sec->addr);
		pprint_help.is64 = FALSE;
		pprint_help.cputype = ft_gswap_32(cputype);
		otool_pretty_print(&pprint_help);
	}
}

static t_bool	handle_segment_text(
					t_ldf *ldf,
					size_t offset,
					struct segment_command *seg,
					cpu_type_t cputype)
{
	struct section		*sec;
	size_t				i;

	i = 0;
	offset += sizeof(struct segment_command);
	sec = (struct section *)ft_ldf_jmp(ldf, seg, offset, sizeof(*sec));
	if (sec == NULL)
		return (FALSE);
	while (i < ft_gswap_32(seg->nsects))
	{
		if (ft_strequ(sec->segname, SEG_TEXT)
			&& ft_strequ(sec->sectname, SECT_TEXT))
		{
			handle_section_text(ldf, sec, cputype);
			return (FALSE);
		}
		offset += sizeof(struct section);
		sec = (struct section *)ft_ldf_jmp(ldf, sec, offset, sizeof(*sec));
		if (sec == NULL)
			return (FALSE);
		++i;
	}
	return (TRUE);
}

void			otool_m32(t_ldf *ldf, t_bool doswap)
{
	struct mach_header			*h32;
	struct load_command			*lc;
	struct segment_command		*seg;
	uint32_t					i;
	size_t						offset;

	ft_swap_set(doswap);
	ft_ldf_print_name(ldf);
	offset = sizeof(struct mach_header);
	if ((h32 = ft_ldf_jmp(ldf, NULL, 0, sizeof(*h32))) == NULL)
		return ;
	i = 0;
	lc = NULL;
	while (i++ < ft_gswap_32(h32->ncmds)
			&& (lc = ft_ldf_jmp(ldf, lc, offset, sizeof(*lc))) != NULL)
	{
		if (ft_gswap_32(lc->cmd) == LC_SEGMENT)
		{
			seg = (struct segment_command *)lc;
			if (handle_segment_text(ldf, offset, seg, h32->cputype) == FALSE)
				break ;
		}
		offset += ft_gswap_32(lc->cmdsize);
	}
}
