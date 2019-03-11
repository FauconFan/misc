#include "cimp.h"


/**Une fonction qui cree la zone de selection associee au rectangle rect.
 * Si une selectionexiste deja on met a jour les donnees du rectangle  **/
int cimp_select(SDL_Rect rect, char ** errno_str) {
	if (g_cimp->select != NULL) {
		g_cimp->select->surface = rect;
		return 0;
	}

	t_cimp_select * selection = cimp_init_select(rect, errno_str);

	if (selection == NULL) {
		return -1;
	}

	g_cimp->select = selection;

	return 0;
}

/** Une fonction aui libere la memoire associee a une selection,
 * mets a jour le champ correspondant dans g_cimp.**/
void cimp_unselect() {
	cimp_end_select(g_cimp->select);
	g_cimp->select = NULL;
}
