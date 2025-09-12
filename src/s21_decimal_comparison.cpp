#include "s21_decimal_comparison.h"
#include "s21_decimal_arithmetic.h"



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
    int res = 1;
    int sign1 = s21_get_sign(value1);
    int sign2 = s21_get_sign(value2);
    if(sign1 != sign2) res = 0;
    else{
        s21_decimal_advanced val1 = s21_convert_to_advanced(value1);
        s21_decimal_advanced val2 = s21_convert_to_advanced(value2);
        s21_correct_pow(&val1, &val2);

        res = s21_compare_mantissa(val1, val2);
        
    }
    return res;
}


int s21_is_not_equal(s21_decimal, s21_decimal)
{
    return 0;
}