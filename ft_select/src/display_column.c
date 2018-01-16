/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_column.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 12:29:47 by fauconfan         #+#    #+#             */
/*   Updated: 2018/01/16 12:03:58 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static t_bool	ft_match(char *s1, char *s2)
{
	if (*s1 != '\0' && *s2 == '*')
		return (ft_match(s1 + 1, s2) || ft_match(s1, s2 + 1));
	if (*s1 == '\0' && *s2 == '*')
		return (ft_match(s1, s2 + 1));
	if (*s1 == *s2 && *s1 != '\0' && *s2 != '\0')
		return (ft_match(s1 + 1, s2 + 1));
	if (*s1 == *s2 && *s1 == '\0' && *s2 == '\0')
		return (TRUE);
	return (FALSE);
}

static int		count_max_len_args(t_arg **args)
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

static void		display_color(char *str)
{
	if (ft_match(str, "*.c"))
		ft_putstr_fd(C_COLOR, STDERR_FILENO);
	else if (ft_match(str, "*.o"))
		ft_putstr_fd(O_COLOR, STDERR_FILENO);
	else if (ft_match(str, "*.h"))
		ft_putstr_fd(H_COLOR, STDERR_FILENO);
	else if (ft_strcmp(str, "Makefile") == 0 || ft_strcmp(str, "MAKEFILE") == 0)
		ft_putstr_fd(MAKEFILE_COLOR, STDERR_FILENO);
	else if (ft_match(str, "*.a"))
		ft_putstr_fd(A_COLOR, STDERR_FILENO);
}

static void		display_arg(t_select *env, int max_len)
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
		display_color(str_actu);
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

void			display_column(void)
{
	int				max_len_arg;
	int				cols;
	int				rows;

	if (g_select == 0 || g_select->args == 0)
		return ;
	tputs(tgetstr("cl", NULL), 1, ft_printnbr);
	ioctl(STDERR_FILENO, TIOCGWINSZ, &g_select->ws);
	max_len_arg = count_max_len_args(g_select->args);
	if (max_len_arg > g_select->ws.ws_col)
		return ;
	cols = g_select->ws.ws_col / (max_len_arg + 1);
	if (cols == 0)
		cols++;
	if ((max_len_arg + 1) * g_select->tot_args < g_select->ws.ws_col)
		cols = g_select->tot_args;
	rows = g_select->tot_args / cols;
	if (rows >= g_select->ws.ws_row || max_len_arg >= g_select->ws.ws_col)
		return ;
	if (g_select->tot_args % cols)
		rows++;
	g_select->rows = rows;
	g_select->cols = cols;
	display_arg(g_select, max_len_arg);
}
