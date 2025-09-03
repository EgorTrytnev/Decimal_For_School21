#include "s21_decimal.h"

/*
Возвращаемое значение:

0 — FALSE;
1 — TRUE.
*/

// <
int s21_is_less(s21_decimal, s21_decimal);
// <=
int s21_is_less_or_equal(s21_decimal, s21_decimal);
// >
int s21_is_greater(s21_decimal, s21_decimal);
// >= 
int s21_is_greater_or_equal(s21_decimal, s21_decimal);
// ==
int s21_is_equal(s21_decimal, s21_decimal);
// != 
int s21_is_not_equal(s21_decimal, s21_decimal);