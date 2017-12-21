/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_treat_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 08:33:22 by jpriou            #+#    #+#             */
/*   Updated: 2017/12/21 19:25:43 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		parse_cmd(char *cmd, char **name_cmd, char ***args)
{
	int		index;

	if (*cmd == 0)
	{
		*name_cmd = ft_strnew(0);
		ft_memcheck((*args = (char **)malloc(sizeof(char *))));
		**args = 0;
	}
	else
	{
		index = 0;
		while (ft_iswhitespace(cmd[index]) == 0 && cmd[index] != 0)
			index++;
		*name_cmd = ft_strndup(cmd, index);
		cmd = cmd + index;
		while (ft_iswhitespace(*cmd) && *cmd != 0)
			cmd++;
		if (*cmd == 0)
		{
			*args = (char **)malloc(sizeof(char *) * 1);
			**args = 0;
		}
		else
			*args = ft_strsplit(cmd, ' ');
	}
}

static void		free_parsed_cmd(char **cmd, char **real_cmd, char ***args)
{
	int		index;

	index = 0;
	free(*cmd);
	free(*real_cmd);
	while ((*args)[index])
	{
		free((*args)[index]);
		index++;
	}
	free(*args);
	*cmd = 0;
	*real_cmd = 0;
	*args = 0;
}

int				treat_cmd(char *s, t_ms_env *ms_env)
{
	char	**args;
	char	*real_cmd;

	if (ft_strcmp(real_cmd, "") == 0)
	{
		free(s);
		return (0);
	}
	parse_cmd(s, &real_cmd, &args);
	if (ft_strcmp(real_cmd, CST_EXIT) == 0)
	{
		free_parsed_cmd(&s, &real_cmd, &args);
		return (1);
	}
	else if (ft_strcmp(real_cmd, CST_ENV) == 0)
		builtin_env(ms_env);
	else if (ft_strcmp(real_cmd, CST_SETENV) == 0)
		builtin_setenv(ms_env, args);
	else if (ft_strcmp(real_cmd, CST_UNSETENV) == 0)
		builtin_unsetenv(ms_env, args);
	else
		treat_from_scratch(ms_env, real_cmd, args);
	free_parsed_cmd(&s, &real_cmd, &args);
	return (0);
}
