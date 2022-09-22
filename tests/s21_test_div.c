#include "s21_decimal_test.h"

START_TEST(div_test_5) {
    s21_decimal c = {{UINT32_MAX, UINT32_MAX, UINT32_MAX, 0}};
    s21_decimal b = {{1, 0, 0, 0}};
    s21_decimal res = {0};
    s21_div(c, b, &res);
    s21_decimal a = {{UINT32_MAX, UINT32_MAX, UINT32_MAX, 0}};
    ck_assert_int_eq(a.bits[3], res.bits[3]);
    ck_assert_int_eq(a.bits[2], res.bits[2]);
    ck_assert_int_eq(a.bits[1], res.bits[1]);
    ck_assert_int_eq(a.bits[0], res.bits[0]);
}
END_TEST

START_TEST(div_test_1) {
    int num1 = 100;
    int num2 = 50;
    int res_origin = 2;
    s21_decimal a = {0};
    s21_decimal b = {0};
    s21_from_int_to_decimal(num1, &a);
    s21_from_int_to_decimal(num2, &b);
    s21_decimal res_dec = {0};
    int res_int = 0;
    s21_div(a, b, &res_dec);
    s21_from_decimal_to_int(res_dec, &res_int);
    ck_assert_int_eq(res_int, res_origin);
}
END_TEST

START_TEST(div_test_2) {
    int num1 = -32768;
    int num2 = 2;
    int res_origin = -16384;
    s21_decimal a = {0};
    s21_decimal b = {0};
    s21_from_int_to_decimal(num1, &a);
    s21_from_int_to_decimal(num2, &b);
    s21_decimal res_dec = {0};
    int res_int = 0;
    s21_div(a, b, &res_dec);
    s21_from_decimal_to_int(res_dec, &res_int);
    ck_assert_int_eq(res_int, res_origin);
}
END_TEST

START_TEST(div_test_3) {
    int num1 = 2;
    int num2 = 2;
    int res_origin = 1;
    s21_decimal a = {0};
    s21_decimal b = {0};
    s21_from_int_to_decimal(num1, &a);
    s21_from_int_to_decimal(num2, &b);
    s21_decimal res_dec = {0};
    int res_int = 0;
    s21_div(a, b, &res_dec);
    s21_from_decimal_to_int(res_dec, &res_int);
    ck_assert_int_eq(res_int, res_origin);
}
END_TEST

START_TEST(div_test_4) {
    int num1 = 0;
    int num2 = 5;
    int res_origin = num1 / num2;
    s21_decimal a = {0};
    s21_decimal b = {0};
    s21_from_int_to_decimal(num1, &a);
    s21_from_int_to_decimal(num2, &b);
    s21_decimal res_dec = {0};
    int res_int = 0;
    s21_div(a, b, &res_dec);
    s21_from_decimal_to_int(res_dec, &res_int);
    ck_assert_int_eq(res_int, res_origin);
}
END_TEST
