# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/15 10:07:29 by jpriou            #+#    #+#              #
#    Updated: 2017/11/11 07:14:51 by jpriou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft
GCC = gcc -Wall -Wextra -Werror -I ./

SRCS_FOLDER = src/
PARTIE1_FOLDER = Partie1/
PARTIE2_FOLDER = Partie2/
BONUS_FOLDER = Bonus/
MYBONUS_FOLDER = MyBonus/

PARTIE1 = 	$(SRCS_FOLDER)$(PARTIE1_FOLDER)ft_memset.c \
			$(SRCS_FOLDER)$(PARTIE1_FOLDER)ft_bzero.c \
			$(SRCS_FOLDER)$(PARTIE1_FOLDER)ft_memcpy.c \
			$(SRCS_FOLDER)$(PARTIE1_FOLDER)ft_memccpy.c \
			$(SRCS_FOLDER)$(PARTIE1_FOLDER)ft_memmove.c \
			$(SRCS_FOLDER)$(PARTIE1_FOLDER)ft_memchr.c \
			$(SRCS_FOLDER)$(PARTIE1_FOLDER)ft_memcmp.c \
			$(SRCS_FOLDER)$(PARTIE1_FOLDER)ft_strlen.c \
			$(SRCS_FOLDER)$(PARTIE1_FOLDER)ft_strdup.c \
			$(SRCS_FOLDER)$(PARTIE1_FOLDER)ft_strcpy.c \
			$(SRCS_FOLDER)$(PARTIE1_FOLDER)ft_strncpy.c \
			$(SRCS_FOLDER)$(PARTIE1_FOLDER)ft_strcat.c \
			$(SRCS_FOLDER)$(PARTIE1_FOLDER)ft_strncat.c \
			$(SRCS_FOLDER)$(PARTIE1_FOLDER)ft_strlcat.c \
			$(SRCS_FOLDER)$(PARTIE1_FOLDER)ft_strchr.c \
			$(SRCS_FOLDER)$(PARTIE1_FOLDER)ft_strrchr.c \
			$(SRCS_FOLDER)$(PARTIE1_FOLDER)ft_strstr.c \
			$(SRCS_FOLDER)$(PARTIE1_FOLDER)ft_strnstr.c \
			$(SRCS_FOLDER)$(PARTIE1_FOLDER)ft_strcmp.c \
			$(SRCS_FOLDER)$(PARTIE1_FOLDER)ft_strncmp.c \
			$(SRCS_FOLDER)$(PARTIE1_FOLDER)ft_atoi.c \
			$(SRCS_FOLDER)$(PARTIE1_FOLDER)ft_isalnum.c \
			$(SRCS_FOLDER)$(PARTIE1_FOLDER)ft_isalpha.c \
			$(SRCS_FOLDER)$(PARTIE1_FOLDER)ft_isdigit.c \
			$(SRCS_FOLDER)$(PARTIE1_FOLDER)ft_isprint.c \
			$(SRCS_FOLDER)$(PARTIE1_FOLDER)ft_isascii.c \
			$(SRCS_FOLDER)$(PARTIE1_FOLDER)ft_toupper.c \
			$(SRCS_FOLDER)$(PARTIE1_FOLDER)ft_tolower.c

