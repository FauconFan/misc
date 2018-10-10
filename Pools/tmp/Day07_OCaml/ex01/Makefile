# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/20 17:42:24 by jpriou            #+#    #+#              #
#    Updated: 2018/07/23 15:06:04 by jpriou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OCAMLMAKEFILE = OCamlMakefile

RESULT = The_Name_Of_The_Doctor_!

SOURCES = \
			people.ml \
			doctor.ml \
			main.ml

all:
	make -C . nc
	mv $(RESULT) $(RESULT).opt
	make -C . bc
	mv $(RESULT) $(RESULT).byt
	ln -s $(RESULT).opt $(RESULT)

fclean: cleanup
	rm -f $(RESULT).opt $(RESULT).byt
	rm -f $(RESULT)

re: clean all

include $(OCAMLMAKEFILE)
