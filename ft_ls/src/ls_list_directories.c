/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_list_directories.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 08:27:25 by fauconfan         #+#    #+#             */
/*   Updated: 2017/12/11 20:42:39 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void							ls_fill_list_actu_properly(
										int flags,
										struct dirent *dirent_actu,
										t_list_directory *list_actu,
										char *name_directory,
										t_max_values_long_format *max_values)
{
	t_file_content	*elem;

	elem = ls_new_file_content(dirent_actu,
					name_directory, dirent_actu->d_name);
	if (*(dirent_actu->d_name) == '.' && (flags & FLAG_A_MIN) == FALSE)
		return ;
	ft_lstmerge_nocpy(&(list_actu->dir_content),
		(void *)elem,
		get_sort_function(flags));
	max_values->max_st_nlink = ft_max(max_values->max_st_nlink,
		ft_log10(elem->stat_file->st_nlink));
	max_values->max_st_size = ft_max(max_values->max_st_size,
		ft_log10(elem->stat_file->st_size));
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
}

static t_max_values_long_format		*init_max_values(void)
{
	t_max_values_long_format	*res;

	ft_memcheck((res = (t_max_values_long_format *)
			malloc(sizeof(t_max_values_long_format))));
	res->max_st_nlink = 0;
	res->max_st_size = 0;
	return (res);
}

static void							display_header_if_needed(
										t_bool display_return_line,
										t_bool display_name_directory,
										char *name_directory)
{
	if (display_return_line)
		ft_printf("\n");
	if (display_name_directory && ft_strcmp(name_directory, "./"))
		ft_printf("%s:\n", name_directory);
}

void								ls_list_directories(
										int flags,
										char *name_directory,
										t_bool display_name,
										t_bool display_ret)
{
	t_list_directory			*list_actu;
	struct dirent				*dirent_actu;
	t_max_values_long_format	*max_values;

	display_header_if_needed(display_ret, display_name, name_directory);
	ft_memcheck((list_actu =
		(t_list_directory *)malloc(sizeof(t_list_directory))));
	if ((list_actu->dir_actu = opendir(name_directory)) == 0)
		ft_printf("ft_ls: %s: %s\n", name_directory, strerror(errno));
	else
	{
		max_values = init_max_values();
		list_actu->dir_content = 0;
		while ((dirent_actu = readdir(list_actu->dir_actu)) != 0)
			ls_fill_list_actu_properly(flags, dirent_actu, list_actu,
					name_directory, max_values);
		display_total_blocks_if_need(flags, list_actu->dir_content);
		ft_lstiterparam(list_actu->dir_content,
			max_values, flag_manager(flags));
		if (flags & FLAG_R_MAJ)
			ls_list_recu(flags, name_directory, list_actu);
		ft_lstfreeall(&(list_actu->dir_content), free_new_file_content);
		free(max_values);
	}
	free(list_actu);
}
