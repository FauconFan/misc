/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_list_directories.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 08:27:25 by fauconfan         #+#    #+#             */
/*   Updated: 2017/12/11 13:13:12 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		(*get_adapted_function(int flags))(void *d1, void *d2)
{
	if (flags & FLAG_T_MIN && flags & FLAG_R_MIN)
		return (ls_sort_by_last_time_modified_reverse);
	else if (flags & FLAG_T_MIN)
		return (ls_sort_by_last_time_modified);
	else if (flags & FLAG_R_MIN)
		return (ls_sort_by_file_name_reverse);
	return (ls_sort_by_file_name);
}

static void		ls_fill_list_actu_properly(
					int flags,
					struct dirent *dirent_actu,
					t_list_directory *list_actu,
					char *name_directory)
{
	if (*(dirent_actu->d_name) == '.' && (flags & FLAG_A_MIN) == False)
		return ;
	ft_lstmerge_nocpy(&(list_actu->dir_content),
		(void *)ls_new_file_content(dirent_actu, name_directory),
		get_adapted_function(flags));
}

static void		ls_list_recu(
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

void			ls_list_directories(
					int flags,
					char *name_directory,
					t_bool display_name_directory)
{
	t_list_directory	*list_actu;
	struct dirent		*dirent_actu;

	ft_printf("\n");
	if (display_name_directory)
		ft_printf("%s:\n", name_directory);
	ft_memcheck((list_actu =
		(t_list_directory *)malloc(sizeof(t_list_directory))));
	list_actu->dir_actu = opendir(name_directory);
	list_actu->dir_content = 0;
	while ((dirent_actu = readdir(list_actu->dir_actu)) != 0)
		ls_fill_list_actu_properly(flags, dirent_actu, list_actu, name_directory);
	ft_lstiter(list_actu->dir_content, display_name_simply);
	if (flags & FLAG_R_MAJ)
		ls_list_recu(flags, name_directory, list_actu);
	ft_lstfreeall(&(list_actu->dir_content), free_new_file_content);
	free(list_actu);
}