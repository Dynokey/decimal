#include "s21_decimal.h"

// Вычитает большй децимал из меньшего
int s21_decimal_sub_simple(s21_decimal var1, s21_decimal var2, s21_decimal *result) {
    s21_decimal res = {0};
    // s21_decimal tmp = {0};
    int per = 0;
    int c = 0;
    for (c = 0; c < 96; c++) {
        if (per == 0) {
            if (get_bit(var1, c) == get_bit(var2, c)) {
                res = clean_bit(res, c);  // Cбрасываем бит №а в 0
            } else {
                res = set_bit(res, c);  // Устанавливаем в бит №c 1

                if (get_bit(var2, c) == 1) {
                    per = 1;
                } else {
                    per = 0;
                }
            }
        } else {  // per = 1
            if (get_bit(var1, c) == get_bit(var2, c)) {
                res = set_bit(res, c);  // Устанавливаем бит №а в 1
                // if (get_bit(var1, c) == 1) per = 1;
                per = 1;
            } else {
                res = clean_bit(res, c);  // Сбрасываем бит №а в 0
                if (get_bit(var2, c) == 1) {
                    per = 1;
                } else {
                    per = 0;
                }
            }
        }
    }
    *result = res;
    return 0;
}
