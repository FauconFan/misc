/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 15:09:36 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/09 15:19:34 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar (char c)
{
	write (1, &c, 1);
}

void	ft_print_combn(int n);

int		main()
{
	int		index;

	index = 1;
	while (index < 10)
	{
		ft_print_combn(index++);
		ft_putchar('\n');
	}
	return (0);
}
