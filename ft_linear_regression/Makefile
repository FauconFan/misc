# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/28 20:29:52 by jpriou            #+#    #+#              #
#    Updated: 2018/10/28 20:33:03 by jpriou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OCAMLMAKEFILE = OCamlMakefile

RESULT = linear_regression

ML_FILES = \
			src/ParsingCSV.ml \
			src/LinearRegression.ml \

MLI_FILES = $(foreach f, $(ML_FILES), $fi)

SOURCES = $(MLI_FILES) $(ML_FILES)

.PHONY: all
all: delete_links
	make -C . nc
	mv $(RESULT) $(RESULT).opt
	make -C . bc
	mv $(RESULT) $(RESULT).byt
	ln -s $(RESULT).opt $(RESULT)

.PHONY: delete_links
delete_links:
	rm -f $(RESULT).opt $(RESULT).byt
	rm -f $(RESULT)

.PHONY: fclean
fclean: cleanup delete_links

.PHONY: re
re: fclean all

include $(OCAMLMAKEFILE)
