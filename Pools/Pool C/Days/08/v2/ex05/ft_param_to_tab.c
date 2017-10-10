/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_to_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 09:15:59 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/12 09:16:01 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_par.h"

void				set_struct(t_stock_par *stock, char *s)
{
	int		index;
	char	*cpy;

	index = 0;
	while (s[index])
		index++;
	cpy = (char *)malloc(sizeof(char *) * (index + 1));
	index = 0;
	while (s[index])
	{
		cpy[index] = s[index];
		index++;
	}
	stock->size_param = index;
	stock->str = s;
	stock->copy = cpy;
	stock->tab = ft_split_whitespaces(s);
}

struct s_stock_par	*ft_param_to_tab(int ac, char **av)
{
	t_stock_par *res;
	int			index;

	res = (t_stock_par *)malloc(sizeof(t_stock_par) * (ac + 1));
	index = 0;
	while (index < ac)
	{
		set_struct(res + index, av[index]);
		index++;
	}
	(res + index)->size_param = 0;
	(res + index)->str = 0;
	(res + index)->copy = 0;
	(res + index)->tab = 0;
	return (res);
}
