/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 21:00:31 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/03 21:00:35 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	print_digits(short digits[], int index)
{
	int j;

	j = index - 1;
	while (j >= 0)
	{
		ft_putchar(digits[j] + '0');
		j--;
	}
}

void	ft_putnbr(int n)
{
	short	digits[16];
	short	index;

	index = 0;
	if (n == 0)
	{
		ft_putchar('0');
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	while (n != 0)
	{
		digits[index] = n % 10;
		n = n / 10;
		index++;
	}
	print_digits(digits, index);
}
