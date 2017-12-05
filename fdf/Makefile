# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/05 12:41:40 by jpriou            #+#    #+#              #
#    Updated: 2017/12/05 19:07:24 by jpriou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC_FOLDER = src/
INCLUDES_FOLDER = includes/
LIBFT_FOLDER = libft/

GWW = gcc -g -Wall -Wextra -Werror
INCLUDES_FLAGS = -I $(INCLUDES_FOLDER) -I $(LIBFT_FOLDER)$(INCLUDES_FOLDER)
LIBS = -L libft -l ft -l mlx -framework OpenGL -framework Appkit

SRC_CODE = main.c \
			fdf_env_utils.c \
			fdf_key_hooks.c \
			fdf_read_file.c \
			fdf_draw_line.c \
			fdf_matrix_base.c \

SRC_FP = $(addprefix $(SRC_FOLDER), $(SRC_CODE))

OBJ = $(SRC_FP:%.c=%.o)

all : $(NAME)

$(NAME) : lib $(OBJ)
	$(GWW) $(INCLUDES_FLAGS) $(OBJ) -o $@ $(LIBS)

lib :
	make -C $(LIBFT_FOLDER)

%.o : %.c
	$(GWW) $(INCLUDES_FLAGS) -c $? -o $@

clean :
	rm -f $(OBJ)
	make clean -C $(LIBFT_FOLDER)

fclean :
	rm -f $(OBJ)
	rm -f $(NAME)
	make fclean -C $(LIBFT_FOLDER)

re : fclean all
