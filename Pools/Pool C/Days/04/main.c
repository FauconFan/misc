/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 15:12:21 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/05 19:46:15 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_iterative_factorial(int nb);
int		ft_recursive_factorial(int nb);
int		ft_iterative_power(int nb, int power);
int		ft_recursive_power(int nb, int power);
int		ft_fibonacci(int index);
int		ft_sqrt(int nb);
int		ft_is_prime(int nb);
int		ft_find_next_prime(int nb);
int		ft_eight_queens_puzzle(void);

int		ft_putchar(char c);
void	ft_end_of_line();
void	ft_putstr(char	*str);
void	print_digits(short digits[], int index);
void	ft_putnbr(int n);

int		main(void)
{
	//ft_putnbr(ft_iterative_factorial(4));
	//ft_putnbr(ft_recursive_factorial(5));
	//ft_putnbr(ft_iterative_power(4, 3));
	//ft_putnbr(ft_recursive_power(2, 10));
	//ft_putnbr(ft_fibonacci(3));
	//ft_putnbr(ft_fibonacci(4));
	//ft_putnbr(ft_fibonacci(5));
	//ft_putnbr(ft_sqrt(1024000001));
	//ft_putnbr(ft_sqrt(2025));
	//ft_putnbr(ft_sqrt(2026));
	//ft_putnbr(ft_sqrt(126737));
	//ft_putnbr(ft_is_prime(121));	
	//ft_putnbr(ft_find_next_prime(20));
	//ft_putnbr(ft_find_next_prime(65));
	//ft_putnbr(ft_find_next_prime(17));
	ft_eight_queens_puzzle();
}

int		ft_putchar(char c)
{
	int		ret;

	ret = write(1, &c, 1);
	return (ret);
}

void	ft_end_of_line()
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
		ft_putchar('0');
		ft_end_of_line();
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
