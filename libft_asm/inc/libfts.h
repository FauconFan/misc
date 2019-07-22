/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfts.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 02:05:29 by jpriou            #+#    #+#             */
/*   Updated: 2019/07/22 15:46:24 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTS_H
# define LIBFTS_H

# include <string.h>

/*
**		ctype
*/

int		ft_isalnum(int c);
int		ft_isdigit(int c);
int		ft_isalpha(int c);
int		ft_isupper(int c);
int		ft_islower(int c);

int		ft_isascii(int c);
int		ft_isprint(int c);

int		ft_toupper(int c);
int		ft_tolower(int c);

/*
**		mem
*/

void	ft_bzero(void *v, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	ft_memset(void *v, int c, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);

/*
**		str
*/

size_t	ft_strlen(const char *string);
char	*ft_strcat(char *s1, const char *s2);
char	*ft_strdup(const char *s);

void	ft_cat(int fd);
int		ft_puts(const char *string);

#endif