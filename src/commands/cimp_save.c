#include "cimp.h"

int cimp_save(t_cmd * cmd) {
	if (g_cimp->screen) {
		t_type_img timg;
		t_export_img_func_ptr fptr;
		char * namefile;
		int ret;

		if (cmd->name == NULL)
			namefile = g_cimp->screen->path;
		else
			namefile = cmd->name;

		if ((timg = get_type_img(namefile)) == NO_SUPPORTED ||
		  (fptr = get_func_img(timg)) == NULL)
			return (1);

		ret = fptr(namefile, g_cimp->screen->buff_screen);
		if (ret == 0 && cmd->name != NULL)
			ret = (cimp_screen_set_path(g_cimp->screen, namefile) == FALSE);
		return (ret);
	}
	return (1);
}
