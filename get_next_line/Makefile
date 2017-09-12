# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/12 14:07:46 by jpriou            #+#    #+#              #
#    Updated: 2017/09/12 14:14:47 by jpriou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test
FLAGS = -Wall -Wextra -Werror -I ./
LIB = -Llibft -lft

FILES_OBJ = get_next_line.o main.o

all: lib $(NAME) exec

$(NAME) : $(FILES_OBJ)
	gcc $(FLAGS) $^ $(LIB) -o $(NAME)

%.o : %.c
	gcc -c $(FLAGS) $? -o $@

clean :
	rm -f $(FILES_OBJ)

fclean : clean
	rm -f $(NAME)
	make fclean -C libft

re : fclean all

exec :
	./$(NAME)

lib :
	make -C libft