#include "s21_decimal.h"
/**
 * @brief Делает перевод из int в децимала
 * @return 0 - OK
1 - ошибка конвертации
 */
int s21_from_int_to_decimal(int src, s21_decimal *dst) {
    empty_struct(dst);
    int res = 0;
    if (!dst) {
        res = 1;
    } else {
        empty_struct(dst);
        if (src < 0) {
            set_minus(dst);
            src *= -1;
        }
        dst->bits[0] = src;
    }
    return res;
}