PARTIE2 = 	$(SRCS_FOLDER)$(PARTIE2_FOLDER)ft_memalloc.c \
			$(SRCS_FOLDER)$(PARTIE2_FOLDER)ft_memdel.c \
			$(SRCS_FOLDER)$(PARTIE2_FOLDER)ft_strnew.c \
			$(SRCS_FOLDER)$(PARTIE2_FOLDER)ft_strdel.c \
			$(SRCS_FOLDER)$(PARTIE2_FOLDER)ft_strclr.c \
			$(SRCS_FOLDER)$(PARTIE2_FOLDER)ft_striter.c \
			$(SRCS_FOLDER)$(PARTIE2_FOLDER)ft_striteri.c \
			$(SRCS_FOLDER)$(PARTIE2_FOLDER)ft_strmap.c \
			$(SRCS_FOLDER)$(PARTIE2_FOLDER)ft_strmapi.c \
			$(SRCS_FOLDER)$(PARTIE2_FOLDER)ft_strequ.c \
			$(SRCS_FOLDER)$(PARTIE2_FOLDER)ft_strnequ.c \
			$(SRCS_FOLDER)$(PARTIE2_FOLDER)ft_strsub.c \
			$(SRCS_FOLDER)$(PARTIE2_FOLDER)ft_strjoin.c \
			$(SRCS_FOLDER)$(PARTIE2_FOLDER)ft_strtrim.c \
			$(SRCS_FOLDER)$(PARTIE2_FOLDER)ft_strsplit.c \
			$(SRCS_FOLDER)$(PARTIE2_FOLDER)ft_itoa.c \
			$(SRCS_FOLDER)$(PARTIE2_FOLDER)ft_putchar.c \
			$(SRCS_FOLDER)$(PARTIE2_FOLDER)ft_putstr.c \
			$(SRCS_FOLDER)$(PARTIE2_FOLDER)ft_putendl.c \
			$(SRCS_FOLDER)$(PARTIE2_FOLDER)ft_putnbr.c \
			$(SRCS_FOLDER)$(PARTIE2_FOLDER)ft_putchar_fd.c \
			$(SRCS_FOLDER)$(PARTIE2_FOLDER)ft_putstr_fd.c \
			$(SRCS_FOLDER)$(PARTIE2_FOLDER)ft_putendl_fd.c \
			$(SRCS_FOLDER)$(PARTIE2_FOLDER)ft_putnbr_fd.c

BONUS = 	$(SRCS_FOLDER)$(BONUS_FOLDER)ft_lstnew.c \
			$(SRCS_FOLDER)$(BONUS_FOLDER)ft_lstdelone.c \
			$(SRCS_FOLDER)$(BONUS_FOLDER)ft_lstdel.c \
			$(SRCS_FOLDER)$(BONUS_FOLDER)ft_lstadd.c \
			$(SRCS_FOLDER)$(BONUS_FOLDER)ft_lstiter.c \
			$(SRCS_FOLDER)$(BONUS_FOLDER)ft_lstmap.c

MyBONUS = 	$(SRCS_FOLDER)$(MYBONUS_FOLDER)ft_strpos.c \
			$(SRCS_FOLDER)$(MYBONUS_FOLDER)ft_strrpos.c \
			$(SRCS_FOLDER)$(MYBONUS_FOLDER)ft_strcpos.c \
			$(SRCS_FOLDER)$(MYBONUS_FOLDER)ft_strcrpos.c \
			$(SRCS_FOLDER)$(MYBONUS_FOLDER)ft_strparse.c \
			$(SRCS_FOLDER)$(MYBONUS_FOLDER)ft_strparse_n_free.c \
			$(SRCS_FOLDER)$(MYBONUS_FOLDER)ft_putnbrl.c

PARTIE1_OBJ = 	$(PARTIE1:%.c=%.o)
PARTIE2_OBJ = 	$(PARTIE2:%.c=%.o)
BONUS_OBJ = 	$(BONUS:%.c=%.o)
MyBONUS_OBJ = 	$(MyBONUS:%.c=%.o)

FILES_O = $(PARTIE1_OBJ) $(PARTIE2_OBJ) $(BONUS_OBJ) $(MyBONUS_OBJ)

all: $(NAME).a

$(NAME): all

$(NAME).a: $(FILES_O)
	@echo "Compiling the library $@"
	@ar rc $@ $(FILES_O)
	@ranlib $@
	@echo "Library built successfully"

%.o: %.c
	@echo "Compiling $?"
	@$(GCC) -c $? -o $@

clean:
	@echo "removing all binary files"
	@rm -f $(FILES_O)

fclean: clean
	@echo "removing the library"
	@rm -f $(NAME).a

re: fclean all

.PHONY: $(NAME) all clean fclean re
