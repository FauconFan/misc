/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 08:15:40 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/28 10:11:00 by jpriou           ###   ########.fr       */
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
# include <signal.h>
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
# define CST_PWD					"pwd"
# define CST_MINISHELL				"minishell"
# define CST_HISTORY				"history"

# define USAGE_ENV3					"[-i|-u VALUE| NAME=VALUE]..."
# define USAGE_ENV2					"[utility[argument]]..."
# define USAGE_ENV					"env "USAGE_ENV3" "USAGE_ENV2
# define USAGE_SETENV				"setenv VAR [VALUE]"
# define USAGE_UNSETENV				"unsetenv VAR"
# define USAGE_CD					"cd [-L|-P] path"
# define USAGE_ECHO					"echo [message]..."
# define USAGE_PWD					"pwd [-L|-P]..."
# define USAGE_HISTORY				"history"

# define ENV_CST_HOME				"HOME"
# define ENV_CST_OLDPWD				"OLDPWD"
# define ENV_CST_PWD				"PWD"
# define ENV_CST_SHLVL				"SHLVL"
# define ENV_CDPATH					"CDPATH"

# define VAR_NAME					"Variable name"
# define ERROR_SETENV_EMPTY			VAR_NAME" can't be an empty string"
# define ERROR_SETENV_BEGIN			VAR_NAME" must begin with a letter"
# define ERROR_ALPHANUM_2			"alphanumeric characters"
# define ERROR_SETENV_ALNUM			VAR_NAME" must contain "ERROR_ALPHANUM_2

int						g_child_pid;
char					*g_cmd_actu;
int						g_cmd_size_actu;

typedef struct			s_array_key
{
	char	*key;
	char	*value;
}						t_array_key;

typedef struct			s_history
{
	t_list	*head;
	t_list	*tail;
}						t_history;

typedef struct			s_ms_env
{
	t_array_key		***env_local;
	t_history		*history_local;
}						t_ms_env;

/*
**	Init environment
*/

t_ms_env				*init_ms_env(char **env);
void					free_ms_env(t_ms_env **ms_env);
t_ms_env				*cpy_from_another_env(t_ms_env *ms_env);

/*
**	Read from standard input
*/

void					read_from_input(void);
int						treat_cmd(char *s, t_ms_env *ms_env);
int						handle_cmd(
							char *real_cmd,
							char **args,
							t_ms_env *ms_env);

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

t_bool					is_binary(char *real_cmd);
void					treat_with_binary(
							t_array_key **env_local,
							char *real_cmd,
							char **args);

/*
**	Signals
*/

void					handle_sigint(int signal);

/*
**	Builtins
*/

void					builtin_env(t_ms_env *env_global, char **args);
void					builtin_setenv(t_array_key ***env_actu, char **args);
void					builtin_unsetenv(t_array_key **env_actu, char **args);
void					builtin_cd(t_array_key ***list_env, char **args);
void					builtin_echo(t_array_key **env_actu, char **args);
void					builtin_pwd(t_array_key ***env_global, char **args);
void					builtin_history(t_ms_env *ms_env);

char					*handle_cd_path(
							t_array_key **list_env,
							char *real_arg);

void					builtin_minishell(t_ms_env *env_global);

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
char					*ft_strreplace_free_first(
							char *res,
							char *search,
							char *rep);
char					*build_from_real_cmd_and_args(char *cmd, char **args);

t_bool					is_file_exist(char *directory, char *name_file);
char					*why_a_folder_is_unreachable(char *abs_path);

char					*get_abs_path_from_getcwd(void);

void					free_history(void *content);
void					add_in_history(
							t_ms_env *ms_env,
							char *cmd,
							char **args);
void					display_history(t_ms_env *ms_env);

void					display_all_usages(void);
void					display_usage(char *option);

#endif
