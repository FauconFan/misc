# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pepe <pepe@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/27 09:05:22 by pepe              #+#    #+#              #
#    Updated: 2018/09/27 16:25:00 by pepe             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := Grace
FILE := Grace.c
KID := Grace_kid.c

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
	rm -rf $(KID)

re: fclean all

testquine: all
	./$(NAME)
	cat $(KID)
	diff $(FILE) $(KID)
	rm -rf $(KID)

.PHONY: all clean fclean re testquine
