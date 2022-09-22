#include "s21_decimal.h"
/**
 * @brief >
 * @return 0 - FALSE  1 - TRUE
 */
int s21_is_greater(s21_decimal value1, s21_decimal value2) {
    int res = 0;
    if (get_scale(&value1) != get_scale(&value2)) {
        scale_eq(&value1, &value2);
    }
    if (get_sign(&value1) < get_sign(&value2))
        res = 1;
    else if (get_sign(&value1) > get_sign(&value2))
        res = 0;
    else if (value1.bits[2] > value2.bits[2])
        res = 1;
    else if (value1.bits[2] < value2.bits[2])
        res = 0;
    else if (value1.bits[1] > value2.bits[1])
        res = 1;
    else if (value1.bits[1] < value2.bits[1])
        res = 0;
    else if (value1.bits[0] > value2.bits[0])
        res = 1;
    else if (value1.bits[0] < value2.bits[0])
        res = 0;
    if (get_sign(&value1) && get_sign(&value2)) res = !res;
    if (s21_is_equal(value1, value2)) res = 0;
    return res;
}
