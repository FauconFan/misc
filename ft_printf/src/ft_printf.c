/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 08:09:02 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/15 16:32:57 by jpriou           ###   ########.fr       */
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

	data = init_treat_data();
	str = set_values_treat_data(++str, data);
	tmp = treat_data(data, va);
	print_and_length(tmp, res);
	free(tmp);
	free_treat_data(data);
	return (str);
}

void			die(char *str)
{
	ft_putendl(str);
	exit(1);
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
			die(WMALLOC);
		print_and_length(tmp, &res);
		free(tmp);
		str += pos_first_percent;
		str = treat(str, va, &res);
	}
	print_and_length(str, &res);
	va_end(va);
	return (res);
}
