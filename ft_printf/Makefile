# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/12 17:06:05 by jpriou            #+#    #+#              #
#    Updated: 2017/11/15 16:32:45 by jpriou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf

L_FT = libft/

FLAGS = -Wall -Wextra -Werror -I libft/ -I includes/ -I includes/converters/
LIBS = -L$(L_FT) -lft
CC = gcc

SRC_FOLDER 				= src/
CONVERTERS_FOLDER		= converters/

LIBFT_CODE		= 	ft_memset.c \
					ft_bzero.c \
					ft_memcpy.c \
					ft_memccpy.c \
					ft_memmove.c \
					ft_memchr.c \
					ft_memcmp.c \
					ft_strlen.c \
					ft_strdup.c \
					ft_strcpy.c \
					ft_strncpy.c \
					ft_strcat.c \
					ft_strncat.c \
					ft_strlcat.c \
					ft_strchr.c \
					ft_strrchr.c \
					ft_strstr.c \
					ft_strnstr.c \
					ft_strcmp.c \
					ft_strncmp.c \
					ft_atoi.c \
					ft_isalnum.c \
					ft_isalpha.c \
					ft_isdigit.c \
					ft_isprint.c \
					ft_isascii.c \
					ft_toupper.c \
					ft_tolower.c \
					ft_memalloc.c \
					ft_memdel.c \
					ft_strnew.c \
					ft_strdel.c \
					ft_strclr.c \
					ft_striter.c \
					ft_striteri.c \
					ft_strmap.c \
					ft_strmapi.c \
					ft_strequ.c \
					ft_strnequ.c \
					ft_strsub.c \
					ft_strjoin.c \
					ft_strtrim.c \
					ft_strsplit.c \
					ft_itoa.c \
					ft_putchar.c \
					ft_putstr.c \
					ft_putendl.c \
					ft_putnbr.c \
					ft_putchar_fd.c \
					ft_putstr_fd.c \
					ft_putendl_fd.c \
					ft_putnbr_fd.c \
					ft_lstnew.c \
					ft_lstdelone.c \
					ft_lstdel.c \
					ft_lstadd.c \
					ft_lstiter.c \
					ft_lstmap.c \
					ft_strsetnew.c \
					ft_strpos.c \
					ft_strrpos.c \
					ft_strcpos.c \
					ft_strcrpos.c \
					ft_strparse.c \
					ft_strparse_n_free.c \
					ft_str_any.c \
					ft_str_all.c \
					ft_isspace.c \
					ft_iswhitespace.c \
					ft_islower.c \
					ft_isupper.c \
					ft_isblank.c \
					ft_isxdigit.c \
					ft_str_is_alnum.c \
					ft_str_is_alpha.c \
					ft_str_is_ascii.c \
					ft_str_is_numeric.c \
					ft_str_is_lowercase.c \
					ft_str_is_uppercase.c \
					ft_str_is_printable.c \
					ft_str_is_blank.c \
					ft_putnbrl.c \
					ft_atoi_base.c \
					ft_itoa_base.c \
					ft_convert_base.c \
					ft_abs.c \
					ft_min.c \
					ft_max.c \
					ft_log10.c \
					ft_logb.c \
					ft_lstsize.c

TEST_FILE_CODE				= 	main.c
SRC_CODE					= 	ft_printf.c \
								treat_data_utils.c \
								set_values_treat_data.c \
								set_values_treat_data2.c \
								build_str_treat_data.c
CONVERTER_CODE				=	management.c \
								ft_lltoa_n_ulltoa.c \
								ci_sep.c \
								ci_numbers.c \
								ci_string.c \
								ci_character.c \
								ci_numbers_utils.c

TEST_FILE 					= 	$(addprefix $(SRC_FOLDER), $(TEST_FILE_CODE))
SRC 						= 	$(addprefix $(SRC_FOLDER), $(SRC_CODE))
CONVERTER_SRC				=	$(addprefix $(SRC_FOLDER)$(CONVERTERS_FOLDER), $(CONVERTER_CODE))
LIBFT						=	$(addprefix $(L_FT), $(LIBFT_CODE))

TEST_OBJ 					=	$(TEST_FILE:%.c=%.o)
SRC_OBJ						=	$(SRC:%.c=%.o)
CONVERTER_OBJ				=	$(CONVERTER_SRC:%.c=%.o)
LIBFT_OBJ					=	$(LIBFT:%.c=%.o)

FILES_OBJ 					= 	$(SRC_OBJ) $(CONVERTER_OBJ) $(LIBFT_OBJ)

all : $(NAME).a

$(NAME): all

$(NAME).a : $(FILES_OBJ)
	ar rc $@ $(FILES_OBJ)
	ranlib $@

%.o: %.c
	$(CC) -c $(FLAGS) $? -o $@

clean :
	rm -rf $(FILES_OBJ)

fclean : clean
	rm -rf $(NAME).a

re : fclean all

test :
	make
	gcc $(TEST_FILE) -L. -lftprintf -I libft/ -I includes/ -I includes/converters/
	./a.out | cat -e
	rm -f a.out