/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldf_jmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 11:05:19 by jpriou            #+#    #+#             */
/*   Updated: 2019/07/01 10:00:52 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

void	*ft_ldf_jmp(t_ldf *ldf, void *at_least, size_t offset, size_t remain)
{
	char	*v;

	v = (char *)ldf->content;
	v += offset;
	if (offset + remain > ldf->len || (void *)v <= at_least)
	{
		write(1, CORRUPTION_MSG "\n", sizeof(CORRUPTION_MSG) + 1);
		ft_buff_disable();
		return (NULL);
	}
	return ((void *)v);
}
