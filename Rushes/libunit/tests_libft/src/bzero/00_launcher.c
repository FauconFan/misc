/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 15:05:16 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/26 15:49:00 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_libft.h"

void	bzero_launcher(void)
{
	t_unit_test		*loader_bzero;

	init_tests(&loader_bzero, "bzero");
	load_test(loader_bzero, "basic_test_1", &basic_test_bzero01);
	load_test(loader_bzero, "basic_test_2", &basic_test_bzero02);
	finish_tests(loader_bzero);
}
