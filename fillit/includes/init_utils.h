/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 16:04:30 by jpriou            #+#    #+#             */
/*   Updated: 2017/11/09 13:34:57 by fauconfan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_UTILS_H
# define INIT_UTILS_H

# include <stdlib.h>
# include "piece_tetris_simp.h"

void						die(char *str);
int						is_in_buf(int x, int y);

#endif
