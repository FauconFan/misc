#include "libtest.h"

START_TEST(test_close) {
	treat_line("close");
	ck_assert(g_cimp->screen == NULL);
	g_cimp->screen = cimp_screen_init("images/untitled17.bmp");
	ck_assert(g_cimp->screen);
	treat_line("close");
	ck_assert(g_cimp->screen == NULL);
} END_TEST;

START_TEST(test_open) {
	ck_assert(cimp_open(NULL) == 0);
	treat_line("open images/untitled17.bmp");
	ck_assert(g_cimp->screen != NULL && g_cimp->screen->buff_screen != NULL &&
	  strcmp("images/untitled17.bmp", g_cimp->screen->path));
	treat_line("open images/untitled5.bmp");
	ck_assert(strcmp("images/untitled17.bmp", g_cimp->screen->path));
} END_TEST;

TCase * window_test() {
	TCase * tc_window = tcase_create("Ouverture et fermeture");

	tcase_add_test(tc_window, test_open);
	tcase_add_test(tc_window, test_close);
	return tc_window;
}
