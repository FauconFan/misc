# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/27 09:05:22 by pepe              #+#    #+#              #
#    Updated: 2019/07/22 19:21:36 by jpriou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := Sully
FILE := Sully.c

OBJ = $(FILE:%.c=%.o)

CC = gcc

.PHONY: all
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) -c $< -o $@

.PHONY: clean
clean:
	rm -rf $(OBJ)

.PHONY: fclean
fclean: clean
	rm -rf $(NAME)
	rm -rf $(NAME)_*

.PHONY: re
re: fclean all

.PHONY: test
test: $(NAME)
	rm -rf test
	mkdir -p test
	cp $(NAME) test/$(NAME)
	(cd test && ./$(NAME) 20)
	ls -1 test | wc -l
	rm -rf test
