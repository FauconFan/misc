# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/12 17:06:05 by jpriou            #+#    #+#              #
#    Updated: 2017/11/11 12:05:34 by jpriou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test_printf

L_FT = libft/

FLAGS = -g -Wall -Wextra -Werror -I libft/ -I includes/
LIBS = -L$(L_FT) -lft
CC = gcc

SRC_FOLDER 				= src/
STRING_BUFFER_FOLDER 	= string_buffer/

TEST_FILE_CODE				= 	main.c \
								ft_printf.c
STRING_BUFFER_SRC_CODE		= 	string_buffer.c \
								string_buffer_utils.c

TEST_FILE 					= 	$(addprefix $(SRC_FOLDER),$(TEST_FILE_CODE))
STRING_BUFFER_SRC 			= 	$(addprefix $(SRC_FOLDER)$(STRING_BUFFER_FOLDER),$(STRING_BUFFER_SRC_CODE))

TEST_OBJ 					=	$(TEST_FILE:%.c=%.o)
STRING_BUFFER_OBJ			=	$(STRING_BUFFER_SRC:%.c=%.o)

FILES_OBJ 					= $(TEST_OBJ) $(STRING_BUFFER_OBJ)

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