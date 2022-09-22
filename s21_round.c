#include "s21_decimal.h"

/**
 * @brief Округляет Decimal до ближайшего целого числа.
 * @return 0 - OK
1 - ошибка вычисления
 */
int s21_round(s21_decimal a, s21_decimal* res) {
    empty_struct(res);
    int result = decimal_err(a) + p_decimal_err(res);
    // s21_decimal one = {{1, 0, 0, 0}};
    int scl = scale(a);
    *res = a;
    if (result == 0 && scl > 0) {
        set_scale(res, 0);
        set_plus(res);
        for (int i = 1; i < scl; i++) {
            s21_div10(res);
        }
        s21_bank_round_new(res, 1);
        // if (res->bits[0] % 10 > 5) {
        //     s21_div10(res);
        //     s21_decimal_add_simple(one, *res, res);
        //
        // } else if (res->bits[0] % 10 == 5) {
        //     s21_div10(res);
        //     if (res->bits[0] % 2 != 0)
        //         s21_decimal_add_simple(one, *res, res);
        // } else
        //     s21_div10(res);
        if (get_sign(&a) == 1) set_minus(res);
    }
    return result;
}
