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
	char *        path;
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
	char *    cmd;
	char *    name;
	int       num;
	SDL_Rect  rect;
	SDL_Point point;
}                   t_cmd;

#define	NB_ARG_TYPE 5

typedef enum        e_arg_type {
	ARG_NAME = 0x1,
	ARG_NUM  = 0x2,
	ARG_PATH = 0x4,
	ARG_RECT = 0x8,
	ARG_PT   = 0x10,
}                   t_arg_type;

typedef struct      s_cmd_config {
	char *  name;
	int (* func_cmd_ptr)(t_cmd *);
	uint8_t opts;     // Necessary opts
	uint8_t opts_opt; // Optionnal opts
} t_cmd_config;

typedef enum            e_type_img {
	NO_SUPPORTED = -1,
	BMP,
	JPG,
	PNG,
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

extern const t_extension_img g_extension_img_list[];
extern const size_t g_extension_img_size;

extern const t_assoc_type_img_func g_assoc_type_img_func_list[];
extern const size_t g_assoc_type_img_func_size;

// Childs globals
extern int g_fd_readline;
extern int g_fd_callback;

// libtest globale
extern int libtest_viewing_enabled;

#endif // ifndef TYPEDEFS_H
