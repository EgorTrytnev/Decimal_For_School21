#include "s21_decimal.h"

/*
Возвращаемое значение — код ошибки:

0 — OK;
1 — ошибка конвертации.
*/

// from int
int s21_from_int_to_decimal(int src, s21_decimal *dst);
// from float
int s21_from_float_to_decimal(float src, s21_decimal *dst);
// into int
int s21_from_decimal_to_int(s21_decimal src, int *dst);
// into float 
int s21_from_decimal_to_float(s21_decimal src, float *dst);