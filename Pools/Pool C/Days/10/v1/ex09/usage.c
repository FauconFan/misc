/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 16:07:57 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/14 16:39:01 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int		ft_usage(int a, int b)
{
	int		index;

	a = 0;
	b = 0;
	index = 0;
	ft_putstr("error : only [");
	print_symbol();
	ft_putstr("] are accepted.\n");
	return (0);
}
