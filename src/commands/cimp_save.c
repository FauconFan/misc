#include "cimp.h"

int cimp_save(t_cmd * cmd) {
	t_type_img timg;
	t_export_img_func_ptr fptr;

	if (g_cimp->screen) {
		if ((timg = get_type_img(cmd->name_file)) == NO_SUPPORTED ||
		  (fptr = get_func_img(timg)) == NULL)
			return (1);
        return (fptr(cmd->name_file, g_cimp->screen->buff_screen));
	}
	return (1);
}
