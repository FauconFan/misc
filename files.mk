
SRC_FOLDER         = src/
SRC_UTILS_FOLDER   = src/utils/
SRC_STRUCT_FOLDER  = src/struct/
UI_FOLDER          = src/ui/

SRC = \
		$(SRC_FOLDER)main.c \
		$(SRC_FOLDER)getaddrinfo.c \
		$(SRC_FOLDER)socket.c \
		$(SRC_FOLDER)client.c \
		$(SRC_FOLDER)parse_tlv.c \
		$(SRC_UTILS_FOLDER)my_getrandom.c \
		$(SRC_UTILS_FOLDER)my_time.c \
		$(SRC_UTILS_FOLDER)my_str.c \
		$(UI_FOLDER)ui_main.c \
		$(UI_FOLDER)ui_read_pseudo.c \
		$(UI_FOLDER)ui_print.c \
		$(UI_FOLDER)ui_utils.c \
		$(UI_FOLDER)ui_setup.c \
		$(SRC_STRUCT_FOLDER)t_env.c \
		$(SRC_STRUCT_FOLDER)t_list.c \
		$(SRC_STRUCT_FOLDER)t_iovec_builder.c \
		$(SRC_STRUCT_FOLDER)t_tlv_builder.c \
		$(SRC_STRUCT_FOLDER)t_neighbour.c \
		$(SRC_STRUCT_FOLDER)t_potential_neighbour.c \
		$(SRC_STRUCT_FOLDER)t_message.c \
		$(SRC_STRUCT_FOLDER)t_acquit.c \
		$(SRC_STRUCT_FOLDER)t_buffer_tlv_ip.c \
		$(SRC_FOLDER)update_buffer.c \
