# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/12 17:06:05 by jpriou            #+#    #+#              #
#    Updated: 2017/11/12 13:23:57 by jpriou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

L_FT = libft/

FLAGS = -Wall -Wextra -Werror -I libft/ -I includes/
LIBS = -L$(L_FT) -lft
CC = gcc

SRC_FOLDER 				= src/

TEST_FILE_CODE				= 	main.c
SRC_CODE					= 	ft_printf.c \
								string_buffer_utils.c \
								string_buffer.c \
								treat_data_utils.c \
								set_values_treat_data.c

TEST_FILE 					= 	$(addprefix $(SRC_FOLDER),$(TEST_FILE_CODE))
SRC 						= 	$(addprefix $(SRC_FOLDER),$(SRC_CODE))

TEST_OBJ 					=	$(TEST_FILE:%.c=%.o)
SRC_OBJ						=	$(SRC:%.c=%.o)

FILES_OBJ 					= $(SRC_OBJ)

all : $(NAME)

$(NAME) : lib $(FILES_OBJ)
	ar rc $@ $(FILES_OBJ) $(L_FT)*.o
	ranlib $@

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

test :
	make .
	gcc $(TEST_FILE) -L. -lftprintf -I libft/ -I includes/
	./a.out
	rm -f a.out