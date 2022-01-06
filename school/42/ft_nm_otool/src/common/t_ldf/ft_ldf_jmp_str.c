/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldf_jmp_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 13:50:33 by jpriou            #+#    #+#             */
/*   Updated: 2019/07/01 09:12:15 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

void	*ft_ldf_jmp_str(t_ldf *ldf, void *at_least, size_t offset, size_t *size)
{
	char	*v;

	v = (char *)ldf->content;
	v += offset;
	if (offset > ldf->len || (void *)v <= at_least)
	{
		write(1, CORRUPTION_MSG "\n", sizeof(CORRUPTION_MSG) + 1);
		ft_buff_disable();
		return (NULL);
	}
	ft_check_str(v, ldf->len - offset, size);
	return (v);
}
