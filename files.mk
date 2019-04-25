
SRC_FOLDER         = src/
SRC_UTILS_FOLDER   = src/utils/
SRC_STRUCT_FOLDER  = src/struct/

SRC = \
		$(SRC_FOLDER)main.c \
		$(SRC_FOLDER)getaddrinfo.c \
		$(SRC_FOLDER)client.c \
		$(SRC_FOLDER)parse_tlv.c \
		$(SRC_UTILS_FOLDER)my_getrandom.c \
		$(SRC_UTILS_FOLDER)my_time.c \
		$(SRC_STRUCT_FOLDER)t_env.c \
		$(SRC_STRUCT_FOLDER)t_list.c \
		$(SRC_STRUCT_FOLDER)t_iovec_builder.c \
		$(SRC_STRUCT_FOLDER)t_tlv_builder.c \
		$(SRC_STRUCT_FOLDER)t_neighbour.c \
		$(SRC_STRUCT_FOLDER)t_potential_neighbour.c \
		$(SRC_STRUCT_FOLDER)t_received_message.c \
		$(SRC_STRUCT_FOLDER)t_acquit_message.c \
