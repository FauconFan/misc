/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_utils_long_format.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 19:25:40 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/12 08:46:50 by jpriou           ###   ########.fr       */
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
	if (st_mode & S_ISUID)
		res[2] = (res[2] == 'x') ? 's' : 'S';
	if (st_mode & S_ISGID)
		res[5] = (res[5] == 'x') ? 's' : 'S';
	if (st_mode & S_ISVTX)
		res[8] = (res[8] == 'x') ? 't' : 'T';
	return (res);
}

static char		*build_date(struct stat my_stat)
{
	char	*res;
	time_t	actual_time;
	char	**time_from_ctime;
	int		index;

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
		ft_strncpy(res + 8, time_from_ctime[4],
				ft_strlen(time_from_ctime[4]) - 1);
	index = 0;
	while (index < 5)
	{
		free(time_from_ctime[index]);
		index++;
	}
	free(time_from_ctime);
	return (res);
}

static char		*build_name(
					struct stat my_stat,
					char *name_directory,
					char *name_file)
{
	ssize_t		ret;
	char		*buff;
	char		*tmp;
	char		*final_name;

	if (S_ISLNK(my_stat.st_mode))
	{
		buff = ft_strnew(255);
		final_name = ls_utils_build_name(name_directory, name_file);
		ret = readlink(final_name, buff, 255);
		if (ret == -1)
			ft_dprintf(2, "%s", strerror(errno));
		buff[ret] = 0;
		tmp = ft_strjoin(" -> ", buff);
		free(buff);
		buff = ft_strjoin(name_file, tmp);
		free(tmp);
		free(final_name);
		return (buff);
	}
	return (ft_strdup(name_file));
}

void			display_l_option(void *content, void *param)
{
	t_file_content				*tmp;
	t_list_directory			*ld;
	char						*builted_str[3];

	tmp = (t_file_content *)content;
	ld = (t_list_directory *)param;
	builted_str[0] = build_access_right(tmp->stat_file->st_mode);
	builted_str[1] = build_date(*(tmp->stat_file));
	builted_str[2] = build_name(*(tmp->stat_file), ld->name_directory, tmp->name_file);
	ft_printf("%c%s %*d %*s  %*s %*d %s %s\n",
		get_idchar_from_type_file(tmp->stat_file->st_mode), builted_str[0],
		ld->max_values->max_st_nlink + 1, tmp->stat_file->st_nlink,
		ld->max_values->max_len_user_id,
			getpwuid(tmp->stat_file->st_uid)->pw_name,
		ld->max_values->max_len_group_id,
			getgrgid(tmp->stat_file->st_gid)->gr_name,
		ld->max_values->max_st_size + 1, tmp->stat_file->st_size,
		builted_str[1],
		builted_str[2]);
	free(builted_str[0]);
	free(builted_str[1]);
	free(builted_str[2]);
}
