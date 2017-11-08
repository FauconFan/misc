# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/09 17:08:35 by jpriou            #+#    #+#              #
#    Updated: 2017/11/08 18:18:49 by jpriou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

L_FT = libft/

NAME = fillit
FLAGS = -Wall -Wextra -Werror -I libft/ -I includes/
LIBS = -L$(L_FT) -lft
CC = clang

SRC_FOLDER = src/
BIN_FOLDER = bin/

FILES_CODE = $(SRC_FOLDER)main.c \
			 $(SRC_FOLDER)main_utils.c \
			 $(SRC_FOLDER)map.c \
			 $(SRC_FOLDER)map_utils.c \
			 $(SRC_FOLDER)solver.c \
			 $(SRC_FOLDER)init.c \
			 $(SRC_FOLDER)init_utils.c \
			 $(SRC_FOLDER)piece_tetris_simp.c
FILES_OBJ =	$(patsubst $(SRC_FOLDER)%.c,$(BIN_FOLDER)%.o,$(FILES_CODE))

all : $(NAME)

bin :
	mkdir -p $(BIN_FOLDER)

lib :
	make -C $(L_FT)

$(NAME) : bin lib $(FILES_OBJ)
	$(CC) $(FLAGS) $(FILES_OBJ) -o $(NAME) $(LIBS)

$(BIN_FOLDER)%.o : $(SRC_FOLDER)%.c 
	$(CC) -c $(FLAGS) $? -o $@

clean :
	rm -rf $(BIN_FOLDER)

fclean : clean
	rm -rf $(NAME)
	make fclean -C $(L_FT)

re : fclean all