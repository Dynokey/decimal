#include "s21_decimal.h"
/**
 * @brief Делает перевод из децимала в float
 * @return 0 - OK
 *1 - ошибка конвертации
 */
int s21_from_decimal_to_float(s21_decimal src, float* dst) {
    int res = decimal_err(src);
    double temp = 0.0;
    if (res == 0) {
        for (int i = 0; i < 32 * 3; i++) {
            int bit = get_bit(src, i);
            if (bit) temp += pow(2, i);
        }
        int scl = get_scale(&src);
        while (scl != 0) {
            temp /= 10;
            scl -= 1;
        }
        *dst = (float)temp;
        if (get_bit(src, 127)) *dst *= -1;
    }
    return res;
}
