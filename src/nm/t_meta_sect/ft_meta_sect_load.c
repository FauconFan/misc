/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_meta_sect_load.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 08:16:35 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/18 08:19:00 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

void	ft_meta_sect_load(
			t_meta_sect *meta,
			char *seg_name,
			char *sect_name,
			uint8_t i)
{
	if (ft_strequ(seg_name, SEG_TEXT) && ft_strequ(sect_name, SECT_TEXT))
		meta->text_index = i;
	if (ft_strequ(seg_name, SEG_DATA) && ft_strequ(sect_name, SECT_BSS))
		meta->bss_index = i;
	if (ft_strequ(seg_name, SEG_DATA) && ft_strequ(sect_name, SECT_DATA))
		meta->data_index = i;
}
