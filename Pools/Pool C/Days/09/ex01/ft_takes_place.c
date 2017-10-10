/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_takes_place.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 17:44:47 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/10 18:24:53 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#define BEGINNING_SENTENCE "THE FOLLOWING TAKES PLACE BETWEEN "
#define AM " A.M."
#define PM " P.M."
#define AND " AND "
#define END_HOUR ":00"
#define END_SENTENCE "\n"

int		my_strlen(char *str)
{
	int		length;

	length = 0;
	while (str[length])
		length++;
	return (length);
}

void	print_str(char *str)
{
	write(1, str, my_strlen(str));
}

void	my_putchar(char c)
{
	write(1, &c, 1);
}

void	print_hour(int hour)
{
	int		is_am;

	while (hour > 24)
		hour -= 24;
	is_am = (hour < 12 || hour == 24);
	hour %= 12;
	if (hour == 0)
		hour += 12;
	my_putchar(hour / 10 + '0');
	my_putchar(hour % 10 + '0');
	print_str(END_HOUR);
	print_str((is_am) ? AM : PM);
}

void	ft_takes_place(int hour)
{
	print_str(BEGINNING_SENTENCE);
	print_hour(hour);
	print_str(AND);
	print_hour(hour + 1);
	print_str(END_SENTENCE);
}
