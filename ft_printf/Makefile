# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/12 17:06:05 by jpriou            #+#    #+#              #
#    Updated: 2017/11/12 09:21:54 by jpriou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test_printf

L_FT = libft/

FLAGS = -Wall -Wextra -Werror -I libft/ -I includes/
LIBS = -L$(L_FT) -lft
CC = gcc

SRC_FOLDER 				= src/

TEST_FILE_CODE				= 	main.c
SRC_CODE					= 	string_buffer.c \
								string_buffer_utils.c \
								ft_printf.c \
								treat_data_utils.c \
								set_values_treat_data.c

TEST_FILE 					= 	$(addprefix $(SRC_FOLDER),$(TEST_FILE_CODE))
SRC 						= 	$(addprefix $(SRC_FOLDER),$(SRC_CODE))

TEST_OBJ 					=	$(TEST_FILE:%.c=%.o)
SRC_OBJ						=	$(SRC:%.c=%.o)

FILES_OBJ 					= $(TEST_OBJ) $(SRC_OBJ)

all : lib $(NAME)

$(NAME) : $(FILES_OBJ)
	$(CC) $(FLAGS) $^ -o $(NAME) $(LIBS)

%.o: %.c
	$(CC) -c $(FLAGS) $? -o $@

lib :
	make -C $(L_FT)

clean :
	rm -rf $(FILES_OBJ)
	make clean -C $(L_FT)

fclean : clean
	rm -rf $(NAME)
	make fclean -C $(L_FT)

re : fclean all