/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 12:59:15 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/15 10:26:57 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

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
	int		(*tab_funcs[5]) (int, int);

	index_tab = verify_tab_func(argv[1]);
	if (index_tab == -1)
	{
		ft_putnbr(0);
		return ;
	}
	value[0] = ft_atoi(argv[0]);
	value[1] = ft_atoi(argv[2]);
	tab_funcs[0] = add;
	tab_funcs[1] = substract;
	tab_funcs[2] = times;
	tab_funcs[3] = divide;
	tab_funcs[4] = modulo;
	if (index_tab == 3 && value[1] == 0)
		ft_putstr("Stop : division by zero\n");
	else if (index_tab == 4 && value[1] == 0)
		ft_putstr("Stop : modulo by zero\n");
	else
		ft_putnbr(tab_funcs[index_tab](value[0], value[1]));
}

int		verify_tab_func(char *str)
{
	int		index;
	char	*charset;

	index = 0;
	charset = "+-*/%";
	while (str[index])
		index++;
	if (index != 1)
		return (-1);
	index = 0;
	while (*charset)
	{
		if (*charset == *str)
			return (index);
		index++;
		charset++;
	}
	return (-1);
}
