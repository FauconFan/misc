# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/21 08:09:16 by jpriou            #+#    #+#              #
#    Updated: 2019/01/13 11:38:15 by jpriou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ssl

SRC_FOLDER = src/
INCLUDES_FOLDER = inc/
LIBFT_FOLDER = ../../my_awesome_libft/libft/

GWW = gcc -g -Wall -Wextra -Werror -I $(INCLUDES_FOLDER) -I $(LIBFT_FOLDER)
LIBS = -L $(LIBFT_FOLDER) -l ft

SRC_PROJECT = \
				parser/base_cmd.c \
				parser/dgst_cmd.c \
				parser/des_cmd.c \
				parser/cmds.c \
				structures/t_dgst_cmd.c \
				structures/t_des_cmd.c \
				structures/globals.c \
				core/do_dgst.c \
				core/do_base.c \
				core/do_des.c \
				utils/get_in.c \
				utils/set_out.c \
				main.c \

SRC_FP = $(addprefix $(SRC_FOLDER), $(SRC_PROJECT))

ALL_SRC = $(SRC_FP)

OBJ = $(ALL_SRC:%.c=%.o)

.PHONY: all
all : $(NAME)

$(NAME) : $(OBJ)
	make -C $(LIBFT_FOLDER)
	$(GWW) $(OBJ) -o $@ $(LIBS)

%.o : %.c
	$(GWW) -c $? -o $@

.PHONY: clean
clean :
	rm -rf $(OBJ)
	make -C $(LIBFT_FOLDER) clean

.PHONY: fclean
fclean :
	rm -rf $(OBJ)
	rm -rf $(NAME)
	make -C $(LIBFT_FOLDER) fclean

.PHONY: re
re : fclean all
