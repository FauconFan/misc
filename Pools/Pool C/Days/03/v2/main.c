/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 15:12:21 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/05 11:52:55 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_atoi(char *str);

int		ft_putchar(char c);
void	ft_end_of_line();
void	ft_putstr(char	*str);
void	print_digits(short digits[], int index);
void	ft_putnbr(int n);

int		main(void)
{
	ft_putnbr(ft_atoi("495 chevaux"));
	ft_putnbr(ft_atoi("-2147483648 escargots"));
	ft_putnbr(ft_atoi("32 escargots"));
	ft_putnbr(ft_atoi("12 escargots"));
	ft_putnbr(ft_atoi("2147483647 escargots"));
	ft_putnbr(ft_atoi("2147483648 escargots"));
}

int		ft_putchar(char c)
{
	int		ret;

	ret = write(1, &c, 1);
	return (ret);
}

void	ft_end_of_line(void)
{
	write(1, "\n", 1);
}

void	ft_putstr(char *str)
{
	char	c;
	int		index;

	index = 0;
	c = *str;
	while (c != '\0')
	{
		ft_putchar(c);
		index++;
		c = str[index];
	}
	ft_end_of_line();
}

void	print_digits(short digits[], int index)
{
	int		j;

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
		ft_putchar('-');
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-');
	}
	else
	{
		n = -n;
	}
	while (n != 0)
	{
		digits[index] = -(n % 10);
		n = n / 10;
		index++;
	}
	print_digits(digits, index);
	ft_end_of_line();
}
