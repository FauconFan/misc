/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scrambler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 11:32:04 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/11 11:42:38 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_scrambler(int ***a, int *b, int *******c, int ****d)
{
	int		tmp_a;
	int		tmp_b;
	int		tmp_c;
	int		tmp_d;

	tmp_a = ***a;
	tmp_b = *b;
	tmp_c = *******c;
	tmp_d = ****d;
	***a = tmp_b;
	*b = tmp_d;
	*******c = tmp_a;
	****d = tmp_d;
}
