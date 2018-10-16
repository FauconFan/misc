# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/09 16:03:24 by jpriou            #+#    #+#              #
#    Updated: 2018/10/16 23:08:11 by pepe             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TESTS_PATH="./tests/tests.sh"

all:
	printf "No compilation for python yet..."

test_soluble:
	@bash $(TESTS_PATH) soluble

test_non_soluble:
	@bash $(TESTS_PATH) non_soluble

profile:
	python3 -m cProfile -s tottime ./main.py tests/soluble/size5_00.txt | tee profile.out

clean:
	rm -rf __pycache__
	rm -rf src/__pycache__
