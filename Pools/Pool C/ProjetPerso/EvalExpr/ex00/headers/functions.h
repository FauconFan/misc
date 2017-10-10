/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 11:11:43 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/20 18:45:43 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

void	ft_putchar(char c);
void	ft_putstr(char *s);
void	ft_putnbr(int n);
int		ft_strlen(char *str);
int		ft_atoi(char *s);

int		add(int a, int b);
int		substract(int a, int b);
int		times(int a, int b);
int		divide(int a, int b);
int		modulo(int a, int b);

int		operation_treatment(char c, int a, int b);

int		eval_expr(char *str);

char	*remove_unused_parenthesis(char *str);

#endif
