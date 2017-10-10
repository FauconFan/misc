/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 17:06:20 by jpriou            #+#    #+#             */
/*   Updated: 2017/10/10 17:15:20 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

typedef struct 		s_map
{
	char 			**map;
	int				size;
}					t_map;

#include <stdlib.h>
#include "init_utils.h"
#include "libft.h"

t_map				*new_map(int size);
void				print_map(t_map *map);
void 				free_map(t_map *map);

#endif