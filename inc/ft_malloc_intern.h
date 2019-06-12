/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_intern.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 15:05:35 by jpriou            #+#    #+#             */
/*   Updated: 2019/06/12 08:13:44 by jpriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_INTERN_H
# define FT_MALLOC_INTERN_H

/*
**	This file is the center of my implementation of malloc
**
**	My implementation is based on simple linked list
**	I have three kind of lists
**		- Tiny list
**		- Small list
**		- Large list
**
**	Tiny list : tiny sized alloc (size between 1 and TINY_MAX)
**	Small list : small sized alloc (size between TINY_MAX + 1 and SMALL_MAX)
**	Large list : large sized alloc (size greater than SMALL_MAX)
**
**
**	The lib process some preallocation page that is done in the first use
**	of any function in the malloc family (except show_alloc_mem)
**
**	When a page must be allocated we ask more dependant of the type
**	For tiny page: We ask MULT_PAGE_TIBY * getpagesize() bytes
**	For small page: We ask MULT_PAGE_SMALL * getpagesize() bytes
**	For large page: We ask MULT_PAGE_LARGE * getpagesize() bytes
*/

# include <sys/mman.h>
# include <unistd.h>
# include <stdint.h>

/*
**	General defines
*/

# define TRUE				1
# define FALSE				0

# define STR_OF_BOOL(b)		((b) ? "true" : "false")

typedef unsigned char		t_bool;

/*
**	Global defines for the program
*/

# define TINY_MAX			512
# define SMALL_MAX			65536

# define DEFAULT_MIN_ALLOC	100
# define MULT_PAGE_TINY		4
# define MULT_PAGE_SMALL	16
# define MULT_PAGE_LARGE	1

/*
**	t_blk stands for the header of blocks
**	The actual space given to user if the multiple of 16 next to
**	the pointer of this struct
**	We generally returns block + 1
**
**	We can also find next block with len_block
**
**	The first thought was to have a header with just 2 bytes
**		- the first bit means if the block is free
**		- the 15th next bits is the length of the block
**	But some programs checks if the returned pointer is a multiple of 16
**	So to handle that, we could seperate the header of the block and the block
**	and just have some external pages that just manage headers.
**	But, we choose to keep thinks like that to simplify the implementation.
**	It is just a pedagogic project, we just have to understand how a libmalloc
**	works. If i must do a real libmalloc for professional application.
**	I would do this, and some more...
*/

typedef struct				s_blk
{
	size_t			len_block;
	uint8_t			is_free;
	char			pad[7];
}							t_blk;

# define NEXT_BLOCK(blk)	((t_blk *)(((char *)blk) + blk->len_block))

/*
**	t_ph stands for malloc_page_header.
**
**	It is managed as a simple linked list with the len of page
**	in the front of the page.
**
**	There is no difference of the management of tiny, small and large pages
**
**	We could also seperate headers of the page and
**	the actual content of the page.
**	(the same way that for blocks)
*/

typedef	struct				s_ph
{
	struct s_ph		*next_page;
	size_t			len_page;
}							t_ph;

/*
**	Global structure
*/

typedef struct				s_env {
	size_t	len_main;
	t_ph	*tn_header;
	t_ph	*sm_header;
	t_ph	*lrg_header;
}							t_env;

extern t_env				*g_ft_env;

/*
**	Functions used for the global t_env structure
**
**	get() returns an allocated t_env structure,
**			and initialized it in first use.
**	print() is used by show_alloc_mem
**	alloc() find an empty space of siwe len in pages
**			and allocated new pages if there is no space
**	find_free() find a pointer in all of the pages and free it
**			returns 0 if no pointer has been found
**				or the size of the fresh free space
*/

t_env						*ft_env_get(void);
void						ft_env_print(t_env *main);
t_blk						*ft_env_alloc(t_env *main, size_t len);
size_t						ft_env_find_free(t_env *main, void *ptr);

/*
**	Functions used for t_ph structure
**
**	new() calls mmap
**	print() for show_alloc_mem
**	alloc() search free space to allocate
**	find_free() free space in the actual page.
**			returns 0 if no pointer has been found
**				or the size of the fresh free space
*/

t_ph						*ft_ph_new(size_t size, size_t mult);
void						ft_ph_print(t_ph *ph);
t_blk						*ft_ph_alloc(
								t_ph *ph,
								size_t len,
								size_t mult);
size_t						ft_ph_find_free(t_ph *ph, void *ptr);

/*
**	Functions used for t_blk
**
**	init() initiliawze fields in the given void * pointer
**	print() for show_alloc_mem
**	alloc() search free space to allocate
**	find_free() free space in the actual page.
**			returns 0 if no pointer has been found
**				or the size of the fresh free space
*/

void						ft_blk_init(void *v, size_t remain_tot);
void						ft_blk_print(t_blk *block, size_t remain);
t_blk						*ft_blk_alloc(
								t_blk *block,
								size_t remain,
								size_t size);
size_t						ft_blk_find_free(
								t_blk *block,
								size_t remain,
								void *ptr);

/*
**	Utils
*/

/*
**	mmap_utils.c
**
**	mmap_good_size() => wrapper for mmap (multiple of getpagesize)
*/

void						*mmap_good_size(size_t *size, size_t mult);

/*
**	size_utils.c
**
**	size_multiple_16 => process a number greater (or equals)
**						than the given number that is multiple of 16
**	size_multiple_page => process a number greater (or equals)
**						  than the given number that is multiple of getpagesize
*/

void						size_multiple_16(size_t *new_len);
void						size_multiple_page(size_t *new_len);

/*
**	print utils
**
**	Some helpers to print stuff with write
*/

void						ft_put_str(char *str);
void						ft_put_str_ln(char *str);
void						ft_put_uint(unsigned long int nb);
void						ft_put_uint16(unsigned long int nb);
void						ft_put_uint_ln(unsigned long int nb);
void						ft_put_uint16_ln(unsigned long int nb);
void						ft_put_addr(void *v);
void						ft_put_addr_ln(void *v);

#endif
