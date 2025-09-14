#include "s21_decimal.h"

int s21_is_greater(s21_decimal value_1, s21_decimal value_2) {
    int result = 0;
    
    // Handle special cases with zeros
    if (s21_is_zero(value_1) && s21_is_zero(value_2)) {
        return 0;  // 0 is not greater than 0
    }
    
    // Get signs
    int sign1 = S21_GET_SIGN(value_1);
    int sign2 = S21_GET_SIGN(value_2);
    
    // If signs are different
    if (sign1 != sign2) {
        // Positive number is greater than negative
        result = sign1 ? 0 : 1;
    } else {
        // Same signs - compare magnitudes
        int magnitude_compare = s21_compare_magnitude(value_1, value_2);
        
        if (sign1) {
            // Both negative: smaller magnitude is greater
            result = (magnitude_compare < 0) ? 1 : 0;
        } else {
            // Both positive: larger magnitude is greater
            result = (magnitude_compare > 0) ? 1 : 0;
        }
    }
    
    return result;
}
