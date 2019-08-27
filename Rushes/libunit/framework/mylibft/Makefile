# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/05 13:52:24 by dwald             #+#    #+#              #
#    Updated: 2017/11/26 13:05:06 by jpriou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 		libft_unit_tests.a

SRC_FILES	=	my_atoi.c \
				my_bzero.c \
				my_countdigits.c \
				my_isalnum.c \
				my_isalpha.c \
				my_isascii.c \
				my_isdigit.c \
				my_isprint.c \
				my_iswhitespaces.c \
				my_itoa.c \
				my_memalloc.c \
				my_memccpy.c \
				my_memchr.c \
				my_memcmp.c \
				my_memcpy.c \
				my_memdel.c \
				my_memdup.c \
				my_memmove.c \
				my_memset.c \
				my_myputchar.c \
				my_myputendl.c \
				my_myputnbr.c \
				my_myputstr.c \
				my_protect_malloc.c \
				my_putchar.c \
				my_putchar_fd.c \
				my_putendl.c \
				my_putendl_fd.c \
				my_putnbr.c \
				my_putnbrn.c \
				my_putnbr_base.c \
				my_putnbr_fd.c \
				my_putstr.c \
				my_putstr_fd.c \
				my_strcat.c \
				my_strchr.c \
				my_strclr.c \
				my_strcmp.c \
				my_strcpy.c \
				my_strdel.c \
				my_strdup.c \
				my_strdupfree.c \
				my_strequ.c \
				my_striter.c \
				my_striteri.c \
				my_strjoin.c \
				my_strlcat.c \
				my_strlen.c \
				my_strmap.c \
				my_strmapi.c \
				my_strmemrev.c \
				my_strncat.c \
				my_strncmp.c \
				my_strncpy.c \
				my_strndup.c \
				my_strndupfree.c \
				my_strnequ.c \
				my_strnew.c \
				my_strnewset.c \
				my_strnstr.c \
				my_strrchr.c \
				my_strrev.c \
				my_strsplit.c \
				my_strstr.c \
				my_strsub.c \
				my_strtrim.c \
				my_swap.c \
				my_tolower.c \
				my_toupper.c \

SRC_PATH	=	srcs

OBJ_PATH	=	objs

SRC			=	$(addprefix $(SRC_PATH)/,$(SRC_FILES))

OBJ			=	$(addprefix $(OBJ_PATH)/,$(SRC_FILES:.c=.o))

INC			=	includes

CC			=	gcc

FLAGS		=	-Wall -Wextra -Werror -O3

GREEN		=	\033[0;32m
RED			=	\033[0;31m
NC			=	\033[0m

all		: 	$(NAME)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
			@printf "✅  $(notdir $<)\r"
			@mkdir -p $(OBJ_PATH)
			@$(CC) $(FLAGS) -I $(INC) -o $@ -c $<

$(NAME)	:	$(OBJ)
			@ar rc $(NAME) $(OBJ)
			@ranlib $(NAME)
			@echo "$(GREEN)Success : $(NC)compilation libft_unit_tests.a"

clean	:
				@/bin/rm -f 	$(OBJ)
				@echo "$(RED)---all objects removed---$(NC)"

fclean	: 		clean
				/bin/rm -f 	$(NAME)
				@echo "$(RED)---libmy removed completely---$(NC)"

re		:		fclean all

ree		:		re
				rm -f $(OBJ)

.PHONY: all clean fclean re ree
