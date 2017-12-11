/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 12:10:59 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/11 13:08:18 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ls_display_usage(char illegal_option, t_env_ls *env_ls)
{
	free_ls_env(&env_ls);
	ft_printf("ft_ls: illegal option -- %c\n", illegal_option);
	ft_printf("usage: ft_ls [-Ralrt] [file ...]\n");
	exit(1);
}

int		main(int argc, char **argv)
{
	t_env_ls	*env_ls;

	argc--;
	argv++;
	env_ls = init_ls_env(&argc, &argv);
	ft_lstiter(env_ls->list_error_files, display_error);
	ft_lstiterparam(env_ls->list_contents_args, env_ls, display_content);
	ls_list_directories(env_ls->flags, "./", True);
	free_ls_env(&env_ls);
	return (0);
}
