# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/09 06:49:12 by jpriou            #+#    #+#              #
#    Updated: 2018/11/14 10:22:15 by jpriou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	@printf "No compilation for python yet...\\n"

test_deduction:
	sh ./tests.sh deduction

test_correction:
	sh ./tests.sh correction

pycodestyle:
	sh ./tests.sh pycodestyle

clean:
	rm -rf venv
	rm -rf __pycache__
	rm -rf src/__pycache__
