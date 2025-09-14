#include <check.h>
#include "../s21_decimal.h"

// Test s21_from_int_to_decimal
START_TEST(test_from_int_to_decimal_positive) {
    s21_decimal result;
    int status = s21_from_int_to_decimal(123, &result);
    
    ck_assert_int_eq(status, S21_OK);
    ck_assert_int_eq(result.bits[0], 123);
    ck_assert_int_eq(result.bits[1], 0);
    ck_assert_int_eq(result.bits[2], 0);
    ck_assert_int_eq(S21_GET_SIGN(result), 0);
}
END_TEST

START_TEST(test_from_int_to_decimal_negative) {
    s21_decimal result;
    int status = s21_from_int_to_decimal(-456, &result);
    
    ck_assert_int_eq(status, S21_OK);
    ck_assert_int_eq(result.bits[0], 456);
    ck_assert_int_eq(result.bits[1], 0);
    ck_assert_int_eq(result.bits[2], 0);
    ck_assert_int_eq(S21_GET_SIGN(result), 1);
}
END_TEST

START_TEST(test_from_int_to_decimal_zero) {
    s21_decimal result;
    int status = s21_from_int_to_decimal(0, &result);
    
    ck_assert_int_eq(status, S21_OK);
    ck_assert_int_eq(result.bits[0], 0);
    ck_assert_int_eq(result.bits[1], 0);
    ck_assert_int_eq(result.bits[2], 0);
    ck_assert_int_eq(S21_GET_SIGN(result), 0);
}
END_TEST

START_TEST(test_from_int_to_decimal_null) {
    int status = s21_from_int_to_decimal(123, NULL);
    ck_assert_int_eq(status, S21_ERROR);
}
END_TEST

// Test s21_from_decimal_to_int
START_TEST(test_from_decimal_to_int_positive) {
    s21_decimal decimal;
    s21_from_int_to_decimal(789, &decimal);
    
    int result;
    int status = s21_from_decimal_to_int(decimal, &result);
    
    ck_assert_int_eq(status, S21_OK);
    ck_assert_int_eq(result, 789);
}
END_TEST

START_TEST(test_from_decimal_to_int_negative) {
    s21_decimal decimal;
    s21_from_int_to_decimal(-321, &decimal);
    
    int result;
    int status = s21_from_decimal_to_int(decimal, &result);
    
    ck_assert_int_eq(status, S21_OK);
    ck_assert_int_eq(result, -321);
}
END_TEST

START_TEST(test_from_decimal_to_int_zero) {
    s21_decimal decimal;
    s21_from_int_to_decimal(0, &decimal);
    
    int result;
    int status = s21_from_decimal_to_int(decimal, &result);
    
    ck_assert_int_eq(status, S21_OK);
    ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_from_decimal_to_int_null) {
    s21_decimal decimal;
    s21_from_int_to_decimal(123, &decimal);
    
    int status = s21_from_decimal_to_int(decimal, NULL);
    ck_assert_int_eq(status, S21_ERROR);
}
END_TEST

// Test s21_is_less
START_TEST(test_is_less_positive) {
    s21_decimal a, b;
    s21_from_int_to_decimal(5, &a);
    s21_from_int_to_decimal(10, &b);
    
    ck_assert_int_eq(s21_is_less(a, b), 1);
    ck_assert_int_eq(s21_is_less(b, a), 0);
}
END_TEST

START_TEST(test_is_less_negative) {
    s21_decimal a, b;
    s21_from_int_to_decimal(-10, &a);
    s21_from_int_to_decimal(-5, &b);
    
    ck_assert_int_eq(s21_is_less(a, b), 1);
    ck_assert_int_eq(s21_is_less(b, a), 0);
}
END_TEST

START_TEST(test_is_less_mixed_signs) {
    s21_decimal a, b;
    s21_from_int_to_decimal(-5, &a);
    s21_from_int_to_decimal(5, &b);
    
    ck_assert_int_eq(s21_is_less(a, b), 1);
    ck_assert_int_eq(s21_is_less(b, a), 0);
}
END_TEST

START_TEST(test_is_less_equal) {
    s21_decimal a, b;
    s21_from_int_to_decimal(7, &a);
    s21_from_int_to_decimal(7, &b);
    
    ck_assert_int_eq(s21_is_less(a, b), 0);
}
END_TEST

