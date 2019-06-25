# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.makefile                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/20 10:29:49 by jpriou            #+#    #+#              #
#    Updated: 2019/06/25 15:26:46 by jpriou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_NM = ./ft_nm
NAME_OTOOL = ./ft_otool

FIND_PARAMS = -maxdepth 1 -type f -exec bash -c 'if [ ! "`file $$0 | grep ASCII`" -a -r "$$0" ]; then echo $$0; fi' {} \; | sort

FILES_BIN = $(shell find /bin $(FIND_PARAMS))
FILES_SBIN = $(shell find /sbin $(FIND_PARAMS))
FILES_USR_BIN = $(shell find /usr/bin $(FIND_PARAMS))
FILES_USR_LIB = $(shell find /usr/lib $(FIND_PARAMS))

.PHONY: all
all: test_bin test_sbin test_usr_bin test_usr_lib

$(NAME_NM):
	make -f Makefile $(NAME_NM)

$(NAME_OTOOL):
	make -f Makefile $(NAME_OTOOL)

.PHONY: test_bin
test_bin: 
	@ make -f test.makefile $(FILES_BIN)

.PHONY: test_sbin
test_sbin: 
	@ make -f test.makefile $(FILES_SBIN)

.PHONY: test_usr_bin
test_usr_bin:
	@ make -f test.makefile $(FILES_USR_BIN)

.PHONY: test_usr_lib
test_usr_lib:
	@ make -f test.makefile $(FILES_USR_LIB)

/%: $(NAME_NM) $(NAME_OTOOL) FORCE
	@ printf "%s\\n" "$@"
	@ bash -c "diff <(nm $@) <($(NAME_NM) $@)"
	@ bash -c "diff <(otool -t $@) <($(NAME_OTOOL) $@)"

.PHONY: FORCE
FORCE: