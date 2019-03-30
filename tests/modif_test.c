#include "libtest.h"

static void exec(SDL_Surface ** surf, char **lines, size_t len) {
	g_cimp->screen = malloc(sizeof(t_cimp_screen));
	g_cimp->screen->buff_screen = *surf;
	treat_line("unselect");
	for (size_t i = 0; i < len; ++i)
		treat_line(lines[i]);
	*surf = g_cimp->screen->buff_screen;
	free(g_cimp->screen);
	g_cimp->screen = NULL;
}

static void test_img(
				char * line,
				const int w,
				const int h,
				const int point,
				const int w_new,
				const int h_new,
				const int point_new) {
	SDL_Surface * surf;
	uint32_t * pixels;
	uint32_t value;

	surf = genSurface(w, h);
	pixels = (uint32_t *) surf->pixels;

	value = pixels[point];
	exec(&surf, &line, 1);
	ck_assert(surf->w == w_new);
	ck_assert(surf->h == h_new);
	pixels = (uint32_t *) surf->pixels;
	ck_assert(pixels[point_new] == value);

	SDL_FreeSurface(surf);
}

static void test_idempotent(
				char **lines,
				size_t len_lines) {
	SDL_Surface * surf;
	SDL_Surface * copy;
	const int w = 50;
	const int h = 50;

	surf = genSurface(w, h);
	copy = copySurface(surf);

	exec(&surf, lines, len_lines);

	ck_assert(compareSurfaces(surf, copy));

	SDL_FreeSurface(copy);
	SDL_FreeSurface(surf);
}

static void test_same_treatment(
				char **lines1,
				size_t len_lines1,
				char **lines2,
				size_t len_lines2) {
	SDL_Surface * surf1;
	SDL_Surface * surf2;
	const int w = 50;
	const int h = 50;

	surf1 = genSurface(w, h);
	surf2 = genSurface(w, h);

	exec(&surf1, lines1, len_lines1);
	exec(&surf2, lines2, len_lines2);

	ck_assert(compareSurfaces(surf1, surf2));

	SDL_FreeSurface(surf1);
	SDL_FreeSurface(surf2);
}

START_TEST(test_rotate) {
	ck_assert(cimp_rotate(NULL) == 0);

	test_img("rotate 45", 3, 2, 0, 3, 2, 0);
	test_img("rotate 0", 3, 2, 0, 3, 2, 0);
	test_img("rotate 720", 3, 2, 0, 3, 2, 0);
	test_img("rotate 90", 3, 2, 0, 2, 3, 1);
	test_img("rotate 180", 3, 2, 0, 3, 2, 5);
	test_img("rotate 270", 3, 2, 0, 2, 3, 4);
	test_img("rotate -90", 3, 2, 0, 2, 3, 4);

	test_idempotent((char *[]){"rotate 0"}, 1);
	test_idempotent((char *[]){"rotate 0", "rotate 0"}, 2);
	test_idempotent((char *[]){"rotate 360"}, 1);
	test_idempotent((char *[]){"rotate 720"}, 1);
	test_idempotent((char *[]){"rotate -360"}, 1);

	test_same_treatment((char *[]){"rotate 0"}, 1,
						(char *[]){"rotate 360"}, 1);
	test_same_treatment((char *[]){"rotate 90"}, 1,
						(char *[]){"rotate -270"}, 1);
	test_same_treatment((char *[]){"rotate 180"}, 1,
						(char *[]){"rotate -180"}, 1);
	test_same_treatment((char *[]){"rotate 270"}, 1,
						(char *[]){"rotate -90"}, 1);

} END_TEST;

START_TEST(test_sym) {
	ck_assert(cimp_sym_hori(NULL) == 0);
	ck_assert(cimp_sym_verti(NULL) == 0);

	test_img("sym_verti", 3, 2, 0, 3, 2, 2);
	test_img("sym_hori", 3, 2, 0, 3, 2, 3);

	test_idempotent((char *[]){"sym_verti", "sym_verti"}, 2);
	test_idempotent((char *[]){"sym_hori", "sym_hori"}, 2);
	test_idempotent((char *[]){"sym_hori", "sym_hori", "sym_verti", "sym_verti"}, 4);
	test_idempotent((char *[]){"sym_hori", "sym_verti", "sym_hori", "sym_verti"}, 4);

} END_TEST;

START_TEST(test_fill) {
	ck_assert(cimp_fill(NULL) == 0);

	test_same_treatment((char *[]){"fill 0xFF0000", "fill 0x00FF00"}, 2,
						(char *[]){"fill 0x00FF00"}, 1);

	test_same_treatment((char *[]){"select (0 0 20 20)", "fill 0xFF0000", "unselect", "fill 0x00FF00"}, 4,
						(char *[]){"fill 0x00FF00"}, 1);

	test_same_treatment((char *[]){"fill 0xFF0000 (0 0 20 20)", "fill 0x00FF00"}, 2,
						(char *[]){"fill 0x00FF00"}, 1);

	test_same_treatment((char *[]){"fill 0xFF0000 (0 0 20 20)", "fill (0 0 25 25) 0x00FF00"}, 2,
						(char *[]){"fill 0x00FF00 (0 0 25 25)"}, 1);
} END_TEST;

START_TEST(test_gray) {
	SDL_Surface * surf;
	uint32_t * pixels;

	ck_assert(cimp_color_gray(NULL) == 0);

	surf = genSurface(3, 1);
	pixels = (uint32_t *) surf->pixels;
	pixels[0] = SDL_MapRGB(surf->format, 80, 100, 120); //gray = 100
	pixels[1] = SDL_MapRGB(surf->format, 10, 15, 35); // gray = 20
	pixels[2] = SDL_MapRGB(surf->format, 243, 250, 255); // gray = 249

	exec(&surf, (char *[]){"color_gray"}, 1);

	pixels = (uint32_t *) surf->pixels;
	for (size_t i = 0; i < 3; ++i) {
		uint8_t gray, r, g, b;

		if (i == 0)
			gray = 100;
		else if (i == 1)
			gray = 20;
		else
			gray = 249;
		SDL_GetRGB(pixels[i], surf->format, &r, &g, &b);
		ck_assert(gray == r);
		ck_assert(gray == g);
		ck_assert(gray == b);
	}

	SDL_FreeSurface(surf);

	test_same_treatment((char *[]){"color_gray", "color_gray"}, 2,
						(char *[]){"color_gray"}, 1);
} END_TEST;

TCase * modif_test() {
	TCase * tc_modif = tcase_create("Modif images");

	tcase_add_test(tc_modif, test_rotate);
	tcase_add_test(tc_modif, test_sym);
	tcase_add_test(tc_modif, test_fill);
	tcase_add_test(tc_modif, test_gray);
	return tc_modif;
}
