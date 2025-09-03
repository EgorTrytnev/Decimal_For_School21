#include "s21_decimal.h"

/*
Функции возвращают код ошибки:

0 — OK;
1 — число слишком велико или равно бесконечности;
2 — число слишком мало или равно отрицательной бесконечности;
3 — деление на 0.
*/

// +
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
// -
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
// *
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
// /
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
