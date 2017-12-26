/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_file_error_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 16:47:57 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/25 20:06:35 by fauconfan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_bool	have_access_right(char *directory)
{
	struct stat		stats;

	if (lstat(directory, &stats) == -1)
		return (FALSE);
	return ((stats.st_mode & S_IXUSR));
}

static t_bool	is_folder(char *directory)
{
	struct stat		stats;

	if (lstat(directory, &stats) == -1)
		return (FALSE);
	return (S_ISDIR(stats.st_mode));
}

t_bool			is_file_exist(char *directory, char *name_file)
{
	DIR				*dir_actu;
	struct dirent	*dirent_actu;
	t_bool			res;

	res = FALSE;
	if ((dir_actu = opendir(directory)) == 0)
		return (FALSE);
	while ((dirent_actu = readdir(dir_actu)))
	{
		if (ft_strcmp(dirent_actu->d_name, name_file) == 0)
		{
			res = TRUE;
			break ;
		}
	}
	if (closedir(dir_actu) == -1)
		return (FALSE);
	return (res);
}

static int		handle_next(char *directory, char *name_file)
{
	char	*tmp;

	if (is_file_exist(directory, name_file) == FALSE)
		return (1);
	tmp = concat_dir_str(directory, name_file);
	if (is_folder(tmp) == FALSE)
	{
		free(tmp);
		return (2);
	}
	if (have_access_right(tmp) == FALSE)
	{
		free(tmp);
		return (3);
	}
	free(tmp);
	return (0);
}

char			*why_a_folder_is_unreachable(char *abs_path)
{
	char	*cpy;
	char	*tmp;
	int		size_actu;
	int		size_next;
	int		ret;

	ret = 0;
	size_actu = 1;
	while (abs_path[size_actu] != 0)
	{
		cpy = ft_strndup(abs_path, size_actu);
		size_next = 1;
		while (abs_path[size_actu + size_next] != '/')
			size_next++;
		tmp = ft_strndup(abs_path + size_actu, size_next);
		ret = handle_next(cpy, tmp);
		free(tmp);
		free(cpy);
		if (ret == 1)
			return (CST_NO_SUCH_FOUND);
		else if (ret >= 2)
			return ((ret == 2) ? CST_NOT_A_DIRECTORY : CST_PERMISSION_DENIED);
		size_actu += size_next + (abs_path[size_actu + size_next] != 0);
	}
	return (0);
}
