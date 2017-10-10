# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpriou <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/19 11:13:26 by jpriou            #+#    #+#              #
#    Updated: 2017/08/20 18:47:18 by jpriou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = eval_expr
FLAGS = -Wall -Wextra -Werror -I $(FOLDER_HEADER)
FOLDER_FT = ft/
FOLDER_HEADER = headers/
FOLDER_LIST = list/
FOLDER_BIN = bin/
FILES_FT = $(FOLDER_FT)ft_putchar.c \
		   $(FOLDER_FT)ft_putnbr.c \
		   $(FOLDER_FT)ft_strlen.c \
		   $(FOLDER_FT)ft_putstr.c \
		   $(FOLDER_FT)ft_atoi.c
FILES_MAIN = main.c \
			 eval_expr.c \
			 operation.c \
			 operation_treatment.c \
			 expr_treatment.c \
			 expr_check_state.c \
			 state_pattern.c
FILES_LIST = $(FOLDER_LIST)ft_create_elem.c \
			 $(FOLDER_LIST)ft_list_clear.c \
			 $(FOLDER_LIST)ft_list_push_back.c \
			 $(FOLDER_LIST)ft_list_size.c \
			 $(FOLDER_LIST)ft_build_expr.c \
			 $(FOLDER_LIST)ft_remove_next.c
OBJECTS = eval_expr.o expr_check_state.o expr_treatment.o \
		  ft_build_expr.o ft_create_elem.o ft_list_clear.o ft_list_push_back.o ft_list_size.o \
		  ft_putchar.o ft_putnbr.o ft_putstr.o ft_remove_next.o ft_strlen.o ft_atoi.o\
		  main.o operation.o operation_treatment.o state_pattern.o
OBJECTS_BIN = $(FOLDER_BIN)eval_expr.o $(FOLDER_BIN)expr_check_state.o $(FOLDER_BIN)expr_treatment.o \
		      $(FOLDER_BIN)ft_build_expr.o $(FOLDER_BIN)ft_create_elem.o $(FOLDER_BIN)ft_list_clear.o \
		      $(FOLDER_BIN)ft_list_push_back.o $(FOLDER_BIN)ft_list_size.o \
		      $(FOLDER_BIN)ft_putchar.o $(FOLDER_BIN)ft_putnbr.o $(FOLDER_BIN)ft_putstr.o \
		      $(FOLDER_BIN)ft_remove_next.o $(FOLDER_BIN)ft_strlen.o $(FOLDER_BIN)ft_atoi.o \
		      $(FOLDER_BIN)main.o $(FOLDER_BIN)operation.o $(FOLDER_BIN)operation_treatment.o \
		      $(FOLDER_BIN)state_pattern.o

all : $(NAME)

$(NAME) :
	@echo "Building"
	@gcc -c $(FLAGS) $(FILES_MAIN) $(FILES_FT) $(FILES_LIST)
	@mv $(OBJECTS) $(FOLDER_BIN)
	@gcc $(OBJECTS_BIN) -o $(NAME)
clean:
	@echo "Deleting .o"
	@rm -f $(OBJECTS_BIN)
fclean: clean
	@echo "Deleting $(NAME)"
	@rm -f $(NAME)
re: fclean all
	@echo "Code Rebuilt"
