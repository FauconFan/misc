/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 08:09:02 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/21 11:36:31 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		print_and_length(char *str, int *res)
{
	ft_putstr(str);
	*res = *res + ft_strlen(str);
}

static char		*treat(char *str, va_list va, int *res)
{
	t_treat_data	*data;
	char			*tmp;

	if ((data = init_treat_data()) == 0)
		return (0);
	if ((str = set_values_treat_data(++str, data)) == 0)
	{
		free_treat_data(data);
		return (str);
	}
	tmp = treat_data(data, va, res);
	if (tmp != 0)
	{
		print_and_length(tmp, res);
		free(tmp);
	}
	free_treat_data(data);
	return (str);
}

int				ft_printf(char *str, ...)
{
	va_list				va;
	char				*tmp;
	int					pos_first_percent;
	int					res;

	res = 0;
	va_start(va, str);
	while ((pos_first_percent = ft_strcpos(str, SEPERATOR)) != -1)
	{
		if ((tmp = ft_strsub(str, 0, pos_first_percent)) == 0)
			return (-1);
		print_and_length(tmp, &res);
		free(tmp);
		str += pos_first_percent;
		if ((str = treat(str, va, &res)) == 0)
			return (-1);
	}
	print_and_length(str, &res);
	va_end(va);
	return (res);
}
