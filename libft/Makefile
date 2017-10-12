# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/15 10:07:29 by jpriou            #+#    #+#              #
#    Updated: 2017/10/12 11:11:05 by jpriou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
GCC = gcc -g -Wall -Wextra -Werror -I ./includes/

SRCS_FOLDER = src/
PARTIE1_FOLDER = Partie1/
PARTIE2_FOLDER = Partie2/
BONUS_FOLDER = Bonus/
MYBONUS_FOLDER = MyBonus/
BIN_FOLDER = bin/

include variables_files.mk

FILES_O = $(PARTIE1_OBJ) $(PARTIE2_OBJ) $(BONUS_OBJ) $(MyBONUS_OBJ)

all: bin $(NAME)

$(NAME): $(FILES_O)
	ar rc $(NAME) $^
	ranlib $(NAME)

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

.PHONY: all $(NAME) clean fclean re