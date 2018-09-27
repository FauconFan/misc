# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/27 09:05:22 by pepe              #+#    #+#              #
#    Updated: 2018/09/27 16:25:07 by pepe             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := Colleen
FILE := Colleen.c

OBJ = $(FILE:%.c=%.o)

CC = gcc

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) -c $? -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

testquine: all
	./$(NAME) | tee diff1
	diff diff1 $(FILE) || true
	rm diff1

.PHONY: all clean fclean re testquine
