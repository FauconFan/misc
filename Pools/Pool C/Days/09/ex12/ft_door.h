/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_door.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 11:54:36 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/11 16:32:16 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DOOR_H
# define FT_DOOR_H

# define TRUE				1
# define FALSE				0

# define OPEN				1
# define CLOSE				0
# define EXIT_SUCCESS		0

# include <unistd.h>

typedef short				t_bool;

typedef struct				s_door
{
	t_bool	state;
}							t_door;

t_bool						open_door(t_door *door);
t_bool						close_door(t_door *door);
t_bool						is_door_open(t_door *door);
t_bool						is_door_close(t_door *door);

#endif
