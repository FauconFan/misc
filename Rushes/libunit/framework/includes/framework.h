/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   framework.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 14:19:55 by dwald             #+#    #+#             */
/*   Updated: 2017/11/26 16:21:41 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAMEWORK_H
# define FRAMEWORK_H

# include <sys/wait.h>
# include <stdlib.h>
# include "libft_unit_tests.h"

# define ANSI_GREEN "\u001b[32m"

/*
** --------------------------- typedef structs -----------------------------
** char *name do not free (t_unit_test)
** chat *name_single_test do not free (t_test)
*/

typedef	struct				s_test
{
	char					*name_single_test;
	int						success;
	int						signal;
	struct s_test			*next;
	int						(*fptr)();
}							t_test;

typedef	struct				s_unit_test
{
	char					*name;
	t_test					*functions;
}							t_unit_test;

/*
** --------------------------- utilities functions ------------------------
*/

t_test						*ft_new_node(int (*fptr)(), char *name_single_test);
void						ft_add_node(t_test *alst, t_test *new);

void						test_function(t_test *test);

void						print_result();
void						print_result_unit_test(t_unit_test *loader);
void						free_unit_test(t_unit_test *ut);
void						free_all_functions_tests(t_test *ptr);

/*
** --------------------------- test functions -----------------------------
*/

void						init_tests(t_unit_test **loader, char *name_test);
void						load_test(
					t_unit_test *loader, char *name_single_test, int (*fptr)());
void						finish_tests(t_unit_test *loader);

#endif
