/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 08:17:31 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/17 11:00:13 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

void		ft_nm(t_ldf *ldf)
{
	uint32_t	magic_number;

	magic_number = *(uint32_t *)ldf->content;
	if (magic_number != MH_MAGIC_64)
	{
		ft_put_str_ln("Not a 64 bit Mach-O");
		return ;
	}
	nm_m64(ldf);
}
