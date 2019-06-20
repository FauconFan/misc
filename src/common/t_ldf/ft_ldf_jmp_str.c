/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldf_jmp_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 13:50:33 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/20 12:04:21 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

void	*ft_ldf_jmp_str(t_ldf *ldf, size_t offset)
{
	char	*v;

	if (offset >= ldf->len)
	{
		ft_bput_str_ln(CORRUPTION_MSG);
		return (NULL);
	}
	v = (char *)ldf->content;
	v += offset;
	if (ft_check_str(v, ldf->len - offset) == FALSE)
	{
		ft_bput_str_ln(CORRUPTION_MSG);
		return (NULL);
	}
	return (v);
}
