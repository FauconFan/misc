/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_test_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 11:14:45 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/26 17:05:59 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework.h"

static char	*treat_error_signal(t_test *tmp)
{
	if (tmp->success == 0)
		return ("OK !");
	if (tmp->signal == SIGSEGV)
		return ("SIGV");
	else if (tmp->signal == SIGBUS)
		return ("BUSE");
	else if (tmp->signal == SIGABRT)
		return ("ABRT");
	return ("KO !");
}

void		free_unit_test(t_unit_test *ut)
{
	free_all_functions_tests(ut->functions);
	free(ut);
}

void		free_all_functions_tests(t_test *ptr)
{
	if (ptr != 0)
	{
		free_all_functions_tests(ptr->next);
		free(ptr);
	}
}

void		print_result_unit_test(t_unit_test *loader)
{
	t_test	*tmp;
	char	*ret;

	tmp = loader->functions;
	while (tmp)
	{
		my_putstr("[");
		ret = treat_error_signal(tmp);
		if (my_strcmp(ret, "OK !") == 0)
			my_putstr("\e[1m\e[32m");
		else
			my_putstr("\e[1m\e[31m");
		my_putstr(ret);
		my_putstr("\e[39m\e[0m] <== ");
		my_putstr(tmp->name_single_test);
		my_putstr("\n\t");
		tmp = tmp->next;
	}
}
