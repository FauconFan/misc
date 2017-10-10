/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 18:59:00 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/05 19:12:13 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_prime(int nb)
{
	int		compteur;
	int		res;

	if (nb <= 1)
		return (0);
	res = 1;
	compteur = 2;
	while (compteur * compteur <= nb)
	{
		if (nb % compteur == 0)
			return (0);
		compteur++;
	}
	return (1);
}
