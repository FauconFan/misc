# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/03 15:58:37 by fauconfan         #+#    #+#              #
#    Updated: 2017/12/03 16:02:20 by fauconfan        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_FT_PRINTF = ft_printf_family.c \
				ft_vprintf_family.c  \
				treat_data_utils.c \
				set_values_treat_data.c \
				set_values_treat_data2.c \
				string_buffer.c \
				string_buffer_utils.c \

SRC_FT_PRINTF_CONVERTERS = ft_lltoa_n_ulltoa.c \
							ci_sep.c \
							ci_numbers.c \
							ci_string_ascii.c \
							ci_string_unicode.c \
							ci_string_unicode_utils.c \
							ci_numbers_utils.c \
							ci_numbers_utils2.c \
							ci_unused_flags.c \

SRC_FT_PRINTF_CONVERTERS_TMP = $(addprefix $(CONVERTERS_FT_PRINTF_FOLDER), $(SRC_FT_PRINTF_CONVERTERS))
SRC_FT_PRINTF += $(SRC_FT_PRINTF_CONVERTERS_TMP)

SRC_FT_PRINTF_FP = $(addprefix $(SRC_FOLDER)$(FT_PRINTF_FOLDER), $(SRC_FT_PRINTF))
