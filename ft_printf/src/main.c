/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 17:13:52 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/30 20:04:02 by fauconfan        ###   ########.fr       */
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
	char	*s;

	ft_printf("-----\n");
	//ft_snprintf(&s, 9, "oui%s%d\n", "non", 42);
	//printf("%*.*s\n", 4, 2, "oui");
	//ft_printf("%*.*s\n", 4, 2, "oui");
	ft_printf("@main_ftprintf: %###-#0000 33...12..#0+0d", 256);
	//ft_putstr(s);
	free(s);
	ft_printf("\n-----\n");
	return (0);
}
