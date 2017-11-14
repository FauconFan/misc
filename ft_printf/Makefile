# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/12 17:06:05 by jpriou            #+#    #+#              #
#    Updated: 2017/11/14 19:27:28 by jpriou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf

L_FT = libft/

FLAGS = -Wall -Wextra -Werror -I libft/ -I includes/ -I includes/converters/
LIBS = -L$(L_FT) -lft
CC = gcc

SRC_FOLDER 				= src/
CONVERTERS_FOLDER		= converters/

TEST_FILE_CODE				= 	main.c
SRC_CODE					= 	ft_printf.c \
								treat_data_utils.c \
								set_values_treat_data.c \
								set_values_treat_data2.c \
								build_str_treat_data.c
CONVERTER_CODE				=	management.c \
								ft_lltoa_n_ulltoa.c \
								ci_sep.c \
								ci_numbers.c

TEST_FILE 					= 	$(addprefix $(SRC_FOLDER),$(TEST_FILE_CODE))
SRC 						= 	$(addprefix $(SRC_FOLDER),$(SRC_CODE))
CONVERTER_SRC				=	$(addprefix $(SRC_FOLDER)$(CONVERTERS_FOLDER), $(CONVERTER_CODE))

TEST_OBJ 					=	$(TEST_FILE:%.c=%.o)
SRC_OBJ						=	$(SRC:%.c=%.o)
CONVERTER_OBJ				=	$(CONVERTER_SRC:%.c=%.o)

FILES_OBJ 					= 	$(SRC_OBJ) $(CONVERTER_OBJ)

all : $(NAME).a

$(NAME): all

$(NAME).a : $(L_FT)libft.a $(FILES_OBJ)
	ar rc $@ $(L_FT)libft.a $(FILES_OBJ)
	ranlib $@

%.o: %.c
	$(CC) -c $(FLAGS) $? -o $@

$(L_FT)libft.a :
	make -C $(L_FT)

clean :
	rm -rf $(FILES_OBJ)
	make clean -C $(L_FT)

fclean : clean
	rm -rf $(NAME).a
	make fclean -C $(L_FT)

re : fclean all

test :
	make
	gcc $(TEST_FILE) -L. -lftprintf -I libft/ -I includes/ -I includes/converters/
	./a.out
	rm -f a.out