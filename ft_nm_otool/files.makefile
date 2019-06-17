# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    files.Makefile                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/17 11:13:01 by jpriou            #+#    #+#              #
#    Updated: 2019/06/17 11:14:40 by jpriou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

__COMMON_FILES = \
			t_ldf/ft_ldf_init.c \
			t_ldf/ft_ldf_end.c \
			std/ft_strequ.c \
			std/ft_put_vm_addr.c \
			std/ft_put_hex_char.c \
			std/ft_put_str.c \
			std/ft_put_uint.c \
			std/ft_put_uint_base.c \

__COMMON_ENTRY = main.c

_COMMON_FILES = \
			$(addprefix $(COM_FOLDER), $(__COMMON_FILES)) \
			$(__COMMON_ENTRY) \

__NM_FILES = \
			nm_m64.c \

__NM_ENTRY = ft_nm.c \

_NM_FILES = \
			$(addprefix $(NM_FOLDER), $(__NM_FILES)) \
			$(__NM_ENTRY) \

__OTOOL_FILES = \
			otool_m64.c \

__OTOOL_ENTRY = ft_otool.c \

_OTOOL_FILES = \
			$(addprefix $(OTOOL_FOLDER), $(__OTOOL_FILES)) \
			$(__OTOOL_ENTRY) \

COMMON_FILES = $(addprefix $(SRC_FOLDER), $(_COMMON_FILES))
NM_FILES = $(addprefix $(SRC_FOLDER), $(_NM_FILES))
OTOOL_FILES = $(addprefix $(SRC_FOLDER), $(_OTOOL_FILES))

HEADER_FILES = \
			$(INC_FOLDER)ft_nm_otool.h \
