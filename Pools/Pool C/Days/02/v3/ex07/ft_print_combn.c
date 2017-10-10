/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 09:57:06 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/07 11:58:57 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	print_digits(short digits[], int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		ft_putchar(digits[i] + '0');
		i++;
	}
}

void	print_link(void)
{
	ft_putchar(',');
	ft_putchar(' ');
}

void	ft_print_combn(int n)
{
	int		i;
	int		j;
	short	digits[n];

	i = 0;
	if (n == 0)
	{
		return ;
	}
	while (i < n)
	{
		digits[i] = i;
		i++;
	}
	print_digits(digits, n);
	i = n - 1;
	while (digits[0] < 10)
	{
		digits[i]++;
		if (digits[i] > 9)
		{
			i--;
			continue;
		}
		j = i + 1;
		while (j < n)
		{
			digits[j] = digits[j - 1] + 1;
			if (digits[0] > 10 - n)
			{
				return ;
			}
			if (digits[j] > 9)
			{
				continue;
			}
			i++;
			j++;
		}
		print_link();
		print_digits(digits, n);
	}
}
