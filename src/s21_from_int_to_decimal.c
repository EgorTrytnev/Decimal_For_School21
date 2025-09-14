#include "s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
    int result = S21_OK;
    
    if (dst == NULL) {
        result = S21_ERROR;
    } else {
        // Initialize decimal to zero
        dst->bits[0] = 0;
        dst->bits[1] = 0;
        dst->bits[2] = 0;
        dst->bits[3] = 0;
        
        if (src != 0) {
            // Handle negative numbers
            if (src < 0) {
                dst->bits[3] |= 0x80000000;  // Set sign bit
                src = -src;  // Make positive for processing
            }
            
            // Store the absolute value in the first 32 bits
            dst->bits[0] = src;
        }
    }
    
    return result;
}
