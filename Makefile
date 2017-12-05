# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/10 19:06:31 by jpriou            #+#    #+#              #
#    Updated: 2017/12/05 12:03:25 by jpriou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RENDU_DIR = rendu/

LIBFT_DIR = libft
LIBFT_RENDU_DIR = $(RENDU_DIR)$(LIBFT_DIR)

all :
	@echo "This makefile is not a makefile he is more a bash script file"
	@echo "make rendu_libft"
	@echo "make rendu_ft_printf"

rendu_libft : memo clean
	@mkdir -p $(LIBFT_RENDU_DIR)
	@cp -R $(LIBFT_DIR)/* $(LIBFT_RENDU_DIR)
	rm -f $(LIBFT_RENDU_DIR)/src/main.c

memo :
	@cat memo_rendu.txt

gource :
	@gource -f --title "All Progress of Priou Development at 42 School" -a 1 -s 0.5 --key

clean :
	@rm -rf $(RENDU_DIR)

fclean : clean
