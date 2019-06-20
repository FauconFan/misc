/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 08:17:31 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/19 17:44:01 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

void		ft_nm(t_ldf *ldf)
{
	uint32_t	magic_number;

	magic_number = *(uint32_t *)ldf->content;
	if (magic_number == MH_MAGIC_64)
		nm_m64(ldf);
	else if (magic_number == FAT_CIGAM)
		fat_cigam(ldf, ft_nm);
	else
		ft_put_str_ln(UNKNOWN_FILE);
}
