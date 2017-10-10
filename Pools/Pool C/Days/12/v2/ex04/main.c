/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 17:55:46 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/21 20:40:31 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utmp.h>
#include <time.h>
#include <sys/types.h>
#include "functions.h"

void	print_date(void)
{
	time_t secondes;
	struct tm instant;

	time(&secondes);
	instant = *localtime(&secondes);
	ft_putstr(get_str_from_day_week(instant.tm_wday));
	ft_putstr(" ");
	ft_putstr(get_str_from_month(instant.tm_mon));
	ft_putnbr(instant.tm_hour);
	ft_putchar(':');
	ft_putnbr(instant.tm_min);
	ft_putstr("  \n");
}

int		main(void)
{
	print_date();

	return (0);
}
