/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_m64.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 11:00:48 by jpriou            #+#    #+#             */
/*   Updated: 2019/07/01 09:28:17 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"

static void		handle_section_text(
					t_ldf *ldf,
					struct section_64 *sec,
					cpu_type_t cputype)
{
	char			*v;
	t_pprint_help	pprint_help;
	size_t			len;

	len = ft_gswap_64(sec->size);
	v = NULL;
	if (len == 0
		|| (v = ft_ldf_jmp(ldf, sec, ft_gswap_32(sec->offset), len)) != NULL)
	{
		pprint_help.v = v;
		pprint_help.len = ft_gswap_64(sec->size);
		pprint_help.vm_addr = ft_gswap_64(sec->addr);
		pprint_help.is64 = TRUE;
		pprint_help.cputype = ft_gswap_32(cputype);
		otool_pretty_print(&pprint_help);
	}
}

static t_bool	handle_segment_text(
					t_ldf *ldf,
					size_t offset,
					struct segment_command_64 *seg,
					cpu_type_t cputype)
{
	struct section_64	*sec;
	size_t				i;

	i = 0;
	offset += sizeof(struct segment_command_64);
	sec = (struct section_64 *)ft_ldf_jmp(ldf, seg, offset, sizeof(*sec));
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
		offset += sizeof(struct section_64);
		sec = (struct section_64 *)ft_ldf_jmp(ldf, sec, offset, sizeof(*sec));
		if (sec == NULL)
			return (FALSE);
		++i;
	}
	return (TRUE);
}

void			otool_m64(t_ldf *ldf, t_bool doswap)
{
	struct mach_header_64		*h64;
	struct load_command			*lc;
	struct segment_command_64	*seg;
	uint32_t					i;
	size_t						offset;

	ft_swap_set(doswap);
	ft_ldf_print_name(ldf);
	offset = sizeof(struct mach_header_64);
	if ((h64 = ft_ldf_jmp(ldf, NULL, 0, sizeof(*h64))) == NULL)
		return ;
	i = 0;
	lc = NULL;
	while (i++ < ft_gswap_32(h64->ncmds)
			&& (lc = ft_ldf_jmp(ldf, lc, offset, sizeof(*lc))) != NULL)
	{
		if (ft_gswap_32(lc->cmd) == LC_SEGMENT_64)
		{
			seg = (struct segment_command_64 *)lc;
			if (handle_segment_text(ldf, offset, seg, h64->cputype) == FALSE)
				break ;
		}
		offset += ft_gswap_32(lc->cmdsize);
	}
}
