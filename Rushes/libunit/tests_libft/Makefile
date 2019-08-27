# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/26 09:44:22 by jpriou            #+#    #+#              #
#    Updated: 2017/11/26 15:52:47 by jpriou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test_libft

INCLUDES_FOLDER = includes/
SRC_FOLDER = src/

CC = gcc
FLAGS = -Wall -Wextra -Werror -I $(INCLUDES_FOLDER) -I ../framework/$(INCLUDES_FOLDER) -I ../framework/mylibft/$(INCLUDES_FOLDER)
LIBS = -L./ -lft -L../framework -lunit

FOLDER_BZERO = bzero/
FOLDER_STRLEN = strlen/
FOLDER_TOUPPER = toupper/
FOLDER_ISALNUM = isalnum/
FOLDER_ISALPHA = isalpha/
FOLDER_ISASCII = isascii/
FOLDER_ISDIGIT = isdigit/
FOLDER_ISPRINT = isprint/
FOLDER_ITOA = itoa/
FOLDER_ATOI = atoi/
FOLDER_MEMCPY = memcpy/

LIB_UNIT = libunit

SRC_MAIN = main.c \

SRC_BZERO = 00_launcher.c \
			01_basic_test_bzero.c \
			02_basic_test_bzero.c \

SRC_STRLEN = 00_launcher.c \
				01_simple_test1.c \
				02_simple_test2.c \
				03_empty_test.c \

SRC_TOUPPER = 00_launcher.c \
				01_simple_test1.c \
				02_simple_test2.c \
				03_simple_test3.c \

SRC_ISALNUM = 00_launcher.c \
				01_basic_test_isalnum.c \
				02_basic_test_isalnum.c \
				03_basic_test_isalnum.c \

SRC_ISALPHA = 00_launcher.c \
				01_basic_test_isalpha.c \
				02_basic_test_isalpha.c \

SRC_ISASCII = 00_launcher.c \
				01_basic_test_isascii.c \

SRC_ISDIGIT = 00_launcher.c \
				01_basic_test_isdigit.c \
				02_basic_test_isdigit.c \

SRC_ISPRINT = 00_launcher.c \
				01_basic_test_isprint.c \

SRC_ITOA = 00_launcher.c \
				01_basic_test_itoa.c \
				02_basic_test_itoa.c \
				03_basic_test_itoa.c \
				04_basic_test_itoa.c \
				05_basic_test_itoa.c \

SRC_ATOI = 00_launcher.c \
				01_basic_test_atoi.c \
				02_basic_test_atoi.c \
				03_basic_test_atoi.c \

SRC_MEMCPY = 00_launcher.c \
				01_basic_test_memcpy.c \
				02_basic_test_memcpy.c \

SRC_BZERO_FP = $(addprefix $(SRC_FOLDER)$(FOLDER_BZERO), $(SRC_BZERO))
SRC_STRLEN_FP = $(addprefix $(SRC_FOLDER)$(FOLDER_STRLEN), $(SRC_STRLEN))
SRC_TOUPPER_FP = $(addprefix $(SRC_FOLDER)$(FOLDER_TOUPPER), $(SRC_TOUPPER))
SRC_ISALNUM_FP = $(addprefix $(SRC_FOLDER)$(FOLDER_ISALNUM), $(SRC_ISALNUM))
SRC_ISALPHA_FP = $(addprefix $(SRC_FOLDER)$(FOLDER_ISALPHA), $(SRC_ISALPHA))
SRC_ISASCII_FP = $(addprefix $(SRC_FOLDER)$(FOLDER_ISASCII), $(SRC_ISASCII))
SRC_ISDIGIT_FP = $(addprefix $(SRC_FOLDER)$(FOLDER_ISDIGIT), $(SRC_ISDIGIT))
SRC_ISPRINT_FP = $(addprefix $(SRC_FOLDER)$(FOLDER_ISPRINT), $(SRC_ISPRINT))
SRC_ITOA_FP = $(addprefix $(SRC_FOLDER)$(FOLDER_ITOA), $(SRC_ITOA))
SRC_ATOI_FP = $(addprefix $(SRC_FOLDER)$(FOLDER_ATOI), $(SRC_ATOI))
SRC_MEMCPY_FP = $(addprefix $(SRC_FOLDER)$(FOLDER_MEMCPY), $(SRC_MEMCPY))

SRC_ALL = $(SRC_MAIN) $(SRC_STRLEN_FP) $(SRC_BZERO_FP) $(SRC_TOUPPER_FP) \
		$(SRC_ISALNUM_FP) $(SRC_ISALPHA_FP) $(SRC_ISASCII_FP) $(SRC_ISDIGIT_FP) \
		$(SRC_ISPRINT_FP) $(SRC_ITOA_FP) $(SRC_ATOI_FP) $(SRC_MEMCPY_FP)

OBJ_ALL = $(SRC_ALL:%.c=%.o)

all : $(NAME)

$(NAME) : $(LIB_UNIT) $(OBJ_ALL)
	@echo Compiling the executable $(NAME)
	@$(CC) $(FLAGS) $(OBJ_ALL) $(LIBS) -o $@

$(LIB_UNIT) :
	@echo Compiling libunit
	@make -C ../framework

%.o : %.c
	@echo "Compiling $?"
	$(CC) -c $(FLAGS) $? -o $@

clean :
	@rm -rf $(OBJ_ALL)

fclean : clean
	@rm -rf $(NAME)
	@make -C ../framework fclean
	@rm -rf libft.a
	@rm -rf $(INCLUDES_FOLDER)/libft.h

run :
	./$(NAME)

re : fclean all
