# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpriou <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/16 14:57:50 by jpriou            #+#    #+#              #
#    Updated: 2017/08/16 16:23:55 by jpriou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror
NAME_EXEC = ft_cat
FOLDER_FT = ftlib/
FILES_FT = $(FOLDER_FT)ft_putstr.c
FILES_MAIN = main.c

all :
	gcc $(FLAGS) $(FILES_FT) $(FILES_MAIN) -I ./ -o $(NAME_EXEC)
clean :
	rm -f $(NAME_EXEC)
fclean : clean

