#include "s21_decimal.h"

s21_decimal decimal_init()
{
    return s21_decimal();
}

int s21_get_sign(s21_decimal value)
{
    return (value.bits[3] >> 31);
}
int s21_get_scale(s21_decimal value)
{
    return (value.bits[3] >> 16) & 0x7F;
}
s21_decimal_advanced s21_convert_to_advanced(s21_decimal value){
    s21_decimal_advanced res;
    res.decimal[0] = value;
    res.decimal[1] = decimal_init();
    res.dop_data = s21_get_scale(value);
    res.sign = s21_get_sign(value);
    res.decimal[0].bits[3] = 0;
    return res;
}