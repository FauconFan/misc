/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 16:04:16 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/09 13:31:06 by fauconfan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_utils.h"

/*
**	Die function if there is an error, often this function is called with ERROR
**	String constant.
*/

void					die(char *str)
{
	ft_putendl(str);
	exit(1);
}

/*
**	Check is a couple is in the buffer - map
*/

int						is_in_buf(int x, int y)
{
	return (x >= 0 && x < 4 && y >= 0 && y < 4);
}
