/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_formatutils_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 23:19:11 by fauconfan         #+#    #+#             */
/*   Updated: 2018/02/10 23:52:40 by fauconfan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static t_bool		fl_verify_checker_header_map(char *str, size_t x)
{
	size_t		index;

	if (str[0] == '\0' || str[1] == '\0' || str[2] == '\0' || str[3] == '\0')
		return (FALSE);
	index = 0;
	while (str[4 + index])
	{
		if (str[4 + index] != '0' + ((int)index % 10))
			return (FALSE);
		index++;
	}
	if (index != x)
		return (FALSE);
	return (TRUE);
}

void				fl_verify_header_map(t_fillerenv *fl_env, size_t x)
{
	char	*tmp;

	get_next_line(0, &tmp, fl_env->env_gnl);
	if (fl_verify_checker_header_map(tmp, x) == FALSE)
	{
		free(tmp);
		free_env(&fl_env, WRONG_FORMAT);
	}
	free(tmp);
}

t_bool				fl_verify_each_line_map(char *str, size_t y, size_t x)
{
	size_t		index;

	if (str[0] == '\0' || str[1] == '\0' || str[2] == '\0' || str[3] == '\0' ||
		(size_t)ft_atoi(str) != y)
		return (FALSE);
	index = 0;
	while (str[4 + index])
	{
		if (str[4 + index] != EMPTY_CASE && str[4 + index] != X_MAJ_CASE &&
			str[4 + index] != X_MIN_CASE && str[4 + index] != O_MIN_CASE &&
			str[4 + index] != O_MAJ_CASE)
			return (FALSE);
		index++;
	}
	if (index != x)
		return (FALSE);
	return (TRUE);
}
