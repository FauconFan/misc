# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/09 16:03:24 by jpriou            #+#    #+#              #
#    Updated: 2018/10/18 11:14:40 by jpriou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TESTS_PATH="./tests/tests.sh"

all:
	@printf "No compilation for python yet...\\n"

test_soluble:
	@bash $(TESTS_PATH) soluble

test_non_soluble:
	@bash $(TESTS_PATH) non_soluble

test_random:
	@printf "This command is infinit, make sure to Ctrl-C if you are satisfied\\n"
	@printf "Starting in 5 seconds\\n"
	@sleep 5
	@bash $(TESTS_PATH) random

profile:
	python3 -m cProfile -s tottime ./main.py tests/soluble/size5_00.txt | tee profile.out

clean:
	rm -rf __pycache__
	rm -rf src/__pycache__
	rm -f profile.out
	rm -f puzzle_random.txt
