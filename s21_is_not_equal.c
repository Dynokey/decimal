#include "s21_decimal.h"
/**
 * @brief !=
 * @return 0 - FALSE  1 - TRUE
 */
int s21_is_not_equal(s21_decimal dec1, s21_decimal dec2) {
    return (!s21_is_equal(dec1, dec2));
}
