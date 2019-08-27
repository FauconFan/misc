# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/26 13:17:22 by jpriou            #+#    #+#              #
#    Updated: 2017/11/26 14:22:47 by jpriou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FRAMEWORK_FOLDER = framework/
TESTS_LIBFT = tests_libft

PATH_LIBFT = "/path/to/your/libft"

all : libunit

libunit :
	make -C $(FRAMEWORK_FOLDER)

libft :
	make -C $(PATH_LIBFT)
	cp $(PATH_LIBFT)/libft.a $(TESTS_LIBFT)
	cp $(PATH_LIBFT)/libft.h $(TESTS_LIBFT)/includes
	make -C $(TESTS_LIBFT)
	make run -C $(TESTS_LIBFT)

clean :
	make clean -C $(FRAMEWORK_FOLDER)
	make clean -C $(TESTS_LIBFT)

fclean :
	make fclean -C $(FRAMEWORK_FOLDER)
	make fclean -C $(TESTS_LIBFT)

re : fclean all