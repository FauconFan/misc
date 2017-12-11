/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 12:10:59 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/11 19:24:58 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		fill_is_all_empty(t_env_ls *env_ls)
{
	struct stat	*stats;

	if (ft_lstsize(env_ls->list_error_files) == 0 &&
		ft_lstsize(env_ls->list_contents_args) == 0)
	{
		ft_memcheck((stats = (struct stat *)malloc(sizeof(struct stat))));
		lstat("./", stats);
		ft_lstaddfront_nocpy(&(env_ls->list_contents_args),
				(void *)ls_new_file_content(0, "./", ""));
	}
}

void			ls_display_usage(char illegal_option, t_env_ls *env_ls)
{
	free_ls_env(&env_ls);
	ft_printf("ft_ls: illegal option -- %c\n", illegal_option);
	ft_printf("usage: ft_ls [-Ralrt] [file ...]\n");
	exit(1);
}

void			ls_list_files_only(t_env_ls *env_ls)
{
	t_list			*list_contents_args;
	t_file_content	*content_args;
	t_file_content	*file_content;

	list_contents_args = env_ls->list_contents_args;
	while (list_contents_args != 0)
	{
		content_args = list_contents_args->content;
		if ((S_ISDIR(content_args->stat_file->st_mode)) == FALSE)
		{
			ft_memcheck((file_content =
					(t_file_content *)malloc(sizeof(t_file_content))));
			file_content->name_file = content_args->name_file;
			file_content->stat_file = content_args->stat_file;
			file_content->dirent_file = 0;
			flag_manager(env_ls->flags)(file_content);
			free(file_content);
		}
		list_contents_args = list_contents_args->next;
	}
}

void			ls_list_directories_only(t_env_ls *env_ls)
{
	t_list			*list_contents_args;
	t_file_content	*content_args;

	list_contents_args = env_ls->list_contents_args;
	while (list_contents_args != 0)
	{
		content_args = list_contents_args->content;
		if ((S_ISDIR(content_args->stat_file->st_mode)))
			ls_list_directories(env_ls->flags,
				content_args->name_file, TRUE, TRUE);
		list_contents_args = list_contents_args->next;
	}
}

int				main(int argc, char **argv)
{
	t_env_ls	*env_ls;

	argc--;
	argv++;
	env_ls = init_ls_env(&argc, &argv);
	ft_lstiter(env_ls->list_error_files, display_error);
	fill_is_all_empty(env_ls);
	ls_list_files_only(env_ls);
	ls_list_directories_only(env_ls);
	free_ls_env(&env_ls);
	return (0);
}
