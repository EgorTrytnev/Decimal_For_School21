#include "s21_decimal_comparison.h"



int s21_is_less(s21_decimal, s21_decimal)
{
    return 0;
}
int s21_is_less_or_equal(s21_decimal, s21_decimal)
{
    return 0;
}
int s21_is_greater(s21_decimal, s21_decimal)
{
    return 0;
}
int s21_is_greater_or_equal(s21_decimal, s21_decimal)
{
    return 0;
}
int s21_is_equal(s21_decimal value1, s21_decimal value2)
{
    int flag = 1;
    for(int i = 0; i < 4; i++) {
        if (value1.bits[i] != value2.bits[i]) {
            flag = 0;
        }
    }
    return flag;
}


int s21_is_not_equal(s21_decimal, s21_decimal)
{
    return 0;
}