#include "../s21_decimal.h"
#include <stdio.h>
#include <assert.h>

void test_from_int_to_decimal() {
    printf("Testing s21_from_int_to_decimal...\n");
    
    s21_decimal result;
    int status;
    
    // Test positive number
    status = s21_from_int_to_decimal(123, &result);
    assert(status == S21_OK);
    assert(result.bits[0] == 123);
    assert(result.bits[1] == 0);
    assert(result.bits[2] == 0);
    assert(S21_GET_SIGN(result) == 0);
    printf("✓ Positive number conversion: OK\n");
    
    // Test negative number
    status = s21_from_int_to_decimal(-456, &result);
    assert(status == S21_OK);
    assert(result.bits[0] == 456);
    assert(S21_GET_SIGN(result) == 1);
    printf("✓ Negative number conversion: OK\n");
    
    // Test zero
    status = s21_from_int_to_decimal(0, &result);
    assert(status == S21_OK);
    assert(result.bits[0] == 0);
    assert(result.bits[1] == 0);
    assert(result.bits[2] == 0);
    assert(S21_GET_SIGN(result) == 0);
    printf("✓ Zero conversion: OK\n");
    
    // Test NULL pointer
    status = s21_from_int_to_decimal(123, NULL);
    assert(status == S21_ERROR);
    printf("✓ NULL pointer handling: OK\n");
}

void test_from_decimal_to_int() {
    printf("\nTesting s21_from_decimal_to_int...\n");
    
    s21_decimal decimal;
    int result;
    int status;
    
    // Test positive number
    s21_from_int_to_decimal(789, &decimal);
    status = s21_from_decimal_to_int(decimal, &result);
    assert(status == S21_OK);
    assert(result == 789);
    printf("✓ Positive number conversion: OK\n");
    
    // Test negative number
    s21_from_int_to_decimal(-321, &decimal);
    status = s21_from_decimal_to_int(decimal, &result);
    assert(status == S21_OK);
    assert(result == -321);
    printf("✓ Negative number conversion: OK\n");
    
    // Test zero
    s21_from_int_to_decimal(0, &decimal);
    status = s21_from_decimal_to_int(decimal, &result);
    assert(status == S21_OK);
    assert(result == 0);
    printf("✓ Zero conversion: OK\n");
    
    // Test NULL pointer
    s21_from_int_to_decimal(123, &decimal);
    status = s21_from_decimal_to_int(decimal, NULL);
    assert(status == S21_ERROR);
    printf("✓ NULL pointer handling: OK\n");
}

void test_comparison_functions() {
    printf("\nTesting comparison functions...\n");
    
    s21_decimal a, b;
    
    // Test 5 < 10
    s21_from_int_to_decimal(5, &a);
    s21_from_int_to_decimal(10, &b);
    assert(s21_is_less(a, b) == 1);
    assert(s21_is_greater(a, b) == 0);
    assert(s21_is_less_or_equal(a, b) == 1);
    assert(s21_is_greater_or_equal(a, b) == 0);
    printf("✓ 5 < 10: OK\n");
    
    // Test 10 > 5
    assert(s21_is_less(b, a) == 0);
    assert(s21_is_greater(b, a) == 1);
    assert(s21_is_less_or_equal(b, a) == 0);
    assert(s21_is_greater_or_equal(b, a) == 1);
    printf("✓ 10 > 5: OK\n");
    
    // Test -5 < 5
    s21_from_int_to_decimal(-5, &a);
    s21_from_int_to_decimal(5, &b);
    assert(s21_is_less(a, b) == 1);
    assert(s21_is_greater(a, b) == 0);
    printf("✓ -5 < 5: OK\n");
    
    // Test 5 > -5
    s21_from_int_to_decimal(5, &a);
    s21_from_int_to_decimal(-5, &b);
    assert(s21_is_less(a, b) == 0);
    assert(s21_is_greater(a, b) == 1);
    printf("✓ 5 > -5: OK\n");
    
    // Test equal numbers
    s21_from_int_to_decimal(7, &a);
    s21_from_int_to_decimal(7, &b);
    assert(s21_is_less(a, b) == 0);
    assert(s21_is_greater(a, b) == 0);
    assert(s21_is_less_or_equal(a, b) == 1);
    assert(s21_is_greater_or_equal(a, b) == 1);
    printf("✓ 7 == 7: OK\n");
}

int main() {
    printf("=== Testing Level 4 Functions ===\n\n");
    
    test_from_int_to_decimal();
    test_from_decimal_to_int();
    test_comparison_functions();
    
    printf("\n=== All tests passed! ===\n");
    return 0;
}
