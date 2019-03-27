#include "cimp.h"

#define	SIZE_TAB(t) (sizeof(t) / sizeof(*(t)))

t_cimp * g_cimp = NULL;

// Take care to configure the opts properly
// No opts of type ARG_PATH | ARG_OPT_PATH
const t_cmd_config g_command_list[] = {
	{"help",                 cimp_help,                 0,                    0       },
	{"open",                 cimp_open,                 ARG_PATH,             0       },
	{"close",                cimp_close,                0,                    0       },
	{"list",                 cimp_list,                 0,                    0       },
	{"sym_verti",            cimp_sym_verti,            0,                    0       },
	{"sym_hori",             cimp_sym_hori,             0,                    0       },
	{"rotate",               cimp_rotate,               ARG_NUM,              0       },
	{"select",               cimp_select,               ARG_RECT,             0       },
	{"unselect",             cimp_unselect,             0,                    0       },
	{"save",                 cimp_save,                 0,                    ARG_PATH},
	{"update",               cimp_update,               0,                    ARG_PATH},
	{"copy",                 cimp_copy,                 0,                    ARG_RECT},
	{"cut",                  cimp_paste,                0,                    ARG_RECT},
	{"paste",                cimp_paste,                ARG_PT,               0       },
	{"fill",                 cimp_fill,                 ARG_COLOR,            ARG_RECT},
	{"color_replace",        cimp_color_replace,        ARG_COLOR2 | ARG_NUM, ARG_RECT},
	{"color_negative",       cimp_color_negative,       0,                    ARG_RECT},
	{"color_gray",           cimp_color_gray,           0,                    ARG_RECT},
	{"ajust_light_contrast", cimp_ajust_light_contrast, ARG_NUM,              ARG_RECT},
	{"QUIT",                 NULL,                      0,                    0       }, // QUIT must have NULL as func_ptr
};

const size_t g_command_list_size = SIZE_TAB(g_command_list);

static const char * bmp_list[] = {"bmp", "dib", "rle"};
static const char * png_list[] = {"png"};
static const char * jpg_list[] = {"jpg", "jpeg"};

const t_extension_img g_extension_img_list[] = {
	{BMP, (char **) bmp_list, SIZE_TAB(bmp_list)},
	{PNG, (char **) png_list, SIZE_TAB(png_list)},
	{JPG, (char **) jpg_list, SIZE_TAB(jpg_list)},
};

const size_t g_extension_img_size = SIZE_TAB(g_extension_img_list);

const t_assoc_type_img_func g_assoc_type_img_func_list[] = {
	{BMP, save_surface_bmp },
	{PNG, save_surface_png },
	{JPG, save_surface_jpeg},
};

const size_t g_assoc_type_img_func_size = SIZE_TAB(g_assoc_type_img_func_list);

int g_fd_readline = -1;
int g_fd_callback = -1;
