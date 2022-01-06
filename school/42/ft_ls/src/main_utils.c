/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 16:46:15 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/13 08:44:30 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			display_for_only_file(
						t_file_content *content_args,
						t_max_values_long_format *max_values,
						int flags)
{
	t_file_content		*file_content;
	t_list_directory	*ld;

	ft_memcheck((file_content =
			(t_file_content *)malloc(sizeof(t_file_content))));
	file_content->name_file = content_args->name_file;
	file_content->stat_file = content_args->stat_file;
	file_content->dirent_file = 0;
	ft_memcheck((ld = (t_list_directory *)malloc(sizeof(t_list_directory))));
	ld->name_directory = "";
	ld->max_values = max_values;
	flag_manager(flags)(file_content, ld);
	free(ld);
	free(file_content);
}

int					ls_list_files_only(
					t_env_ls *env_ls,
					t_max_values_long_format *max_values)
{
	t_list			*list_contents_args;
	t_file_content	*content_args;
	int				ret;

	ret = 0;
	list_contents_args = env_ls->list_contents_args;
	while (list_contents_args != 0)
	{
		content_args = list_contents_args->content;
		if ((env_ls->flags & FLAG_D_MIN) ||
			check_if_a_file_is_readable_as_a_folder(content_args->name_file)
			== FALSE)
		{
			display_for_only_file(content_args, max_values, env_ls->flags);
			ret = 1;
		}
		list_contents_args = list_contents_args->next;
	}
	return (ret);
}

void				ls_list_directories_only(
						t_env_ls *env_ls,
						int ret_files_only)
{
	t_list			*list_contents_args;
	t_file_content	*content_args;
	t_bool			display_name_directory;
	t_bool			display_new_line;

	list_contents_args = env_ls->list_contents_args;
	display_name_directory = (ret_files_only == 1 ||
		ft_lstsize(env_ls->list_contents_args) >= 2 ||
		ft_lstsize(env_ls->list_error_files) != 0) ? TRUE : FALSE;
	display_new_line = (ret_files_only == 1) ? TRUE : FALSE;
	while (list_contents_args != 0)
	{
		content_args = list_contents_args->content;
		if (((env_ls->flags & FLAG_D_MIN) == FALSE) &&
			check_if_a_file_is_readable_as_a_folder(content_args->name_file))
		{
			ls_list_directories(env_ls->flags, content_args->name_file,
				display_name_directory, display_new_line);
			display_name_directory = TRUE;
			display_new_line = TRUE;
		}
		list_contents_args = list_contents_args->next;
	}
}
