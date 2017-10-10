/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 21:01:56 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/03 21:02:00 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	ft_print_comb2(void)
{
	short a;
	short b;

	a = 0;
	while (a < 99)
	{
		b = a + 1;
		while (b < 100)
		{
			if (!(a == 0 && b == 1))
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
			ft_putchar((a / 10) + '0');
			ft_putchar((a % 10) + '0');
			ft_putchar(' ');
			ft_putchar((b / 10) + '0');
			ft_putchar((b % 10) + '0');
			b++;
		}
		a++;
	}
}
