/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_treat_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 08:33:22 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/26 15:39:24 by fauconfan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		parse_cmd(char *cmd, char **name_cmd, char ***args)
{
	int		index;

	if (*cmd == 0)
		*name_cmd = ft_strnew(0);
	else
	{
		while (ft_iswhitespace(*cmd) && *cmd != 0)
			cmd++;
		index = 0;
		while (ft_iswhitespace(cmd[index]) == 0 && cmd[index] != 0)
			index++;
		*name_cmd = ft_strndup(cmd, index);
		cmd = cmd + index;
		while (ft_iswhitespace(*cmd) && *cmd != 0)
			cmd++;
		if (*cmd != 0)
		{
			*args = ft_strsplit(cmd, ' ');
			return ;
		}
	}
	ft_memcheck((*args = (char **)malloc(sizeof(char *) * 1)));
	**args = 0;
}

static void		free_parsed_cmd(char **cmd, char **real_cmd, char ***args)
{
	int		index;

	index = 0;
	if (cmd)
	{
		free(*cmd);
		*cmd = 0;
	}
	free(*real_cmd);
	*real_cmd = 0;
	while ((*args)[index])
	{
		free((*args)[index]);
		index++;
	}
	free(*args);
	*args = 0;
}

int				treat_cmd(char *s, t_ms_env *ms_env)
{
	char	**splited;
	char	**args;
	char	*real_cmd;
	int		ret;
	int		index;

	splited = ft_strsplit(s, ';');
	index = 0;
	while (splited[index])
	{
		parse_cmd(splited[index], &real_cmd, &args);
		if ((ret = handle_cmd(real_cmd, args, ms_env)) == 1)
		{
			free_parsed_cmd(0, &real_cmd, &args);
			break ;
		}
		free_parsed_cmd(0, &real_cmd, &args);
		index++;
	}
	index = -1;
	while (splited[++index])
		free(splited[index]);
	free(splited);
	free(s);
	return (ret);
}

int				handle_cmd(char *real_cmd, char **args, t_ms_env *ms_env)
{
	add_in_history(ms_env, real_cmd, args);
	if (ft_strcmp(real_cmd, CST_EXIT) == 0)
		return (1);
	else if (ft_strcmp(real_cmd, CST_ENV) == 0)
		builtin_env(ms_env, args);
	else if (ft_strcmp(real_cmd, CST_SETENV) == 0)
		builtin_setenv(ms_env->env_local, args);
	else if (ft_strcmp(real_cmd, CST_UNSETENV) == 0)
		builtin_unsetenv(*(ms_env->env_local), args);
	else if (ft_strcmp(real_cmd, CST_ECHO) == 0)
		builtin_echo(*(ms_env->env_local), args);
	else if (ft_strcmp(real_cmd, CST_CD) == 0)
		builtin_cd(ms_env->env_local, args);
	else if (ft_strcmp(real_cmd, CST_PWD) == 0)
		builtin_pwd(ms_env->env_local, args);
	else if (ft_strcmp(real_cmd, CST_MINISHELL) == 0)
		builtin_minishell(ms_env);
	else if (ft_strcmp(real_cmd, CST_HISTORY) == 0)
		builtin_history(ms_env);
	else if (is_binary(real_cmd))
		treat_with_binary(*(ms_env->env_local), real_cmd, args);
	else if (ft_strcmp(real_cmd, ""))
		treat_from_scratch(*(ms_env->env_local), real_cmd, args);
	return (0);
}
