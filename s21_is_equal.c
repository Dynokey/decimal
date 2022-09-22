#include "s21_decimal.h"

/**
 * @brief Равно ==
 * @return 0 - FALSE
1 - TRUE
 */

int s21_is_equal(s21_decimal a, s21_decimal b) {
    s21_decimal tmp_a = a;
    s21_decimal tmp_b = b;

    if (scale(tmp_a) != scale(tmp_b)) {
        s21_decimal* p_tmp_a = &tmp_a;
        s21_decimal* p_tmp_b = &tmp_b;
        scale_eq(p_tmp_a, p_tmp_b);
    }

    int res = S21_TRUE;

    int sing_a = get_bit(tmp_a, SIZE * 4 - 1);
    int sing_b = get_bit(tmp_b, SIZE * 4 - 1);

    if (sing_a == sing_b) {
        for (int i = 0; i < 3; i++) {
            if ((tmp_a.bits[i] ^ tmp_b.bits[i]) != 0) {
                res = S21_FALSE;
                break;
            }
        }
    }

    if (sing_a != sing_b) {
        for (int i = 0; i < 3; i++) {
            if (a.bits[i] != 0 || b.bits[i] != 0) {
                res = S21_FALSE;
                break;
            }
        }
    }
    return res;
}
