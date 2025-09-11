#include "s21_decimal_other_func.h"

int s21_floor(s21_decimal value, s21_decimal *result)
{
    return 0;
}

int s21_round(s21_decimal value, s21_decimal *result)
{
    return 0;
}

int s21_truncate(s21_decimal value, s21_decimal *result)
{
    return 0;
}

int s21_negate(s21_decimal value, s21_decimal *result)
{
    return 0;
}

int s21_get_sign(s21_decimal value)
{
    return (value.bits[3] >> 31);
}
