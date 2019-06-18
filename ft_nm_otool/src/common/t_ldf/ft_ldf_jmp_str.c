/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldf_jpm_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 13:50:33 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/18 13:54:22 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

void	*ft_ldf_jmp_str(t_ldf *ldf, size_t offset)
{
	char	*v;
	size_t	i;

	if (offset >= ldf->len)
	{
		ft_put_str_ln(CORRUPTION_MSG);
		return (NULL);
	}
	v = (char *)ldf->content;
	v += offset;
	i = 0;
	while (offset + i < ldf->len && v[i])
		++i;
	if (offset + i == ldf->len)
	{
		ft_put_str_ln(CORRUPTION_MSG);
		return (NULL);
	}
	return (v);
}
