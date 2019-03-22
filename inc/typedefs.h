#ifndef TYPEDEFS_H
#define	TYPEDEFS_H

#include "cimp.h"

#define	TRUE  1
#define	FALSE 0

typedef unsigned char t_bool;

/**
 * Ici sont définies les structures standards utilisées dans le programme.
 */
typedef struct s_cimp_select {
	SDL_Rect surface;
} t_cimp_select;

typedef struct          s_cimp_screen {
	SDL_Window *  window;
	SDL_Surface * buff_screen;
	char *        original_path;
}                       t_cimp_screen;

typedef struct      s_cimp_event {
	SDL_Rect selection;
	int8_t   button_pressed;
} t_cimp_event;

typedef struct          s_cimp {
	t_cimp_screen * screen;
	int             running;
	t_cimp_select * select;
	t_cimp_event *  event;
}                       t_cimp;

typedef struct      s_cmd {
	char *   cmd;
	char *   name;
	int      num;
	SDL_Rect rect;
}                   t_cmd;

#define NB_ARG_TYPE		4

typedef enum		e_arg_type {
	ARG_NAME = 0x1,
	ARG_NUM = 0x2,
	ARG_PATH = 0x4,
	ARG_RECT = 0x8,
}					t_arg_type;

typedef struct      s_cmd_config {
	char *  name;
	int (* func_cmd_ptr)(t_cmd *);
	uint8_t opts;     // Necessary opts
	uint8_t opts_opt; // Optionnal opts
} t_cmd_config;


typedef enum e_error_parser {
	TOO_MUCH_ARGS = 0,
	NOT_ENOUGH_ARGS,
	UNKNOW_NAME,
	MALLOC_EST_LE_MAILLON_FAIBLE,
	INVALID_ARGUMENT,
	NO_LINE,
	INVALID_RECT,
}            t_error_parser;

/**
 * Ici est définie la variable globale g_cimp qui stocke l'instance de notre programme.
 */

extern t_cimp * g_cimp;

// Parser globals
extern const t_cmd_config g_command_list[];
extern const size_t g_command_list_size;

extern const char * g_error_parser_strings [];

// Childs globals
extern int g_fd_readline;
extern int g_fd_callback;

#endif // ifndef TYPEDEFS_H
