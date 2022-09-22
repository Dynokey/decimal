#include "s21_decimal.h"

/**
 * @brief <
 * @return 0 - FALSE  1 - TRUE
 */
int s21_is_less(s21_decimal dec1, s21_decimal dec2) {
    int res = !s21_is_greater(dec1, dec2);
    if (s21_is_equal(dec1, dec2)) res = 0;
    return res;
}
