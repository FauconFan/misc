#ifndef TYPEDEFS_H
#define	TYPEDEFS_H

#include "cimp.h"

/**
 * Ici sont définies les structures standards utilisées dans le programme.
 */

typedef struct          s_cimp_screen {
	SDL_Window *  window;
	SDL_Surface * buff_screen;
	char *        original_path;
}                       t_cimp_screen;

typedef struct          s_cimp {
	t_cimp_screen * screen;
}                       t_cimp;

/********************************* PARSER ************************************/

typedef struct      s_parser_config {
	char * name;
	int8_t has_name;
	int8_t has_angle;
}                   t_parser_config;

typedef struct      s_parser_out {
	char * cmd;
	char * name_file;
	int    angle;
}                   t_parser_out;

typedef enum e_error_parser {
	TOO_MUCH_ARGS = 0,
	NOT_ENOUGH_ARGS,
	UNKNOW_NAME,
	MALLOC_EST_LE_MAILLON_FAIBLE,
	INVALID_ARGUMENT,
	NO_LINE,
}            t_error_parser;

/**
 * Ici est définie la variable globale g_cimp qui stocke l'instance de notre programme.
 */

extern t_cimp * g_cimp;

// Parser globals
extern const t_parser_config g_command_list[];
extern const size_t g_command_list_size;

extern const char * g_error_parser_strings [];

#endif // ifndef TYPEDEFS_H
