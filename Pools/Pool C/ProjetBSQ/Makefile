# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpriou <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/21 11:48:28 by jpriou            #+#    #+#              #
#    Updated: 2017/08/24 09:56:42 by jpriou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq
FLAGS = -Wall -Wextra -Werror
DEBUG_FLAGS = -g -fsanitize=address
FOLDER_FT = ft/
FOLDER_SRCS = srcs/
FOLDER_HEADERS = headers/
FILES_SRCS = $(FOLDER_SRCS)main.c \
			 $(FOLDER_SRCS)standard_input.c \
			 $(FOLDER_SRCS)entry_test.c \
			 $(FOLDER_SRCS)entry_build.c \
			 $(FOLDER_SRCS)solve.c
FILES_SRCS_OBJ = main.o \
			 	 standard_input.o \
			 	 entry_test.o \
			 	 entry_build.o \
			 	 solve.o
FILES_FT = $(FOLDER_FT)ft_putchar.c \
		   $(FOLDER_FT)ft_putstr.c \
		   $(FOLDER_FT)ft_putstrerr.c \
		   $(FOLDER_FT)ft_putnbr.c \
		   $(FOLDER_FT)ft_strcmp.c \
		   $(FOLDER_FT)ft_strcat.c \
		   $(FOLDER_FT)ft_strcpy.c \
		   $(FOLDER_FT)ft_strncpy.c \
		   $(FOLDER_FT)ft_strlen.c
FILES_FT_OBJ = ft_putchar.o \
		       ft_putstr.o \
		       ft_putstrerr.o \
		       ft_putnbr.o \
		       ft_strcmp.o \
		       ft_strcat.o \
		       ft_strcpy.o \
		       ft_strncpy.o \
		       ft_strlen.o
FILES = $(FILES_FT) $(FILES_SRCS)
FILES_OBJ = $(FILES_SRCS_OBJ) $(FILES_FT_OBJ)

all: $(NAME)

$(NAME): $(FILES_OBJ)
	gcc $(FLAGS) $(FILES_OBJ) -o $(NAME) -I$(FOLDER_HEADERS)

%.o : $(FOLDER_SRCS)%.c
	gcc -c $(FLAGS) $? -o $@ -I$(FOLDER_HEADERS)

%.o : $(FOLDER_FT)%.c
	gcc -c $(FLAGS) $? -o $@ -I$(FOLDER_HEADERS)

clean:
	rm -rf $(FILES_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
