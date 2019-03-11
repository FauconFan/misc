#include "cimp.h"

/** Une fontion qui alloue la memoire necessaire et cree un t_cimp_select correspondant
 * au SDL_Rect passe en argument**/
t_cimp_select * cimp_init_select(SDL_Rect rectangle, char ** errno_str) {
	t_cimp_select * res = malloc(sizeof(t_cimp_select));

	if (res == NULL) {
		*errno_str = MALLOC_FAIL;
		return NULL;
	}

	res->surface = rectangle;
	return res;
}

/** Une fonction qui libere la memoire allouee au t_cimp_select selection
**/
void cimp_end_select(t_cimp_select * selection) {
	free(selection);
}
