/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha_sig_maj_256_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 14:58:51 by jpriou            #+#    #+#             */
/*   Updated: 2018/08/14 15:01:20 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uint32_t	ft_sha_sig_maj_256_1(uint32_t x)
{
	return ((ft_rotright_uint32(x, 6))
			^ (ft_rotright_uint32(x, 11))
			^ (ft_rotright_uint32(x, 25)));
}
