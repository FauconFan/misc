
SRC_FOLDER			= src/
ENV_FOLDER			= src/env/
UTILS_FOLDER		= src/utils/
COMMANDS_FOLDER = src/commands/

SRC_FILES = \
			main.c \
			readline.c \

ENV_FILES = \
			t_cimp.c \
			t_cimp_screen.c \

UTILS_FILES = \
			path_utils.c \
			str_utils.c \

COMMANDS_FILES =\
			cimp_open.c\
			cimp_close.c\
			cimp_help.c\
			cimp_list.c\
			cimp_sym.c\
			

SRC = \
		$(addprefix $(SRC_FOLDER), $(SRC_FILES)) \
		$(addprefix $(ENV_FOLDER), $(ENV_FILES)) \
		$(addprefix $(UTILS_FOLDER), $(UTILS_FILES)) \
		$(addprefix $(COMMANDS_FOLDER), $(COMMANDS_FILES)) \
