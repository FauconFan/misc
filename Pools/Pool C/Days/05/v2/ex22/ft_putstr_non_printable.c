/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 10:35:44 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/07 11:22:23 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_good_char(char c)
{
	int		a;
	int		b;

	a = c / 16;
	b = c % 16;
	if (a < 10)
	{
		ft_putchar(a + '0');
	}
	else
	{
		ft_putchar(a + 'a' - 10);
	}
	if (b < 10)
	{
		ft_putchar(b + '0');
	}
	else
	{
		ft_putchar(b + 'a' - 10);
	}
}

void	ft_putstr_non_printable(char *str)
{
	int		index;

	index = 0;
	while (str[index] != '\0')
	{
		if (str[index] == 127)
		{
			ft_putchar('\\');
			print_good_char(str[index]);
		}
		else if (str[index] < 32)
		{
			ft_putchar('\\');
			print_good_char(str[index]);
		}
		else
		{
			ft_putchar(str[index]);
		}
		index++;
	}
}
