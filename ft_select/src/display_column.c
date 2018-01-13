/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_column.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 12:29:47 by fauconfan         #+#    #+#             */
/*   Updated: 2018/01/13 15:33:24 by fauconfan        ###   ########.fr       */
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

static void display_arg(t_arg **args, int rows, int cols, int max_len)
{
	char	*str_actu;
	int		index;

	(void)rows;
	index = -1;
	while (args[++index])
	{
		str_actu = args[index]->value;
		ft_dprintf(STDERR_FILENO, "%s%*s", str_actu, max_len - ft_strlen(str_actu) + 1, "");
		if ((index + 1) % cols == 0)
		{
			ft_dprintf(STDERR_FILENO, "\n");
		}
	}
}

void		display_column(t_select *env)
{
	struct winsize	ws;
	int				max_len_arg;
	int				cols;
	int				rows;

	if (env == 0 || env->args == 0)
		return ;
	tputs(tgetstr("cl", NULL), 1, ft_printnbr);
	ioctl(STDERR_FILENO, TIOCGWINSZ, &ws);
	max_len_arg = count_max_len_args(env->args);
	if (max_len_arg > ws.ws_col)
		return ;
	cols = ws.ws_col / (max_len_arg + 1);
	if (cols == 0)
		cols++;
	if ((max_len_arg + 1) * env->tot_args < ws.ws_col)
		cols = env->tot_args;
	rows = env->tot_args / cols;
	if (rows > ws.ws_row)
		return ;
	if (env->tot_args % cols)
		rows++;
	ft_dprintf(STDERR_FILENO, "rows %d cols %d\n", rows, cols);
	display_arg(env->args, rows, cols, max_len_arg);
}
