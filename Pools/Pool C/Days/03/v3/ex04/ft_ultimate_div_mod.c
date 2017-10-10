/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 19:00:51 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/05 11:32:43 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int		a_previous;
	int		b_previous;

	a_previous = *a;
	b_previous = *b;
	*a = a_previous / b_previous;
	*b = a_previous % b_previous;
}
