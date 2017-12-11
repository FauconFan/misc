/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_list_directories.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 08:27:25 by fauconfan         #+#    #+#             */
/*   Updated: 2017/12/11 19:25:14 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ls_fill_list_actu_properly(
					int flags,
					struct dirent *dirent_actu,
					t_list_directory *list_actu,
					char *name_directory)
{
	if (*(dirent_actu->d_name) == '.' && (flags & FLAG_A_MIN) == FALSE)
		return ;
	ft_lstmerge_nocpy(&(list_actu->dir_content),
		(void *)ls_new_file_content(dirent_actu,
					name_directory, dirent_actu->d_name),
		get_sort_function(flags));
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
					t_bool display_name_directory,
					t_bool display_return_line)
{
	t_list_directory	*list_actu;
	struct dirent		*dirent_actu;

	if (display_return_line)
		ft_printf("\n");
	if (display_name_directory)
		ft_printf("%s:\n", name_directory);
	ft_memcheck((list_actu =
		(t_list_directory *)malloc(sizeof(t_list_directory))));
	list_actu->dir_actu = opendir(name_directory);
	list_actu->dir_content = 0;
	while ((dirent_actu = readdir(list_actu->dir_actu)) != 0)
		ls_fill_list_actu_properly(flags, dirent_actu, list_actu,
				name_directory);
	display_total_blocks_if_need(flags, list_actu->dir_content);
	ft_lstiter(list_actu->dir_content, flag_manager(flags));
	if (flags & FLAG_R_MAJ)
		ls_list_recu(flags, name_directory, list_actu);
	ft_lstfreeall(&(list_actu->dir_content), free_new_file_content);
	free(list_actu);
}
