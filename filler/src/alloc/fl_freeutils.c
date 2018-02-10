/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_freeutils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 22:34:18 by fauconfan         #+#    #+#             */
/*   Updated: 2018/02/11 00:09:27 by fauconfan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		fl_free_parsed_string(char ***splited, char **line)
{
	free(*line);
	free((*splited)[0]);
	free((*splited)[1]);
	free((*splited)[2]);
	free((*splited));
}

void		fl_free_tab_strings(char ***tab, size_t y)
{
	size_t	index;

	index = 0;
	while (index < y)
	{
		free((*tab)[index]);
		index++;
	}
	free(*tab);
}
