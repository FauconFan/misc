/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrdigit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 11:30:07 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/18 12:52:54 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_number_recursive(int nbr)
{
	char	*base;
	
	base = "0123456789abcdef";
	if (nbr == 0)
		return ;
	print_number_recursive(nbr / 16);
	ft_putchar(base[(nbr % 16)]);
}

void	print_nb_zero(unsigned long nbr, int digit_max)
{
	int		nb_digit;

	nb_digit = 0;
	while (nbr != 0)
	{
		nb_digit++;
		nbr /= 16;
	}
	nb_digit = digit_max - nb_digit;
	while (nb_digit != 0)
	{
		ft_putchar('0');
		nb_digit--;
	}
}

void	ft_putnbr_addr(unsigned long nbr)
{
	print_nb_zero(nbr, 8);
	print_number_recursive(nbr);
}

void	ft_putnbr_value(char c)
{
	unsigned long n;

	n = (unsigned long)c;
	print_nb_zero(n, 2);
	print_number_recursive(n);
}
