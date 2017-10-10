# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpriou <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/13 19:37:03 by jpriou            #+#    #+#              #
#    Updated: 2017/08/14 16:55:27 by jpriou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_LIB = libft.a
F_SRCS = srcs
F_HEADERS = includes
FLAGS = -Wall -Wextra -Werror
PUTCHAR = ft_putchar
PUTSTR = ft_putstr
STRCMP = ft_strcmp
STRLEN = ft_strlen
SWAP = ft_swap
ALL_POINT_O = $(PUTCHAR).o $(PUTSTR).o $(STRCMP).o $(STRLEN).o $(SWAP).o

all :
	gcc $(FLAGS) -c $(F_SRCS)/$(PUTCHAR).c \
		-c $(F_SRCS)/$(PUTSTR).c \
		-c $(F_SRCS)/$(STRCMP).c \
		-c $(F_SRCS)/$(STRLEN).c \
		-c $(F_SRCS)/$(SWAP).c \
		-I $(F_HEADERS)
	ar rc $(NAME_LIB) $(ALL_POINT_O)
	ranlib $(NAME_LIB)
clean :
	rm -f $(ALL_POINT_O) 
fclean : clean
	rm -f $(NAME_LIB)
re : fclean all
