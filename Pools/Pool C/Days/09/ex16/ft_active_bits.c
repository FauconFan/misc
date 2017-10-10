/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_active_bits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 14:10:49 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/11 14:19:45 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_active_bits(int value)
{
	if (value < 0)
		return (32 - ft_active_bits(-value));
	if (value == 0)
		return (0);
	return (ft_active_bits(value / 2) + value % 2);
}
