#include "s21_decimal.h"
/**
 * @brief Делает перевод из float в децимала
 * @return 0 - OK
1 - ошибка конвертации
 */
int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  empty_struct(dst);
  int new = (int)src;
  int i = 0;
  int res = 0;
  if (!dst) {
    res = 1;
  } else {
    if (src < 0) {
      set_minus(dst);
      src *= -1;
    }
    while (src - ((float)new / (int)(pow(10, i))) != 0) {
      i++;
      new = src *(int)(pow(10, i));
    }
    dst->bits[0] = new;
    set_scale(dst, i);
  }
  return res;
}
