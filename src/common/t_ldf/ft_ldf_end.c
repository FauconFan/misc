/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldf_end.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 13:38:37 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/20 12:04:07 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

t_bool		ft_ldf_end(t_ldf *ld)
{
	if (munmap(ld->content, ld->len) < 0)
	{
		ft_bput_str("Failed to munmap the file : ");
		ft_bput_str_ln(ld->filepath);
		return (FALSE);
	}
	return (TRUE);
}
