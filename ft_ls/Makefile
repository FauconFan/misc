# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpriou <jpriou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/05 12:09:48 by jpriou            #+#    #+#              #
#    Updated: 2017/12/13 09:46:51 by jpriou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC_FOLDER = src/
INCLUDES_FOLDER = includes/
LIBFT_FOLDER = libft/

LIBS = -L$(LIBFT_FOLDER) -lft
GWW = gcc -g -Wall -Wextra -Werror
INCLUDES_FLAGS = -I $(INCLUDES_FOLDER) -I $(LIBFT_FOLDER)$(INCLUDES_FOLDER) -I $(LIBFT_FOLDER)

SRC_CODE = main.c \
			main_utils.c \
			ls_env_utils.c \
			ls_flags_utils.c \
			ls_error_files_utils.c \
			ls_list_directories.c \
			ls_file_content_utils.c \
			ls_file_content_utils2.c \
			ls_utils_long_format.c \
			ls_utils_long_format2.c \
			ls_sort_utils.c \
			ls_sort_utils_time_modified.c \
			ls_sort_utils_time_accessed.c \
			ls_sort_utils_time_birth.c \
			ls_sort_utils_time_change_status.c \
			ls_sort_utils_size.c \
			ls_max_values_utils.c \
			ls_utils_group_user_id.c \

SRC = $(addprefix $(SRC_FOLDER), $(SRC_CODE))

OBJ = $(SRC:%.c=%.o)

all : $(NAME)

$(NAME) : lib $(OBJ)
	$(GWW) $(INCLUDES_FLAGS) $(OBJ) -o $@ $(LIBS)

lib :
	make -C $(LIBFT_FOLDER)

%.o : %.c
	$(GWW) $(INCLUDES_FLAGS) -c $? -o $@ 

clean :
	rm -rf $(OBJ)
	make clean -C $(LIBFT_FOLDER)

fclean :
	rm -rf $(OBJ)
	rm -rf $(NAME)
	make fclean -C $(LIBFT_FOLDER)

re : fclean all
