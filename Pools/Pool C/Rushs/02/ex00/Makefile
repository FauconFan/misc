# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpriou <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/19 08:31:50 by jpriou            #+#    #+#              #
#    Updated: 2017/08/20 22:01:42 by blarreze         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = colle-2
FLAGS = -Wall -Wextra -Werror
FOLDER_SRC = srcs/
FOLDER_FT = ft/
FOLDER_BIN = bin/
FOLDER_HEADER = ./
FILES_SRCS = $(FOLDER_SRC)main.c \
			 $(FOLDER_SRC)standard_input.c \
			 $(FOLDER_SRC)rush00.c \
			 $(FOLDER_SRC)id_recognize.c
FILES_FT = $(FOLDER_FT)ft_putchar.c \
		   $(FOLDER_FT)ft_putstr.c \
		   $(FOLDER_FT)ft_strcmp.c \
		   $(FOLDER_FT)ft_strcpy.c \
		   $(FOLDER_FT)ft_strlen.c \
		   $(FOLDER_FT)ft_putnbr.c
FILES_O = main.o \
		  standard_input.o \
		  rush00.o \
		  id_recognize.o \
		  ft_putchar.o \
		  ft_putstr.o \
		  ft_strcmp.o \
		  ft_strcpy.o \
		  ft_strlen.o \
		  ft_putnbr.o
FILES_O_BIN = 	$(FOLDER_BIN)main.o \
				$(FOLDER_BIN)standard_input.o \
				$(FOLDER_BIN)rush00.o \
				$(FOLDER_BIN)id_recognize.o \
				$(FOLDER_BIN)ft_putchar.o \
				$(FOLDER_BIN)ft_putstr.o \
				$(FOLDER_BIN)ft_strcmp.o \
				$(FOLDER_BIN)ft_strcpy.o \
				$(FOLDER_BIN)ft_strlen.o \
				$(FOLDER_BIN)ft_putnbr.o


all : $(NAME)

$(NAME):
	gcc -c $(FILES_FT) $(FILES_SRCS) -I $(FOLDER_HEADER)
	gcc $(FLAGS) $(FILES_O) -I $(FOLDER_HEADER) -o $(NAME)
	mv $(FILES_O) $(FOLDER_BIN)
clean:
	rm -f $(FILES_O_BIN)
fclean : clean
	rm -f $(NAME)
re : fclean all
