/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 09:17:25 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/26 16:00:11 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "framework.h"

void		init_tests(t_unit_test **loader, char *name_test)
{
	t_unit_test		*res;

	if ((res = (t_unit_test *)malloc(sizeof(t_unit_test))) == 0)
		exit(1);
	res->name = name_test;
	res->functions = 0;
	*loader = res;
	my_putstr("\n### ");
	my_putstr(res->name);
	my_putstr(" ###\n\t");
}

void		load_test(t_unit_test *loader,
				char *name_single_test,
				int (*fptr)())
{
	t_test		*next_test;

	next_test = ft_new_node(fptr, name_single_test);
	if (loader->functions == 0)
		loader->functions = next_test;
	else
		ft_add_node(loader->functions, next_test);
	test_function(next_test);
}

void		finish_tests(t_unit_test *loader)
{
	print_result_unit_test(loader);
	free_unit_test(loader);
}

void		print_result(void)
{
	my_putstr("\nAll is good !\n");
}
