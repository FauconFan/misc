/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:46:42 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/13 14:09:40 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
# define FT_MALLOC_H

# include "inc/ft_malloc_intern.h"

/*
**	Std function for malloc family
*/

void			*malloc(size_t size);
void			free(void *ptr);
void			*calloc(size_t nmemb, size_t size);
void			*realloc(void *ptr, size_t size);

void			show_alloc_mem(void);
void			show_alloc_mem_hex(void);

size_t			malloc_size(const void *ptr);
size_t			malloc_asked_size(const void *ptr);

/*
**	Same functions but with a malloc zone (t_malloc_zone)
*/

t_malloc_zone	*ft_malloc_zone_create(void);
void			ft_malloc_zone_destroy(t_malloc_zone *mzone);

void			*ft_malloc_zone_malloc(
					t_malloc_zone *mzone,
					size_t size);
void			ft_malloc_zone_free(
					t_malloc_zone *mzone,
					void *ptr);
void			*ft_malloc_zone_calloc(
					t_malloc_zone *mzone,
					size_t nmemb,
					size_t size);
void			*ft_malloc_zone_realloc(
					t_malloc_zone *mzone,
					void *ptr,
					size_t size);

void			ft_malloc_zone_show_alloc_mem(t_malloc_zone *mzone);
void			ft_malloc_zone_show_alloc_mem_hex(t_malloc_zone *mzone);

size_t			ft_malloc_zone_malloc_size(
					t_malloc_zone *mzone,
					const void *ptr);
size_t			ft_malloc_zone_malloc_asked_size(
					t_malloc_zone *mzone,
					const void *ptr);

/*
**	General functions
*/

size_t			malloc_good_size(size_t size);

#endif
