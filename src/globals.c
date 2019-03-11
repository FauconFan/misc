#include "cimp.h"

t_cimp * g_cimp = NULL;

const t_parser_config g_command_list[] = {
	{"help",      0, 0, 0},
	{"open",      1, 0, 0},
	{"close",     0, 0, 0},
	{"list",      0, 0, 0},
	{"sym_verti", 0, 0, 0},
	{"sym_hori",  0, 0, 0},
	{"rotate",    0, 1, 0},
	{"QUIT",      0, 0, 0},
	{"select",    0, 0, 1},
	{"unselect",  0, 0, 0}
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
