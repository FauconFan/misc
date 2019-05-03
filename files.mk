
SRC_FOLDER                  = src/
SRC_UTILS_FOLDER            = src/utils/
SRC_STRUCT_FOLDER           = src/struct/
SRC_STRUCT_DATA_FOLDER      = src/struct/data/
SRC_STRUCT_NETWORK_FOLDER   = src/struct/network/
SRC_STRUCT_PROTOCOL_FOLDER  = src/struct/protocol/
SRC_UI_FOLDER               = src/ui/
SRC_CORE_FOLDER             = src/core/

SRC = \
		$(SRC_FOLDER)main.c \
		$(SRC_FOLDER)getaddrinfo.c \
		$(SRC_FOLDER)socket.c \
		$(SRC_CORE_FOLDER)core_loop.c \
		$(SRC_CORE_FOLDER)parse_tlv.c \
		$(SRC_CORE_FOLDER)select_treat_input.c \
		$(SRC_CORE_FOLDER)update_buffer.c \
		$(SRC_CORE_FOLDER)clear_buffer.c \
		$(SRC_UTILS_FOLDER)my_getrandom.c \
		$(SRC_UTILS_FOLDER)my_time.c \
		$(SRC_UTILS_FOLDER)my_str.c \
		$(SRC_UI_FOLDER)ui_main.c \
		$(SRC_UI_FOLDER)ui_read_pseudo.c \
		$(SRC_UI_FOLDER)ui_print.c \
		$(SRC_UI_FOLDER)ui_utils.c \
		$(SRC_UI_FOLDER)ui_setup.c \
		$(SRC_STRUCT_DATA_FOLDER)t_list.c \
		$(SRC_STRUCT_NETWORK_FOLDER)t_ip_port.c \
		$(SRC_STRUCT_NETWORK_FOLDER)t_tlv_builder.c \
		$(SRC_STRUCT_NETWORK_FOLDER)t_iovec_builder.c \
		$(SRC_STRUCT_NETWORK_FOLDER)t_buffer_tlv_ip.c \
		$(SRC_STRUCT_PROTOCOL_FOLDER)t_neighbour.c \
		$(SRC_STRUCT_PROTOCOL_FOLDER)t_potential_neighbour.c \
		$(SRC_STRUCT_PROTOCOL_FOLDER)t_message.c \
		$(SRC_STRUCT_PROTOCOL_FOLDER)t_acquit.c \
		$(SRC_STRUCT_FOLDER)t_env.c \

INC = $(shell find $(INC_FOLDER) -name "*.h")

ALL_FILES = $(SRC) $(INC)