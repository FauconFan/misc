# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/03 11:13:57 by fauconfan         #+#    #+#              #
#    Updated: 2018/02/10 12:17:43 by jpriou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = jpriou.filler

SRC_FOLDER = src/
INCLUDES_FOLDER = includes/
LIBFT_FOLDER = libft/

GWW = gcc -Wall -Wextra -Werror -I $(INCLUDES_FOLDER) -I $(LIBFT_FOLDER)
LIBS = -L libft -l ft

SRC = main.c \
		fl_envutils.c \
		fl_pieceutils.c \
		fl_maputils.c \
		fl_playerutils.c \
		fl_nextmove.c \
		fl_algo_findbestmove.c \
		fl_adapt_strategy.c \
		fl_math.c \
		fl_storeoppositecases.c \

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
