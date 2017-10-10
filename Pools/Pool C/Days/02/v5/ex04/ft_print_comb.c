/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 15:14:33 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/03 20:56:48 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	print_link(void)
{
	ft_putchar(',');
	ft_putchar(' ');
}

void	print_digits(short digits[])
{
	ft_putchar(digits[0] + '0');
	ft_putchar(digits[1] + '0');
	ft_putchar(digits[2] + '0');
}

void	ft_print_comb(void)
{
	short digits[3];

	digits[0] = 0;
	digits[1] = 1;
	digits[2] = 2;
	print_digits(digits);
	digits[2]++;
	while (digits[0] < 8)
	{
		print_link();
		print_digits(digits);
		digits[2]++;
		if (digits[2] > 9)
		{
			digits[1]++;
			if (digits[1] > 8)
			{
				digits[0]++;
				digits[1] = digits[0] + 1;
			}
			digits[2] = digits[1] + 1;
		}
	}
}
