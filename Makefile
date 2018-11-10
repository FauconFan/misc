# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/09 06:49:12 by jpriou            #+#    #+#              #
#    Updated: 2018/11/09 13:15:39 by jpriou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	@printf "No compilation for python yet...\\n"

test_deduction:
	sh ./tests.sh deduction

test_correction:
	sh ./tests.sh correction

clean:
	rm -rf __pycache__
	rm -rf src/__pycache__
