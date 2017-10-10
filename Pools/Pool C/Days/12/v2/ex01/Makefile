# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpriou <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/16 14:57:50 by jpriou            #+#    #+#              #
#    Updated: 2017/08/24 09:44:38 by jpriou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror
NAME = ft_cat

all : $(NAME)

$(NAME) : main.o
	gcc $^ -o $@

main.o : main.c
	gcc -c $(FLAGS) $<

clean :
	rm -f main.o

fclean : clean
	rm -f $(NAME)

re : fclean all
