/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 12:10:55 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/13 10:16:05 by jpriou           ###   ########.fr       */
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
# define FLAG_N_MIN			0b100000
# define FLAG_P_MIN			0b1000000
# define FLAG_D_MIN			0b10000000
# define FLAG_U_MIN			0b100000000
# define FLAG_U_MAJ			0b1000000000
# define FLAG_C_MIN			0b10000000000
# define FLAG_S_MAJ			0b100000000000
# define FLAG_A_MAJ			0b1000000000000
# define FLAG_F_MIN			0b10000000000000

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
	int					max_len_user_id;
	int					max_len_group_id;
}							t_max_values_long_format;

typedef struct				s_list_directory
{
	int							flags;
	DIR							*dir_actu;
	char						*name_directory;
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

int							ls_list_files_only(
								t_env_ls *env_ls,
								t_max_values_long_format *max_values);
void						ls_list_directories_only(
								t_env_ls *env_ls,
								int ret_files_only);

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

void						handle_flags(t_env_ls *env_ls, char c);
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

char						*add_slash_next_to_folder_name(char *name_folder);

t_max_values_long_format	*init_max_values(void);
void						free_max_values(t_max_values_long_format **max);
void						update_max_values(
								t_max_values_long_format *max,
								struct stat stats,
								int flags);

t_bool						check_if_a_file_is_readable_as_a_folder(
								char *name_file);

char						**build_all_strings_long_format(
								struct stat my_stat,
								char *name_directory,
								char *name_file,
								int flags);

char						*get_real_pw_name(struct stat mystat, int flags);
char						*get_real_gr_name(struct stat mystat, int flags);

char						*build_str_size(struct stat my_stat);

/*
**	Sort utils
*/

t_ptr_cmp					get_sort_function(int flags);

int							ls_sort_by_file_name(void *d1, void *d2);
int							ls_sort_by_file_name_reverse(void *d1, void *d2);
int							ls_sort_by_last_time_modified(void *d1, void *d2);
int							ls_sort_by_last_time_modified_reverse
								(void *d1, void *d2);
int							ls_sort_by_last_time_accessed(void *d1, void *d2);
int							ls_sort_by_last_time_accessed_reverse
								(void *d1, void *d2);
int							ls_sort_by_last_time_birth(void *d1, void *d2);
int							ls_sort_by_last_time_birth_reverse
								(void *d1, void *d2);
int							ls_sort_by_last_time_change_status
								(void *d1, void *d2);
int							ls_sort_by_last_time_change_status_reverse
								(void *d1, void *d2);
int							ls_sort_by_size(void *d1, void *d2);
int							ls_sort_by_size_reverse(void *d1, void *d2);

#endif
