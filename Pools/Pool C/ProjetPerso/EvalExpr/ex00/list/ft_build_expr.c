/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_expr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 08:08:34 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/20 18:46:30 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "functions.h"

char	*ignore_number_then_whitespaces(char *str)
{
	int		mode;

	if ((*str >= '0' && *str <= '9') ||
			((*str == '-' || *str == '+') &&
			 *(str + 1) >= '0' && *(str + 1) <= '9'))
		mode = 0;
	else
		mode = 1;
	if (mode == 0)
	{
		if (*str == '-' || *str == '+')
			str++;
		while (*str != 0 && *str >= '0' && *str <= '9')
			str++;
		if (*str == 0)
			return (0);
		while (*str == ' ')
			str++;
	}
	else if (mode == 1)
	{
		str++;
		while (*str == ' ')
			str++;
		if (*str == 0)
			return (0);
	}
	return (str);
}

t_list	*ft_build_expr(char *str)
{
	t_list	*beginning;

	beginning = ft_create_elem("0");
	while (str != 0)
	{
		ft_list_push_back(beginning, str);
		str = ignore_number_then_whitespaces(str);
	}
	return (beginning);
}

void	ft_print_list(t_list *begin)
{
	if (begin == 0)
		return ;
	if (begin->data->is_number == 1)
	{
		ft_putstr("Number :");
		ft_putnbr(begin->data->value);
		ft_putstr("\n");
	}
	else if (begin->data->is_number == 0)
	{
		ft_putstr("Operation :");
		ft_putchar(begin->data->operation);
		ft_putchar('\n');
	}
	if (begin->next != 0)
		ft_print_list(begin->next);
}
