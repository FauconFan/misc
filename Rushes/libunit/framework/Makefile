# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/25 09:06:13 by jpriou            #+#    #+#              #
#    Updated: 2017/11/26 17:12:40 by jpriou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libunit

SRC_FOLDER = src/
INCLUDES_FOLDERS = includes/
LIBFT_PATH =    mylibft/
LIBFTA =        libft_unit_tests.a

CC = gcc
FLAGS = -Wall -Wextra -Werror -I $(INCLUDES_FOLDERS) -I $(LIBFT_PATH)$(INCLUDES_FOLDERS)

FM_SRC_FILES = main_utils.c \
				testing_fork.c \
				framework_auxiliary_functions.c \
				unit_test_utils.c \

FM_SRC_CODE = $(addprefix $(SRC_FOLDER), $(FM_SRC_FILES))

SRC = $(FM_SRC_CODE)

OBJ = $(SRC:%.c=%.o)

all : $(NAME)

$(NAME) : makelibft $(NAME).a

$(NAME).a : $(OBJ)
	@echo "Compiling the library $@"
	libtool -static -o $@ $(OBJ) $(LIBFT_PATH)$(LIBFTA)
	@echo "Library built successfully"

%.o : %.c
	@echo "Compiling $?"
	@$(CC) $(FLAGS) -c $? -o $@

makelibft:
	@make -C $(LIBFT_PATH)

clean :
	@echo "removing all binary files"
	@rm -f $(OBJ)
	@make fclean -C $(LIBFT_PATH)

fclean : clean
	@echo "removing the library"
	@rm -f $(NAME).a

re : fclean all

test : all
	gcc -Wall -Wextra -Werror tests/main.c tests/testtest/00_launcher.c \
		tests/testtest/01_ok.c \
		tests/testtest/02_ko.c \
		tests/testtest/03_ft_segf.c \
		tests/testtest/04_buse.c \
		-I tests/ -I $(INCLUDES_FOLDERS) -I $(LIBFT_PATH)$(INCLUDES_FOLDERS) \
		-o test_all -L./ -l unit
	./test_all
	rm -f test_all
	
.PHONY : $(NAME) all clean fclean re
