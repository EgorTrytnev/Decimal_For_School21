#include "s21_decimal_arithmetic.h"
#include "math.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result)
{
    return 0;
}

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result)
{
    return 0;
}

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result)
{
    return 0;
}

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result)
{
    return 0;
}

//dop functions


int s21_multiply_by_10(s21_decimal_advanced* num) {
  unsigned carry = 0;
  for (int i = 0; i < 8; i++) {
    int part = i / 4, idx = i % 4;

    unsigned val = (unsigned)num->decimal[part].bits[idx];
    unsigned long long temp =
        (unsigned long long)val * 10 + (unsigned long long)carry;
    num->decimal[part].bits[idx] = (int)(temp & 0xFFFFFFFF);
    carry = (unsigned)(temp >> 32);
  }
  return carry ? 1 : 0;
}

int s21_multiply_by_pow10(s21_decimal_advanced* num, int power) {
  int code_func = 0;
  if (power < 0 || power > 28) {
    code_func = 1;
  }
  for (int i = 0; i < power && code_func == 0; i++)
    if (s21_multiply_by_10(num)) {
      code_func = 1;
    }

  return code_func;
}

int s21_correct_pow(s21_decimal_advanced* a, s21_decimal_advanced* b) {
  int diff = a->dop_data - b->dop_data;
  int code_func = 0;
  if (diff != 0) {
    s21_decimal_advanced* target = diff > 0 ? b : a;
    int power = abs(diff);

    if (target->dop_data + power > 28) {
      code_func = 1;
    }

    s21_multiply_by_pow10(target, power);

    if (code_func != 1) {
      target->dop_data += power;
    }
  }
  return code_func;
}

int s21_compare_mantissa(s21_decimal_advanced a, s21_decimal_advanced b) {
  int res = 0;
  for (int i = 7; i >= 0; i--) {
    int part = i / 4, idx = i % 4;
    unsigned va = (unsigned)a.decimal[part].bits[idx];
    unsigned vb = (unsigned)b.decimal[part].bits[idx];
    if (va != vb) {
      res = va > vb ? 1 : -1;
      i = -1;
    }
  }
  return res;
}