// Test s21_is_greater
START_TEST(test_is_greater_positive) {
    s21_decimal a, b;
    s21_from_int_to_decimal(10, &a);
    s21_from_int_to_decimal(5, &b);
    
    ck_assert_int_eq(s21_is_greater(a, b), 1);
    ck_assert_int_eq(s21_is_greater(b, a), 0);
}
END_TEST

START_TEST(test_is_greater_negative) {
    s21_decimal a, b;
    s21_from_int_to_decimal(-5, &a);
    s21_from_int_to_decimal(-10, &b);
    
    ck_assert_int_eq(s21_is_greater(a, b), 1);
    ck_assert_int_eq(s21_is_greater(b, a), 0);
}
END_TEST

START_TEST(test_is_greater_mixed_signs) {
    s21_decimal a, b;
    s21_from_int_to_decimal(5, &a);
    s21_from_int_to_decimal(-5, &b);
    
    ck_assert_int_eq(s21_is_greater(a, b), 1);
    ck_assert_int_eq(s21_is_greater(b, a), 0);
}
END_TEST

START_TEST(test_is_greater_equal) {
    s21_decimal a, b;
    s21_from_int_to_decimal(7, &a);
    s21_from_int_to_decimal(7, &b);
    
    ck_assert_int_eq(s21_is_greater(a, b), 0);
}
END_TEST

// Test s21_is_less_or_equal
START_TEST(test_is_less_or_equal) {
    s21_decimal a, b, c;
    s21_from_int_to_decimal(5, &a);
    s21_from_int_to_decimal(10, &b);
    s21_from_int_to_decimal(5, &c);
    
    ck_assert_int_eq(s21_is_less_or_equal(a, b), 1);  // 5 <= 10
    ck_assert_int_eq(s21_is_less_or_equal(b, a), 0);  // 10 <= 5
    ck_assert_int_eq(s21_is_less_or_equal(a, c), 1);  // 5 <= 5
}
END_TEST

// Test s21_is_greater_or_equal
START_TEST(test_is_greater_or_equal) {
    s21_decimal a, b, c;
    s21_from_int_to_decimal(10, &a);
    s21_from_int_to_decimal(5, &b);
    s21_from_int_to_decimal(10, &c);
    
    ck_assert_int_eq(s21_is_greater_or_equal(a, b), 1);  // 10 >= 5
    ck_assert_int_eq(s21_is_greater_or_equal(b, a), 0);  // 5 >= 10
    ck_assert_int_eq(s21_is_greater_or_equal(a, c), 1);  // 10 >= 10
}
END_TEST

Suite *comparison_suite(void) {
    Suite *s;
    TCase *tc;

    s = suite_create("Comparison Functions");

    tc = tcase_create("from_int_to_decimal");
    tcase_add_test(tc, test_from_int_to_decimal_positive);
    tcase_add_test(tc, test_from_int_to_decimal_negative);
    tcase_add_test(tc, test_from_int_to_decimal_zero);
    tcase_add_test(tc, test_from_int_to_decimal_null);
    suite_add_tcase(s, tc);

    tc = tcase_create("from_decimal_to_int");
    tcase_add_test(tc, test_from_decimal_to_int_positive);
    tcase_add_test(tc, test_from_decimal_to_int_negative);
    tcase_add_test(tc, test_from_decimal_to_int_zero);
    tcase_add_test(tc, test_from_decimal_to_int_null);
    suite_add_tcase(s, tc);

    tc = tcase_create("is_less");
    tcase_add_test(tc, test_is_less_positive);
    tcase_add_test(tc, test_is_less_negative);
    tcase_add_test(tc, test_is_less_mixed_signs);
    tcase_add_test(tc, test_is_less_equal);
    suite_add_tcase(s, tc);

    tc = tcase_create("is_greater");
    tcase_add_test(tc, test_is_greater_positive);
    tcase_add_test(tc, test_is_greater_negative);
    tcase_add_test(tc, test_is_greater_mixed_signs);
    tcase_add_test(tc, test_is_greater_equal);
    suite_add_tcase(s, tc);

    tc = tcase_create("is_less_or_equal");
    tcase_add_test(tc, test_is_less_or_equal);
    suite_add_tcase(s, tc);

    tc = tcase_create("is_greater_or_equal");
    tcase_add_test(tc, test_is_greater_or_equal);
    suite_add_tcase(s, tc);

    return s;
}

int main(void) {
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = comparison_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? 0 : 1;
}
