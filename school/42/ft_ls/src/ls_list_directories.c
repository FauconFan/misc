/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_list_directories.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 08:27:25 by fauconfan         #+#    #+#             */
/*   Updated: 2017/12/13 10:05:22 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void							ls_fill_list_actu_properly(
										int flags,
										struct dirent *dirent_actu,
										t_list_directory *list_actu,
										char *name_directory)
{
	t_file_content	*elem;

	if ((flags & FLAG_A_MIN) == FALSE)
	{
		if ((flags & FLAG_A_MAJ) == FALSE && *(dirent_actu->d_name) == '.')
			return ;
		else
		{
			if (ft_strcmp(dirent_actu->d_name, ".") == 0 ||
				ft_strcmp(dirent_actu->d_name, "..") == 0)
				return ;
		}
	}
	elem = ls_new_file_content(dirent_actu,
			name_directory, dirent_actu->d_name);
	ft_lstmerge_nocpy(&(list_actu->dir_content),
		(void *)elem,
		get_sort_function(flags));
	update_max_values(list_actu->max_values, *(elem->stat_file), flags);
}

static void							ls_list_recu(
										int flags,
										char *name_directory,
										t_list_directory *list_actu)
{
	t_tmp_recu		*tmp;

	ft_memcheck((tmp = (t_tmp_recu *)malloc(sizeof(t_tmp_recu))));
	tmp->name_parent_folder = name_directory;
	tmp->flags = flags;
	ft_lstiterparam(list_actu->dir_content, tmp, display_recursively);
	free(tmp);
}

static void							display_header_if_needed(
										t_bool display_return_line,
										t_bool display_name_directory,
										char *name_directory)
{
	if (display_return_line)
		ft_printf("\n");
	if (display_name_directory)
		ft_printf("%s:\n", name_directory);
}

static t_list_directory				*init_new_list_directory(
										char *name_directory,
										int flags)
{
	t_list_directory			*res;
	struct dirent				*dirent_actu;

	ft_memcheck((res = (t_list_directory *)malloc(sizeof(t_list_directory))));
	if ((res->dir_actu = opendir(name_directory)) == 0)
		ft_dprintf(2, "ft_ls: %s: %s\n", name_directory, strerror(errno));
	else
	{
		res->name_directory = name_directory;
		res->max_values = init_max_values();
		res->dir_content = 0;
		res->flags = flags;
		while ((dirent_actu = readdir(res->dir_actu)) != 0)
			ls_fill_list_actu_properly(flags, dirent_actu, res,
					name_directory);
	}
	return (res);
}

void								ls_list_directories(
										int flags,
										char *name_directory,
										t_bool display_name,
										t_bool display_ret)
{
	t_list_directory			*list_actu;

	display_header_if_needed(display_ret, display_name, name_directory);
	list_actu = init_new_list_directory(name_directory, flags);
	if (list_actu->dir_actu != 0)
	{
		display_total_blocks_if_need(flags, list_actu->dir_content);
		ft_lstiterparam(list_actu->dir_content,
			list_actu, flag_manager(flags));
		if (flags & FLAG_R_MAJ)
			ls_list_recu(flags, name_directory, list_actu);
		ft_lstfreeall(&(list_actu->dir_content), free_new_file_content);
		free(list_actu->max_values);
		if (closedir(list_actu->dir_actu) == -1)
			ft_dprintf(2, "%s\n", strerror(errno));
	}
	free(list_actu);
}
