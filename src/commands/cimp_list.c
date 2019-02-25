#include "cimp.h"


void cimp_list() {
	if (g_cimp->screen) {
		int max_name, max_ID, max_taille, max_path, w, h;
		int space_default = 5;

		char * name = basename(g_cimp->screen->original_path);

		w = g_cimp->screen->buff_screen->w;
		h = g_cimp->screen->buff_screen->h;

		max_name   = strlen(name) + space_default;
		max_ID     = strlen("ID") + space_default;
		max_taille = nb_digit(w) + nb_digit(h) + 1 + space_default;
		max_path   = strlen(g_cimp->screen->original_path);

		char * width  = malloc(sizeof(char) * (nb_digit(w) + 1));
		char * height = malloc(sizeof(char) * (nb_digit(h) + 1));
		char * taille = malloc(sizeof(char) * (nb_digit(w) + nb_digit(h) + 3));

		if (width == NULL || height == NULL || taille == NULL) {
			perror("malloc");
			return;
		}
		itoa(w, width);
		itoa(h, height);

		strcat(taille, width);
		strcat(taille, "x");
		strcat(taille, height);

		printf("w : %s h : %s \n", width, height);

		printf("%-*s %-*s %-*s %-*s\n", max_name, "NAME", max_ID, "ID", max_taille, "TAILLE",
		  max_path, "FILEPATH");

		printf("%-*s %-*s %-*s %-*s\n", max_name, name, max_ID, "1", max_taille, taille, max_path,
		  g_cimp->screen->original_path);

		free(taille);
		free(width);
		free(height);
	}
} /* cimp_list */
