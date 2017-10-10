/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 14:54:22 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/04 15:03:58 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int		res;

	if (nb < 0)
		return (0);
	res = 1;
	while (nb != 0)
	{
		res *= nb;
		nb--;
	}
	return (res);
}
