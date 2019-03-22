#include "cimp.h"

t_cimp * g_cimp = NULL;

// Take care to configure the opts properly
// No opts of type ARG_PATH | ARG_OPT_PATH
const t_cmd_config g_command_list[] = {
	{"help",      cimp_help,      0,        0},
	{"open",      cimp_open,      ARG_PATH, 0},
	{"close",     cimp_close,     0,        0},
	{"list",      cimp_list,      0,        0},
	{"sym_verti", cimp_sym_verti, 0,        0},
	{"sym_hori",  cimp_sym_hori,  0,        0},
	{"rotate",    cimp_rotate,    ARG_NUM,  0},
	{"select",    cimp_select,    ARG_RECT, 0},
	{"unselect",  cimp_unselect,  0,        0},
	{"QUIT",      NULL,           0,        0} // QUIT must have NULL as func_ptr
};

const size_t g_command_list_size = sizeof(g_command_list) / sizeof(*g_command_list);

int g_fd_readline = -1;
int g_fd_callback = -1;

int libtest_viewing_enabled = 1;
