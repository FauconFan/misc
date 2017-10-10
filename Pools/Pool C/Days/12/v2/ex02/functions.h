/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 08:58:22 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/19 13:04:49 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# define MODE_FROM_HEAD 1
# define MODE_FROM_BOTTOM 2

# define ABS(x) ((x < 0) ? -x : x)

void			ft_putstr(char *str);
int				ft_strcmp(char *s1, char *s2);
int				ft_atoi(char *s);

int				do_main(int argc, char **argv,
		int mode_tail_or_head, int vallue_of_c);
unsigned int	get_size_file(char *name_file);
void			display_main_file(char *file_name, int to_ignore, int mode);
void			echo_issue(char *errno, char *name_file);

#endif
