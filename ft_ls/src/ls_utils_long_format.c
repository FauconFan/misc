/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_utils_long_format.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 19:25:40 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/11 21:01:28 by jpriou           ###   ########.fr       */
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
	time_t	actual_time;
	char	**time_from_ctime;

	res = ft_strsetnew(12, ' ');
	time_from_ctime = ft_strsplit(ctime(&(my_stat.st_mtimespec.tv_sec)), ' ');
	ft_strncpy(res, time_from_ctime[1], 3);
	ft_strncpy(res + 4 + (ft_strlen(time_from_ctime[2]) == 1),
					*(time_from_ctime + 2),
					1 + (ft_strlen(time_from_ctime[2]) != 1));
	actual_time = time(0);
	if (ft_abs(actual_time - my_stat.st_mtimespec.tv_sec) < 3600 * 24 * 180)
		ft_strncpy(res + 7, time_from_ctime[3], 5);
	else
		ft_strncpy(res + 8, time_from_ctime[4], ft_strlen(time_from_ctime[4]) - 1);
	return (res);
}

static char		*build_name(struct stat my_stat, char *name_file)
{
	ssize_t		ret;
	char		*buff;
	char		*tmp;

	if (S_ISLNK(my_stat.st_mode))
	{
		buff = ft_strnew(255);
		ret = readlink(name_file, buff, 255);
		if (ret > 255)
		{
			ft_putendl(WARNING_SNA);
			exit(2);
		}
		buff[ret] = 0;
		tmp = ft_strjoin(" -> ", buff);
		free(buff);
		buff = ft_strjoin(name_file, tmp);
		free(tmp);
		return (buff);
	}
	return (ft_strdup(name_file));
}

void			display_l_option(void *content, void *param)
{
	t_file_content				*tmp;
	char						*permissions;
	char						*date;
	char						*name;
	t_max_values_long_format	*max_values;

	max_values = (t_max_values_long_format *)param;
	tmp = (t_file_content *)content;
	permissions = build_access_right(tmp->stat_file->st_mode);
	date = build_date(*(tmp->stat_file));
	name = build_name(*(tmp->stat_file), tmp->name_file);
	ft_printf("%c%s %*d %s  %s %*d %s %s\n",
				get_idchar_from_type_file(tmp->stat_file->st_mode),
				permissions,
				max_values->max_st_nlink + 1, tmp->stat_file->st_nlink,
				getpwuid(tmp->stat_file->st_uid)->pw_name,
				getgrgid(tmp->stat_file->st_gid)->gr_name,
				max_values->max_st_size + 1, tmp->stat_file->st_size,
				date,
				name);
	free(permissions);
	free(date);
	free(name);
}
