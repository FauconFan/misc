# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/01 16:57:39 by jpriou            #+#    #+#              #
#    Updated: 2018/11/01 18:06:25 by jpriou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all
all: predict training

.PHONY: predict
predict:
	make -f Predict.Makefile

.PHONY: training
training:
	make -f Training.Makefile

.PHONY: clean
clean:
	make -f Predict.Makefile clean
	make -f Training.Makefile clean

.PHONY: fclean
fclean: reset
	make -f Predict.Makefile fclean
	make -f Training.Makefile fclean

.PHONY: re
re: fclean all

.PHONY: re
reset:
	rm data.csv
