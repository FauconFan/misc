/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 18:51:52 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/20 18:46:07 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "functions.h"
#include <stdlib.h>

t_cara	*ft_create_data(char *s)
{
	t_cara	*data;
	int		n;

	data = (t_cara *)malloc(sizeof(t_cara *));
	n = 0;
	if ((*s >= '0' && *s <= '9') || ((
			(*s == '+' || *s == '-') && *(s + 1) >= '0' && *(s + 1) <= '9')))
	{
		data->is_number = 1;
		data->value = ft_atoi(s);
	}
	else
	{
		data->is_number = 0;
		data->operation = *s;
	}
	return (data);
}

t_list	*ft_create_elem(char *s)
{
	t_list	*res;

	res = (t_list *)malloc(sizeof(t_list *));
	res->data = ft_create_data(s);
	res->next = NULL;
	return (res);
}
