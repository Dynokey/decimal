#include "s21_decimal.h"

/**
 * @brief Простое сложение двух чисел децимал
 * @param var1 число децимал
 * @param var2 число децимал
 * @param result число децимал
 * @return число цимал
 */
int s21_decimal_add_simple(s21_decimal var1, s21_decimal var2, s21_decimal *result) {
    s21_decimal res = {0};

    int c = 0;
    int per = 0;
    int flag = 2222;
    int tb = 0;
    int scaled = scale(var1);

    if (decimal_err(var2) == 0 && decimal_err(var1) == 0) {
        while ((flag == 2222 && scaled >= 0) || tb == 3) {
            tb = 2;
            for (c = 0; c < 96; c++) {
                if (per == get_bit(var1, c)) {
                    if (per == 1) {
                        res = clean_bit(res, c);
                        if (get_bit(var2, c))
                            res = set_bit(res, c);
                    } else {
                        res = clean_bit(res, c);
                        if (get_bit(var2, c))
                            res = set_bit(res, c);
                    }
                } else {
                    per = 1;
                    if (per != get_bit(var2, c)) {
                        res = set_bit(res, c);
                        per = 0;
                    } else {
                        per = 1;
                        res = clean_bit(res, c);
                    }
                }
            }

            set_scale(&res, scale(var1));

            while (c == 96) {
                if (per || get_bit(var1, c) || get_bit(var2, c)) {
                    tb = 0;
                }
                c++;
            }

            if (tb == 0 && scaled > 0) {
                overflow(&var1);
                overflow(&var2);

                tb = 3;
            } else if (tb == 1) {
                flag = 0;

            } else if (tb == 0 && scaled == 0) {
                flag = 1;

            } else {
                flag = 0;
            }
        }

        *result = res;

    } else {
        flag = 1;
    }

    return flag;
}
