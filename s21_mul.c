#include "s21_decimal.h"

int s21_mul(s21_decimal dec1, s21_decimal dec2, s21_decimal* result) {
    empty_struct(result);
    s21_mul_simple_new(dec1, dec2, result);
    return 0;
}
