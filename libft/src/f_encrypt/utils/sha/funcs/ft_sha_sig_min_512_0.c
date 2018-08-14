/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha_sig_min_512_0.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 14:58:51 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/14 15:32:54 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uint64_t	ft_sha_sig_min_512_0(uint64_t x)
{
	return ((ft_rotright_uint64(x, 1))
			^ (ft_rotright_uint64(x, 8))
			^ (x >> 7));
}
