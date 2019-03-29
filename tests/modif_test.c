#include "libtest.h"
#include "cimp.h"

START_TEST(test_rotate45) {
	ck_assert(cimp_rotate(NULL) == 1);
	SDL_Surface * surf = SDL_CreateRGBSurface(0, 3, 2, 32, 0, 0, 0, 0);
	uint32_t * new     = (uint32_t *) surf->pixels;
	uint32_t to_test   = (uint32_t) 32;
	new[0]         = to_test;
	g_cimp->screen = malloc(sizeof(t_cimp_screen));
	g_cimp->screen->buff_screen = surf;
	treat_line("rotate 45");
	ck_assert(g_cimp->screen->buff_screen->w == 3 && g_cimp->screen->buff_screen->h == 2);
	uint32_t * pixels = (uint32_t *) g_cimp->screen->buff_screen->pixels;
	for (int i = 0; i < 6; i++) {
		if (i == 0) ck_assert(pixels[0] == to_test); else ck_assert(pixels[i] == 0);
	}
} END_TEST;

START_TEST(test_rotate0) {
	ck_assert(cimp_rotate(NULL) == 1);
	SDL_Surface * surf = SDL_CreateRGBSurface(0, 3, 2, 32, 0, 0, 0, 0);
	uint32_t * new     = (uint32_t *) surf->pixels;
	uint32_t to_test   = (uint32_t) 32;
	new[0]         = to_test;
	g_cimp->screen = malloc(sizeof(t_cimp_screen));
	g_cimp->screen->buff_screen = surf;
	treat_line("rotate 0");
	ck_assert(g_cimp->screen->buff_screen->w == 3 && g_cimp->screen->buff_screen->h == 2);
	uint32_t * pixels = (uint32_t *) g_cimp->screen->buff_screen->pixels;
	for (int i = 0; i < 6; i++) {
		if (i == 0) ck_assert(pixels[0] == to_test); else ck_assert(pixels[i] == 0); }
} END_TEST;

START_TEST(test_rotate720) {
	ck_assert(cimp_rotate(NULL) == 1);
	SDL_Surface * surf = SDL_CreateRGBSurface(0, 3, 2, 32, 0, 0, 0, 0);
	uint32_t * new     = (uint32_t *) surf->pixels;
	uint32_t to_test   = (uint32_t) 32;
	new[0]         = to_test;
	g_cimp->screen = malloc(sizeof(t_cimp_screen));
	g_cimp->screen->buff_screen = surf;
	treat_line("rotate 720");
	ck_assert(g_cimp->screen->buff_screen->w == 3 && g_cimp->screen->buff_screen->h == 2);
	uint32_t * pixels = (uint32_t *) g_cimp->screen->buff_screen->pixels;
	for (int i = 0; i < 6; i++) {
		if (i == 0) ck_assert(pixels[0] == to_test); else ck_assert(pixels[i] == 0); }
} END_TEST;

START_TEST(test_rotate90) {
	ck_assert(cimp_rotate(NULL) == 1);
	SDL_Surface * surf = SDL_CreateRGBSurface(0, 3, 2, 32, 0, 0, 0, 0);
	uint32_t * new     = (uint32_t *) surf->pixels;
	uint32_t to_test   = (uint32_t) 32;
	new[0]         = to_test;
	g_cimp->screen = malloc(sizeof(t_cimp_screen));
	g_cimp->screen->buff_screen = surf;
	treat_line("rotate 90");
	ck_assert(g_cimp->screen->buff_screen->w == 2 && g_cimp->screen->buff_screen->h == 3);
	uint32_t * pixels = (uint32_t *) g_cimp->screen->buff_screen->pixels;
	for (int i = 0; i < 6; i++) {
		if (i == 1) ck_assert(pixels[1] == to_test); else ck_assert(pixels[i] == 0); }
} END_TEST;

