/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/06 19:06:33 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/07 09:23:10 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>

void	ft_putstr(char *str);
void	ft_putnbr(int nb);
unsigned int ft_strlcpy(char *dest, char *src, unsigned int size);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	init(char *s)
{
	s[0] = 'o';
	s[1] = 'u';
	s[2] = 'i';
	s[3] = 'h';
	s[4] = 'e';
	int index = 5;
	while (index < 50)
	{
		s[index++] = '\0';
	}
}

int main(void)
{
	char s1[50] = "ouihe";
	char s2[50] = "bacadaeafa";
	int index = 0;

	while (index < 20)
	{
		ft_putnbr(strlcpy(s1, s2, index));
		ft_putchar('?');
		ft_putstr(s1);
		ft_putchar('\n');
		init(s1);
		index++;
	}
	index = 0;

	ft_putstr("------------------------------------------------\n");
	while (index < 20)
	{
		ft_putnbr(ft_strlcpy(s1, s2, index));
		ft_putchar('?');
		ft_putstr(s1);
		ft_putchar('\n');
		init(s1);
		index++;
	}
	return (0);
}
