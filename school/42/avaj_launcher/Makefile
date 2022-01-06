# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/17 10:09:03 by jpriou            #+#    #+#              #
#    Updated: 2019/01/17 10:09:43 by jpriou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAIN_PATH = fr/jpriou/forty_two/avaj_launcher/Main.java

.PHONY: all
all: build

.PHONY: build
build:
	javac $(MAIN_PATH)

.PHONY: clean
clean:
	find . -name "*.class" -delete
	find tests -name "*.log" -delete

.PHONY: fclean
fclean: clean

.PHONY: re
re: fclean all
