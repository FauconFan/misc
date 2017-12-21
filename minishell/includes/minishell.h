/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 08:15:40 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/21 19:15:15 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
#include <errno.h>
# include <dirent.h>
# include "libft.h"

# define	CST_CMD_NOT_FOUND	"Command not found."

# define	CST_EXIT			"exit"
# define	CST_ENV				"env"
# define	CST_SETENV			"setenv"
# define	CST_UNSETENV		"unsetenv"

typedef struct			s_ms_env
{
	char			**cpy_env;
}						t_ms_env;

t_ms_env				*init_ms_env(char **env);
void					free_ms_env(t_ms_env **ms_env);

char					*read_from_input(void);
int						treat_cmd(char *s, t_ms_env *ms_env);

char					**build_cpy_env(char **env);
void					free_cpy_env(char ***list);
char					*get_env_local(char **list, char *key);
void					set_env_local(char ***list, char *key, char *value);
void					remove_env_local(char ***list, char *key);

char					*concat_dir_str(char *s1, char *s2);

void					fork_n_wait(t_ms_env *ms_env, char *directory, char *cmd_real, char **args);

void					treat_from_scratch(t_ms_env *ms_env, char *cmd_real, char **args);

void					builtin_env(t_ms_env *ms_env);
void					builtin_setenv(t_ms_env *ms_env, char **args);
void					builtin_unsetenv(t_ms_env *ms_env, char **args);

#endif
