/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_meta_sect_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 08:03:17 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/18 08:05:18 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

void	ft_meta_sect_init(t_meta_sect *meta)
{
	meta->text_index = 0;
	meta->data_index = 0;
	meta->bss_index = 0;
}
