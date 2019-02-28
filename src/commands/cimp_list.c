#include "cimp.h"


void cimp_list() {
	if (g_cimp->screen) {
		int max_name, max_ID, max_taille, max_path, w, h;
		int space_default = 5;

		char * name = basename(g_cimp->screen->original_path);

		w = g_cimp->screen->buff_screen->w;
		h = g_cimp->screen->buff_screen->h;
		int w_len = nb_digit(w);
		int h_len = nb_digit(h);

		max_name   = strlen(name) + space_default;
		max_ID     = strlen("ID") + space_default;
		max_taille = w_len + h_len + 1 + space_default;
		max_path   = strlen(g_cimp->screen->original_path);

		char * width  = malloc(sizeof(char) * (w_len + 1));
		char * height = malloc(sizeof(char) * (h_len + 1));
		char * taille = malloc(sizeof(char) * (w_len + h_len + 2));

		if (width == NULL || height == NULL || taille == NULL) {
			free(taille);
			free(width);
			free(height);
			perror("malloc");
			return;
		}

		itoa(w, width);
		itoa(h, height);

		strncpy(taille, width, w_len + 1);
		strncpy(taille + w_len, "x", 2);
		strncpy(taille + w_len + 1, height, h_len + 1);

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
