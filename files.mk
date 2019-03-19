
################################# HEADERS CODE #################################

INC_FILES = \
	cimp.h \
	env.h \
	typedefs.h \
	utils.h \
	parser.h \
	commands.h \
	child_readline.h \

INC = $(addprefix $(INC_FOLDER), $(INC_FILES))

################################# SOURCE CODE ##################################

SRC_FOLDER			= src/
ENV_FOLDER			= src/env/
UTILS_FOLDER		= src/utils/
COMMANDS_FOLDER     = src/commands/
CHILD_RD_FOLDER		= src/child_readline/

MAIN_FILE = $(SRC_FOLDER)main.c

SRC_FILES = \
			parser.c \
			globals.c \
			cimp_exe.c \
			core.c \

CHILD_RD_FILES = \
			child_readline.c \
			child_communicate.c \
			core_readline.c \

ENV_FILES = \
			t_cimp.c \
			t_cimp_screen.c \
			t_cimp_select.c \
			t_cimp_event.c \

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
			cimp_select.c \
			cimp_copy.c \

SRC_NO_MAIN = \
		$(addprefix $(SRC_FOLDER), $(SRC_FILES)) \
		$(addprefix $(CHILD_RD_FOLDER), $(CHILD_RD_FILES)) \
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
