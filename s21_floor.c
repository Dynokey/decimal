#include "s21_decimal.h"
/**
 * @brief Округляет указанное Decimal число до 
 * ближайшего целого числа в сторону отрицательной бесконечности.
 * @param dec1 Число к округлению
 * @return 0 - OK. 1 - ошибка вычисления.
 */
int s21_floor(s21_decimal value, s21_decimal *result) {
    empty_struct(result);
    *result = value;
    int scale = get_scale(result);
    for (; scale > 0; scale--)
        s21_div10(result);
    if (get_sign(result))
        result->bits[0] = result->bits[0] + 1;  // либо Настино сложение беззнаковое + 1
    set_scale(result, 0);
    return 0;
}
