/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_file_content_utils2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 16:08:31 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/12 18:37:30 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_simple_ptr	flag_manager(int flags)
{
	if (flags & FLAG_L_MIN)
		return (display_l_option);
	return (display_name_simply);
}

char			*add_slash_next_to_folder_name(char *name_folder)
{
	char	*new_name;
	int		len_folder_name;

	len_folder_name = ft_strlen(name_folder);
	new_name = ft_strnew(len_folder_name + 1);
	ft_strncpy(new_name, name_folder, len_folder_name);
	new_name[len_folder_name] = '/';
	return (new_name);
}

void			display_name_simply(void *content, void *param)
{
	t_file_content		*tmp;
	t_list_directory	*ld;
	char				*new_name;

	ld = (t_list_directory *)param;
	tmp = (t_file_content *)content;
	if ((ld->flags & FLAG_P_MIN) && S_ISDIR(tmp->stat_file->st_mode))
	{
		new_name = add_slash_next_to_folder_name(tmp->name_file);
		ft_printf("%s\n", new_name);
		free(new_name);
	}
	else
		ft_printf("%s\n", tmp->name_file);
}

t_bool			check_if_a_file_is_readable_as_a_folder(char *name_file)
{
	struct stat		stats;
	char			buff[255];
	ssize_t			ret;

	if ((stat(name_file, &stats)) == -1)
		return (FALSE);
	if (S_ISDIR(stats.st_mode))
		return (TRUE);
	else if (S_ISLNK(stats.st_mode))
	{
		ft_bzero(buff, 255);
		ret = readlink(name_file, buff, 255);
		if (ret > 255)
			return (FALSE);
		buff[ret] = 0;
		stat(buff, &stats);
		return (S_ISDIR(stats.st_mode));
	}
	return (FALSE);
}
