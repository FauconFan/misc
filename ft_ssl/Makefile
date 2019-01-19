# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/21 08:09:16 by jpriou            #+#    #+#              #
#    Updated: 2019/01/19 09:08:51 by jpriou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ssl

_RED=$(shell tput setaf 1 2> /dev/null || echo "")
_GREEN=$(shell tput setaf 2 2> /dev/null || echo "")
_YELLOW=$(shell tput setaf 3 2> /dev/null || echo "")
_BLUE=$(shell tput setaf 4 2> /dev/null || echo "")
_PURPLE=$(shell tput setaf 5 2> /dev/null || echo "")
_CYAN=$(shell tput setaf 6 2> /dev/null || echo "")
_WHITE=$(shell tput setaf 7 2> /dev/null || echo "")
_END=$(shell tput sgr0 2> /dev/null || echo "")

SRC_FOLDER = src/
INCLUDES_FOLDER = inc/
LIBFT_FOLDER = ../../my_awesome_libft/libft/

GWW = gcc -Wall -Wextra -Werror -I $(INCLUDES_FOLDER) -I $(LIBFT_FOLDER)
LIBS = -L $(LIBFT_FOLDER) -l ft
LIBFTA = $(LIBFT_FOLDER)libft.a

SRC_PROJECT = \
				parser/base_cmd.c \
				parser/dgst_cmd.c \
				parser/des_cmd.c \
				parser/cmds.c \
				structures/t_dgst_cmd.c \
				structures/t_des_cmd.c \
				structures/globals.c \
				core/do_dgst.c \
				core/do_base.c \
				core/do_des.c \
				core/do_des2.c \
				utils/get_in.c \
				utils/set_out.c \
				utils/ask_key_iv.c \
				utils/ask_pass.c \
				utils/ft_getrandom.c \
				utils/ft_str_to_uint64_ssl.c \
				custom_pbkdf2/ft_poor_pbkdf2.c \
				main.c \

SRC_FP = $(addprefix $(SRC_FOLDER), $(SRC_PROJECT))

ALL_SRC = $(SRC_FP)

OBJ = $(ALL_SRC:%.c=%.o)

.PHONY: all
all :
	make -C $(LIBFT_FOLDER)
	make $(NAME)

$(NAME) : $(OBJ) $(LIBFTA)
	@make -C $(LIBFT_FOLDER)
	@printf "Program %s... " "$(NAME)"
	@$(GWW) $(OBJ) -o $@ $(LIBS)
	@printf "%scompiled%s\\n" "$(_CYAN)" "$(_END)"

%.o : %.c
	@printf "Compiling %s... " "$?"
	@$(GWW) -c $? -o $@
	@printf "%scompiled%s\\n" "$(_GREEN)" "$(_END)"

.PHONY: clean
clean :
	rm -rf $(OBJ)
	make -C $(LIBFT_FOLDER) clean

.PHONY: fclean
fclean :
	rm -rf $(OBJ)
	rm -rf $(NAME)
	make -C $(LIBFT_FOLDER) fclean

.PHONY: re
re : fclean all
