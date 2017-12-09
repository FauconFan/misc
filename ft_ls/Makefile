# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/05 12:09:48 by jpriou            #+#    #+#              #
#    Updated: 2017/12/09 09:39:07 by jpriou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC_FOLDER = src/
INCLUDES_FOLDER = includes/
LIBFT_FOLDER = libft/

LIBS = -L$(LIBFT_FOLDER) -lft
GWW = gcc -Wall -Wextra -Werror
INCLUDES_FLAGS = -I $(INCLUDES_FOLDER) -I $(LIBFT_FOLDER)$(INCLUDES_FOLDER)

SRC_CODE = main.c

SRC = $(addprefix $(SRC_FOLDER), $(SRC_CODE))

OBJ = $(SRC:%.c=%.o)

all : $(NAME)

$(NAME) : lib $(OBJ)
	$(GWW) $(INCLUDES_FLAGS) $(OBJ) -o $@ $(LIBS)

lib :
	make -C $(LIBFT_FOLDER)

%.o : %.c
	$(GWW) $(INCLUDES_FLAGS) -c $? -o $@ 

clean :
	rm -rf $(OBJ)
	make clean -C $(LIBFT_FOLDER)

fclean :
	rm -rf $(OBJ)
	rm -rf $(NAME)
	make fclean -C $(LIBFT_FOLDER)

re : fclean all
