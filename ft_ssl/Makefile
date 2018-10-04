# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/21 08:09:16 by jpriou            #+#    #+#              #
#    Updated: 2018/10/03 18:37:21 by pepe             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ssl

SRC_FOLDER = src/
INCLUDES_FOLDER = inc/
LIBFT_FOLDER = ../../my_awesome_libft/libft/

GWW = gcc -Wall -Wextra -Werror -I $(INCLUDES_FOLDER) -I $(LIBFT_FOLDER)
LIBS = -L $(LIBFT_FOLDER) -l ft

SRC_PROJECT = \
				parser/base_cmd.c \
				parser/dgst_cmd.c \
				parser/cmds.c \
				custom_pbkdf2/custom_pbkdf2.c \
				custom_pbkdf2/ft_getrandom.c \
				main.c \
				t_dgst_cmd.c \
				do_dgst.c \
				do_base.c \

SRC_FP = $(addprefix $(SRC_FOLDER), $(SRC_PROJECT))

ALL_SRC = $(SRC_FP)

OBJ = $(ALL_SRC:%.c=%.o)

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

.PHONY: all clean fclean re
