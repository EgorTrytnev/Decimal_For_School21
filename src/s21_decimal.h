#pragma once

typedef struct
{
    int bits[4];
}s21_decimal;

typedef struct
{
    s21_decimal decimal[2];
    int dop_data;
    int sign;
} s21_decimal_advanced;

//инициализация
s21_decimal decimal_init();

int s21_get_sign(s21_decimal value);
int s21_get_scale(s21_decimal value);
s21_decimal_advanced s21_convert_to_advanced(s21_decimal value);