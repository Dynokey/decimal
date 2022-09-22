#include <stdio.h>
#include <sys/time.h>

#include "s21_decimal_test.h"
#include "s21_test_add.c"
// #include "s21_test_add_simple.c"
#include "s21_test_comparision.c"
#include "s21_test_floor.c"
#include "s21_test_from_decimal_to_float.c"
#include "s21_test_from_decimal_to_int.c"
#include "s21_test_from_int_to_decimal.c"
#include "s21_test_is_equal.c"
#include "s21_test_is_greater.c"
#include "s21_test_is_less_or_equal.c"
#include "s21_test_mul.c"
#include "s21_test_mul10.c"
#include "s21_test_negate.c"
#include "s21_test_round.c"
#include "s21_test_sub.c"
// #include "s21_test_sub_simple.c"
#include "s21_test_div10.c"
#include "s21_test_div.c"
#include "s21_test_from_float_to_decimal.c"
#include "s21_test_mod.c"
#include "s21_test_truncate.c"

// #include "s21_decimal_test.h"

struct timeval tv1,
    tv2, dtv;

struct timezone tz;

void time_start() { gettimeofday(&tv1, &tz); }

long time_stop()

{
    gettimeofday(&tv2, &tz);

    dtv.tv_sec = tv2.tv_sec - tv1.tv_sec;

    dtv.tv_usec = tv2.tv_usec - tv1.tv_usec;

    if (dtv.tv_usec < 0) {
        dtv.tv_sec--;
        dtv.tv_usec += 1000000;
    }

    return dtv.tv_sec * 1000 + dtv.tv_usec / 1000;
}

/* Функция time_stop() возвращает время,
прошедшее с запуска time_start(), в миллисекундах.Пример использования :
*/

int main(void) {
    time_start();
    Suite* s1 = suite_create("Core");
    TCase* tc = tcase_create("Core");
    SRunner* sr = srunner_create(s1);
    int nf;
    suite_add_tcase(s1, tc);

    printf("%s", GREEN);
    tcase_add_test(tc, equal_4);
    tcase_add_test(tc, uytre);
    tcase_add_test(tc, equal_5);
    tcase_add_test(tc, equal_6);
    tcase_add_test(tc, equal_7);
    tcase_add_test(tc, equal_8);
    tcase_add_test(tc, equal_9);
    tcase_add_test(tc, equal_10);
    tcase_add_test(tc, s21_equal_null_12);
    tcase_add_test(tc, s21_is_equalTest1);
    tcase_add_test(tc, s21_is_equalTest2);
    tcase_add_test(tc, s21_is_equalTest3);
    tcase_add_test(tc, s21_is_equalTest4);
    tcase_add_test(tc, s21_is_equalTest5);
    tcase_add_test(tc, s21_is_equalTest6);
    tcase_add_test(tc, s21_is_equalTest7);
    tcase_add_test(tc, s21_is_equalTest8);
    tcase_add_test(tc, s21_is_equalTest9);
    tcase_add_test(tc, s21_is_equalTest10);
    tcase_add_test(tc, s21_is_equalTest11);
    tcase_add_test(tc, s21_is_equalTest12);
    tcase_add_test(tc, s21_is_equalTest13);
    tcase_add_test(tc, s21_is_equalTest14);
    tcase_add_test(tc, s21_is_equalTest15);
    tcase_add_test(tc, s21_is_equalTest16);
    tcase_add_test(tc, s21_is_equalTest17);
    tcase_add_test(tc, s21_is_equalTest18);
    tcase_add_test(tc, s21_is_equalTest19);
    tcase_add_test(tc, s21_is_equalTest20);
    tcase_add_test(tc, s21_is_equalTest21);
    tcase_add_test(tc, s21_is_equalTest22);
    tcase_add_test(tc, s21_is_equalTest23);
    tcase_add_test(tc, s21_is_equalTest24);
    tcase_add_test(tc, s21_is_equalTest25);
    tcase_add_test(tc, s21_is_equalTest26);
    tcase_add_test(tc, s21_is_equalTest27);
    tcase_add_test(tc, s21_is_equalTest28);
    tcase_add_test(tc, s21_is_equalTest29);
    tcase_add_test(tc, s21_is_equalTest30);
    tcase_add_test(tc, s21_is_equalTest31);
    tcase_add_test(tc, s21_is_equalTest32);
    tcase_add_test(tc, s21_is_equalTest33);
    tcase_add_test(tc, s21_is_equalTest34);
    tcase_add_test(tc, s21_is_equalTest35);
    tcase_add_test(tc, s21_is_equalTest36);
    tcase_add_test(tc, s21_from_decimal_to_float_1);
    tcase_add_test(tc, s21_from_decimal_to_float_2);
    tcase_add_test(tc, s21_from_decimal_to_float_3);
    tcase_add_test(tc, s21_from_decimal_to_float_5);
    tcase_add_test(tc, s21_from_decimal_to_float_7);
    tcase_add_test(tc, s21_from_decimal_to_float_8);
    tcase_add_test(tc, s21_from_decimal_to_float_10);
    tcase_add_test(tc, s21_from_decimal_to_floatTest1);
    tcase_add_test(tc, s21_from_decimal_to_floatTest2);
    tcase_add_test(tc, s21_from_decimal_to_floatTest3);
    tcase_add_test(tc, s21_from_decimal_to_floatTest4);
    tcase_add_test(tc, s21_from_decimal_to_floatTest5);
    tcase_add_test(tc, s21_from_decimal_to_floatTest6);
    tcase_add_test(tc, s21_from_decimal_to_floatTest7);
    tcase_add_test(tc, s21_from_decimal_to_float_001);
    tcase_add_test(tc, s21_from_decimal_to_float_002);
    tcase_add_test(tc, s21_from_decimal_to_float_003);
    tcase_add_test(tc, s21_from_decimal_to_float_004);
    tcase_add_test(tc, s21_from_decimal_to_float_005);
    tcase_add_test(tc, less_or_equal_4);
    tcase_add_test(tc, less_or_equal_5);
    tcase_add_test(tc, less_or_equal_6);
    tcase_add_test(tc, less_or_equal_17);
    tcase_add_test(tc, less_or_equal_18);
    tcase_add_test(tc, less_or_equal_19);
    tcase_add_test(tc, less_or_equal_20);
    tcase_add_test(tc, s21_less_or_equal_23);
    tcase_add_test(tc, s21_test_is_less_or_equal_1);
    tcase_add_test(tc, s21_test_is_less_or_equal_2);
    tcase_add_test(tc, s21_test_is_less_or_equal_2i);
    tcase_add_test(tc, s21_test_is_less_or_equal_3);
    tcase_add_test(tc, s21_test_is_less_or_equal_4);
    tcase_add_test(tc, s21_test_is_less_or_equal_41);
    tcase_add_test(tc, s21_test_is_less_or_equal_5);
    tcase_add_test(tc, s21_test_is_less_or_equal_6);
    tcase_add_test(tc, s21_test_is_less_or_equal_7);
    tcase_add_test(tc, s21_test_is_less_or_equal_8);
    tcase_add_test(tc, s21_test_is_less_or_equal_8);
    tcase_add_test(tc, s21_test_is_less_or_equal_9);
    tcase_add_test(tc, s21_test_is_less_or_equal_10);
    tcase_add_test(tc, s21_is_less_or_equalTest1);
    tcase_add_test(tc, s21_is_less_or_equalTest2);
    tcase_add_test(tc, s21_is_less_or_equalTest3);
    tcase_add_test(tc, s21_is_less_or_equalTest4);
    tcase_add_test(tc, s21_is_less_or_equalTest5);
    tcase_add_test(tc, s21_is_less_or_equalTest6);
    tcase_add_test(tc, s21_is_less_or_equalTest7);
    tcase_add_test(tc, s21_is_less_or_equalTest8);
    tcase_add_test(tc, s21_is_less_or_equalTest9);
    tcase_add_test(tc, s21_is_less_or_equalTest10);
    tcase_add_test(tc, s21_is_less_or_equalTest11);
    tcase_add_test(tc, s21_is_less_or_equalTest12);
    tcase_add_test(tc, s21_is_less_or_equalTest13);
    tcase_add_test(tc, s21_is_less_or_equalTest14);
    tcase_add_test(tc, s21_is_less_or_equalTest15);
    tcase_add_test(tc, s21_is_less_or_equalTest16);
    tcase_add_test(tc, s21_is_less_or_equalTest18);
    tcase_add_test(tc, s21_is_less_or_equalTest19);
    // tcase_add_test(tc, s21_is_less_or_equalTest20);  // --
    // tcase_add_test(tc, s21_is_less_or_equalTest21);  // --
    // tcase_add_test(tc, s21_is_less_or_equalTest22);  // --
    tcase_add_test(tc, s21_is_less_or_equalTest23);
    tcase_add_test(tc, s21_is_less_or_equalTest24);
    tcase_add_test(tc, s21_is_less_or_equalTest25);
    tcase_add_test(tc, s21_is_less_or_equalTest26);
    tcase_add_test(tc, s21_is_less_or_equalTest27);
    tcase_add_test(tc, s21_is_less_or_equalTest28);
    tcase_add_test(tc, s21_is_less_or_equalTest29);
    tcase_add_test(tc, s21_is_less_or_equalTest30);
    tcase_add_test(tc, s21_is_less_or_equalTest31);
    tcase_add_test(tc, s21_is_less_or_equalTest32);
    tcase_add_test(tc, s21_is_less_or_equalTest33);
    tcase_add_test(tc, s21_is_less_or_equalTest34);
    // tcase_add_test(tc, s21_is_less_or_equalTest35);
    tcase_add_test(tc, s21_is_less_or_equalTest36);
    tcase_add_test(tc, less_4);
    tcase_add_test(tc, less_5);
    tcase_add_test(tc, less_6);
    tcase_add_test(tc, s21_less_8);
    tcase_add_test(tc, not_equal_4);
    tcase_add_test(tc, not_equal_5);
    tcase_add_test(tc, not_equal_6);
    tcase_add_test(tc, s21_not_equal_7);
    tcase_add_test(tc, s21_not_equal_8);
    tcase_add_test(tc, s21_round_1);
    tcase_add_test(tc, s21_round_2);
    tcase_add_test(tc, s21_round_3);
    tcase_add_test(tc, s21_round_4);
    tcase_add_test(tc, s21_round_5);
    tcase_add_test(tc, s21_round_6);
    tcase_add_test(tc, s21_round_7);
    tcase_add_test(tc, s21_round_8);
    tcase_add_test(tc, s21_round_9);
    tcase_add_test(tc, s21_round_10);
    tcase_add_test(tc, s21_round_11);
    // tcase_add_test(tc, s21_round_12);
    // tcase_add_test(tc, s21_round_13);
    tcase_add_test(tc, s21_roundTest1);
    tcase_add_test(tc, s21_roundTest2);
    tcase_add_test(tc, s21_roundTest3);
    tcase_add_test(tc, s21_roundTest4);
    tcase_add_test(tc, s21_roundTest5);
    tcase_add_test(tc, s21_roundTest6);
    tcase_add_test(tc, s21_roundTest7);
    tcase_add_test(tc, s21_roundTest8);
    tcase_add_test(tc, s21_roundTest9);
    tcase_add_test(tc, s21_roundTest10);
    tcase_add_test(tc, s21_roundTest11);
    tcase_add_test(tc, s21_roundTest12);
    tcase_add_test(tc, s21_roundTest13);
    tcase_add_test(tc, s21_roundTest14);
    tcase_add_test(tc, s21_roundTest15);
    tcase_add_test(tc, greater_or_equal_2);
    tcase_add_test(tc, greater_or_equal_4);
    tcase_add_test(tc, greater_or_equal_5);
    tcase_add_test(tc, greater_or_equal_6);
    tcase_add_test(tc, greater_or_equal_7);
    tcase_add_test(tc, s21_greater_or_equal_13);
    tcase_add_test(tc, s21_trun_1);
    tcase_add_test(tc, s21_trun_2);
    tcase_add_test(tc, s21_trun_3);
    tcase_add_test(tc, s21_trun_4);
    tcase_add_test(tc, s21_truncate_1);
    tcase_add_test(tc, s21_truncate_2);
    tcase_add_test(tc, s21_truncate_3);
    tcase_add_test(tc, s21_truncate_4);
    tcase_add_test(tc, s21_truncate_5);
    tcase_add_test(tc, s21_truncate_6);
    tcase_add_test(tc, s21_truncate_7);
    tcase_add_test(tc, s21_truncate_8);
    tcase_add_test(tc, s21_truncateTest1);
    tcase_add_test(tc, s21_truncateTest2);
    tcase_add_test(tc, s21_truncateTest3);
    tcase_add_test(tc, s21_truncateTest4);
    tcase_add_test(tc, s21_truncateTest5);
    tcase_add_test(tc, s21_truncateTest6);
    tcase_add_test(tc, s21_truncateTest7);
    tcase_add_test(tc, s21_truncateTest8);
    tcase_add_test(tc, s21_truncateTest9);
    tcase_add_test(tc, s21_truncateTest10);
    tcase_add_test(tc, s21_truncateTest11);
    tcase_add_test(tc, s21_floor_1);
    tcase_add_test(tc, s21_floor_2);
    tcase_add_test(tc, s21_floor_3);
    tcase_add_test(tc, s21_floor_4);
    tcase_add_test(tc, s21_floor_5);
    tcase_add_test(tc, s21_floor_6);
    tcase_add_test(tc, s21_floor_7);
    tcase_add_test(tc, s21_floor_8);
    tcase_add_test(tc, s21_floor_9);
    tcase_add_test(tc, s21_floor_10);
    tcase_add_test(tc, s21_floor_11);
    tcase_add_test(tc, s21_floor_0);
    tcase_add_test(tc, s21_floor_01);
    tcase_add_test(tc, s21_floor_02);
    tcase_add_test(tc, s21_floorTest1);
    tcase_add_test(tc, s21_floorTest2);
    tcase_add_test(tc, s21_floorTest3);
    tcase_add_test(tc, s21_floorTest4);
    tcase_add_test(tc, s21_floorTest5);
    tcase_add_test(tc, s21_floorTest6);
    tcase_add_test(tc, s21_floorTest7);
    tcase_add_test(tc, s21_floorTest8);
    tcase_add_test(tc, s21_floorTest9);
    tcase_add_test(tc, s21_floorTest10);
    tcase_add_test(tc, s21_floorTest11);
    tcase_add_test(tc, s21_negate_1);
    tcase_add_test(tc, s21_negate_5);
    tcase_add_test(tc, s21_test_negate_0);
    tcase_add_test(tc, s21_test_negate_1);
    tcase_add_test(tc, s21_test_negate_2);
    tcase_add_test(tc, s21_test_negate_3);
    tcase_add_test(tc, s21_test_negate_4);
    tcase_add_test(tc, s21_test_negate_5);
    tcase_add_test(tc, s21_test_negate_6);
    tcase_add_test(tc, s21_test_negate_7);
    tcase_add_test(tc, s21_test_negate_8);
    tcase_add_test(tc, negate_0);
    tcase_add_test(tc, negate_1);
    tcase_add_test(tc, negate_2);
    tcase_add_test(tc, negate_3);
    tcase_add_test(tc, s21_from_int_to_decimal_1);
    tcase_add_test(tc, s21_test_from_int_to_decimal_0);
    tcase_add_test(tc, s21_test_from_int_to_decimal_1);
    tcase_add_test(tc, s21_test_from_int_to_decimal_2);
    tcase_add_test(tc, s21_test_from_int_to_decimal_3);
    tcase_add_test(tc, s21_test_from_int_to_decimal_4);
    tcase_add_test(tc, s21_test_from_int_to_decimal_5);
    tcase_add_test(tc, s21_from_int_to_decimalTest1);
    tcase_add_test(tc, s21_from_int_to_decimalTest2);
    tcase_add_test(tc, s21_from_int_to_decimalTest3);
    tcase_add_test(tc, s21_from_int_to_decimalTest4);
    tcase_add_test(tc, s21_from_int_to_decimalTest5);
    tcase_add_test(tc, s21_from_int_to_decimalTest6);
    tcase_add_test(tc, s21_from_int_to_decimalTest7);
    tcase_add_test(tc, s21_from_int_to_decimalTest8);
    tcase_add_test(tc, s21_from_int_to_decimalTest9);
    tcase_add_test(tc, from_int_to_decimal_0);
    tcase_add_test(tc, from_int_to_decimal_1);
    tcase_add_test(tc, greater_4);
    tcase_add_test(tc, greater_5);
    tcase_add_test(tc, greater_6);
    tcase_add_test(tc, greater_7);
    tcase_add_test(tc, s21_greater_11);
    tcase_add_test(tc, s21_is_greaterTest1);
    tcase_add_test(tc, s21_is_greaterTest2);
    tcase_add_test(tc, s21_is_greaterTest3);
    tcase_add_test(tc, s21_is_greaterTest4);
    tcase_add_test(tc, s21_is_greaterTest5);
    tcase_add_test(tc, s21_is_greaterTest6);
    tcase_add_test(tc, s21_is_greaterTest7);
    tcase_add_test(tc, s21_is_greaterTest8);
    tcase_add_test(tc, s21_is_greaterTest8);
    tcase_add_test(tc, s21_is_greaterTest9);
    tcase_add_test(tc, s21_is_greaterTest10);
    tcase_add_test(tc, s21_is_greaterTest11);
    tcase_add_test(tc, s21_is_greaterTest12);
    tcase_add_test(tc, s21_is_greaterTest13);
    tcase_add_test(tc, s21_is_greaterTest14);
    tcase_add_test(tc, s21_is_greaterTest15);
    tcase_add_test(tc, s21_is_greaterTest16);
    tcase_add_test(tc, s21_is_greaterTest17);
    tcase_add_test(tc, s21_is_greaterTest18);
    tcase_add_test(tc, s21_is_greaterTest19);
    tcase_add_test(tc, s21_is_greaterTest20);
    tcase_add_test(tc, s21_is_greaterTest21);
    tcase_add_test(tc, s21_is_greaterTest22);
    tcase_add_test(tc, s21_is_greaterTest23);
    tcase_add_test(tc, s21_is_greaterTest24);
    tcase_add_test(tc, s21_is_greaterTest25);
    tcase_add_test(tc, s21_is_greaterTest26);
    tcase_add_test(tc, s21_is_greaterTest27);
    tcase_add_test(tc, s21_is_greaterTest28);
    tcase_add_test(tc, s21_is_greaterTest29);
    tcase_add_test(tc, s21_is_greaterTest30);
    tcase_add_test(tc, s21_is_greaterTest31);
    tcase_add_test(tc, s21_is_greaterTest32);
    tcase_add_test(tc, s21_is_greaterTest33);
    tcase_add_test(tc, s21_is_greaterTest34);
    tcase_add_test(tc, s21_is_greaterTest35);
    tcase_add_test(tc, s21_is_greaterTest36);
    tcase_add_test(tc, s21_test_is_greater_1);
    tcase_add_test(tc, s21_test_is_greater_2);
    tcase_add_test(tc, s21_test_is_greater_3);
    tcase_add_test(tc, s21_test_is_greater_4);
    tcase_add_test(tc, s21_test_is_greater_5);
    tcase_add_test(tc, s21_test_is_greater_6);
    tcase_add_test(tc, s21_test_is_greater_7);
    tcase_add_test(tc, s21_test_is_greater_8);
    tcase_add_test(tc, s21_test_is_greater_9);
    tcase_add_test(tc, s21_test_is_greater_10);
    tcase_add_test(tc, s21_test_is_greater_51);
    tcase_add_test(tc, s21_test_is_greater_41);
    tcase_add_test(tc, s21_test_is_greater_2i);
    tcase_add_test(tc, s21_from_decimal_to_int_0);
    tcase_add_test(tc, s21_from_decimal_to_int_1);
    tcase_add_test(tc, s21_from_decimal_to_int_2);
    tcase_add_test(tc, s21_from_decimal_to_int_4);
    tcase_add_test(tc, s21_from_decimal_to_int_5);
    tcase_add_test(tc, s21_from_decimal_to_int_6);
    tcase_add_test(tc, s21_test_from_decimal_to_int_0);
    tcase_add_test(tc, s21_test_from_decimal_to_int_1);
    tcase_add_test(tc, s21_test_from_decimal_to_int_3);
    tcase_add_test(tc, s21_test_from_decimal_to_int_4);
    tcase_add_test(tc, s21_test_from_decimal_to_int_6);
    tcase_add_test(tc, s21_test_from_decimal_to_int_7);
    tcase_add_test(tc, s21_test_from_decimal_to_int_8);
    tcase_add_test(tc, s21_test_from_decimal_to_int_9);
    tcase_add_test(tc, s21_test_from_decimal_to_int_10);
    tcase_add_test(tc, s21_test_from_decimal_to_int_11);
    tcase_add_test(tc, s21_test_from_decimal_to_int_12);
    tcase_add_test(tc, s21_test_from_decimal_to_int_14);
    tcase_add_test(tc, s21_test_from_decimal_to_int_16);
    tcase_add_test(tc, s21_from_decimal_to_intTest1);
    tcase_add_test(tc, s21_from_decimal_to_intTest2);
    tcase_add_test(tc, s21_from_decimal_to_intTest3);
    tcase_add_test(tc, s21_from_decimal_to_intTest4);
    tcase_add_test(tc, s21_from_decimal_to_intTest5);
    tcase_add_test(tc, s21_from_decimal_to_intTest6);
    tcase_add_test(tc, s21_from_decimal_to_intTest7);
    tcase_add_test(tc, s21_from_decimal_to_intTest8);
    tcase_add_test(tc, s21_from_decimal_to_intTest9);
    tcase_add_test(tc, s21_from_decimal_to_intTest10);
    tcase_add_test(tc, s21_from_decimal_to_intTest11);
    tcase_add_test(tc, s21_from_decimal_to_intTest12);
    tcase_add_test(tc, s21_from_decimal_to_intTest13);
    tcase_add_test(tc, s21_from_decimal_to_intTest14);
    tcase_add_test(tc, s21_from_decimal_to_intTest15);
    // tcase_add_test(tc, s21_from_float_to_decimalTest0);
    tcase_add_test(tc, s21_from_float_to_decimalTest1);
    tcase_add_test(tc, s21_from_float_to_decimalTest2);
    tcase_add_test(tc, s21_from_float_to_decimalTest3);
    tcase_add_test(tc, s21_from_float_to_decimalTest7);
    tcase_add_test(tc, s21_from_float_to_decimalTest8);
    tcase_add_test(tc, scale_eq_02_a);
    tcase_add_test(tc, scale_eq_02_b);
    tcase_add_test(tc, scale_eq_03_a);
    tcase_add_test(tc, scale_eq_03_b);
    tcase_add_test(tc, scale_eq_04_a);
    tcase_add_test(tc, scale_eq_04_b);
    tcase_add_test(tc, scale_eq_05_b);
    tcase_add_test(tc, scale_eq_05_a);
    tcase_add_test(tc, scale_eq_06_b);
    tcase_add_test(tc, scale_eq_06_a);
    tcase_add_test(tc, scale_eq_07_b);
    tcase_add_test(tc, scale_eq_07_a);
    tcase_add_test(tc, scale_eq_08_b);
    tcase_add_test(tc, scale_eq_08_a);
    tcase_add_test(tc, scale_eq_09);
    tcase_add_test(tc, scale_eq_10);
    tcase_add_test(tc, scale_eq_11);
    tcase_add_test(tc, add_test_1);
    tcase_add_test(tc, add_test_2);
    tcase_add_test(tc, add_test_3);
    tcase_add_test(tc, add_test_4);
    tcase_add_test(tc, add_test_5);
    tcase_add_test(tc, add_test_6);
    tcase_add_test(tc, add_test_7);
    tcase_add_test(tc, add_test_8);
    tcase_add_test(tc, add_test_9);
    tcase_add_test(tc, add_test_10);
    tcase_add_test(tc, sub_test_1);
    tcase_add_test(tc, sub_test_2);
    tcase_add_test(tc, sub_test_3);
    tcase_add_test(tc, sub_test_4);
    tcase_add_test(tc, sub_test_5);
    tcase_add_test(tc, sub_test_6);
    tcase_add_test(tc, sub_test_7);
    tcase_add_test(tc, sub_test_8);
    tcase_add_test(tc, sub_test_9);
    tcase_add_test(tc, sub_test_10);
    tcase_add_test(tc, s21_subTest1);
    tcase_add_test(tc, s21_subTest2);
    tcase_add_test(tc, s21_subTest3);
    tcase_add_test(tc, s21_subTest4);
    tcase_add_test(tc, s21_subTest5);
    tcase_add_test(tc, s21_subTest6);
    tcase_add_test(tc, s21_subTest7);
    tcase_add_test(tc, s21_subTest8);
    tcase_add_test(tc, s21_subTest9);
    tcase_add_test(tc, s21_subTest10);
    tcase_add_test(tc, s21_subTest11);
    tcase_add_test(tc, s21_subTest12);
    tcase_add_test(tc, s21_subTest13);
    tcase_add_test(tc, s21_subTest14);
    tcase_add_test(tc, s21_subTest15);
    tcase_add_test(tc, s21_subTest16);
    tcase_add_test(tc, s21_subTest17);
    tcase_add_test(tc, s21_subTest18);
    tcase_add_test(tc, s21_subTest20);
    tcase_add_test(tc, s21_subTest21);
    tcase_add_test(tc, s21_subTest26);
    tcase_add_test(tc, s21_subTest27);
    tcase_add_test(tc, s21_subTest28);
    tcase_add_test(tc, s21_subTest29);
    tcase_add_test(tc, s21_subTest30);
    tcase_add_test(tc, s21_subTest31);
    tcase_add_test(tc, s21_subTest33);
    tcase_add_test(tc, s21_test_decimal_sub_0);
    tcase_add_test(tc, s21_test_decimal_sub_1);
    tcase_add_test(tc, s21_test_decimal_sub_2);
    tcase_add_test(tc, s21_test_decimal_sub_3);
    tcase_add_test(tc, s21_test_decimal_sub_7);
    tcase_add_test(tc, s21_test_decimal_sub_8);
    tcase_add_test(tc, s21_test_decimal_sub_10);
    tcase_add_test(tc, s21_test_decimal_sub_11);
    tcase_add_test(tc, s21_sub_inf_27);
    tcase_add_test(tc, s21_sub_neg_inf_28);
    tcase_add_test(tc, s21_sub_max_32);
    tcase_add_test(tc, s21_sub_max_33);
    tcase_add_test(tc, s21_sub_max_34);
    tcase_add_test(tc, s21_sub_max_34_1);
    tcase_add_test(tc, s21_sub_max_35);
    tcase_add_test(tc, s21_test_decimal_add_0);
    tcase_add_test(tc, s21_test_decimal_add_1);
    tcase_add_test(tc, s21_test_decimal_add_2);
    tcase_add_test(tc, s21_test_decimal_add_3);
    tcase_add_test(tc, s21_test_decimal_add_4);
    tcase_add_test(tc, s21_test_decimal_add_5);
    tcase_add_test(tc, s21_test_decimal_add_6);
    tcase_add_test(tc, s21_test_decimal_add_7);
    tcase_add_test(tc, s21_test_decimal_add_8);
    tcase_add_test(tc, s21_test_decimal_add_8_1);
    tcase_add_test(tc, s21_test_decimal_add_9);
    tcase_add_test(tc, s21_test_decimal_add_10);
    tcase_add_test(tc, s21_test_decimal_add_11);
    tcase_add_test(tc, s21_test_decimal_add_12);
    tcase_add_test(tc, s21_test_decimal_add_13);
    tcase_add_test(tc, s21_test_decimal_add_14);
    tcase_add_test(tc, s21_test_decimal_add_15);
    tcase_add_test(tc, s21_test_decimal_add_16);
    tcase_add_test(tc, s21_test_decimal_add_17);
    tcase_add_test(tc, s21_test_decimal_add_18);
    tcase_add_test(tc, s21_test_decimal_add_19);
    tcase_add_test(tc, s21_test_decimal_add_20);
    tcase_add_test(tc, s21_test_decimal_add_21);
    tcase_add_test(tc, s21_test_decimal_add_25);
    tcase_add_test(tc, s21_test_decimal_add_26);
    tcase_add_test(tc, s21_test_decimal_add_27);
    tcase_add_test(tc, s21_test_decimal_add_30);
    tcase_add_test(tc, add_0);
    tcase_add_test(tc, add_1);
    tcase_add_test(tc, add_2);
    tcase_add_test(tc, add_3);
    tcase_add_test(tc, add_4);
    tcase_add_test(tc, add_5);
    tcase_add_test(tc, add_6);
    tcase_add_test(tc, add_7);
    tcase_add_test(tc, add_8);
    tcase_add_test(tc, add_9);
    tcase_add_test(tc, add_10);
    tcase_add_test(tc, add_11);
    tcase_add_test(tc, add_12);
    tcase_add_test(tc, add_13);
    tcase_add_test(tc, add_14);
    tcase_add_test(tc, add_15);
    tcase_add_test(tc, add_16);
    tcase_add_test(tc, s21_test_decimal_add_simple_0);
    tcase_add_test(tc, s21_test_decimal_add_simple_1);
    tcase_add_test(tc, s21_test_decimal_add_simple_2);
    tcase_add_test(tc, s21_test_decimal_add_simple_4);
    tcase_add_test(tc, s21_test_decimal_add_simple_5);
    tcase_add_test(tc, s21_test_decimal_add_simple_6);
    tcase_add_test(tc, s21_test_decimal_add_simple_7);
    tcase_add_test(tc, s21_test_decimal_add_simple_8);
    tcase_add_test(tc, s21_test_decimal_add_simple_9);
    tcase_add_test(tc, s21_test_decimal_add_simple_10);
    tcase_add_test(tc, s21_test_decimal_add_simple_13);
    tcase_add_test(tc, s21_test_decimal_add_simple_14);
    tcase_add_test(tc, s21_test_decimal_add_simple_20);
    tcase_add_test(tc, s21_test_decimal_add_simple_21);
    tcase_add_test(tc, s21_test_decimal_add_simple_22);
    tcase_add_test(tc, add_test_21);
    tcase_add_test(tc, add_test_22);
    tcase_add_test(tc, add_test_23);
    // tcase_add_test(tc, add_test_24);
    tcase_add_test(tc, add_test_25);
    tcase_add_test(tc, add_test_26);
    tcase_add_test(tc, s21_add_max_31);
    tcase_add_test(tc, s21_add_max_32);
    tcase_add_test(tc, s21_add_max_32_1);
    tcase_add_test(tc, s21_add_max_33);
    tcase_add_test(tc, s21_add_max_36);
    tcase_add_test(tc, add_test_37);
    tcase_add_test(tc, mod_test_1);
    tcase_add_test(tc, mod_test_5);
    tcase_add_test(tc, mod_test_6);
    tcase_add_test(tc, mul_test_1);
    tcase_add_test(tc, div_test_1);
    tcase_add_test(tc, div_test_3);
    tcase_add_test(tc, div_test_4);
    tcase_add_test(tc, div_test_5);

    // srunner_run_all(sr, CK_ENV);
    // nf = srunner_ntests_failed(sr);
    // srunner_free(sr);
    // return nf == 0 ? 0 : 1;

    // srunner_set_log(sr, "test1.log"); // создается файл с логом тестов с папке src
    srunner_run_all(sr, CK_ENV);  // краткий отчет - выводит результаты всех ошибок
    // srunner_run_all(sr, CK_VERBOSE); // подкробный отчет - выводит результаты всех тестов
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);
    // -------------------------------------------------------------
    printf("%s", RESET);
    printf("Time: %ld\n", time_stop());
    // -------------------------------------------------------------
    return nf == 0 ? 0 : 1;
}
