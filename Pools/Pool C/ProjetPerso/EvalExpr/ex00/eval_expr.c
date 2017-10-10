/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 11:11:16 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/20 18:48:56 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include "ft_list.h"

int		eval_expr_recu(t_list *beginning)
{
	check_state4(beginning);
	if (ft_list_size(beginning) == 2)
		return (beginning->next->data->value);
	check_state3(beginning);
	check_state0(beginning);
	check_state3(beginning);
	check_state2(beginning);
	check_state3(beginning);
	check_state1(beginning);
	return (eval_expr_recu(beginning));
}

int		eval_expr(char *str)
{
	t_list	*begining;

	str = remove_unused_parenthesis(str);
	begining = ft_build_expr(str);
	check_no_operand_parenthesis(begining);
	if (begining == 0)
		return (0);
	return (eval_expr_recu(begining));
}
