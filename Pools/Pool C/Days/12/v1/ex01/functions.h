/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 14:51:15 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/18 15:53:29 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

void	ft_putstr(char *str);

int		do_main_file(char *name_file);
void	do_main_standard_file(void);
void	echo_issue(char *error, char *name_file);

#endif
