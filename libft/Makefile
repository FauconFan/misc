# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/15 10:07:29 by jpriou            #+#    #+#              #
#    Updated: 2017/11/19 16:56:09 by jpriou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft
GCC = gcc -Wall -Wextra -Werror -I ./

FILES_PARTIE1 = 	ft_memset.c \
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
					ft_tolower.c

FILES_PARTIE2 = 	ft_memalloc.c \
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
					ft_putnbr_fd.c

FILES_BONUS = 		ft_lstnew.c \
					ft_lstdelone.c \
					ft_lstdel.c \
					ft_lstadd.c \
					ft_lstiter.c \
					ft_lstmap.c

FILES_MyBONUS = 	ft_strsetnew.c \
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
					ft_strndup.c \
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

PARTIE1_OBJ = 	$(FILES_PARTIE1:%.c=%.o)
PARTIE2_OBJ = 	$(FILES_PARTIE2:%.c=%.o)
BONUS_OBJ = 	$(FILES_BONUS:%.c=%.o)
MyBONUS_OBJ = 	$(FILES_MyBONUS:%.c=%.o)

FILES_O = $(PARTIE1_OBJ) $(PARTIE2_OBJ) $(BONUS_OBJ) $(MyBONUS_OBJ)

all: $(NAME).a

$(NAME): all

$(NAME).a: $(FILES_O)
	@echo "Compiling the library $@"
	@ar rc $@ $(FILES_O)
	@ranlib $@
	@echo "Library built successfully"

%.o: %.c
	@echo "Compiling $?"
	@$(GCC) -c $? -o $@

clean:
	@echo "removing all binary files"
	@rm -f $(FILES_O)

fclean: clean
	@echo "removing the library"
	@rm -f $(NAME).a

re: fclean all

.PHONY: $(NAME) all clean fclean re
