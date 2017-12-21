# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/21 08:09:16 by jpriou            #+#    #+#              #
#    Updated: 2017/12/21 18:56:28 by jpriou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC_FOLDER = src/
INCLUDES_FOLDER = includes/
LIBFT_FOLDER = libft/

GWW = gcc -g -Wall -Wextra -Werror -I $(INCLUDES_FOLDER) -I $(LIBFT_FOLDER)
LIBS = -L libft -l ft

SRC_PROJECT = main.c \
				ms_read_from_input.c \
				ms_treat_cmd.c \
				ms_env_utils.c \
				ms_env_sys_utils.c \
				ms_builtin1.c \
				ms_treat_path.c \
				ms_exec_fork_wait.c \
				ms_str_utils.c \

SRC_FP = $(addprefix $(SRC_FOLDER), $(SRC_PROJECT))

OBJ = $(SRC_FP:%.c=%.o)

all : $(NAME)

$(NAME) : lib $(OBJ)
	$(GWW) $(OBJ) -o $@ $(LIBS)

%.o : %.c
	$(GWW) -c $? -o $@

lib :
	make -C $(LIBFT_FOLDER)

clean :
	rm -rf $(OBJ)
	make -C $(LIBFT_FOLDER) clean

fclean :
	rm -rf $(OBJ)
	rm -rf $(NAME)
	make -C $(LIBFT_FOLDER) fclean

re : fclean all
