/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 19:18:48 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/06 08:51:16 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check_if_prime(int nb)
{
	int		compteur;

	if (nb <= 1)
		return (0);
	compteur = 2;
	while (compteur * compteur <= nb)
	{
		if (nb % compteur == 0)
			return (0);
		compteur++;
	}
	return (1);
}

int		ft_find_next_prime(int nb)
{
	int next_prime;

	if (check_if_prime(nb) == 1)
		return (nb);
	next_prime = nb + 1;
	while (check_if_prime(next_prime) == 0)
	{
		next_prime++;
	}
	return (next_prime);
}
