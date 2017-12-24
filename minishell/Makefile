# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/21 08:09:16 by jpriou            #+#    #+#              #
#    Updated: 2017/12/24 09:38:37 by fauconfan        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC_FOLDER = src/
INCLUDES_FOLDER = includes/
BUILTIN_FOLDER = builtin/
UTILS_FOLDER = utils/
LIBFT_FOLDER = libft/

GWW = gcc -g -Wall -Wextra -Werror -I $(INCLUDES_FOLDER) -I $(LIBFT_FOLDER)
LIBS = -L libft -l ft

SRC_PROJECT = main.c \
				ms_read_from_input.c \
				ms_treat_cmd.c \
				ms_treat_unknown_cmd.c \
				ms_exec_fork_wait.c \

BUILTIN_PROJECT = cd.c \
					env.c \
					setenv.c \
					unsetenv.c \
					echo.c \

UTILS_PROJECT = ms_str_utils.c \
				ms_get_set_env_local.c \
				ms_env_utils.c \
				ms_env_sys_utils.c \
				ms_array_keys_utils.c \
				ms_file_error_utils.c \

SRC_FP = $(addprefix $(SRC_FOLDER), $(SRC_PROJECT))
BUILTIN_FP = $(addprefix $(SRC_FOLDER)$(BUILTIN_FOLDER), $(BUILTIN_PROJECT))
UTILS_FP = $(addprefix $(SRC_FOLDER)$(UTILS_FOLDER), $(UTILS_PROJECT))

ALL_SRC = $(SRC_FP) $(BUILTIN_FP) $(UTILS_FP)

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
