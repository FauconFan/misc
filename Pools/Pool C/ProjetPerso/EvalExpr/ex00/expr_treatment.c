/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expr_treatment.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 09:46:42 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/20 14:55:10 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "functions.h"

int		is_nextn_exist(t_list *actu, int n)
{
	if (actu == 0 || actu->next == 0)
		return (0);
	actu = actu->next;
	while (n > 0)
	{
		if (actu == 0)
			return (0);
		actu = actu->next;
		n--;
	}
	return (1);
}

int		is_pattern_match(t_list *actu, int *pattern)
{
	if (actu == 0 || actu->next == 0)
		return (0);
	actu = actu->next;
	while (actu != 0 && *pattern != -1)
	{
		if (actu->data->is_number != *pattern)
			return (0);
		pattern++;
		actu = actu->next;
	}
	return (1);
}

void	check_no_operand_parenthesis(t_list *actu)
{
	t_list	*tmp;
	char	c;

	if (actu == 0 || actu->next == 0 || actu->next->next == 0)
		return ;
	if (actu->next->next->data->is_number == 0 &&
			actu->next->next->data->operation == '(')
	{
		c = actu->next->data->operation;
		if (actu->next->data->is_number == 1 ||
				(actu->next->data->is_number == 0 &&
				c != '+' && c != '-' && c != '*' &&
				c != '/' && c != '%'))
		{
			tmp = actu->next->next;
			actu->next->next = ft_create_elem("*");
			actu->next->next->next = tmp;
		}
	}
	check_no_operand_parenthesis(actu->next);
}

char	*rm_beg_end(char *str)
{
	str++;
	str[ft_strlen(str) - 1] = 0;
	return (str);
}

char	*remove_unused_parenthesis(char *str)
{
	int		index;
	int		to_ignore;

	if (*str != '(')
		return (str);
	index = 1;
	to_ignore = 0;
	while (str[index] != 0)
	{
		if (str[index] == ')')
		{
			if (to_ignore == 0)
			{
				if (index == ft_strlen(str) - 1)
					return (remove_unused_parenthesis(rm_beg_end(str)));
				return (str);
			}
			else
				to_ignore--;
		}
		else if (str[index] == '(')
			to_ignore++;
		index++;
	}
	return (str);
}
