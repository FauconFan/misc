/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha_sig_min_256_0.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 14:58:51 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/14 15:02:37 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uint32_t	ft_sha_sig_min_256_0(uint32_t x)
{
	return ((ft_rotright_uint32(x, 7))
			^ (ft_rotright_uint32(x, 18))
			^ (x >> 3));
}
