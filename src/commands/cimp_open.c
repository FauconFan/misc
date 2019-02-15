#include "cimp.h"

int cimp_open(char * path, char ** errno_str) {
	if (g_cimp->screen == NULL) {// condition à modifier quand nous aurons plusieurs écrans à gérer
		g_cimp->screen = cimp_init_screen(path, errno_str);
		return 0;// for now we'll check conditions after if everithing gone right or no.
	}
	return -1;
}
