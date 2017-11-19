/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 17:13:52 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/19 15:50:40 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
#include "ft_printf.h"
#include "ft_lltoa_n_ulltoa.h"

int		main(void)
{
	int		n;

	n = 42;
	ft_putstr("---\n");
	ft_printf("@moulitest: %#.x %#.0x", 0, 0);
	ft_putstr("\n---\n");
	return (0);
}
