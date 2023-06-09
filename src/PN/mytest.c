#include <check.h>
#include <math.h>

#include "graph.h"

START_TEST(calculate_01) {
  char *str = "2+6";
  double result_num = 8;
  double *test_num = mainpn(str, 1, 3);
  ck_assert_double_eq(test_num[0], result_num);
}

START_TEST(calculate_02) {
  char *str = "x^2";
  double result_num = 16;
  double *test_num = mainpn(str, 4, 6);
  ck_assert_double_eq(test_num[0], result_num);
}

START_TEST(calculate_03) {
  char *str = "sin(x)";
  double result_num = 0;
  double *test_num = mainpn(str, 0, 2);
  ck_assert_double_eq(test_num[0], result_num);
}

START_TEST(calculate_04) {
  char *str = "cos(x)+1";
  double result_num = 2.000000;
  double *test_num = mainpn(str, 0, 2);
  ck_assert_double_eq(test_num[0], result_num);
}

START_TEST(calculate_05) {
  char *str = "cos(log(x))";
  double result_num = 0.536661;
  double *test_num = mainpn(str, 0, 10);
  ck_assert_double_eq((int)(test_num[101] * 100000),
                      (int)(result_num * 100000));
}

START_TEST(calculate_06) {
  char *str = "asin(x)";
  double result_num = -1.570796;
  double *test_num = mainpn(str, -1, 1);
  ck_assert_double_eq((int)(test_num[0] * 100000), (int)(result_num * 100000));
}

START_TEST(calculate_07) {
  char *str = "tan(x)";
  double result_num = 0.100335;
  double *test_num = mainpn(str, 0, 1);
  ck_assert_double_eq((int)(test_num[1] * 100000), (int)(result_num * 100000));
}

START_TEST(calculate_08) {
  char *str = "52%4";
  double result_num = 0;
  double *test_num = mainpn(str, 0, 1);
  ck_assert_double_eq((int)(test_num[1] * 100000), (int)(result_num)*100000);
}

START_TEST(calculate_09) {
  char *str = "log(x)";
  double result_num = -0.69897;
  double *test_num = mainpn(str, 0, 1);
  ck_assert_double_eq((int)(test_num[2] * 100000), (int)((result_num)*100000));
}

START_TEST(calculate_10) {
  char *str = "sqrt(x)";
  double result_num = 0 / 0.0;
  double *test_num = mainpn(str, -1, 2);
  ck_assert_double_eq((int)test_num[0], (int)result_num);
}

START_TEST(calculate_11) {
  char *str = "sqrt(x)";
  double result_num = 7;
  double *test_num = mainpn(str, 49, 52);
  ck_assert_double_eq((int)test_num[0], (int)result_num);
}

START_TEST(calculate_12) {
  char *str = "sqrt(x)+0.5";
  double result_num = 7.5;
  double *test_num = mainpn(str, 49, 52);
  ck_assert_double_eq((int)(test_num[0] * 10), (int)(result_num * 10));
}

START_TEST(calculate_13) {
  char *str = "sqrt(x)-0.5+0.5";
  double result_num = 8;
  double *test_num = mainpn(str, 64, 70);
  ck_assert_double_eq((int)test_num[0], (int)result_num);
}

START_TEST(calculate_14) {
  char *str = "0.6+0.5*2";
  double result_num = 1.6;
  double *test_num = mainpn(str, -2, 2);
  ck_assert_double_eq((int)(test_num[0] * 10), (int)(result_num * 10));
}

START_TEST(calculate_15) {
  char *str = "atan(x)";
  double result_num = 0.197395;
  double *test_num = mainpn(str, 0, 10);
  ck_assert_double_eq((int)(test_num[2] * 1000000),
                      (int)(result_num * 1000000));
}

START_TEST(calculate_16) {
  char *str = "atan(x)-0.07";
  double result_num = 0.127395;
  double *test_num = mainpn(str, 0, 10);
  ck_assert_double_eq((int)(test_num[2] * 1000000),
                      (int)(result_num * 1000000));
}

START_TEST(calculate_17) {
  char *str = "acos(x)";
  double result_num = 1.570796;
  double *test_num = mainpn(str, 0, 10);
  ck_assert_double_eq((int)(test_num[0] * 1000000),
                      (int)(result_num * 1000000));
}

START_TEST(calculate_18) {
  char *str = "acos(x)*2";
  double result_num = 3.141592;
  double *test_num = mainpn(str, 0, 10);
  ck_assert_double_eq((int)(test_num[0] * 1000000),
                      (int)(result_num * 1000000));
}

START_TEST(calculate_19) {
  char *str = "(atan(x)-0.07)*3";
  double result_num = 0.382186;
  double *test_num = mainpn(str, 0, 10);
  ck_assert_double_eq((int)(test_num[2] * 1000000),
                      (int)(result_num * 1000000));
}

START_TEST(calculate_20) {
  char *str = "2*(atan(x)-0.07)*3";
  double result_num = 0.764373;
  double *test_num = mainpn(str, 0, 10);
  ck_assert_double_eq((int)(test_num[2] * 1000000),
                      (int)(result_num * 1000000));
}

START_TEST(calculate_21) {
  char *str = "(0.6+0.5*2)*3";
  double result_num = 4.8;
  double *test_num = mainpn(str, -2, 2);
  ck_assert_double_eq((int)(test_num[0] * 10), (int)(result_num * 10));
}

