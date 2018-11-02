# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/28 20:29:52 by jpriou            #+#    #+#              #
#    Updated: 2018/10/29 08:46:28 by jpriou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OCAMLMAKEFILE = OCamlMakefile

RESULT = linear_regression_predict

MAIN_PREDICT = MainPredict.ml

ML_FILES = \
			src/ParsingCSV.ml \
			src/LinearRegression.ml \
			src/IO.ml \

MLI_FILES = $(foreach f, $(ML_FILES), $fi)

SOURCES = $(MLI_FILES) $(ML_FILES) $(MAIN_PREDICT)

.PHONY: all
all: delete_links
	make -f Predict.Makefile nc
	mv $(RESULT) $(RESULT).opt
	make -f Predict.Makefile bc
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
