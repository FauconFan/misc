#include "libtest.h"

START_TEST(strjoin_test) {
	char * str1 = "Un";
	char * str2 = "Deux";
	char * res  = strjoin(str1, str2);

	ck_assert_str_eq(res, "UnDeux");
} END_TEST;

START_TEST(nb_digit_test10) {
	ck_assert(nb_digit(10) == 2);
} END_TEST;

START_TEST(nb_digit_test1000) {
	ck_assert(nb_digit(1000) == 4);
} END_TEST;

START_TEST(nb_digit_test999) {
	ck_assert(nb_digit(999) == 3);
} END_TEST;
START_TEST(nb_digit_test1000000000) {
	ck_assert(nb_digit(1000000000) == 10);
} END_TEST;

START_TEST(nb_digit_test9998554) {
	ck_assert(nb_digit(9998554) == 7);
} END_TEST;

START_TEST(nb_digit_test0) {
	ck_assert(nb_digit(0) == 1);
} END_TEST;

/*START_TEST(itoa_test){
 *
 * }END_TEST*/

TCase * utils_test() {
	TCase * tc_utils = tcase_create("Utils");

	tcase_add_test(tc_utils, strjoin_test);
	tcase_add_test(tc_utils, nb_digit_test10);
	tcase_add_test(tc_utils, nb_digit_test1000);
	tcase_add_test(tc_utils, nb_digit_test999);
	tcase_add_test(tc_utils, nb_digit_test1000000000);
	tcase_add_test(tc_utils, nb_digit_test9998554);
	tcase_add_test(tc_utils, nb_digit_test0);

	return tc_utils;
}
