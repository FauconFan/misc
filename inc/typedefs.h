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
	int             running;
}                       t_cimp;

typedef struct          s_cmd {
	char * cmd;
	char * name_file;
	int    angle;
}                       t_cmd;

typedef struct          s_cmd_config {
	char * name;
	int (* func_cmd_ptr)(t_cmd *);
	int8_t need_name;
	int8_t need_angle;
}                       t_cmd_config;

typedef enum            e_error_parser {
	TOO_MUCH_ARGS = 0,
	NOT_ENOUGH_ARGS,
	UNKNOW_NAME,
	MALLOC_EST_LE_MAILLON_FAIBLE,
	INVALID_ARGUMENT,
	NO_LINE,
}                       t_error_parser;

typedef enum            e_type_img {
	NO_SUPPORTED = -1,
	BMP,
	PNG,
	JPG,
}                       t_type_img;

typedef struct          s_extension_img {
	t_type_img type;
	char **    li_extensions;
	size_t     len_nb_extensions;
}                       t_extension_img;

typedef int (* t_export_img_func_ptr)(const char *, SDL_Surface *);

typedef struct          s_assoc_type_img_func {
	t_type_img            type;
	t_export_img_func_ptr func_export;
}                       t_assoc_type_img_func;

/**
 * Ici est définie la variable globale g_cimp qui stocke l'instance de notre programme.
 */

extern t_cimp * g_cimp;

// Parser globals
extern const t_cmd_config g_command_list[];
extern const size_t g_command_list_size;

extern const char * g_error_parser_strings [];

extern const t_extension_img g_extension_img_list[];
extern const size_t g_extension_img_size;

extern const t_assoc_type_img_func g_assoc_type_img_func_list[];
extern const size_t g_assoc_type_img_func_size;

// Childs globals
extern int g_fd_readline;
extern int g_fd_callback;

#endif // ifndef TYPEDEFS_H
