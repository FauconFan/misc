# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/09 17:08:35 by jpriou            #+#    #+#              #
#    Updated: 2017/11/14 14:48:37 by agrossma         ###   ########.fr        #
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

$(NAME) : $(L_FT)libft.a $(FILES_OBJ)
	$(CC) $(FLAGS) $(FILES_OBJ) -o $@ $(LIBS)

$(L_FT)libft.a:
	make -C $(L_FT)

%.o : %.c
	$(CC) -c $(FLAGS) $? -o $@

clean :
	rm -f $(FILES_OBJ)
	make clean -C $(L_FT)

fclean : clean
	rm -rf $(NAME)
	make fclean -C $(L_FT)

re : fclean all
