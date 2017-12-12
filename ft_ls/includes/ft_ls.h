/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 12:10:55 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/12 09:24:28 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <stdlib.h>
# include <dirent.h>
# include <errno.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <pwd.h>
# include <unistd.h>
# include <time.h>
# include "libft.h"

# define FLAG_L_MIN			0b1
# define FLAG_R_MAJ			0b10
# define FLAG_A_MIN			0b100
# define FLAG_R_MIN			0b1000
# define FLAG_T_MIN			0b10000

# define WARNING_SNA		"Warning : Should never happen"

typedef void				(*t_simple_ptr)(void *content, void *param);
typedef int					(*t_ptr_cmp)(void *d1, void *d2);

typedef struct				s_content_error_files
{
	char	*file_name;
	char	*perror_message;
}							t_content_error_files;

typedef struct				s_file_content
{
	char			*name_file;
	struct stat		*stat_file;
	struct dirent	*dirent_file;
}							t_file_content;

typedef struct				s_max_values_long_format
{
	int					max_st_nlink;
	int					max_st_size;
}							t_max_values_long_format;

typedef struct				s_list_directory
{
	DIR							*dir_actu;
	t_list						*dir_content;
	t_max_values_long_format	*max_values;
}							t_list_directory;

typedef struct				s_tmp_recu
{
	int					flags;
	char				*name_parent_folder;
}							t_tmp_recu;

typedef struct				s_env_ls
{
	int					flags;
	t_list				*list_contents_args;
	t_list				*list_error_files;
}							t_env_ls;

void						ls_display_usage(char illegal_option,
									t_env_ls *env_ls);

t_env_ls					*init_ls_env(int *argc, char ***argv,
								t_max_values_long_format *max_values);
void						free_ls_env(t_env_ls **env);

t_content_error_files		*ls_new_error_file(char *name);
void						free_error_file(void *content);
void						display_error(void *elem);
int							cmp_error_files(void *d1, void *d2);

t_file_content				*ls_new_file_content(
							struct dirent *dirent_file,
							char *name_directory,
							char *name_file);
void						free_new_file_content(void *content);

t_simple_ptr				flag_manager(int flags);

void						display_name_simply(void *content, void *param);
void						display_l_option(void *content, void *param);

void						display_total_blocks_if_need(int flags,
							t_list *dir_content);

void						ls_list_directories(
							int flags,
							char *name_directory,
							t_bool display_name_directory,
							t_bool display_return_line);

void						display_recursively(void *content, void *param);
char						*ls_utils_build_name(char *name_directory,
											char *name_file);

t_max_values_long_format	*init_max_values(void);
void						free_max_values(t_max_values_long_format **max);
void						update_max_values(
								t_max_values_long_format *max,
								int st_nlink,
								int st_size);

t_bool						check_if_a_file_is_readable_as_a_folder(
								char *name_file);
/*
**	Sort utils
*/

t_ptr_cmp					get_sort_function(int flags);

int							ls_sort_by_file_name(void *d1, void *d2);
int							ls_sort_by_file_name_reverse(void *d1, void *d2);
int							ls_sort_by_last_time_modified(void *d1, void *d2);
int							ls_sort_by_last_time_modified_reverse
								(void *d1, void *d2);

#endif
