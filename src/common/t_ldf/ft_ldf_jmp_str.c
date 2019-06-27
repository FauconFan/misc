/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldf_jmp_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 13:50:33 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/27 18:40:58 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

void	*ft_ldf_jmp_str(t_ldf *ldf, size_t offset, size_t *size)
{
	char	*v;

	if (offset > ldf->len)
	{
		write(1, CORRUPTION_MSG "\n", sizeof(CORRUPTION_MSG) + 1);
		ft_buff_disable();
		return (NULL);
	}
	v = (char *)ldf->content;
	v += offset;
	ft_check_str(v, ldf->len - offset, size);
	return (v);
}
