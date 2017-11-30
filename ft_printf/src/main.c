/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 17:13:52 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/30 12:15:50 by fauconfan        ###   ########.fr       */
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
	ft_printf("%s\n", "coucou");
	ft_printf("%6C\n", L'é');
	printf("%1C\n", L'é');
	//ft_putstr(s);
	free(s);
	ft_printf("-----\n");
	return (0);
}
