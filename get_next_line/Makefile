# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/15 18:43:28 by jpriou            #+#    #+#              #
#    Updated: 2017/09/15 18:44:08 by jpriou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test
FLAGS = -Wall -Wextra -Werror -I ./libft/includes/
LIB = -Llibft -lft

FILES_OBJ = get_next_line.o main.o

all: lib $(NAME)

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

lib :
	make -C libft

#rule to recopy libft
cpylib:
	rm -rf libft/
	cp -r ../libft .