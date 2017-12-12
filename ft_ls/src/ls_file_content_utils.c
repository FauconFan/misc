/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_file_content_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 11:20:22 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/12 09:30:15 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file_content	*ls_new_file_content(
					struct dirent *dirent_file,
					char *name_directory,
					char *name_file)
{
	t_file_content	*res;
	struct stat		*stat_file;
	char			*name_tmp;

	ft_memcheck((res = (t_file_content *)malloc(sizeof(t_file_content))));
	res->name_file = name_file;
	ft_memcheck((stat_file = (struct stat *)malloc(sizeof(struct stat))));
	name_tmp = ls_utils_build_name(name_directory, name_file);
	if (lstat(name_tmp, stat_file) == -1)
		ft_printf("%s => lstat, ls_new_file_content return -1\n", WARNING_SNA);
	res->stat_file = stat_file;
	res->dirent_file = dirent_file;
	free(name_tmp);
	return (res);
}

void			free_new_file_content(void *content)
{
	t_file_content	*tmp;

	tmp = (t_file_content *)content;
	free(tmp->stat_file);
	free(content);
}

void			display_recursively(void *content, void *param)
{
	t_file_content	*tmp;
	t_tmp_recu		*data_sample;
	char			*final_name;

	tmp = (t_file_content *)content;
	data_sample = (t_tmp_recu *)param;
	final_name = ls_utils_build_name(data_sample->name_parent_folder,
										tmp->dirent_file->d_name);
	if ((check_if_a_file_is_readable_as_a_folder(final_name)) &&
		ft_strcmp(tmp->dirent_file->d_name, ".") != 0 &&
		ft_strcmp(tmp->dirent_file->d_name, "..") != 0)
	{
		ls_list_directories(data_sample->flags, final_name, TRUE, TRUE);
	}
	free(final_name);
}

char			*ls_utils_build_name(char *name_directory, char *name_file)
{
	char	*res;
	int		length_name_directory;
	int		length_name_file;

	length_name_directory = ft_strlen(name_directory);
	length_name_file = ft_strlen(name_file);
	if (length_name_directory == 0)
		return (ft_strndup(name_file, length_name_file));
	if (name_directory[length_name_directory - 1] != '/')
	{
		res = ft_strnew(length_name_directory + length_name_file + 1);
		ft_strncpy(res, name_directory, length_name_directory);
		ft_strncpy(res + length_name_directory, "/", 1);
		ft_strncpy(res + length_name_directory + 1, name_file,
					length_name_file);
	}
	else
	{
		res = ft_strnew(length_name_directory + length_name_file);
		ft_strncpy(res, name_directory, length_name_directory);
		ft_strncpy(res + length_name_directory, name_file, length_name_file);
	}
	return (res);
}
