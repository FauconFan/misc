/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_env_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 09:45:52 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/11 08:20:20 by fauconfan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		handle_flags(t_env_ls *env_ls, char c)
{
	if (c == 'R')
		env_ls->flags += FLAG_R_MAJ * (env_ls->flags & FLAG_R_MAJ);
	else if (c == 'a')
		env_ls->flags += FLAG_A_MIN * (env_ls->flags & FLAG_A_MIN);
	else if (c == 'l')
		env_ls->flags += FLAG_L_MIN * (env_ls->flags & FLAG_L_MIN);
	else if (c == 'r')
		env_ls->flags += FLAG_R_MIN * (env_ls->flags & FLAG_R_MIN);
	else if (c == 't')
		env_ls->flags += FLAG_T_MIN * (env_ls->flags & FLAG_T_MIN);
	else
		ls_display_usage(c, env_ls);
}

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

static void		fill_file_names(t_env_ls *env_ls, int *argc, char ***argv)
{
	struct stat	*stats;
	int			index;

	(void)env_ls;
	index = 0;
	while (index < *argc)
	{
		ft_memcheck((stats = (struct stat *)malloc(sizeof(struct stat))));
		if (lstat(argv[0][index], stats) == -1)
		{
			ft_lstmerge_nocpy(&(env_ls->list_error_files),
				(void *)ls_new_error_file(argv[0][index]),
				cmp_error_files);
			free(stats);
		}
		else
		{
			ft_lstmerge_nocpy(&(env_ls->list_contents_args),
				(void *)ls_new_content_args(stats, argv[0][index]),
				cmp_content_args);
		}
		index++;
	}
	*argc = 0;
	*argv = 0;
}

t_env_ls		*init_ls_env(int *argc, char ***argv)
{
	t_env_ls	*res;

	ft_memcheck((res = (t_env_ls *)malloc(sizeof(t_env_ls))));
	res->flags = 0;
	fill_flags(res, argc, argv);
	res->list_contents_args = 0;
	res->list_error_files = 0;
	fill_file_names(res, argc, argv);
	return (res);
}

void			free_ls_env(t_env_ls **env)
{
	ft_lstfreeall(&((*env)->list_error_files), free_error_file);
	ft_lstfreeall(&((*env)->list_contents_args), free_new_content_file);
	free(*env);
	*env = 0;
}
