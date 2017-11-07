# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/15 10:07:29 by jpriou            #+#    #+#              #
#    Updated: 2017/11/07 23:22:58 by jpriou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
GCC = gcc -Wall -Wextra -Werror -I ./

SRCS_FOLDER = src/
PARTIE1_FOLDER = Partie1/
PARTIE2_FOLDER = Partie2/
BONUS_FOLDER = Bonus/
MYBONUS_FOLDER = MyBonus/
BIN_FOLDER = bin/

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

PARTIE1_OBJ = 	$(patsubst $(SRCS_FOLDER)$(PARTIE1_FOLDER)%.c,$(BIN_FOLDER)%.o,$(PARTIE1))
PARTIE2_OBJ = 	$(patsubst $(SRCS_FOLDER)$(PARTIE2_FOLDER)%.c,$(BIN_FOLDER)%.o,$(PARTIE2))
BONUS_OBJ = 	$(patsubst $(SRCS_FOLDER)$(BONUS_FOLDER)%.c,$(BIN_FOLDER)%.o,$(BONUS))
MyBONUS_OBJ = 	$(patsubst $(SRCS_FOLDER)$(MYBONUS_FOLDER)%.c,$(BIN_FOLDER)%.o,$(MyBONUS))

FILES_O = $(PARTIE1_OBJ) $(PARTIE2_OBJ) $(BONUS_OBJ) $(MyBONUS_OBJ)

all: bin $(NAME)

$(NAME): $(FILES_O)
	ar rc $@ $^
	ranlib $@

$(BIN_FOLDER)%.o: $(SRCS_FOLDER)$(PARTIE1_FOLDER)%.c
	$(GCC) -c $? -o $@

$(BIN_FOLDER)%.o: $(SRCS_FOLDER)$(PARTIE2_FOLDER)%.c
	$(GCC) -c $? -o $@

$(BIN_FOLDER)%.o: $(SRCS_FOLDER)$(BONUS_FOLDER)%.c
	$(GCC) -c $? -o $@

$(BIN_FOLDER)%.o: $(SRCS_FOLDER)$(MYBONUS_FOLDER)%.c
	$(GCC) -c $? -o $@

bin:
	mkdir -p $(BIN_FOLDER)

clean:
	rm -f $(FILES_O)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re