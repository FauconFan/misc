/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collatz_conjecture.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 09:41:28 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/11 09:46:43 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_collatz_conjecture(unsigned int base)
{
	if (base <= 1)
		return (0);
	if (base % 2 == 0)
		return (ft_collatz_conjecture(base / 2) + 1);
	return (ft_collatz_conjecture(base * 3 + 1) + 1);
}
