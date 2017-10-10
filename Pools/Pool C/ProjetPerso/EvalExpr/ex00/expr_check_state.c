/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expr_check_state.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 10:57:16 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/20 10:58:29 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "functions.h"

void	check_state0(t_list *actu)
{
	char	c;
	int		pattern[4];

	set_pattern(1, pattern);
	if (is_nextn_exist(actu, 3) == 0)
		return ;
	if (is_pattern_match(actu, pattern) == 1)
	{
		c = actu->next->next->data->operation;
		if (c == '*' || c == '/' || c == '%')
		{
			actu->next->data->value =
				operation_treatment(c, actu->next->data->value,
				actu->next->next->next->data->value);
			ft_remove_nextn(actu->next, 2);
			return ;
		}
	}
	check_state0(actu->next);
}

void	check_state1(t_list *actu)
{
	int		temp;
	int		pattern[6];

	set_pattern(2, pattern);
	if (is_nextn_exist(actu, 5) == 0)
		return ;
	if (is_pattern_match(actu, pattern) == 1)
	{
		if (actu->next->data->operation == '(' &&
				actu->next->next->next->next->next->data->operation == ')')
		{
			temp = operation_treatment(actu->next->next->next->data->operation,
				actu->next->next->data->value,
				actu->next->next->next->next->data->value);
			ft_remove_nextn(actu->next, 4);
			actu->next->data->is_number = 1;
			actu->next->data->value = temp;
			return ;
		}
	}
	check_state1(actu->next);
}

void	check_state2(t_list *actu)
{
	int		temp;
	char	c;
	int		pattern[5];

	set_pattern(3, pattern);
	if (is_nextn_exist(actu, 4) == 0)
		return ;
	if (is_pattern_match(actu, pattern) == 1)
	{
		c = actu->next->next->data->operation;
		if (c == '+' || c == '-')
		{
			c = actu->next->next->next->next->data->operation;
			if (c != '*' && c != '/' && c != '%')
			{
				temp = operation_treatment(actu->next->next->data->operation,
						actu->next->data->value,
						actu->next->next->next->data->value);
				ft_remove_nextn(actu->next, 2);
				actu->next->data->value = temp;
				return ;
			}
		}
	}
	check_state2(actu->next);
}

void	check_state3(t_list *actu)
{
	int		temp;
	int		pattern[4];

	set_pattern(4, pattern);
	if (is_nextn_exist(actu, 3) == 0)
		return ;
	if (is_pattern_match(actu, pattern) == 1)
	{
		if (actu->next->data->operation == '(' &&
				actu->next->next->next->data->operation == ')')
		{
			temp = actu->next->next->data->value;
			ft_remove_nextn(actu->next, 2);
			actu->next->data->is_number = 1;
			actu->next->data->value = temp;
			return ;
		}
	}
	check_state3(actu->next);
}

void	check_state4(t_list *actu)
{
	int		temp;

	if (ft_list_size(actu) == 4)
	{
		temp = operation_treatment(actu->next->next->data->operation,
				actu->next->data->value,
				actu->next->next->next->data->value);
		ft_remove_nextn(actu->next, 2);
		actu->next->data->is_number = 1;
		actu->next->data->value = temp;
	}
}
