#include "libtest.h"

START_TEST(type_test_NULL) {
	ck_assert(get_type_img(NULL) == -1);
} END_TEST


TCase * util_images_test() {
	TCase * tc_utils_images = tcase_create("Utils images");

	tcase_add_test(tc_utils_images, type_test_NULL);
	return tc_utils_images;
}
