#include "cimp.h"

int cimp_select(SDL_Rect rect, char ** errno_str) {
	t_cimp_select * selection = cimp_init_select(rect, errno_str);

	if(selection == NULL){
		return -1;
	}

	g_cimp->select = selection;

	return 0;
}

void cimp_unselect(){
	cimp_end_select(g_cimp->select);
	g_cimp->select = NULL;
}
