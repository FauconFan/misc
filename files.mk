
################################# HEADERS CODE #################################

INC_FILES = \
	cimp.h \
	env.h \
	typedefs.h \
	utils.h \
	parser.h \
	commands.h \

INC = $(addprefix $(INC_FOLDER), $(INC_FILES))

################################# SOURCE CODE ##################################

SRC_FOLDER			= src/
ENV_FOLDER			= src/env/
UTILS_FOLDER		= src/utils/
COMMANDS_FOLDER = src/commands/

MAIN_FILE = $(SRC_FOLDER)main.c

SRC_FILES = \
			readline.c \
			parser.c \
			globals.c \

ENV_FILES = \
			t_cimp.c \
			t_cimp_screen.c \

UTILS_FILES = \
			path_utils.c \
			str_utils.c \

COMMANDS_FILES = \
			cimp_open.c \
			cimp_close.c \
			cimp_help.c \
			cimp_list.c \
			cimp_sym.c \
			cimp_rotate.c \

SRC_NO_MAIN = \
		$(addprefix $(SRC_FOLDER), $(SRC_FILES)) \
		$(addprefix $(ENV_FOLDER), $(ENV_FILES)) \
		$(addprefix $(UTILS_FOLDER), $(UTILS_FILES)) \
		$(addprefix $(COMMANDS_FOLDER), $(COMMANDS_FILES)) \

SRC = \
		$(SRC_NO_MAIN) \
		$(MAIN_FILE) \

################################# TEST SOURCE CODE ############################

TEST_FOLDER			= tests/

TEST_FILES = \
			main_test.c \

TEST_SRC = \
		$(addprefix $(TEST_FOLDER), $(TEST_FILES)) \
