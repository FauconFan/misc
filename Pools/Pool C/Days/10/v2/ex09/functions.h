/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 12:57:59 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/14 17:41:49 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

int				ft_atoi(char *str);
void			ft_putnbr(int n);
void			ft_putchar(char c);
void			ft_putstr(char *str);
int				ft_strcmp(char *s1, char *s2);

void			do_main(char **argv);
int				verify_tab_func(char *str);

int				ft_add(int a, int b);
int				ft_sub(int a, int b);
int				ft_mul(int a, int b);
int				ft_div(int a, int b);
int				ft_mod(int a, int b);
int				ft_usage(int a, int b);

typedef struct	s_opp
{
	char	*s;
	int		(*f) (int, int);
}				t_opp;

void			print_symbol(void);

#endif
