/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 12:10:59 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/12 16:47:53 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		fill_is_all_empty(t_env_ls *env_ls)
{
	if (ft_lstsize(env_ls->list_error_files) == 0 &&
		ft_lstsize(env_ls->list_contents_args) == 0)
	{
		ft_lstaddfront_nocpy(&(env_ls->list_contents_args),
				(void *)ls_new_file_content(0, "", "./"));
	}
}

void			ls_display_usage(char illegal_option, t_env_ls *env_ls)
{
	free_ls_env(&env_ls);
	ft_dprintf(2, "ft_ls: illegal option -- %c\n", illegal_option);
	ft_dprintf(2, "usage: ft_ls [-1Ralrt] [file ...]\n");
	exit(1);
}

int				main(int argc, char **argv)
{
	t_env_ls					*env_ls;
	t_max_values_long_format	*max_values;
	int							ret_files_only;
	int							ret;

	argc--;
	argv++;
	max_values = init_max_values();
	env_ls = init_ls_env(&argc, &argv, max_values);
	ft_lstiter(env_ls->list_error_files, display_error);
	fill_is_all_empty(env_ls);
	ret_files_only = ls_list_files_only(env_ls, max_values);
	ls_list_directories_only(env_ls, ret_files_only);
	free_max_values(&max_values);
	ret = ft_lstsize(env_ls->list_error_files) != 0;
	free_ls_env(&env_ls);
	return (ret);
}
