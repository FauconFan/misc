#include "libtest.h"

Suite * sample_suite(void) {
	Suite * s;

	s = suite_create("cimp commandes");
	suite_add_tcase(s, modif_test());
	suite_add_tcase(s, window_test());
	suite_add_tcase(s, parsing_test());
	suite_add_tcase(s, util_images_test());
	suite_add_tcase(s, save_test());
	return s;
}

int main(void) {
	int no_failed = 0;
	Suite * s;
	SRunner * runner;

	libtest_viewing_enabled = 0;
	cimp_init();
	s      = sample_suite();
	runner = srunner_create(s);
	srunner_run_all(runner, CK_NORMAL);
	no_failed = srunner_ntests_failed(runner);
	srunner_free(runner);
	return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
