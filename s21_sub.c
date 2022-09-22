#include "s21_decimal.h"

/**
 * @brief Вычитание
 * @return
 * 0 - OK.
 * 1 - число слишком велико или равно бесконечности.
 * 2 - число слишком мало или равно отрицательной бесконечности.
 * 3 - деление на 0.
 */
int s21_sub(s21_decimal var1, s21_decimal var2, s21_decimal *result) {
    empty_struct(result);
    int flag = 0;

    if (decimal_err(var2) == 0 && decimal_err(var1) == 0) {
        if (scale(var1) != scale(var2)) {
            flag = scale_eq2(&var1, &var2);
        }
        if (scale_eq2(&var1, &var2) != 0) {
            flag = 1;
        }

        if (flag != 1) {
            if (get_bit(var1, 127) != get_bit(var2, 127)) {
                flag = s21_decimal_add_simple(var1, var2, result);

                if (get_bit(var1, 127) == 1) set_minus(result);

            } else {
                if ((is_equal(var1, var2) == 1) &&
                    (get_bit(var1, 127) == get_bit(var2, 127))) {
                    empty_struct(result);

                    flag = 0;
                } else if (is_greater(var1, var2) == 1) {
                    flag = s21_decimal_sub_simple(var1, var2, result);

                    if (get_bit(var1, 127) == 1) {
                        set_minus(result);
                    } else {
                        set_plus(result);
                    }

                } else {
                    flag = s21_decimal_sub_simple(var2, var1, result);

                    if (get_bit(var1, 127) == 0) {
                        set_minus(result);
                    } else {
                        set_plus(result);
                    }
                }
            }
            set_scale(result, scale(var1));
        }
        if (flag == 1 && get_bit(*result, 127)) {
            flag = 2;
        }

  } else {
    flag = 1;
    if (get_bit(*result, 127)) {
      flag = 2;
    }
  }

  return flag;
}
