# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/27 09:05:22 by pepe              #+#    #+#              #
#    Updated: 2019/07/22 18:41:13 by jpriou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := Grace
FILE := Grace.c
KID := Grace_kid.c

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
	rm -rf $(KID)

.PHONY: re
re: fclean all

.PHONY: testquine
testquine: $(NAME)
	rm -rf $(KID)
	./$(NAME)
	diff $(FILE) $(KID)
	rm -rf $(KID)
