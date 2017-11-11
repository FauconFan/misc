# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/09 17:08:35 by jpriou            #+#    #+#              #
#    Updated: 2017/11/11 07:49:01 by jpriou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

L_FT = libft/

NAME = fillit
FLAGS = -Wall -Wextra -Werror -I libft/ -I includes/
LIBS = -L$(L_FT) -lft
CC = gcc

SRC_FOLDER = src/

CODE = main.c \
		main_utils.c \
		map.c \
		map_utils.c \
		solver.c \
		init.c \
		init_utils.c \
		piece_tetris_simp.c \
		piece_tetris_simp2.c

FILES_CODE = $(addprefix $(SRC_FOLDER), $(CODE))

FILES_OBJ = $(FILES_CODE:%.c=%.o)

all : $(NAME)

lib :
	make -C $(L_FT)

$(NAME) : lib $(FILES_OBJ)
	$(CC) $(FLAGS) $(FILES_OBJ) -o $(NAME) $(LIBS)

%.o : %.c
	$(CC) -c $(FLAGS) $? -o $@

clean :
	rm -f $(FILES_OBJ)
	make clean -C $(L_FT)

fclean : clean
	rm -rf $(NAME)
	make fclean -C $(L_FT)

re : fclean all
	make re -C $(L_FT)