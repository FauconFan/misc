/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 17:13:52 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/01 10:25:24 by jpriou           ###   ########.fr       */
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
	ft_printf("-----\n");
	//ft_snprintf(&s, 9, "oui%s%d\n", "non", 42);
	//printf("%*.*s\n", 4, 2, "oui");
	//ft_printf("%*.*s\n", 4, 2, "oui");
	ft_printf("%S\n", L"米");
	ft_printf("%d\n", printf("%S", L"米"));
	//ft_putstr(s);
	ft_printf("\n-----\n");
	return (0);
}
