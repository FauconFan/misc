# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/27 09:05:22 by pepe              #+#    #+#              #
#    Updated: 2018/09/27 17:39:19 by pepe             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := Sully
FILE := Sully.c

OBJ = $(FILE:%.c=%.o)

CC = gcc -g

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) -c $? -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)
	rm -rf $(NAME)_*

re: fclean all

testquine: all
	./$(NAME)
	cat $(Sully:%.c=%_5.c)

.PHONY: all clean fclean re
