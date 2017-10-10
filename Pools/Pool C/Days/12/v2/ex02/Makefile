# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpriou <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/17 09:12:53 by jpriou            #+#    #+#              #
#    Updated: 2017/08/24 09:49:34 by jpriou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_tail
FLAGS = -Wall -Wextra -Werror
FOLDER_FT = ftlib/
FILES_FT = ftlib/ft_putstr.c ftlib/ft_strcmp.c ftlib/ft_atoi.c
FILES_MAIN = main.c
FILES_OBJECTS = main.o ft_atoi.o ft_strcmp.o ft_putstr.o

all : $(NAME)

$(NAME) : $(FILES_OBJECTS)
	gcc $(FLAGS) $(FILES_OBJECTS) -o $(NAME)

%.o : $(FOLDER_FT)%.c
	gcc -c $(FLAGS) $? -I ./

main.o : main.c
	gcc -c $(FLAGS) $? -I ./

clean :
	rm -f $(FILES_OBJECTS)

fclean : clean
	rm -f $(NAME)

re : fclean all
