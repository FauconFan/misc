/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldf_end.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 13:38:37 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/25 11:10:30 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

t_bool		ft_ldf_end(t_ldf *ld)
{
	if (ld->is_mmap && munmap(ld->content, ld->len) < 0)
	{
		ft_bput_str_ln("Failed to munmap");
		return (FALSE);
	}
	if (ld->name)
		free(ld->name);
	return (TRUE);
}
