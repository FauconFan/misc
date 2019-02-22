#include "cimp.h"

void cimp_list() {
	if (g_cimp->screen)
		printf("1.Name: %s\n", g_cimp->screen->original_path);
}
