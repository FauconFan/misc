
################################# HEADERS CODE #################################

INC_FILES = \
	cimp.h \
	env.h \
	typedefs.h \
	utils.h \
	parser.h \

INC = $(addprefix $(INC_FOLDER), $(INC_FILES))

################################# SOURCE CODE ##################################

SRC_FOLDER			= src/
ENV_FOLDER			= src/env/
UTILS_FOLDER		= src/utils/

SRC_FILES = \
			main.c \
			readline.c \
			parser.c \

ENV_FILES = \
			t_cimp.c \
			t_cimp_screen.c \

UTILS_FILES = \
			path_utils.c \
			str_utils.c \

SRC = \
		$(addprefix $(SRC_FOLDER), $(SRC_FILES)) \
		$(addprefix $(ENV_FOLDER), $(ENV_FILES)) \
		$(addprefix $(UTILS_FOLDER), $(UTILS_FILES)) \
