/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 14:44:44 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/10 16:01:04 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_number_recu(unsigned int nb)
{
	int		digit;
	
	if (nb == 0)
		return ;
	print_number_recu(nb / 16);
	digit = nb % 16;
	if (digit < 10)
		ft_putchar(digit + '0');
	else 
		ft_putchar(digit + 'a' - 10);
}

void	print_number_nb_digits(unsigned int nb, int nb_digit)
{
	int				log;
	unsigned int	cpy;
	int				index;

	log = 0;
	cpy = nb;
	while (cpy != 0)
	{
		cpy = cpy / 16;
		log++;
	}
	index = 0;
	while (index < nb_digit - log)
	{
		index++;
		ft_putchar('0');
	}
	print_number_recu(nb);
}

void	ft_print_memory(unsigned int addr, unsigned int size)
{
	int		index;
	int		rank;
	short	*ptr;

	rank = 0;
	while (size != 0)
	{
		print_number_nb_digits(addr, 8);
		index = (size < 16) ? size : 15;
		while (index >= 0)
		{
			ptr = addr + (15 - index);
			index--;
		}
	}
	print_number_nb_digits(addr, 8);
}

int		main(void)
{
	unsigned int add = 0x00001234;
	ft_print_memory((add), 10);
	return (0);
}
