#include "s21_decimal.h"

// Get bit at specific position
int s21_get_bit(s21_decimal decimal, int bit_position) {
    int bit_index = bit_position / 32;
    int bit_offset = bit_position % 32;
    
    if (bit_index >= 0 && bit_index < 4) {
        return (decimal.bits[bit_index] >> bit_offset) & 1;
    }
    return 0;
}

// Set bit at specific position
void s21_set_bit(s21_decimal *decimal, int bit_position, int bit_value) {
    if (decimal != NULL) {
        int bit_index = bit_position / 32;
        int bit_offset = bit_position % 32;
        
        if (bit_index >= 0 && bit_index < 4) {
            if (bit_value) {
                decimal->bits[bit_index] |= (1 << bit_offset);
            } else {
                decimal->bits[bit_index] &= ~(1 << bit_offset);
            }
        }
    }
}

// Get scale (exponent) from decimal
int s21_get_scale(s21_decimal decimal) {
    return S21_GET_EXPONENT(decimal);
}

// Set scale (exponent) for decimal
void s21_set_scale(s21_decimal *decimal, int scale) {
    if (decimal != NULL && scale >= 0 && scale <= 28) {
        S21_SET_EXPONENT(*decimal, scale);
    }
}

// Check if decimal is zero
int s21_is_zero(s21_decimal decimal) {
    return (decimal.bits[0] == 0 && decimal.bits[1] == 0 && decimal.bits[2] == 0);
}

// Compare magnitudes of two decimals (ignoring signs)
int s21_compare_magnitude(s21_decimal value_1, s21_decimal value_2) {
    // Compare from most significant to least significant
    for (int i = 2; i >= 0; i--) {
        if (value_1.bits[i] > value_2.bits[i]) {
            return 1;  // value_1 magnitude is greater
        } else if (value_1.bits[i] < value_2.bits[i]) {
            return -1; // value_2 magnitude is greater
        }
    }
    return 0;  // magnitudes are equal
}
