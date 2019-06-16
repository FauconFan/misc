# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    files.makefile                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/13 13:16:25 by jpriou            #+#    #+#              #
#    Updated: 2019/06/13 15:53:44 by jpriou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

API_FOLDER = api/
ENV_FOLDER = ft_env/
PH_FOLDER = ft_ph/
BLK_FOLDER = ft_blk/
UTILS_FOLDER = utils/

_API_FILES = \
	malloc.c \
	free.c \
	realloc.c \
	calloc.c \
	show_alloc_mem.c \
	show_alloc_mem_hex.c \
	ft_malloc_zone_create.c \
	ft_malloc_zone_destroy.c \
	malloc_size.c \
	malloc_good_size.c \

_ENV_FILES = \
	ft_env_get.c \
	ft_env_new.c \
	ft_env_munmap.c \
	ft_env_print.c \
	ft_env_alloc.c \
	ft_env_find_free.c \
	ft_env_find.c \
	ft_env_clear.c \
	ft_env_cache_len.c \
	ft_env_cache_get.c \
	ft_env_cache_put.c \
	ft_env_mzone_lock.c \
	ft_env_mzone_unlock.c \

_PH_FILES = \
	ft_ph_new.c \
	ft_ph_munmap.c \
	ft_ph_alloc.c \
	ft_ph_find_free.c \
	ft_ph_find.c \
	ft_ph_print.c \
	ft_ph_empty.c \
	ft_ph_is_in_page.c \

_BLK_FILES = \
	ft_blk_init.c \
	ft_blk_next.c \
	ft_blk_alloc.c \
	ft_blk_find_free.c \
	ft_blk_find.c \
	ft_blk_print.c \
	ft_blk_is_free.c \
	ft_blk_set_free.c \
	ft_blk_set_occupied.c \
	ft_blk_get_len_asked.c \

_UTILS_FILES = \
	std/ft_put_addr.c \
	std/ft_put_str.c \
	std/ft_put_uint.c \
	std/ft_bzero.c \
	std/ft_memcpy.c \
	std/ft_strequ.c \
	print_dump.c \
	mmap_utils.c \
	size_utils.c \
	math_check.c \

API_FILES = $(addprefix $(API_FOLDER), $(_API_FILES))
ENV_FILES = $(addprefix $(ENV_FOLDER), $(_ENV_FILES))
PH_FILES = $(addprefix $(PH_FOLDER), $(_PH_FILES))
BLK_FILES = $(addprefix $(BLK_FOLDER), $(_BLK_FILES))
UTILS_FILES = $(addprefix $(UTILS_FOLDER), $(_UTILS_FILES))

SRC_FILES = $(API_FILES) $(ENV_FILES) $(PH_FILES) $(BLK_FILES) $(UTILS_FILES)

HEADER_FILES = \
			ft_malloc.h \
			inc/ft_malloc_intern.h \
