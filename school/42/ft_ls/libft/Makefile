NAME = libft.a

CC ?= gcc
FLAGS = -Wall -Werror -Wextra -I ./

SRC = \
			src/ft_printf/converters/ci_numbers.c \
			src/ft_printf/converters/ci_numbers_utils.c \
			src/ft_printf/converters/ci_numbers_utils2.c \
			src/ft_printf/converters/ci_sep.c \
			src/ft_printf/converters/ci_string_ascii.c \
			src/ft_printf/converters/ci_string_unicode.c \
			src/ft_printf/converters/ci_string_unicode_utils.c \
			src/ft_printf/converters/ci_unused_flags.c \
			src/ft_printf/converters/ft_lltoa_n_ulltoa.c \
			src/ft_printf/ft_printf_family.c \
			src/ft_printf/set_values_treat_data.c \
			src/ft_printf/set_values_treat_data2.c \
			src/ft_printf/string_buffer.c \
			src/ft_printf/string_buffer_utils.c \
			src/ft_printf/treat_data_utils.c \
			src/libft_char/ft_isdigit.c \
			src/libft_char/ft_islower.c \
			src/libft_char/ft_toupper.c \
			src/libft_linked_list/ft_lstadd.c \
			src/libft_linked_list/ft_lstfree.c \
			src/libft_linked_list/ft_lstiter.c \
			src/libft_linked_list/ft_lstmerge.c \
			src/libft_linked_list/ft_lstnew.c \
			src/libft_linked_list/ft_lstsize.c \
			src/libft_math/ft_abs.c \
			src/libft_math/ft_log10.c \
			src/libft_math/ft_logb.c \
			src/libft_math/ft_max.c \
			src/libft_math/ft_min.c \
			src/libft_memmory/ft_bzero.c \
			src/libft_memmory/ft_memcheck.c \
			src/libft_put/ft_putstr_fd.c \
			src/libft_str/ft_itoa.c \
			src/libft_str/ft_strcmp.c \
			src/libft_str/ft_strcpos.c \
			src/libft_str/ft_strdup.c \
			src/libft_str/ft_strjoin.c \
			src/libft_str/ft_strlen.c \
			src/libft_str/ft_strncmp.c \
			src/libft_str/ft_strncpy.c \
			src/libft_str/ft_strndup.c \
			src/libft_str/ft_strnew.c \
			src/libft_str/ft_strsetnew.c \
			src/libft_str/ft_strsplit.c \
			src/libft_str/ft_strsub.c \


OBJ = $(SRC:%.c=%.o)

all : $(NAME)
	@echo builted with $(CC)

$(NAME) : $(OBJ)
	@ar -rc $@ $(OBJ)
	@ranlib $@
	@printf "                                                                \r"
	@echo "libft built successfully"

%.o:%.c
	@printf "                                                                \r"
	@printf "  🍏  <= $?\r"
	@$(CC) $(FLAGS) -c $? -o $@

clean :
	@rm -rf $(OBJ)
	@echo "libft cleaned"

fclean : clean
	@rm -rf $(OBJ)
	@rm -rf $(NAME)
	@echo "libft fcleaned"

re : fclean all
