# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fauconfan <fauconfan@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/12 17:06:05 by jpriou            #+#    #+#              #
#    Updated: 2017/11/29 08:42:27 by fauconfan        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf

L_FT = libft/
L_FTA = libft.a

FLAGS = -g -Wall -Wextra -Werror -I libft/ -I includes/ -I includes/converters/
LIBS = -L$(L_FT) -lft
CC = gcc

SRC_FOLDER 				= src/
CONVERTERS_FOLDER		= converters/

TEST_FILE_CODE				= 	main.c \

SRC_CODE					= 	ft_printf.c \
								treat_data_utils.c \
								set_values_treat_data.c \
								set_values_treat_data2.c \
								string_buffer.c \
								string_buffer_utils.c \

CONVERTER_CODE				=	management.c \
								ft_lltoa_n_ulltoa.c \
								ci_sep.c \
								ci_numbers.c \
								ci_string_ascii.c \
								ci_string_unicode.c \
								ci_numbers_utils.c \

TEST_FILE 					= 	$(addprefix $(SRC_FOLDER), $(TEST_FILE_CODE))
SRC 						= 	$(addprefix $(SRC_FOLDER), $(SRC_CODE))
CONVERTER_SRC				=	$(addprefix $(SRC_FOLDER)$(CONVERTERS_FOLDER), $(CONVERTER_CODE))

TEST_OBJ 					=	$(TEST_FILE:%.c=%.o)
SRC_OBJ						=	$(SRC:%.c=%.o)
CONVERTER_OBJ				=	$(CONVERTER_SRC:%.c=%.o)

FILES_OBJ 					= 	$(SRC_OBJ) $(CONVERTER_OBJ)

all : $(NAME).a

$(NAME): all

$(NAME).a : $(FILES_OBJ) $(L_FT)$(L_FTA)
	#libtool -static -o $@ $^
	ar rc $@ $(FILES_OBJ) libft/*.o
	ranlib $@

$(L_FT)$(L_FTA):
	make -C $(L_FT)

%.o: %.c
	$(CC) -c $(FLAGS) $? -o $@

clean :
	rm -rf $(FILES_OBJ)
	make fclean -C $(L_FT)

fclean : clean
	rm -rf $(NAME).a

re : fclean all

test :
	make
	gcc $(TEST_FILE) -L. -lftprintf -I libft/ -I includes/ -I includes/converters/
	./a.out | cat -e
	@rm -f a.out
