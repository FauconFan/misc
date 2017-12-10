/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 12:10:55 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/10 15:40:48 by fauconfan        ###   ########.fr       */
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
# include <unistd.h>
# include "libft.h"

# define FLAG_L_MIN		0b1
# define FLAG_R_MAJ		0b10
# define FLAG_A_MIN		0b100
# define FLAG_R_MIN		0b1000
# define FLAG_T_MIN		0b10000

typedef struct 			s_content_args
{
	struct stats	*stat_file;
}						t_content_args;

typedef struct 			s_content_error_files
{
	char	*file_name;
	char	*perror_message;
}						t_content_error_files;

typedef struct			s_env_ls
{
	int					flags;
	t_list				*list_contents_args;
	t_list				*list_error_files;
}						t_env_ls;

void					ls_display_usage(char illegal_option, t_env_ls *env_ls);

t_env_ls				*init_ls_env(int *argc, char ***argv);
void					free_ls_env(t_env_ls **env);

t_content_error_files	*ls_new_error_file(char *name);
void					free_error_file(void *content);
void					display_error(t_list *elem);
int						cmp_error_files(void *d1, void *d2);

#endif