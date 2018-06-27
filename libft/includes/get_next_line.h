/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 08:24:56 by jpriou            #+#    #+#             */
/*   Updated: 2018/06/27 08:30:10 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include "libft.h"

# define BUFF_SIZE_GNL			25

typedef struct	s_env_gnl
{
	struct s_env_gnl	*next;
	char				**buff_prog;
	int					fd;
}				t_env_gnl;

int				get_next_line(const int fd, char **line, t_env_gnl *env_gnl);

t_env_gnl		*init_env_gnl(void);
void			free_env_gnl(t_env_gnl *head);
char			**find_buff_prog(t_env_gnl *head, int searched_fd);

#endif
