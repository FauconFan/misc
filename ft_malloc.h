/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:46:42 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/13 11:58:48 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
# define FT_MALLOC_H

# include "inc/ft_malloc_intern.h"

void			*malloc(size_t size);
void			free(void *ptr);
void			*calloc(size_t nmemb, size_t size);
void			*realloc(void *ptr, size_t size);

void			show_alloc_mem(void);
void			show_alloc_mem_hex(void);

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

#endif
