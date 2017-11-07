# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/12 17:06:05 by jpriou            #+#    #+#              #
#    Updated: 2017/11/07 18:04:02 by jpriou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test_printf

L_FT = libft/

FLAGS = -g -Wall -Wextra -Werror -I libft/ -I includes/
LIBS = -L$(L_FT) -lft
CC = gcc

SRC_FOLDER 				= src/
BIN_FOLDER 				= bin/
STRING_BUFFER_FOLDER 	= string_buffer/

TEST_FILE 					= 	$(SRC_FOLDER)main.c \
								$(SRC_FOLDER)ft_printf.c
STRING_BUFFER_SRC 			= 	$(SRC_FOLDER)$(STRING_BUFFER_FOLDER)string_buffer.c \
								$(SRC_FOLDER)$(STRING_BUFFER_FOLDER)string_buffer_utils.c

TEST_OBJ 					= 	$(patsubst $(SRC_FOLDER)%.c,$(BIN_FOLDER)%.o,$(TEST_FILE))
STRING_BUFFER_OBJ 			= 	$(patsubst $(SRC_FOLDER)$(STRING_BUFFER_FOLDER)%.c,$(BIN_FOLDER)%.o,$(STRING_BUFFER_SRC))

FILES_OBJ 					= $(TEST_OBJ) $(STRING_BUFFER_OBJ)

all : bin lib $(NAME)

$(NAME) : $(FILES_OBJ)
	$(CC) $(FLAGS) $^ -o $(NAME) $(LIBS)

$(BIN_FOLDER)%.o : $(SRC_FOLDER)%.c
	$(CC) -c $(FLAGS) $? -o $@

$(BIN_FOLDER)%.o : $(SRC_FOLDER)$(STRING_BUFFER_FOLDER)%.c
	$(CC) -c $(FLAGS) $? -o $@

lib :
	make -C $(L_FT)

bin :
	mkdir -p $(BIN_FOLDER)

clean :
	rm -rf $(BIN_FOLDER)

fclean : clean
	rm -rf $(NAME)
	make fclean -C $(L_FT)

re : fclean all