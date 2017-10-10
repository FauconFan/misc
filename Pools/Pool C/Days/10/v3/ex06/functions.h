/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 12:57:59 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/14 14:17:08 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

int		ft_atoi(char *str);
void	ft_putnbr(int n);
void	ft_putchar(char c);
void	ft_putstr(char *str);

void	do_main(char **argv);
int		verify_tab_func(char *str);

int		add(int a, int b);
int		substract(int a, int b);
int		times(int a, int b);
int		divide(int a, int b);
int		modulo(int a, int b);

#endif
