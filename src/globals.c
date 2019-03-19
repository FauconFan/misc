#include "cimp.h"

t_cimp * g_cimp = NULL;

const t_cmd_config g_command_list[] = {
	{"help",      cimp_help,      0, 0, 0},
	{"open",      cimp_open,      1, 0, 0},
	{"close",     cimp_close,     0, 0, 0},
	{"list",      cimp_list,      0, 0, 0},
	{"sym_verti", cimp_sym_verti, 0, 0, 0},
	{"sym_hori",  cimp_sym_hori,  0, 0, 0},
	{"rotate",    cimp_rotate,    0, 1, 0},
	{"QUIT",      NULL,           0, 0, 0},
	{"select",    cimp_select,    0, 0, 1},
	{"unselect",  cimp_unselect,  0, 0, 0}
};

const size_t g_command_list_size = sizeof(g_command_list) / sizeof(*g_command_list);

const char * g_error_parser_strings [] = {
	"Il y a trop d'arguments pour cette commande",
	"Il y a trop peu d'arguments pour cette commande",
	"Le nom de la commande n'est pas connu",
	"Le malloc a echoue",
	"L'argument est invalide",
	"La ligne entrée est vide",
};

int g_fd_readline = -1;
int g_fd_callback = -1;
