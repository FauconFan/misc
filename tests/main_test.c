#include <check.h>
#include "cimp.h"

START_TEST(test_hello_world) {
    char    *hello_world = "HELLO";

    ck_assert_str_eq(hello_world, "HELLO");
} END_TEST

Suite *sample_suite(void) {
  Suite *s;
  TCase *tc_sample;

  s = suite_create("Hello");
  tc_sample = tcase_create("Sample");

  tcase_add_test(tc_sample, test_hello_world);
  suite_add_tcase(s, tc_sample);

  return s;
}

int main(void) {
  int no_failed = 0;
  Suite *s;
  SRunner *runner;

  s = sample_suite();
  runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  no_failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}