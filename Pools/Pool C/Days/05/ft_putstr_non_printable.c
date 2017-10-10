/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 14:15:25 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/10 15:01:22 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_non_printable(char c)
{
	int		a;
	int		b;

	a = c / 16;
	b = c % 16;
	ft_putchar('\\');
	if (a < 10)
		ft_putchar(a + '0');
	else
		ft_putchar(a + 'a' - 10);
	if (b < 10)
		ft_putchar(b + '0');
	else
		ft_putchar(b + 'a' - 10);
}

void	ft_putstr_non_printable(char *str)
{
	int		index;

	index = 0;
	while (*str != '\0')
	{
		if (*str < 32 || *str == 127)
			print_non_printable(*str);
		else
			ft_putchar(*str);
		str++;
	}
}

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		main()
{
	char s[128];

	int index = 0;
	while (index < 127)
	{
		s[index] = index + 1;
		index++;
	}
	s[127] = 0;
	ft_putstr_non_printable(s);
}
