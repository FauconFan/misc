#include "cimp.h"

t_cimp * g_cimp = NULL;

const t_parser_config g_command_list[] = {
	{"help",      0, 0},
	{"open",      1, 0},
	{"close",     1, 0},
	{"list",      0, 0},
	{"sym_verti", 0, 0},
	{"sym_horti", 0, 0},
	{"rotate",    0, 1},
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
