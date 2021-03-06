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

SRC_LIBFT_CHAR = ft_isalnum.c \
				ft_isalpha.c \
				ft_isascii.c \
				ft_isblank.c \
				ft_isdigit.c \
				ft_islower.c \
				ft_isprint.c \
				ft_isspace.c \
				ft_isupper.c \
				ft_iswhitespace.c \
				ft_isxdigit.c \
				ft_tolower.c \
				ft_toupper.c \

SRC_LIBFT_CHAR_FP = $(addprefix $(SRC_FOLDER)$(LIBFT_CHAR_FOLDER), $(SRC_LIBFT_CHAR))
