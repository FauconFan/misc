/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_file_content_utils2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 16:08:31 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/12 09:24:15 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_simple_ptr	flag_manager(int flags)
{
	if (flags & FLAG_L_MIN)
		return (display_l_option);
	return (display_name_simply);
}

void			display_name_simply(void *content, void *param)
{
	t_file_content	*tmp;

	(void)param;
	tmp = (t_file_content *)content;
	ft_printf("%s\n", tmp->name_file);
}

void			display_total_blocks_if_need(int flags, t_list *dir_content)
{
	t_file_content	*tmp;
	int				size_tot;

	if (flags & FLAG_L_MIN)
	{
		size_tot = 0;
		tmp = (t_file_content *)dir_content->content;
		while (1)
		{
			size_tot += tmp->stat_file->st_blocks;
			if ((dir_content = dir_content->next) == 0)
				break ;
			tmp = (t_file_content *)dir_content->content;
		}
		ft_printf("total %d\n", size_tot);
	}
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
