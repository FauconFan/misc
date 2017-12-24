/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 17:07:07 by fauconfan         #+#    #+#             */
/*   Updated: 2017/12/24 10:53:27 by fauconfan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char				*are_all_variables_exist(t_array_key **env_actu, char *str)
{
	int			index;
	int			size;
	int			pos_dolar;
	t_bool		is_okay;

	while ((pos_dolar = ft_strcpos(str, '$')) != -1)
	{
		str += pos_dolar + 1;
		index = -1;
		is_okay = FALSE;
		size = 0;
		while (env_actu[++index])
		{
			size = ft_strlen(env_actu[index]->key);
			if (ft_strncmp(env_actu[index]->key, str, size) == 0)
			{
				is_okay = TRUE;
				break ;
			}
		}
		if (is_okay == FALSE)
			return (str - 1 - pos_dolar);
		str += size + 1;
	}
	return (0);
}

static char				*get_variable_simple(t_array_key **env_actu, char *arg, int *size)
{
	int		index;
	int		size_key;
	char	*real_key;

	index = 0;
	real_key = arg + 1;
	while (env_actu[index])
	{
		size_key = ft_strlen(env_actu[index]->key);
		if (ft_strncmp(real_key, env_actu[index]->key, size_key) == 0)
		{
			*size = size_key;
			return (env_actu[index]->value);
		}
		index++;
	}
	ft_dprintf(2, "Should never happened\n");
	return (0);
}

static void				treat_arg_env_variable(t_array_key **env_actu, char **arg)
{
	int		pos;
	int		size_key;
	char	*new_value;
	char	*tmp;

	while ((pos = ft_strcpos(*arg, '$')) != -1)
	{
		new_value = get_variable_simple(env_actu, *arg + pos, &size_key);
		tmp = ft_strndup(*arg + pos, size_key + 1);
		*arg = ft_strreplace_free_first(*arg, tmp, new_value);
		free(tmp);
	}
}

static void				treat_arg_backslash(char **arg)
{
	int		pos;

	while ((pos = ft_strcpos(*arg, '\\')) != -1)
	{
		if ((*arg)[pos + 1] == 'n')
			*arg = ft_strreplace_free_first(*arg, "\\n", "\n");
		else if ((*arg)[pos + 1] == 't')
			*arg = ft_strreplace_free_first(*arg, "\\t", "\t");
		else if ((*arg)[pos + 1] == 'a')
			*arg = ft_strreplace_free_first(*arg, "\\a", "\a");
		else if ((*arg)[pos + 1] == 'b')
			*arg = ft_strreplace_free_first(*arg, "\\b", "\b");
		else if ((*arg)[pos + 1] == 'f')
			*arg = ft_strreplace_free_first(*arg, "\\f", "\f");
		else if ((*arg)[pos + 1] == 'r')
			*arg = ft_strreplace_free_first(*arg, "\\r", "\r");
		else if ((*arg)[pos + 1] == 'v')
			*arg = ft_strreplace_free_first(*arg, "\\v", "\v");
	}
}

void					builtin_echo(t_array_key **env_actu, char **args)
{
	int		index;
	char	*error;

	index = -1;
	while (args[++index])
	{
		if ((error = are_all_variables_exist(env_actu, args[index])) != 0)
		{
			ft_dprintf(2, "echo: Undefined variable near : \"%s\"\n", error);
			return ;
		}
	}
	index = -1;
	while (args[++index])
	{
		treat_arg_backslash(args + index);
		treat_arg_env_variable(env_actu, args + index);
		ft_putstr(args[index]);
		if (args[index + 1])
			ft_putchar(' ');
	}
	ft_putchar('\n');
}
