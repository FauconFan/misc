/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 16:23:38 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/05 19:08:59 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt_real(int nb, unsigned int approx)
{
	unsigned int		q;
	int					tmp;

	q = nb / approx;
	if (q == approx)
	{
		tmp = q;
		if (tmp * tmp == nb)
		{
			return (tmp);
		}
		else
		{
			return (0);
		}
	}
	else if (q - approx == 1 || approx - q == 1)
	{
		return (0);
	}
	return (ft_sqrt_real(nb, (q + approx) / 2));
}

int		ft_sqrt(int nb)
{
	if (nb <= 0)
		return (0);
	if (nb == 1)
		return (1);
	return (ft_sqrt_real(nb, 2000));
}
