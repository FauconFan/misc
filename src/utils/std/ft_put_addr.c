/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_addr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:42:53 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/13 13:55:23 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void	ft_put_addr(const void *v)
{
	ft_put_str("0x");
	ft_put_uint16((unsigned long int)v);
}

void	ft_put_addr_ln(const void *v)
{
	ft_put_addr(v);
	write(1, "\n", 1);
}
