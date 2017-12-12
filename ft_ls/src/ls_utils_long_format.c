/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_utils_long_format.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 19:25:40 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/12 19:43:47 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char		get_idchar_from_type_file(mode_t st_mode)
{
	if (S_ISFIFO(st_mode))
		return ('p');
	else if (S_ISCHR(st_mode))
		return ('c');
	else if (S_ISDIR(st_mode))
		return ('d');
	else if (S_ISBLK(st_mode))
		return ('b');
	else if (S_ISREG(st_mode))
		return ('-');
	else if (S_ISLNK(st_mode))
		return ('l');
	else if (S_ISSOCK(st_mode))
		return ('s');
	else if (S_ISWHT(st_mode))
		return ('?');
	return ('$');
}

void			display_total_blocks_if_need(int flags, t_list *dir_content)
{
	t_file_content	*tmp;
	int				size_tot;

	if (flags & FLAG_L_MIN && dir_content != 0)
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

void			display_l_option(void *content, void *param)
{
	t_file_content				*tmp;
	t_list_directory			*ld;
	char						**builted_str;
	int							index;

	tmp = (t_file_content *)content;
	ld = (t_list_directory *)param;
	builted_str = build_all_strings_long_format(*(tmp->stat_file),
							ld->name_directory, tmp->name_file, ld->flags);
	ft_printf("%c%s  %*d %-*s  %-*s  %*s %s %s\n",
		get_idchar_from_type_file(tmp->stat_file->st_mode), builted_str[0],
		ld->max_values->max_st_nlink, tmp->stat_file->st_nlink,
		ld->max_values->max_len_user_id, builted_str[3],
		ld->max_values->max_len_group_id, builted_str[4],
		ld->max_values->max_st_size, builted_str[5],
		builted_str[1],
		builted_str[2]);
	index = -1;
	while (builted_str[++index])
		free(builted_str[index]);
	free(builted_str);
}
