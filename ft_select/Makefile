# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/11 14:44:38 by fauconfan         #+#    #+#              #
#    Updated: 2018/01/11 15:42:53 by fauconfan        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_select

SRC_FOLDER = src/
INCLUDES_FOLDER = includes/
LIBFT_FOLDER = libft/

SRC = main.c \

SRC_FP = $(addprefix $(SRC_FOLDER), $(SRC))

OBJ = $(SRC_FP:%.c=%.o)

GWW = gcc -Wall -Wextra -Werror -I $(INCLUDES_FOLDER) -I $(LIBFT_FOLDER)
LIBS = -L $(LIBFT_FOLDER) -l ft -l termcap

all : $(NAME)

$(NAME) : $(OBJ)
	make -C $(LIBFT_FOLDER)
	$(GWW) $(OBJ) -o $@ $(LIBS)

%.o : %.c
	$(GWW) -c $? -o $@

clean :
	rm -rf $(OBJ)
	make -C $(LIBFT_FOLDER) clean

fclean :
	rm -rf $(OBJ)
	rm -rf $(NAME)
	make -C $(LIBFT_FOLDER) fclean

re : fclean all