# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/27 09:05:22 by pepe              #+#    #+#              #
#    Updated: 2019/07/06 13:31:07 by jpriou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := Colleen
FILE := Colleen.c

OBJ = $(FILE:%.c=%.o)

CC = gcc

.PHONY: all
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) -c $? -o $@

.PHONY: clean
clean:
	rm -rf $(OBJ)

.PHONY: fclean
fclean: clean
	rm -rf $(NAME)

.PHONY: re
re: fclean all

.PHONY: testquine
testquine: $(NAME)
	bash -c 'diff $(FILE) <(./$(NAME))'
