# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/03 11:13:57 by fauconfan         #+#    #+#              #
#    Updated: 2018/02/11 00:32:19 by fauconfan        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = jpriou.filler

SRC_FOLDER = src/
INCLUDES_FOLDER = includes/
LIBFT_FOLDER = libft/

GWW = gcc -Wall -Wextra -Werror -I $(INCLUDES_FOLDER) -I $(LIBFT_FOLDER)
LIBS = -L libft -l ft

SRC = main.c \
		alloc/fl_envutils.c \
		alloc/fl_freeutils.c \
		formatIO/fl_formatutils.c \
		formatIO/fl_formatutils_map.c \
		formatIO/fl_formatutils_piece.c \
		board/fl_pieceutils.c \
		board/fl_maputils.c \
		board/fl_playerutils.c \
		algo/fl_nextmove.c \
		algo/fl_algo_findbestmove.c \
		algo/fl_adapt_strategy.c \
		algo/fl_math.c \
		algo/fl_storeoppositecases.c \

SRC_FP = $(addprefix $(SRC_FOLDER), $(SRC))

OBJ = $(SRC_FP:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT_FOLDER)
	$(GWW) $(OBJ) -o $@ $(LIBS)

%.o: %.c
	$(GWW) -c $? -o $@

clean :
	rm -rf $(OBJ)
	make -C $(LIBFT_FOLDER) clean

fclean :
	rm -rf $(OBJ)
	rm -rf $(NAME)
	make -C $(LIBFT_FOLDER) fclean

re : fclean all
