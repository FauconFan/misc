/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_formatutils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 21:54:51 by fauconfan         #+#    #+#             */
/*   Updated: 2018/02/10 23:55:07 by fauconfan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static t_bool		fl_match(char *s1, char *s2)
{
	if (*s1 != '\0' && *s2 == '*')
		return (fl_match(s1 + 1, s2) || fl_match(s1, s2 + 1));
	if (*s1 == '\0' && *s2 == '*')
		return (fl_match(s1, s2 + 1));
	if (*s1 == *s2 && *s1 != '\0' && *s2 != '\0')
		return (fl_match(s1 + 1, s2 + 1));
	if (*s1 == *s2 && *s1 == '\0' && *s2 == '\0')
		return (TRUE);
	return (FALSE);
}

t_bool				fl_verify_loader_player(char *str)
{
	return (fl_match(str, "$$$ exec p* : *"));
}

t_bool				fl_verify_loader_map(char *str)
{
	return (fl_match(str, "Plateau * *:"));
}

t_bool				fl_verify_loader_piece(char *str)
{
	return (fl_match(str, "Piece * *:"));
}