START_TEST(calculate_22) {
  char *str = "(0.6+0.5*2)*4/2";
  double result_num = 3.2;
  double *test_num = mainpn(str, -2, 2);
  ck_assert_double_eq((int)(test_num[0] * 10), (int)(result_num * 10));
}

START_TEST(calculate_23) {
  char *str = "(((0.6+0.5*2)*4/2)*10)%8";
  double result_num = 0;
  double *test_num = mainpn(str, -2, 2);
  ck_assert_double_eq((int)(test_num[0] * 10), (int)(result_num * 10));
}

START_TEST(calculate_24) {
  char *str = "(2*acos(x)+15)*tan(x)";
  double result_num = 23.3;
  double *test_num = mainpn(str, 1, 2);
  ck_assert_double_eq((int)(test_num[0] * 10), (int)(result_num * 10));
}

START_TEST(calculate_25) {
  char *str = "(2*asin(x)+21)*asin(x)";
  double result_num = 37.9;
  double *test_num = mainpn(str, 1, 2);
  ck_assert_double_eq((int)(test_num[0] * 10), (int)(result_num * 10));
}

START_TEST(calculate_26) {
  char *str = "(atan(x)*2.5-0.5)*asin(x)*26%3";
  double result_num = 4.5;
  double *test_num = mainpn(str, 1, 2);
  ck_assert_double_eq((int)(test_num[0] * 10), (int)(result_num * 10));
}

START_TEST(calculate_27) {
  char *str = "log(cos(log(x)))";
  double result_num = 0;
  double *test_num = mainpn(str, 2, 3);
  ck_assert_double_eq((int)(test_num[0] * 10), (int)(result_num * 10));
}

START_TEST(calculate_28) {
  char *str = "cos(log(cos(x)))";
  double result_num = 1.000000;
  double *test_num = mainpn(str, 0, 10);
  ck_assert_double_eq((int)(test_num[0]), (int)(result_num));
}

START_TEST(calculate_29) {
  char *str = "sin(log(sin(x)))";
  double result_num = -0.074890;
  double *test_num = mainpn(str, 1, 10);
  ck_assert_double_eq((int)(test_num[0] * 1000000),
                      (int)(result_num * 1000000));
}

START_TEST(calculate_30) {
  char *str = "sin(atan(sin(x)))";
  double result_num = 0.643851;
  double *test_num = mainpn(str, 1, 10);
  ck_assert_double_eq((int)(test_num[0] * 1000000),
                      (int)(result_num * 1000000));
}

START_TEST(calculate_31) {
  char *str = "atan(tan(x))";
  double result_num = 0;
  double *test_num = mainpn(str, 0, 10);
  ck_assert_double_eq((int)(test_num[0] * 1000000),
                      (int)(result_num * 1000000));
}

START_TEST(calculate_32) {
  char *str = "asin(sin(x))";
  double result_num = 0;
  double *test_num = mainpn(str, 0, 10);
  ck_assert_double_eq((int)(test_num[0] * 1000000),
                      (int)(result_num * 1000000));
}

START_TEST(calculate_33) {
  char *str = "acos(cos(x))";
  double result_num = 0;
  double *test_num = mainpn(str, 0, 10);
  ck_assert_double_eq((int)(test_num[0] * 1000000),
                      (int)(result_num * 1000000));
}

Suite *count_test(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("count_test");
  tc_core = tcase_create("count_test");

  tcase_add_test(tc_core, calculate_01);
  tcase_add_test(tc_core, calculate_02);
  tcase_add_test(tc_core, calculate_03);
  tcase_add_test(tc_core, calculate_04);
  tcase_add_test(tc_core, calculate_05);
  tcase_add_test(tc_core, calculate_06);
  tcase_add_test(tc_core, calculate_07);
  tcase_add_test(tc_core, calculate_08);
  tcase_add_test(tc_core, calculate_09);
  tcase_add_test(tc_core, calculate_10);
  tcase_add_test(tc_core, calculate_11);
  tcase_add_test(tc_core, calculate_12);
  tcase_add_test(tc_core, calculate_13);
  tcase_add_test(tc_core, calculate_14);
  tcase_add_test(tc_core, calculate_15);
  tcase_add_test(tc_core, calculate_16);
  tcase_add_test(tc_core, calculate_17);
  tcase_add_test(tc_core, calculate_18);
  tcase_add_test(tc_core, calculate_19);
  tcase_add_test(tc_core, calculate_20);
  tcase_add_test(tc_core, calculate_21);
  tcase_add_test(tc_core, calculate_22);
  tcase_add_test(tc_core, calculate_23);
  tcase_add_test(tc_core, calculate_24);
  tcase_add_test(tc_core, calculate_25);
  tcase_add_test(tc_core, calculate_26);
  tcase_add_test(tc_core, calculate_27);
  tcase_add_test(tc_core, calculate_28);
  tcase_add_test(tc_core, calculate_29);
  tcase_add_test(tc_core, calculate_30);
  tcase_add_test(tc_core, calculate_31);
  tcase_add_test(tc_core, calculate_32);
  tcase_add_test(tc_core, calculate_33);

  suite_add_tcase(s, tc_core);

  return s;
}

int main(void) {
  int no_failed = 0;
  Suite *s;
  SRunner *runner;

  s = count_test();
  runner = srunner_create(s);
  srunner_run_all(runner, CK_VERBOSE);
  no_failed += srunner_ntests_failed(runner);
  srunner_free(runner);

  return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}