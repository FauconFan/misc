/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldf_jmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 11:05:19 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/27 11:29:18 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

void	*ft_ldf_jmp(t_ldf *ldf, size_t offset, size_t at_least)
{
	char	*v;

	if (offset + at_least > ldf->len)
	{
		write(1, CORRUPTION_MSG "\n", sizeof(CORRUPTION_MSG) + 1);
		ft_buff_disable();
		return (NULL);
	}
	v = (char *)ldf->content;
	v += offset;
	return ((void *)v);
}
