/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 17:13:52 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/02 10:06:15 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <signal.h>
#include <locale.h>
#include "libft.h"
#include "ft_printf.h"
#include "ft_lltoa_n_ulltoa.h"

int		main(void)
{
	setlocale(LC_ALL, "");
	ft_printf("-----\n");
	ft_putnbrl(MB_CUR_MAX);
	ft_putnbrl(ft_printf("%S\n", L"米"));
	//ft_printf("%lX\n", L'米');
	//ft_putnbrl(printf("%S\n", L"米"));
	//ft_printf("%s %C %d %p %x %% %S\n", "bonjour ", L'該', 42, &free, 42, L"لحم خن");77
	//ft_putnbrl(printf("%s %C %d %p %x %% %S", "bonjour ", L'該', 42, &free, 42, L"لحم خن"));
	ft_printf("\n-----\n");
	return (0);
}
