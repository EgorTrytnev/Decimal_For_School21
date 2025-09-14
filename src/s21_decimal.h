#ifndef S21_DECIMAL_H
#define S21_DECIMAL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Decimal structure definition
typedef struct {
    int bits[4];
} s21_decimal;

// Error codes
#define S21_OK 0
#define S21_ERROR 1
#define S21_ERROR_BIG 1
#define S21_ERROR_SMALL 2
#define S21_ERROR_DIV_BY_ZERO 3

// Bit manipulation macros
#define S21_GET_SIGN(decimal) (((decimal).bits[3] & 0x80000000) != 0)
#define S21_GET_EXPONENT(decimal) (((decimal).bits[3] & 0x7F800000) >> 16)
#define S21_SET_SIGN(decimal, sign) ((decimal).bits[3] |= ((sign) ? 0x80000000 : 0))
#define S21_SET_EXPONENT(decimal, exp) ((decimal).bits[3] |= ((exp) << 16))

// Comparison functions
int s21_is_less(s21_decimal, s21_decimal);
int s21_is_greater(s21_decimal, s21_decimal);
int s21_is_less_or_equal(s21_decimal, s21_decimal);
int s21_is_greater_or_equal(s21_decimal, s21_decimal);
int s21_is_equal(s21_decimal, s21_decimal);
int s21_is_not_equal(s21_decimal, s21_decimal);

// Conversion functions
int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);

// Arithmetic functions
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

// Other functions
int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);

// Helper functions
int s21_get_bit(s21_decimal decimal, int bit_position);
void s21_set_bit(s21_decimal *decimal, int bit_position, int bit_value);
int s21_get_scale(s21_decimal decimal);
void s21_set_scale(s21_decimal *decimal, int scale);
int s21_is_zero(s21_decimal decimal);
int s21_compare_magnitude(s21_decimal value_1, s21_decimal value_2);

// Additional helper functions for comparison
int s21_abs_compare(s21_decimal value_1, s21_decimal value_2);

#endif  // S21_DECIMAL_H
