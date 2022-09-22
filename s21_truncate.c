#include "s21_decimal.h"
/**
 * @brief Возвращает целые цифры указанного Decimal числа;
любые дробные цифры отбрасываются, включая конечные нули.
 * @return 0 - OK
1 - ошибка вычисления
 */
int s21_truncate(s21_decimal a, s21_decimal* p_res) {
    empty_struct(p_res);
    int err = decimal_err(a);
    if (err == 0) {
        int scl = scale(a);
        while (scl > 0) {
            s21_div10(&a);
            scl--;
        }
        set_scale(&a, 0);
        *p_res = a;
    }
    return err;
}
