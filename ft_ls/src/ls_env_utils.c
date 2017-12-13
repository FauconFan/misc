/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_env_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 09:45:52 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/13 08:45:25 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		fill_flags(t_env_ls *env_ls, int *argc, char ***argv)
{
	int		index;
	int		index_argv;

	index = 0;
	while (index < *argc)
	{
		if (argv[0][index][0] != '-' || ft_strcmp(argv[0][index], "-") == 0
			|| (ft_strcmp(argv[0][index], "--") == 0 && ++index))
			break ;
		index_argv = 0;
		while (argv[0][index][++index_argv] != 0)
			handle_flags(env_ls, argv[0][index][index_argv]);
		index++;
	}
	*argc = *argc - index;
	*argv = *argv + index;
}

static void		fill_file_names(
					t_env_ls *env_ls,
					int *argc,
					char ***argv,
					t_max_values_long_format *max_values)
{
	struct stat			*stats;
	int					index;
	t_file_content		*new_file_content;

	index = 0;
	while (index < *argc)
	{
		ft_memcheck((stats = (struct stat *)malloc(sizeof(struct stat))));
		if (lstat(argv[0][index], stats) == -1)
		{
			ft_lstmerge_nocpy(&(env_ls->list_error_files),
				(void *)ls_new_error_file(argv[0][index]),
				cmp_error_files);
		}
		else
		{
			new_file_content = ls_new_file_content(0, "", argv[0][index]);
			ft_lstmerge_nocpy(&(env_ls->list_contents_args),
				(void *)new_file_content,
				get_sort_function(env_ls->flags));
			update_max_values(max_values, *stats, env_ls->flags);
		}
		free(stats);
		index++;
	}
}

t_env_ls		*init_ls_env(
					int *argc,
					char ***argv,
					t_max_values_long_format *max_values)
{
	t_env_ls	*res;

	ft_memcheck((res = (t_env_ls *)malloc(sizeof(t_env_ls))));
	res->flags = 0;
	res->list_contents_args = 0;
	res->list_error_files = 0;
	fill_flags(res, argc, argv);
	fill_file_names(res, argc, argv, max_values);
	*argc = 0;
	*argv = 0;
	return (res);
}

void			free_ls_env(t_env_ls **env)
{
	ft_lstfreeall(&((*env)->list_error_files), free_error_file);
	ft_lstfreeall(&((*env)->list_contents_args), free_new_file_content);
	free(*env);
	*env = 0;
}
