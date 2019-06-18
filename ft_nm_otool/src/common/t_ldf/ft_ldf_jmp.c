/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldf_jmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 11:05:19 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/18 13:41:06 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

void	*ft_ldf_jmp(t_ldf *ldf, size_t offset, size_t at_least)
{
	char	*v;

	if (offset + at_least >= ldf->len)
	{
		ft_put_str_ln(CORRUPTION_MSG);
		return (NULL);
	}
	v = (char *)ldf->content;
	v += offset;
	return ((void *)v);
}
