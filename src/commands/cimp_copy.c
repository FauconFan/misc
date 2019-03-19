#include "cimp.h"

/** Une fonction qui stocke dans le champs copy_buffer de g_cimp la partie de l'image designee
 * par l'argument rect passe a la commande.
 * Renvoie 0 en cas de succes et en cas d'echec ou si aucune image n'es ouverte renvoie -1**/
int cimp_copy(t_cmd * cmd) {
	if (!g_cimp->screen) {
		printf("Pas d'image ouverte : la copie est impossible\n");
		return -1;
	}
	(void) cmd;
	return 0;
}

/**Une fonction qui colle la surface stockee dans copy_buffer a partir des coordonnes x0 y0
 * passees en arguments.
 * Renvoie 0 en cas de succes et -1 sinon en affichant un message d'erreur. **/
int cimp_paste(t_cmd * cmd) {
	if (!g_cimp->screen) {
		printf("Pas d'image ouverte : le collage est impossible\n");
		return -1;
	}
	else if (!g_cimp->copy_buffer) {
		printf("Rien n'a ete copie : le collage est impossible\n");
		return -1;
	}
	(void) cmd;
	return 0;
}

/**Une fonction qui copie la partie de l'image selectionnee et la re place par du rouge.
 * Renvoie 0 en cas de succes et -1 sinon. **/
int cimp_cut(t_cmd * cmd) {
	if (cimp_copy(cmd) < 0)
		return -1;

	if (SDL_FillRect(g_cimp->screen->buff_screen, &cmd->rect, 0xFF0000FF) < 0)
		return -1;

	return 0;
}
