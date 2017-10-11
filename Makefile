# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/10 19:06:31 by jpriou            #+#    #+#              #
#    Updated: 2017/10/11 21:03:31 by jpriou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RENDU_DIR = rendu/

GET_NEXT_LINE_DIR = get_next_line/
GET_NEXT_LINE_RENDU_DIR = $(RENDU_DIR)$(GET_NEXT_LINE_DIR)

FILLIT_DIR = fillit/
FILLIT_RENDU_DIR = $(RENDU_DIR)$(FILLIT_DIR)

all :
	@echo "This makefile is not a makefile he is more a bash script file"
	@echo "make rendu_get_next_line"
	@echo "make rendu_fillit"

rendu_get_next_line : memo
	mkdir -p $(GET_NEXT_LINE_RENDU_DIR)
	cp -R libft/ $(GET_NEXT_LINE_RENDU_DIR)
	cp $(GET_NEXT_LINE_DIR)get_next_line.c 		$(GET_NEXT_LINE_RENDU_DIR)
	cp $(GET_NEXT_LINE_DIR)get_next_line.h 		$(GET_NEXT_LINE_RENDU_DIR)
	cp $(GET_NEXT_LINE_DIR)auteur 			$(GET_NEXT_LINE_RENDU_DIR)

rendu_fillit : memo
	mkdir -p $(FILLIT_RENDU_DIR)
	cp -R libft/ $(FILLIT_RENDU_DIR)
	cp -R $(FILLIT_DIR)src/						$(FILLIT_RENDU_DIR)
	cp -R $(FILLIT_DIR)includes/						$(FILLIT_RENDU_DIR)
	cp -R $(FILLIT_DIR)Makefile						$(FILLIT_RENDU_DIR)

memo :
	cat memo_rendu.txt

clean :
	rm -rf $(RENDU_DIR)