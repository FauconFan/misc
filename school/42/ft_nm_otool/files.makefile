# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    files.makefile                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/17 11:13:01 by jpriou            #+#    #+#              #
#    Updated: 2019/07/01 09:47:19 by jpriou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

___MEM_FOLDER = std/mem/
___STR_FOLDER = std/str/
___INT_FOLDER = std/int/
___BPUT_FOLDER = std/ft_bput/
___BUFF_FOLDER = std/ft_buff/

___MEM_FILES = \
			ft_memcpy.c \
			ft_memset.c \
			ft_bzero.c \

___STR_FILES = \
			ft_isprint.c \
			ft_strnew.c \
			ft_strdup.c \
			ft_strndup.c \
			ft_strlen.c \
			ft_strequ.c \
			ft_strcmp.c \
			ft_strncmp.c \
			ft_strcpy.c \
			ft_strncpy.c \
			ft_toupper.c \
			ft_strcpos.c \
			ft_strncpos.c \
			ft_strnotcpos.c \
			ft_strformat1.c \
			ft_strformat2.c \

___INT_FILES = \
			ft_swap_uint.c \
			ft_antou.c \

___BPUT_FILES = \
			ft_bput_vm_addr.c \
			ft_bput_hex.c \
			ft_bput_str.c \
			ft_bput_uint.c \
			ft_bput_uint_base.c \

___BUFF_FILES = \
			ft_buff.c \
			ft_buff_init_custom.c \
			ft_buff_init_default.c \
			ft_buff_free_recu.c \
			ft_buff_print_recu.c \
			ft_buff_put_last.c \

__COMMON_FILES = \
			$(addprefix $(___MEM_FOLDER), $(___MEM_FILES)) \
			$(addprefix $(___STR_FOLDER), $(___STR_FILES)) \
			$(addprefix $(___INT_FOLDER), $(___INT_FILES)) \
			$(addprefix $(___BPUT_FOLDER), $(___BPUT_FILES)) \
			$(addprefix $(___BUFF_FOLDER), $(___BUFF_FILES)) \
			t_ldf/ft_ldf_init_mmap.c \
			t_ldf/ft_ldf_init_custom.c \
			t_ldf/ft_ldf_end.c \
			t_ldf/ft_ldf_print_name.c \
			t_ldf/ft_ldf_jmp.c \
			t_ldf/ft_ldf_jmp_str.c \
			utils/ft_check_str.c \
			utils/ft_swap.c \
			fat/fat.c \
			fat/fat_bname_mult_arch.c \
			fat/fat_do_all_arch.c \
			archive.c \

_COMMON_FILES = $(addprefix $(COM_FOLDER), $(__COMMON_FILES))

__NM_FILES = \
			ft_nm.c \
			nm_m64.c \
			nm_m32.c \
			t_meta_sect/ft_meta_sect_init.c \
			t_meta_sect/ft_meta_sect_load.c \
			t_sym/ft_sym_init.c \
			t_sym/ft_sym_print.c \
			t_sym/ft_syms_new.c \
			t_sym/ft_syms_free.c \
			t_sym/ft_syms_sort.c \
			t_sym/ft_syms_swap.c \
			t_sym/ft_syms_good_print.c \

_NM_FILES = $(addprefix $(NM_FOLDER), $(__NM_FILES))

__OTOOL_FILES = \
			ft_otool.c \
			otool_m64.c \
			otool_m32.c \
			otool_pretty_print.c \

_OTOOL_FILES = $(addprefix $(OTOOL_FOLDER), $(__OTOOL_FILES))

_NM_MAIN = main_nm.c
_OTOOL_MAIN = main_otool.c

COMMON_FILES = $(addprefix $(SRC_FOLDER), $(_COMMON_FILES))
NM_FILES = $(addprefix $(SRC_FOLDER), $(_NM_FILES))
OTOOL_FILES = $(addprefix $(SRC_FOLDER), $(_OTOOL_FILES))

NM_MAIN = $(addprefix $(SRC_FOLDER), $(_NM_MAIN))
OTOOL_MAIN = $(addprefix $(SRC_FOLDER), $(_OTOOL_MAIN))

HEADER_FILES = \
			$(INC_FOLDER)ft_nm_otool.h \
			$(INC_FOLDER)ft_nm.h \
			$(INC_FOLDER)ft_otool.h \
			$(INC_FOLDER)std.h \
