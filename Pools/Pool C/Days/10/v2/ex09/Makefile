# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpriou <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/14 13:36:45 by jpriou            #+#    #+#              #
#    Updated: 2017/08/14 17:40:41 by jpriou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_advanced_do-op
FILES_FT = ft/ft_atoi.c ft/ft_putchar.c ft/ft_putnbr.c ft/ft_putstr.c ft/ft_strcmp.c
FILES_MAIN = main.c operation.c usage.c

all :
	gcc -Wall -Wextra -Werror $(FILES_FT) $(FILES_MAIN) -I ./ -o $(NAME)
clean :
	rm -f $(NAME)
