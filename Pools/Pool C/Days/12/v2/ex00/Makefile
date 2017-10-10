# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpriou <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/16 14:57:50 by jpriou            #+#    #+#              #
#    Updated: 2017/08/24 09:45:13 by jpriou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror
NAME = ft_display_file

all : $(NAME)

$(NAME) : main.o
	gcc $< $(FLAGS) -o $(NAME)

main.o : main.c
	gcc -c $(FLAGS) main.c 

clean :
	@rm -f main.o

fclean : clean
	@rm -f $(NAME)

re : fclean all

