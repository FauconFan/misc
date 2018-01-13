/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_column.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 12:29:47 by fauconfan         #+#    #+#             */
/*   Updated: 2018/01/13 17:32:08 by fauconfan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static int	count_max_len_args(t_arg **args)
{
	int		res;
	int		tmp;
	int		index;

	res = 0;
	index = 0;
	while (args[index])
	{
		tmp = ft_strlen(args[index]->value);
		if (res < tmp)
		{
			res = tmp;
		}
		index++;
	}
	return (res);
}

static void display_arg(t_select *env, int max_len)
{
	char	*str_actu;
	int		index;

	index = -1;
	while (env->args[++index])
	{
		str_actu = env->args[index]->value;
		if (index == env->index_selected)
			ft_putstr_fd(UNDERLINED, STDERR_FILENO);
		if (env->args[index]->is_selected)
			ft_putstr_fd(REVERSE_VIDEO_COLOR, STDERR_FILENO);
		ft_dprintf(STDERR_FILENO, "%s%s%*s",
				str_actu,
				DEFAULT_COLOR,
				max_len - ft_strlen(str_actu) + 1, "");
		if ((index + 1) % env->cols == 0)
		{
			ft_dprintf(STDERR_FILENO, "\n");
		}
	}
}

void		display_column(t_select *env)
{
	int				max_len_arg;
	int				cols;
	int				rows;

	if (env == 0 || env->args == 0)
		return ;
	tputs(tgetstr("cl", NULL), 1, ft_printnbr);
	ioctl(STDERR_FILENO, TIOCGWINSZ, &env->ws);
	max_len_arg = count_max_len_args(env->args);
	if (max_len_arg > env->ws.ws_col)
		return ;
	cols = env->ws.ws_col / (max_len_arg + 1);
	if (cols == 0)
		cols++;
	if ((max_len_arg + 1) * env->tot_args < env->ws.ws_col)
		cols = env->tot_args;
	rows = env->tot_args / cols;
	if (rows > env->ws.ws_row)
		return ;
	if (env->tot_args % cols)
		rows++;
	env->rows = rows;
	env->cols = cols;
	display_arg(env, max_len_arg);
}
