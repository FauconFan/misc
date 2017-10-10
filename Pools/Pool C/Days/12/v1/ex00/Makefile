# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpriou <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/16 14:57:50 by jpriou            #+#    #+#              #
#    Updated: 2017/08/16 15:22:55 by jpriou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror
NAME_EXEC = ft_display_file
FOLDER_FT = ftlib/
FILES_FT = $(FOLDER_FT)ft_putstr.c
FILES_MAIN = main.c

all :
	gcc $(FLAGS) $(FILES_FT) $(FILES_MAIN) -I ./ -o $(NAME_EXEC)
clean :
	rm -f $(NAME_EXEC)
fclean : clean

