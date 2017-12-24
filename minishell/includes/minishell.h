/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 08:15:40 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/24 11:10:51 by fauconfan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <sys/types.h>
# include <sys/stat.h>
# include <sys/uio.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdlib.h>
# include <dirent.h>
# include "libft.h"

# define CST_CMD_NOT_FOUND			"Command not found."
# define CST_NO_SUCH_FOUND			"No such file or directory"
# define CST_PERMISSION_DENIED		"Permission denied"
# define CST_NOT_A_DIRECTORY		"Not a directory"

# define CST_EXIT					"exit"
# define CST_ENV					"env"
# define CST_SETENV					"setenv"
# define CST_UNSETENV				"unsetenv"
# define CST_CD						"cd"
# define CST_ECHO					"echo"

# define ENV_CST_HOME				"HOME"
# define ENV_CST_OLDPWD				"OLDPWD"
# define ENV_CST_PWD				"PWD"
# define ENV_CST_SHLVL				"SHLVL"

# define ERROR_SETENV_EMPTY			"Variable name can't be an empty string"
# define ERROR_SETENV_BEGIN			"Variable name must begin with a letter"
# define ERROR_SETENV_ALNUM			"Variable name must contain alphanumeric characters"

typedef struct			s_array_key
{
	char	*key;
	char	*value;
}						t_array_key;

typedef struct			s_ms_env
{
	t_array_key		**env_local;
}						t_ms_env;

/*
**	Init environment
*/

t_ms_env				*init_ms_env(char **env);
void					free_ms_env(t_ms_env **ms_env);

/*
**	Read from standard input
*/

char					*read_from_input(void);
int						treat_cmd(char *s, t_array_key ***env_local);

/*
**	Init cpy_env_from system
*/

t_array_key				**build_cpy_env(char **env);
t_array_key				**build_empty_env(void);
void					free_cpy_env(t_array_key ***list);
t_array_key				**cpy_env_from_another(t_array_key **list);
void					display_env(t_array_key **list);

/*
**	Get set remove env variable
*/

char					*get_env_local(t_array_key **list, char *key);
void					set_env_local(
							t_array_key ***list,
							char *key,
							char *value);
void					remove_env_local(t_array_key ***list, char *key);
void					fork_n_wait(
							t_array_key **env_actu,
							char *directory,
							char *cmd_real,
							char **args);

void					treat_from_scratch(
							t_array_key **env_local,
							char *cmd_real,
							char **args);

int						handle_cmd(
							char *real_cmd,
							char **args,
							t_array_key ***env_local);

t_bool					is_binary(char *real_cmd);
void					treat_with_binary(
							t_array_key **env_local,
							char *real_cmd,
							char **args);
/*
**	Builtins
*/

void					builtin_env(t_array_key **env_actu, char **args);
void					builtin_setenv(t_array_key ***env_actu, char **args);
void					builtin_unsetenv(t_array_key **env_actu, char **args);
void					builtin_cd(t_array_key ***list_env, char **args);
void					builtin_echo(t_array_key **env_actu, char **args);

void					handle_exception_n_run(
							t_array_key ***env_actu,
							char *key,
							char *value);

/*
** Utilities functions
*/

char					*concat_dir_str(char *s1, char *s2);
char					*normalize_path(t_array_key **env_actu, char *curpath);
int						size_array_keys(t_array_key **env_local);
char					**from_array_keys_to_array_string(
							t_array_key **env_local);
void					free_array_string(char **list);
char					*ft_strreplace_free_first(char *res, char *search, char *rep);

t_bool					is_file_exist(char *directory, char *name_file);
char					*why_a_folder_is_unreachable(char *abs_path);

#endif
