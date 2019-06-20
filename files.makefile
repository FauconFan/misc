# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    files.makefile                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/17 11:13:01 by jpriou            #+#    #+#              #
#    Updated: 2019/06/20 12:16:24 by jpriou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

___MEM_FOLDER = std/mem/
___STR_FOLDER = std/str/
___INT_FOLDER = std/int/
___BUFF_FOLDER = std/ft_buff/

___MEM_FILES = \
			ft_memcpy.c \

___STR_FILES = \
			ft_strlen.c \
			ft_strequ.c \
			ft_strcmp.c \
			ft_toupper.c \

___INT_FILES = \
			ft_swap_int.c \
			ft_swap_uint.c \

___BUFF_FILES = \
			ft_bput_vm_addr.c \
			ft_bput_hex_char.c \
			ft_bput_str.c \
			ft_bput_uint.c \
			ft_bput_uint_base.c \
			ft_buff.c \

__COMMON_FILES = \
			$(addprefix $(___MEM_FOLDER), $(___MEM_FILES)) \
			$(addprefix $(___STR_FOLDER), $(___STR_FILES)) \
			$(addprefix $(___INT_FOLDER), $(___INT_FILES)) \
			$(addprefix $(___BUFF_FOLDER), $(___BUFF_FILES)) \
			t_ldf/ft_ldf_init.c \
			t_ldf/ft_ldf_end.c \
			t_ldf/ft_ldf_jmp.c \
			t_ldf/ft_ldf_jmp_str.c \
			fat/fat_cigam.c \
			utils/ft_check_str.c \
			get_arch.c \

_COMMON_FILES = $(addprefix $(COM_FOLDER), $(__COMMON_FILES))

__NM_FILES = \
			ft_nm.c \
			nm_m64.c \
			t_meta_sect/ft_meta_sect_init.c \
			t_meta_sect/ft_meta_sect_load.c \
			t_sym/ft_sym_init.c \
			t_sym/ft_sym_print.c \
			t_sym/ft_sym_sort.c \

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
			$(INC_FOLDER)ft_nm.h \
			$(INC_FOLDER)std.h \
