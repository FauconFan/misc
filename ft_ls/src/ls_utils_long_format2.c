/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_utils_long_format2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 16:54:11 by jpriou            #+#    #+#             */
/*   Updated: 2018/11/08 11:43:59 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char		*build_access_right(mode_t st_mode)
{
	char	*res;

	res = ft_strsetnew(10, ' ');
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

static char		*build_date(time_t time_treated)
{
	char	*res;
	time_t	actual_time;
	char	**time_from_ctime;
	int		index;

	res = ft_strsetnew(12, ' ');
	time_from_ctime = ft_strsplit(ctime(&time_treated), ' ');
	ft_strncpy(res, time_from_ctime[1], 3);
	ft_strncpy(res + 4 + (ft_strlen(time_from_ctime[2]) == 1),
					*(time_from_ctime + 2),
					1 + (ft_strlen(time_from_ctime[2]) != 1));
	actual_time = time(0);
	if (ft_abs(actual_time - time_treated) < 3600 * 24 * 180)
		ft_strncpy(res + 7, time_from_ctime[3], 5);
	else
		ft_strncpy(res + 8, time_from_ctime[4],
				ft_strlen(time_from_ctime[4]) - 1);
	index = -1;
	while (++index < 5)
		free(time_from_ctime[index]);
	free(time_from_ctime);
	return (res);
}

static char		*build_name(
					struct stat my_stat,
					char *name_directory,
					char *name_file,
					int flags)
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
			ft_dprintf(2, "%s\n", strerror(errno));
		buff[ret] = 0;
		tmp = ft_strjoin(" -> ", buff);
		free(buff);
		buff = ft_strjoin(name_file, tmp);
		free(tmp);
		free(final_name);
		return (buff);
	}
	else if (S_ISDIR(my_stat.st_mode) && (flags & FLAG_P_MIN))
	{
		return (add_slash_next_to_folder_name(name_file));
	}
	return (ft_strdup(name_file));
}

char			*build_str_size(struct stat my_stat)
{
	char	*res;
	char	*tmp;
	int		major;
	int		minor;
	int		len;

	if (S_ISCHR(my_stat.st_mode) || S_ISBLK(my_stat.st_mode))
	{
		res = ft_strsetnew(8, ' ');
		major = major(my_stat.st_rdev);
		minor = minor(my_stat.st_rdev);
		tmp = ft_itoa(minor);
		len = ft_strlen(tmp);
		ft_strncpy(res + 8 - len, tmp, len);
		free(tmp);
		res[3] = ',';
		tmp = ft_itoa(major);
		len = ft_strlen(tmp);
		ft_strncpy(res + 3 - len, tmp, len);
		free(tmp);
		return (res);
	}
	else
		return (ft_itoa(my_stat.st_size));
}

char			**build_all_strings_long_format(
					struct stat my_stat,
					char *name_directory,
					char *name_file,
					int flags)
{
	char		**res;
	time_t		handle_flag_for_date_output;

	handle_flag_for_date_output = my_stat.st_mtime;
	if (flags & FLAG_U_MAJ)
		handle_flag_for_date_output = my_stat.st_btime;
	else if (flags & FLAG_U_MIN)
		handle_flag_for_date_output = my_stat.st_atime;
	else if (flags & FLAG_C_MIN)
		handle_flag_for_date_output = my_stat.st_ctime;
	ft_memcheck((res = (char **)malloc(sizeof(char *) * 7)));
	res[0] = build_access_right(my_stat.st_mode);
	res[1] = build_date(handle_flag_for_date_output);
	res[2] = build_name(my_stat, name_directory, name_file, flags);
	res[3] = get_real_pw_name(my_stat, flags);
	res[4] = get_real_gr_name(my_stat, flags);
	res[5] = build_str_size(my_stat);
	res[6] = 0;
	return (res);
}
