# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    files.makefile                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/17 11:13:01 by jpriou            #+#    #+#              #
#    Updated: 2019/06/18 09:46:52 by jpriou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

__COMMON_FILES = \
			t_ldf/ft_ldf_init.c \
			t_ldf/ft_ldf_end.c \
			std/ft_toupper.c \
			std/ft_strequ.c \
			std/ft_strcmp.c \
			std/ft_memcpy.c \
			std/ft_put_vm_addr.c \
			std/ft_put_hex_char.c \
			std/ft_put_str.c \
			std/ft_put_uint.c \
			std/ft_put_uint_base.c \

_COMMON_FILES = $(addprefix $(COM_FOLDER), $(__COMMON_FILES))

__NM_FILES = \
			ft_nm.c \
			nm_m64.c \
			t_meta_sect/ft_meta_sect_init.c \
			t_meta_sect/ft_meta_sect_load.c \
			t_sym/ft_sym_init.c \
			t_sym/ft_sym_print.c \
			t_sym/ft_sym_sort_by_name.c \

_NM_FILES = $(addprefix $(NM_FOLDER), $(__NM_FILES))

__OTOOL_FILES = \
			ft_otool.c \
			otool_m64.c \

_OTOOL_FILES = $(addprefix $(OTOOL_FOLDER), $(__OTOOL_FILES))

_COMMON_MAIN = main_o.c
_NM_MAIN = main_nm.c
_OTOOL_MAIN = main_otool.c

COMMON_FILES = $(addprefix $(SRC_FOLDER), $(_COMMON_FILES))
NM_FILES = $(addprefix $(SRC_FOLDER), $(_NM_FILES))
OTOOL_FILES = $(addprefix $(SRC_FOLDER), $(_OTOOL_FILES))

COMMON_MAIN = $(addprefix $(SRC_FOLDER), $(_COMMON_MAIN))
NM_MAIN = $(addprefix $(SRC_FOLDER), $(_NM_MAIN))
OTOOL_MAIN = $(addprefix $(SRC_FOLDER), $(_OTOOL_MAIN))

HEADER_FILES = \
			$(INC_FOLDER)ft_nm_otool.h \
