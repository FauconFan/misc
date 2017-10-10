/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 17:56:09 by jpriou            #+#    #+#             */
/*   Updated: 2017/10/10 17:05:21 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "init_utils.h"
# include "libft.h"
# include "piece_tetris.h"
# include "piece_tetris_utils.h"

# define ERROR		"error"

t_piece_tetris		**init(char *name_file);

#endif