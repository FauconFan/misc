# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.makefile                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/20 10:29:49 by jpriou            #+#    #+#              #
#    Updated: 2019/06/20 12:07:47 by jpriou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_NM = ./ft_nm
NAME_OTOOL = ./ft_otool

FIND_PARAMS = -maxdepth 1 -type f -exec bash -c 'if [ ! "`file $$0 | grep ASCII`" ]; then echo $$0; fi' {} \; | sort

FILES_BIN = $(shell find /bin $(FIND_PARAMS))
FILES_USR_LIB = $(shell find /usr/lib $(FIND_PARAMS))

.PHONY: all
all: test_bin test_usr_lib

$(NAME_NM):
	make -f Makefile $(NAME_NM)

$(NAME_OTOOL):
	make -f Makefile $(NAME_OTOOL)

.PHONY: test_bin
test_bin: 
	@ make -f test.makefile $(FILES_BIN)

.PHONY: test_usr_lib
test_usr_lib:
	@ make -f test.makefile $(FILES_USR_LIB)

/%: $(NAME_NM) $(NAME_OTOOL) FORCE
	@ printf "%s\\n" "$@"
	@ printf "\\tnm/ft_nm\\n"
	@ bash -c "diff <(nm $@) <($(NAME_NM) $@)"
	@ printf "\\totool/ft_otool\\n"
	@ bash -c "diff <(otool -t $@) <($(NAME_OTOOL) $@)"

.PHONY: FORCE
FORCE: