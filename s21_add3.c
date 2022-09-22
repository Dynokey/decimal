#include "s21_decimal.h"

/**
 * @brief Сложение
 * @param var1 число децимал
 * @param var2 число децимал
 * @param result число децимал
 * @return
 * 0 - OK.
 * 1 - число слишком велико или равно бесконечности.
 * 2 - число слишком мало или равно отрицательной бесконечности.
 * 3 - деление на 0.
 */
int s21_add(s21_decimal dec1, s21_decimal dec2, s21_decimal* result) {
    empty_struct(result);
    int is_overfull = 0;
    scale_eq(&dec1, &dec2);
    int exp = scale(dec1);
    int sign_1 = get_sign_new(dec1);
    int sign_2 = get_sign_new(dec2);

    if (!(sign_1 ^ sign_2)) {
        is_overfull = s21_add_simple_new(dec1, dec2, result);
        set_sign_new(result, sign_1);
        if (is_overfull && sign_1 && sign_2) {
            is_overfull = 2;
        }
    } else if (s21_is_less_or_equal_simple_new(dec1, dec2)) {
        s21_sub_simple_new(dec2, dec1, result);
        set_sign_new(result, sign_2);
    } else {
        s21_sub_simple_new(dec1, dec2, result);
        set_sign_new(result, sign_1);
    }
    if (is_overfull && scale(dec1)) {
        s21_bank_round_new(&dec1, 1);
        s21_bank_round_new(&dec2, 1);
        is_overfull = s21_add(dec1, dec2, result);
    } else {
        set_scale(result, exp);
    }
    return is_overfull;
}
