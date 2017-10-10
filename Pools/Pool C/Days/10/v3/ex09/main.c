/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 12:59:15 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/14 17:27:55 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include "ft_opp.h"

int		main(int argc, char **argv)
{
	if (argc == 4)
	{
		argc--;
		argv++;
		do_main(argv);
	}
	return (0);
}

void	do_main(char **argv)
{
	int		value[2];
	int		index_tab;

	index_tab = verify_tab_func(argv[1]);
	if (index_tab == -1 || g_opptab[index_tab].f == &ft_usage)
	{
		ft_usage(0, 0);
		return ;
	}
	value[0] = ft_atoi(argv[0]);
	value[1] = ft_atoi(argv[2]);
	if (g_opptab[index_tab].f == &ft_div && value[1] == 0)
		ft_putstr("Stop : division by zero\n");
	else if (g_opptab[index_tab].f == &ft_mod && value[1] == 0)
		ft_putstr("Stop : modulo by zero\n");
	else
		ft_putnbr(g_opptab[index_tab].f(value[0], value[1]));
}

int		verify_tab_func(char *str)
{
	int		index;

	index = 0;
	while (index < 6)
	{
		if (ft_strcmp(str, g_opptab[index].s) == 0)
			return (index);
		index++;
	}
	return (-1);
}

void	print_symbol(void)
{
	int		index;

	ft_putstr(" ");
	index = 0;
	while (index < 6)
	{
		if (g_opptab[index].f != &ft_usage)
		{
			ft_putstr(g_opptab[index].s);
			ft_putstr(" ");
		}
		index++;
	}
}
