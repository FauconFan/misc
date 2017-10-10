/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 11:18:13 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/18 14:20:27 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# define SIZE_BUF 16

void	ft_putstr(char *str);
void	ft_putchar(char c);
int		ft_strcmp(char *s1, char *s2);
void	ft_strcpy(char *dest, char *src);
void	ft_putnbr_addr(unsigned long nbr);
void	ft_putnbr_value(char c);

void	print_nonprintable(char buffer[SIZE_BUF]);
void	ft_printbuffer(unsigned long addr, char *buffer, int length);

void	do_main(int argc, char **argv);

#endif
