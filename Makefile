# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/09 06:49:12 by jpriou            #+#    #+#              #
#    Updated: 2018/11/09 06:54:35 by jpriou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	@printf "No compilation for python yet...\\n"

test_deduction:
	@for file in $(shell find tests/deduction -name "*.txt") ; do \
		printf "Testing %s " $$file ; \
		python3 main.py $$file > /dev/null ; \
		printf "OK\\n" ; \
	done

clean:
	rm -rf __pycache__
	rm -rf src/__pycache__
