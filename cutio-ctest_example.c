// Copyright (c) 2022 furzoom.com, All rights reserved.
// Author: Furzoom, mn@furzoom.com

#include "cutio-ctest.h"

static int foo;
static int bar;
static double baz;
static const char *s_foo;
static const char *s_bar;

void test_setup() {
  foo = 1;
  bar = 2;
  baz = 0.1;
  s_foo = "foo";
  s_bar = "bar";
}

void test_teardown() {
  // Nothing
}

CU_TEST(test_check) {
  CU_CHECK(foo == 1);
}

CU_TEST(test_check_fail) {
  CU_CHECK(foo != 1);
}

CU_TEST(test_assert) {
  CU_ASSERT(foo == 1, "foo should be 1");
}

CU_TEST(test_assert_fail) {
  CU_ASSERT(foo != 1, "foo should not be 1");
}

CU_TEST(test_assert_int_eq) {
  CU_ASSERT_EQ(2, bar);
}

CU_TEST(test_assert_int_eq_fail) {
  CU_ASSERT_EQ(1, bar);
}

CU_TEST(test_assert_double_eq) {
  CU_ASSERT_DOUBLE_EQ(0.1, baz);
}

CU_TEST(test_assert_double_eq_fail) {
  CU_ASSERT_DOUBLE_EQ(0.2, baz);
}

CU_TEST(test_assert_string_eq) {
  CU_ASSERT_STRING_EQ("foo", s_foo);
  s_foo = NULL;
  CU_ASSERT_STRING_EQ(NULL, NULL);
  CU_ASSERT_STRING_EQ("", "");
}

CU_TEST(test_assert_string_eq_fail) {
  CU_ASSERT_STRING_EQ(s_bar, s_foo);
  CU_ASSERT_STRING_EQ(NULL, s_foo);
}

CU_TEST(test_fail) {
  CU_FAIL("Fail test!");
}

CU_TEST_SUITE(test_suite) {
  CU_SUITE_CONFIGURE(&test_setup, &test_teardown);

  CU_RUN_TEST(test_check);
  CU_RUN_TEST(test_check_fail);
  CU_RUN_TEST(test_assert);
  CU_RUN_TEST(test_assert_fail);
  CU_RUN_TEST(test_assert_int_eq);
  CU_RUN_TEST(test_assert_int_eq_fail);
  CU_RUN_TEST(test_assert_double_eq);
  CU_RUN_TEST(test_assert_double_eq_fail);
  CU_RUN_TEST(test_assert_string_eq);
  CU_RUN_TEST(test_assert_string_eq_fail);

  CU_RUN_TEST(test_fail);
}

int main(int argc, char *argv[]) {
  CU_RUN_SUIT(test_suite);
  CU_REPORT();
  return CU_EXIT_CODE;
}

