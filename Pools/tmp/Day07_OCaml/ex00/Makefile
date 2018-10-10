# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/20 17:42:24 by jpriou            #+#    #+#              #
#    Updated: 2018/07/23 14:28:30 by jpriou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OCAMLMAKEFILE = OCamlMakefile

RESULT = Do_What_I_do_Hold_tight_and_pretend_it_s_a_plan

SOURCES = \
			people.ml \
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
