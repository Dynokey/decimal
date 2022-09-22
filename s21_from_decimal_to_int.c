#include "s21_decimal.h"

/**
 * @brief Делает перевод из decimal в int
 * @return 0 - OK
1 - ошибка конвертации
 */
int s21_from_decimal_to_int(s21_decimal src, int* dst) {
    while (get_scale(&src) > 0)
        s21_div10(&src);
    for (int i = 32; i <= 111; i++) {
        if (get_bit(src, i))
            return 1;
    }
    *dst = src.bits[0];
    if (get_sign(&src))
        *dst *= -1;
    return 0;
}
