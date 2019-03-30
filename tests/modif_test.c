#include "libtest.h"

static void test_img(
				char * line,
				const int w,
				const int h,
				const int point,
				const int w_new,
				const int h_new,
				const int point_new) {
	SDL_Surface * surf;
	uint32_t * old;
	uint32_t * new;
	const uint32_t value = 32;

	ck_assert(cimp_rotate(NULL) == 1);
	surf = SDL_CreateRGBSurface(0, w, h, 32, 0, 0, 0, 0);
	old = (uint32_t *) surf->pixels;

	for (int i = 0; i < w * h; ++i) {
		old[i] = 0;
	}
	old[point] = value;
	g_cimp->screen = malloc(sizeof(t_cimp_screen));
	g_cimp->screen->buff_screen = surf;
	treat_line(line);
	ck_assert(g_cimp->screen->buff_screen->w == w_new);
	ck_assert(g_cimp->screen->buff_screen->h == h_new);
	new = (uint32_t *) g_cimp->screen->buff_screen->pixels;
	for (int i = 0; i < w * h; ++i) {
		if (i == point_new)
			ck_assert(new[i] == value);
		else
			ck_assert(new[i] == 0);
	}
	SDL_FreeSurface(g_cimp->screen->buff_screen);
	free(g_cimp->screen);
	g_cimp->screen = NULL;
}

START_TEST(test_rotate) {
	test_img("rotate 45", 3, 2, 0, 3, 2, 0);
	test_img("rotate 0", 3, 2, 0, 3, 2, 0);
	test_img("rotate 720", 3, 2, 0, 3, 2, 0);
	test_img("rotate 90", 3, 2, 0, 2, 3, 1);
	test_img("rotate 180", 3, 2, 0, 3, 2, 5);
	test_img("rotate -90", 3, 2, 0, 2, 3, 4);
} END_TEST;

START_TEST(test_sym) {
	test_img("sym_verti", 3, 2, 0, 3, 2, 2);
	test_img("sym_hori", 3, 2, 0, 3, 2, 3);
} END_TEST;

TCase * modif_test() {
	TCase * tc_modif = tcase_create("Modif images");

	tcase_add_test(tc_modif, test_rotate);
	tcase_add_test(tc_modif, test_sym);
	return tc_modif;
}
