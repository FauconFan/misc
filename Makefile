# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/09 16:03:24 by jpriou            #+#    #+#              #
#    Updated: 2018/10/15 18:53:54 by jpriou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TESTS_PATH="./tests/tests.sh"

all:
	printf "No compilation for python yet..."

test_soluble:
	@bash $(TESTS_PATH) soluble

test_non_soluble:
	@bash $(TESTS_PATH) non_soluble

clean:
	rm -rf __pycache__
	rm -rf src/__pycache__
