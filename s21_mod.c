#include "s21_decimal.h"

int s21_mod(s21_decimal dec1, s21_decimal dec2, s21_decimal* result) {
    empty_struct(result);
    s21_decimal nul = {0};
    if (s21_is_equal(dec2, nul)) {
        return 3;
    }
    *result = s21_div_simple_new(dec1, dec2, NULL);
    return 0;
}
