# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/10 19:06:31 by jpriou            #+#    #+#              #
#    Updated: 2017/11/12 18:44:37 by jpriou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RENDU_DIR = rendu/

42_COMMANDEMENTS_DIR = 42_commandements/
42_COMMANDEMENTS_RENDU_DIR = $(RENDU_DIR)$(42_COMMANDEMENTS_DIR)

PISCINE_RELOADED_DIR = Piscine_Reloaded
PISCINE_RELOADED_RENDU_DIR = $(RENDU_DIR)$(PISCINE_RELOADED_DIR)

LIBFT_DIR = libft
LIBFT_RENDU_DIR = $(RENDU_DIR)$(LIBFT_DIR)

GET_NEXT_LINE_DIR = get_next_line/
GET_NEXT_LINE_RENDU_DIR = $(RENDU_DIR)$(GET_NEXT_LINE_DIR)

FILLIT_DIR = fillit/
FILLIT_RENDU_DIR = $(RENDU_DIR)$(FILLIT_DIR)

FT_PRINTF_DIR = ft_printf/
FT_PRINTF_RENDU_DIR = $(RENDU_DIR)$(FT_PRINTF_DIR)

all :
	@echo "This makefile is not a makefile he is more a bash script file"
	@echo "make rendu_42_commandements"
	@echo "make rendu_piscine_reloaded"
	@echo "make rendu_libft"
	@echo "make rendu_fillit"
	@echo "make rendu_get_next_line"
	@echo "make rendu_ft_printf"

rendu_42_commandements : memo clean
	@mkdir -p $(42_COMMANDEMENTS_RENDU_DIR)
	@cp $(42_COMMANDEMENTS_DIR)turn_in $(42_COMMANDEMENTS_RENDU_DIR)

rendu_piscine_reloaded : memo clean
	@mkdir -p $(PISCINE_RELOADED_RENDU_DIR)
	@cp -R $(PISCINE_RELOADED_DIR)/* $(PISCINE_RELOADED_RENDU_DIR)

rendu_libft : memo clean
	@mkdir -p $(LIBFT_RENDU_DIR)
	@cp -R $(LIBFT_DIR)/auteur $(LIBFT_RENDU_DIR)
	@cp -R $(LIBFT_DIR)/*.c $(LIBFT_RENDU_DIR)
	@cp -R $(LIBFT_DIR)/libft.h $(LIBFT_RENDU_DIR)
	@cp -R $(LIBFT_DIR)/Makefile $(LIBFT_RENDU_DIR)

rendu_fillit : memo clean
	@mkdir -p $(FILLIT_RENDU_DIR)
	@mkdir -p $(FILLIT_RENDU_DIR)/$(LIBFT_DIR)
	@cp -R $(LIBFT_DIR)/*.c 						$(FILLIT_RENDU_DIR)/$(LIBFT_DIR)
	@cp -R $(LIBFT_DIR)/libft.h 					$(FILLIT_RENDU_DIR)/$(LIBFT_DIR)
	@cp -R $(LIBFT_DIR)/Makefile 					$(FILLIT_RENDU_DIR)/$(LIBFT_DIR)
	@cp -R $(FILLIT_DIR)auteur						$(FILLIT_RENDU_DIR)
	@cp -R $(FILLIT_DIR)src							$(FILLIT_RENDU_DIR)
	@cp -R $(FILLIT_DIR)includes					$(FILLIT_RENDU_DIR)
	@cp -R $(FILLIT_DIR)Makefile					$(FILLIT_RENDU_DIR)

rendu_get_next_line : memo clean
	@mkdir -p $(GET_NEXT_LINE_RENDU_DIR)
	@mkdir -p $(GET_NEXT_LINE_RENDU_DIR)/$(LIBFT_DIR)
	@cp -R $(LIBFT_DIR)/*.c 						$(GET_NEXT_LINE_RENDU_DIR)/$(LIBFT_DIR)
	@cp -R $(LIBFT_DIR)/libft.h 					$(GET_NEXT_LINE_RENDU_DIR)/$(LIBFT_DIR)
	@cp -R $(LIBFT_DIR)/Makefile 					$(GET_NEXT_LINE_RENDU_DIR)/$(LIBFT_DIR)
	@cp $(GET_NEXT_LINE_DIR)get_next_line.c 		$(GET_NEXT_LINE_RENDU_DIR)
	@cp $(GET_NEXT_LINE_DIR)get_next_line.h 		$(GET_NEXT_LINE_RENDU_DIR)
	@cp $(GET_NEXT_LINE_DIR)auteur 					$(GET_NEXT_LINE_RENDU_DIR)

rendu_ft_printf : memo clean
	@mkdir -p $(FT_PRINTF_RENDU_DIR)
	@mkdir -p $(FT_PRINTF_RENDU_DIR)/$(LIBFT_DIR)
	@cp -R $(LIBFT_DIR)/*.c 						$(FT_PRINTF_RENDU_DIR)/$(LIBFT_DIR)
	@cp -R $(LIBFT_DIR)/libft.h 					$(FT_PRINTF_RENDU_DIR)/$(LIBFT_DIR)
	@cp -R $(LIBFT_DIR)/Makefile 					$(FT_PRINTF_RENDU_DIR)/$(LIBFT_DIR)
	@cp -R $(FT_PRINTF_DIR)/auteur					$(FT_PRINTF_RENDU_DIR)
	@cp -R $(FT_PRINTF_DIR)/Makefile				$(FT_PRINTF_RENDU_DIR)
	@cp -R $(FT_PRINTF_DIR)/src						$(FT_PRINTF_RENDU_DIR)
	@cp -R $(FT_PRINTF_DIR)/includes				$(FT_PRINTF_RENDU_DIR)
	@rm -rf $(FT_PRINTF_RENDU_DIR)/src/main.c

memo :
	@cat memo_rendu.txt

gource :
	@gource -f --title "All Progress of Priou Development at 42 School" -a 1 -s 0.5 --key

clean :
	@rm -rf $(RENDU_DIR)

fclean : clean
