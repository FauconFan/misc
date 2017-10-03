/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 13:29:17 by jpriou            #+#    #+#             */
/*   Updated: 2017/09/19 07:53:52 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 			25
# define MAX_FD				200

int 			get_next_line(const int fd, char **line);

typedef	struct				s_buff_prog
{
	char					*buff;
	int						ret;
}							t_buff_prog;

#endif