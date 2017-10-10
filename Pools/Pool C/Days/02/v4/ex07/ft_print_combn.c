/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 18:35:26 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/08 21:23:45 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void			ft_putchar(char c);

void			print_number(unsigned int nb_actu)
{
	if (nb_actu == 0)
		return ;
	print_number(nb_actu / 10);
	ft_putchar(nb_actu % 10 + '0');
}

void			print_numberndigits(unsigned int nb_actu, int nb_digit)
{
	unsigned int	cpy;
	int				log;
	int				index;

	log = 0;
	cpy = nb_actu;
	while (cpy != 0)
	{
		log++;
		cpy /= 10;
	}
	index = 0;
	while (index++ < nb_digit - log)
		ft_putchar('0');
	index = 0;
	print_number(nb_actu);
}

unsigned int	get_next(unsigned int nb, int n)
{
	int					index;
	unsigned int		cpy;
	unsigned int		pow;
	int					tmp[2];

	index = 0;
	cpy = nb;
	pow = 1;
	while (index < n)
	{
		index++;
		pow = pow * 10;
		tmp[1] = cpy % 10;
		cpy = cpy / 10;
		tmp[0] = cpy % 10;
		if (tmp[0] > tmp[1])
		{
			if (tmp[0] == 9)
				return (get_next(nb + pow, n));
			else
				return (get_next(nb + ((pow / 10) * (tmp[0] + 1)), n));
		}
	}
	return (nb);
}

void			ft_print_combn(int n)
{
	unsigned int	value_actu;
	unsigned int	top;
	int				index;

	top = 1;
	index = 0;
	while (index++ < n)
		top *= 10;
	value_actu = 1;
	while (value_actu < top)
	{
		if (value_actu != 1)
		{
			ft_putchar(',');
			ft_putchar(' ');
		}
		print_numberndigits(value_actu, n);
		if (value_actu == 123456789)
			return ;
		value_actu = get_next(value_actu + 1, n);
	}
}
