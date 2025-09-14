#include "s21_decimal.h"

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
    int result = S21_OK;
    
    if (dst == NULL) {
        result = S21_ERROR;
    } else {
        // Check if the number fits in int range
        // For now, just check if the value is in the first 32 bits and no higher bits are set
        if (src.bits[1] != 0 || src.bits[2] != 0) {
            result = S21_ERROR;
        } else {
            // Get the value from the first 32 bits
            *dst = src.bits[0];
            
            // Apply sign if negative
            if (S21_GET_SIGN(src)) {
                *dst = -(*dst);
            }
        }
    }
    
    return result;
}
