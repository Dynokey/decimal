#include "s21_decimal.h"

/**
 * @brief Возвращает результат умножения указанного Decimal на -1.
 * @return 0 - OK
1 - ошибка вычисления
 */
int s21_negate(s21_decimal value, s21_decimal* result) {
    empty_struct(result);
    copy_dec(value, result);
    get_sign(&value) ? set_plus(result) : set_minus(result);
    return 0;
}
