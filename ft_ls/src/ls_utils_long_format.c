/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_utils_long_format.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 19:25:40 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/11 19:26:26 by jpriou           ###   ########.fr       */
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
		return ('?');
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

static char		*build_access_right(mode_t st_mode)
{
	char	*res;

	res = ft_strnew(9);
	res[0] = (st_mode & S_IRUSR) ? 'r' : '-';
	res[1] = (st_mode & S_IWUSR) ? 'w' : '-';
	res[2] = (st_mode & S_IXUSR) ? 'x' : '-';
	res[3] = (st_mode & S_IRGRP) ? 'r' : '-';
	res[4] = (st_mode & S_IWGRP) ? 'w' : '-';
	res[5] = (st_mode & S_IXGRP) ? 'x' : '-';
	res[6] = (st_mode & S_IROTH) ? 'r' : '-';
	res[7] = (st_mode & S_IWOTH) ? 'w' : '-';
	res[8] = (st_mode & S_IXOTH) ? 'x' : '-';
	return (res);
}

static char		*build_date(struct stat my_stat)
{
	char	*res;
	char	*time_from_ctime;
	time_t	actual_time;

	res = ft_strsetnew(12, ' ');
	time_from_ctime = ctime(&(my_stat.st_mtimespec.tv_sec));
	ft_strncpy(res, time_from_ctime + 4, 3);
	ft_strncpy(res + 4, time_from_ctime + 8, 2);
	actual_time = time(0);
	if (ft_abs(actual_time - my_stat.st_mtimespec.tv_sec) < 3600 * 24 * 180)
		ft_strncpy(res + 7, time_from_ctime + 11, 5);
	else
		ft_strncpy(res + 8, time_from_ctime + 20, 4);
	return (res);
}

void			display_l_option(void *content)
{
	t_file_content	*tmp;
	char			*permissions;
	char			*date;

	tmp = (t_file_content *)content;
	permissions = build_access_right(tmp->stat_file->st_mode);
	date = build_date(*(tmp->stat_file));
	ft_printf("%c%s %3d %s  %s %6d %s %s\n",
				get_idchar_from_type_file(tmp->stat_file->st_mode),
				permissions,
				tmp->stat_file->st_nlink,
				getpwuid(tmp->stat_file->st_uid)->pw_name,
				getgrgid(tmp->stat_file->st_gid)->gr_name,
				tmp->stat_file->st_size,
				date,
				tmp->name_file);
	free(permissions);
	free(date);
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
