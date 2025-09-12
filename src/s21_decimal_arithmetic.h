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
// / tiffanet
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);


//dop functions

//умножение на 10 расширенного децимала. В цикле остаток от деления и деление на 4 вычисляет с каким из двух децималов мы сейчас работаем и с каким битом
//возвращает 0 если умножение прошло успешно, 1 если вышли за пределы
int s21_multiply_by_10(s21_decimal_advanced* num);
//умножение на 10 в степени power расширенного децимала. Возвращает 0 если умножение прошло успешно, 1 если вышли за пределы или power некорректен
int s21_multiply_by_pow10(s21_decimal_advanced* num, int power);
//выравнивание степеней двух расширенных децималов(долженв уровнять значения знаков после запятой). Возвращает 0 если выравнивание прошло успешно, 1 если вышли за пределы
int s21_correct_pow(s21_decimal_advanced* a, s21_decimal_advanced* b);
//сравнение мантисс двух расширенных децималов(начинаем сравнение со старших битов, выбираем какое из двух децималов мы проверяем). Возвращает 1 если a > b, -1 если a < b, 0 если равны
int s21_compare_mantissa(s21_decimal_advanced a, s21_decimal_advanced b);