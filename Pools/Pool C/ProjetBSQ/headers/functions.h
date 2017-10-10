/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 08:46:54 by jpriou            #+#    #+#             */
/*   Updated: 2017/08/23 19:15:40 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

void	ft_putstr(char *str);
void	ft_putstrerr(char *str);
void	ft_putchar(char c);
void	ft_putnbr(int nb);
char	*ft_strcpy(char *dest, char *src);
int		ft_atoi(char *str);
int		ft_strcmp(char *s1, char *s2);
void	ft_strcat(char *s1, char *s2, int rank);
int		ft_strlen(char *s);
int		ft_atoi(char *s);

char	*get_file_input(char *name);
char	*get_input(int file_descriptor);

#endif