START_TEST(test_rotate180) {
	ck_assert(cimp_rotate(NULL) == 1);
	SDL_Surface * surf = SDL_CreateRGBSurface(0, 3, 2, 32, 0, 0, 0, 0);
	uint32_t * new     = (uint32_t *) surf->pixels;
	uint32_t to_test   = (uint32_t) 32;
	new[0]         = to_test;
	g_cimp->screen = malloc(sizeof(t_cimp_screen));
	g_cimp->screen->buff_screen = surf;
	treat_line("rotate 180");
	ck_assert(g_cimp->screen->buff_screen->w == 3 && g_cimp->screen->buff_screen->h == 2);
	uint32_t * pixels = (uint32_t *) g_cimp->screen->buff_screen->pixels;
	for (int i = 0; i < 6; i++) {
		if (i == 5) ck_assert(pixels[5] == to_test); else ck_assert(pixels[i] == 0);
	}
} END_TEST;

START_TEST(test_rotateneg90) {
	ck_assert(cimp_rotate(NULL) == 1);
	SDL_Surface * surf = SDL_CreateRGBSurface(0, 3, 2, 32, 0, 0, 0, 0);
	uint32_t * new     = (uint32_t *) surf->pixels;
	uint32_t to_test   = (uint32_t) 32;
	new[0]         = to_test;
	g_cimp->screen = malloc(sizeof(t_cimp_screen));
	g_cimp->screen->buff_screen = surf;
	treat_line("rotate -90");
	ck_assert(g_cimp->screen->buff_screen->w == 2 && g_cimp->screen->buff_screen->h == 3);
	uint32_t * pixels = (uint32_t *) g_cimp->screen->buff_screen->pixels;
	for (int i = 0; i < 6; i++) {
		if (i == 4) ck_assert(pixels[4] == to_test); else ck_assert(pixels[i] == 0); }
} END_TEST;

START_TEST(test_sym_verti) {
	SDL_Surface * surf = SDL_CreateRGBSurface(0, 3, 2, 32, 0, 0, 0, 0);
	uint32_t * new     = (uint32_t *) surf->pixels;
	uint32_t to_test   = (uint32_t) 32;

	new[0]         = to_test;
	g_cimp->screen = malloc(sizeof(t_cimp_screen));
	g_cimp->screen->buff_screen = surf;
	treat_line("sym_verti");
	ck_assert(g_cimp->screen->buff_screen->w == 3 && g_cimp->screen->buff_screen->h == 2);
	uint32_t * pixels = (uint32_t *) g_cimp->screen->buff_screen->pixels;
	for (int i = 0; i < 6; i++) {
		if (i == 2) ck_assert(pixels[2] == to_test); else ck_assert(pixels[i] == 0); }
} END_TEST;

START_TEST(test_sym_hori) {
	SDL_Surface * surf = SDL_CreateRGBSurface(0, 3, 2, 32, 0, 0, 0, 0);
	uint32_t * new     = (uint32_t *) surf->pixels;
	uint32_t to_test   = (uint32_t) 32;

	new[0]         = to_test;
	g_cimp->screen = malloc(sizeof(t_cimp_screen));
	g_cimp->screen->buff_screen = surf;
	treat_line("sym_hori");
	ck_assert(g_cimp->screen->buff_screen->w == 3 && g_cimp->screen->buff_screen->h == 2);
	uint32_t * pixels = (uint32_t *) g_cimp->screen->buff_screen->pixels;
	for (int i = 0; i < 6; i++) {
		if (i == 3) ck_assert(pixels[3] == to_test); else ck_assert(pixels[i] == 0); }
} END_TEST;

TCase * modif_test() {
	TCase * tc_modif = tcase_create("Modif images");

	tcase_add_test(tc_modif, test_rotate45);
	tcase_add_test(tc_modif, test_rotate0);
	tcase_add_test(tc_modif, test_rotate720);
	tcase_add_test(tc_modif, test_rotate90);
	tcase_add_test(tc_modif, test_rotate180);
	tcase_add_test(tc_modif, test_rotateneg90);
	tcase_add_test(tc_modif, test_sym_verti);
	tcase_add_test(tc_modif, test_sym_hori);
	return tc_modif;
}
