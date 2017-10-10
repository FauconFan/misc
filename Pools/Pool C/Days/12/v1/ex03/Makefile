# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpriou <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/18 11:42:26 by jpriou            #+#    #+#              #
#    Updated: 2017/08/18 13:30:32 by jpriou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_hexdump
FLAGS = -Wall -Wextra -Werror
FOLDER_FT = ftlib/
FILES_FT = $(FOLDER_FT)ft_putchar.c $(FOLDER_FT)ft_putnbrdigit.c $(FOLDER_FT)ft_putstr.c $(FOLDER_FT)ft_strcmp.c $(FOLDER_FT)ft_strcpy.c
FILES_MAIN = main.c print.c

all :
	gcc $(FLAGS) $(FILES_FT) $(FILES_MAIN) -I ./ -o $(NAME)
clean :
	rm -f $(NAME)
fclean : clean
