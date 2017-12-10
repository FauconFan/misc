# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/05 12:09:48 by jpriou            #+#    #+#              #
#    Updated: 2017/12/10 17:37:05 by fauconfan        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC_FOLDER = src/
INCLUDES_FOLDER = includes/
LIBFT_FOLDER = libft/

LIBS = -L$(LIBFT_FOLDER) -lft
GWW = gcc -g -Wall -Wextra -Werror
INCLUDES_FLAGS = -I $(INCLUDES_FOLDER) -I $(LIBFT_FOLDER)$(INCLUDES_FOLDER) -I $(LIBFT_FOLDER)

SRC_CODE = main.c \
			ls_env_utils.c \
			ls_error_files_utils.c \
			ls_content_args_utils.c \

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
