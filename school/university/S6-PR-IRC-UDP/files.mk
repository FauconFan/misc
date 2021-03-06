
SRC_FOLDER                      = src/
SRC_UTILS_FOLDER                = src/utils/
SRC_STRUCT_FOLDER               = src/struct/
SRC_STRUCT_DATA_FOLDER          = src/struct/data/
SRC_STRUCT_NETWORK_FOLDER       = src/struct/network/
SRC_STRUCT_PROTOCOL_FOLDER      = src/struct/protocol/
SRC_UI_FOLDER                   = src/ui/
SRC_CORE_FOLDER                 = src/core/
SRC_CORE_PARSER_FOLDER          = src/core/parse_tlv/
SRC_CORE_PROCESS_STEPS_FOLDER   = src/core/process_step/
SRC_CORE_ENV_MANIP_FOLDER       = src/core/env_manip/

SRC = \
		$(SRC_FOLDER)main.c \
		$(SRC_FOLDER)parse_args.c \
		$(SRC_CORE_FOLDER)getaddrinfo.c \
		$(SRC_CORE_FOLDER)socket.c \
		$(SRC_CORE_FOLDER)core_loop.c \
		$(SRC_CORE_FOLDER)select_treat_input.c \
		$(SRC_CORE_FOLDER)update_buffer.c \
		$(SRC_CORE_FOLDER)clear_buffer.c \
		$(SRC_CORE_FOLDER)send_multicast.c \
		$(SRC_CORE_ENV_MANIP_FOLDER)env_build_min_time.c \
		$(SRC_CORE_ENV_MANIP_FOLDER)env_has_already_received_msg.c \
		$(SRC_CORE_ENV_MANIP_FOLDER)env_remove_acquit_by_id_nonce.c \
		$(SRC_CORE_ENV_MANIP_FOLDER)env_has_acquit_by_id_nonce.c \
		$(SRC_CORE_ENV_MANIP_FOLDER)env_go_away_all.c \
		$(SRC_CORE_ENV_MANIP_FOLDER)env_erase_nei.c \
		$(SRC_CORE_ENV_MANIP_FOLDER)env_search_nei.c \
		$(SRC_CORE_ENV_MANIP_FOLDER)env_search_nei_by_acq.c \
		$(SRC_CORE_ENV_MANIP_FOLDER)env_get_pot_nei_available.c \
		$(SRC_CORE_PARSER_FOLDER)parse_tlv_core.c \
		$(SRC_CORE_PARSER_FOLDER)parse_pad1.c \
		$(SRC_CORE_PARSER_FOLDER)parse_padN.c \
		$(SRC_CORE_PARSER_FOLDER)parse_hello.c \
		$(SRC_CORE_PARSER_FOLDER)parse_neighbour.c \
		$(SRC_CORE_PARSER_FOLDER)parse_data.c \
		$(SRC_CORE_PARSER_FOLDER)parse_ack.c \
		$(SRC_CORE_PARSER_FOLDER)parse_go_away.c \
		$(SRC_CORE_PARSER_FOLDER)parse_warning.c \
		$(SRC_CORE_PROCESS_STEPS_FOLDER)ps1_delete_old_pot_neighbours.c \
		$(SRC_CORE_PROCESS_STEPS_FOLDER)ps2_connect_new_neighbour.c \
		$(SRC_CORE_PROCESS_STEPS_FOLDER)ps3_go_away_old_neighbours.c \
		$(SRC_CORE_PROCESS_STEPS_FOLDER)ps4_send_long_hello.c \
		$(SRC_CORE_PROCESS_STEPS_FOLDER)ps5_go_away_ack_missing.c \
		$(SRC_CORE_PROCESS_STEPS_FOLDER)ps6_resend_messages_non_acquitted.c \
		$(SRC_CORE_PROCESS_STEPS_FOLDER)ps7_send_random_neighbour_tlv.c \
		$(SRC_CORE_PROCESS_STEPS_FOLDER)ps8_delete_messages_if_too_late.c \
		$(SRC_UTILS_FOLDER)my_getrandom.c \
		$(SRC_UTILS_FOLDER)my_time.c \
		$(SRC_UTILS_FOLDER)my_str.c \
		$(SRC_UI_FOLDER)ui_main.c \
		$(SRC_UI_FOLDER)ui_read_pseudo.c \
		$(SRC_UI_FOLDER)ui_ncurses_print.c \
		$(SRC_UI_FOLDER)ui_check_message_stop.c \
		$(SRC_UI_FOLDER)ui_send_message.c \
		$(SRC_UI_FOLDER)ui_utils.c \
		$(SRC_UI_FOLDER)ui_setup.c \
		$(SRC_UI_FOLDER)ui_log_setup.c \
		$(SRC_UI_FOLDER)ui_stdin_custom.c \
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
