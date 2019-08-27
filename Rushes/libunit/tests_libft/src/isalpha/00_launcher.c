/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 15:09:17 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/26 15:55:20 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_libft.h"

void		isalpha_launcher(void)
{
	t_unit_test		*loader_isalpha;

	init_tests(&loader_isalpha, "isalpha");
	load_test(loader_isalpha, "basic_test_1", &basic_test_isalpha01);
	load_test(loader_isalpha, "basic_test_2", &basic_test_isalpha02);
	finish_tests(loader_isalpha);
}
