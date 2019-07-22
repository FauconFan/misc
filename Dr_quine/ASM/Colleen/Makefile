# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/06 14:30:24 by jpriou            #+#    #+#              #
#    Updated: 2019/07/22 19:21:43 by jpriou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := Colleen
FILE := Colleen.s

OBJ = $(FILE:%.s=%.o)

AS = nasm
LD = ld

AS_FLAG = -f macho64 --prefix _
LD_FLAG = -macosx_version_min 10.8 -lSystem

.PHONY: all
all: $(NAME)

$(NAME): $(OBJ)
	$(LD) $(LD_FLAG) $< -o $@

%.o: %.s
	$(AS) $(AS_FLAG) $< -o $@

.PHONY: clean
clean:
	rm -rf $(OBJ)

.PHONY: fclean
fclean: clean
	rm -rf $(NAME)

.PHONY: re
re: fclean all

.PHONY: test
test: $(NAME)
	bash -c 'diff $(FILE) <(./$(NAME))'
