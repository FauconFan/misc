# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/09 17:08:35 by jpriou            #+#    #+#              #
#    Updated: 2017/10/10 12:29:13 by jpriou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

L_FT = libft/

NAME = fillit
FLAGS = -g -ggdb -Wall -Wextra -Werror -I libft/includes -I includes/
LIBS = -L$(L_FT) -lft
CC = gcc

SRC_FOLDER = src/
BIN_FOLDER = bin/

FILES_CODE = $(SRC_FOLDER)main.c \
			 $(SRC_FOLDER)init.c \
			 $(SRC_FOLDER)piece_tetris.c
FILES_OBJ = $(BIN_FOLDER)main.o \
			$(BIN_FOLDER)init.o \
			$(BIN_FOLDER)piece_tetris.o

all : bin lib $(NAME)

bin :
	mkdir -p $(BIN_FOLDER)

lib :
	make -C $(L_FT)

$(NAME) : $(FILES_OBJ)
	$(CC) $(FLAGS) $^ -o $(NAME) $(LIBS)

$(BIN_FOLDER)%.o : $(SRC_FOLDER)%.c 
	$(CC) -c $(FLAGS) $? -o $@

clean :
	rm -rf $(BIN_FOLDER)

fclean : clean
	rm -rf $(NAME)
	make -C fclean $(L_FT)

re : fclean all