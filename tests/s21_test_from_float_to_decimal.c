#include "s21_decimal_test.h"

// START_TEST(s21_from_float_to_decimalTest0) {
//     int result = 0;
//     float number = 0;
//     s21_decimal src;
//     src.bits[0] = UINT32_MAX;
//     src.bits[1] = UINT32_MAX;
//     src.bits[2] = UINT32_MAX;
//     src.bits[3] = UINT32_MAX;
//     result = s21_from_float_to_decimal(src, &number);
//     ck_assert_int_eq(result, 1);
// }
// END_TEST

START_TEST(s21_from_float_to_decimalTest1) {
    float src1 = 0.02;
    s21_decimal result = {0};
    s21_decimal etalon = {0};
    s21_from_float_to_decimal(src1, &result);
    etalon.bits[0] = 2;
    etalon.bits[1] = 0;
    etalon.bits[2] = 0;
    etalon.bits[3] = 0;
    set_scale(&etalon, 2);
    ck_assert_int_eq(etalon.bits[3], result.bits[3]);
    ck_assert_int_eq(etalon.bits[2], result.bits[2]);
    ck_assert_int_eq(etalon.bits[1], result.bits[1]);
    ck_assert_int_eq(etalon.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_from_float_to_decimalTest2) {
    float src1 = -0.02;
    s21_decimal result = {0};
    s21_decimal etalon = {0};
    s21_from_float_to_decimal(src1, &result);
    etalon.bits[0] = 2;
    etalon.bits[1] = 0;
    etalon.bits[2] = 0;
    etalon.bits[3] = MINUS;
    set_scale(&etalon, 2);
    ck_assert_int_eq(etalon.bits[3], result.bits[3]);
    ck_assert_int_eq(etalon.bits[2], result.bits[2]);
    ck_assert_int_eq(etalon.bits[1], result.bits[1]);
    ck_assert_int_eq(etalon.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_from_float_to_decimalTest3) {
    float src1 = 0.000000002;
    s21_decimal result = {0};
    s21_decimal etalon = {0};
    s21_from_float_to_decimal(src1, &result);
    etalon.bits[0] = 2;
    etalon.bits[1] = 0;
    etalon.bits[2] = 0;
    etalon.bits[3] = 0;
    set_scale(&etalon, 9);
    ck_assert_int_eq(etalon.bits[3], result.bits[3]);
    ck_assert_int_eq(etalon.bits[2], result.bits[2]);
    ck_assert_int_eq(etalon.bits[1], result.bits[1]);
    ck_assert_int_eq(etalon.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_from_float_to_decimalTest4) {
    float src1 = 10000000000.000000001;
    s21_decimal result = {{0}};
    s21_decimal etalon = {{0}};
    s21_from_float_to_decimal(src1, &result);
    etalon.bits[0] = 0b10001001111010000000000000000001;
    etalon.bits[1] = 0b10001010110001110010001100000100;
    etalon.bits[2] = 0;
    etalon.bits[3] = 0;
    set_scale(&etalon, 9);
    ck_assert_int_eq(etalon.bits[3], result.bits[3]);
    ck_assert_int_eq(etalon.bits[2], result.bits[2]);
    ck_assert_int_eq(etalon.bits[1], result.bits[1]);
    ck_assert_int_eq(etalon.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_from_float_to_decimalTest5) {
    float src1 = 10000.00000001;
    s21_decimal result = {0};
    s21_decimal etalon = {0};
    s21_from_float_to_decimal(src1, &result);
    etalon.bits[0] = 0b01001110011100101010000000000001;
    etalon.bits[1] = 0b00000000000000000000100100011000;
    etalon.bits[2] = 0b00000000000000000000000000000000;
    etalon.bits[3] = 0b00000000000000000000000000000000;
    set_scale(&etalon, 8);
    ck_assert_int_eq(etalon.bits[3], result.bits[3]);
    ck_assert_int_eq(etalon.bits[2], result.bits[2]);
    ck_assert_int_eq(etalon.bits[1], result.bits[1]);
    ck_assert_int_eq(etalon.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_from_float_to_decimalTest6) {
    float src1 = -5454.353;
    s21_decimal result = {0};
    s21_decimal etalon = {0};
    s21_from_float_to_decimal(src1, &result);
    etalon.bits[0] = 0b00000000010100110011101000010001;
    etalon.bits[1] = 0b00000000000000000000000000000000;
    etalon.bits[2] = 0b00000000000000000000000000000000;
    etalon.bits[3] = 0b10000000000000110000000000000000;
    set_scale(&etalon, 8);
    ck_assert_int_eq(etalon.bits[3], result.bits[3]);
    ck_assert_int_eq(etalon.bits[2], result.bits[2]);
    ck_assert_int_eq(etalon.bits[1], result.bits[1]);
    ck_assert_int_eq(etalon.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_from_float_to_decimalTest7) {
    float src1 = -5.492654;
    s21_decimal result = {0};
    s21_decimal etalon = {0};
    s21_from_float_to_decimal(src1, &result);
    etalon.bits[0] = 0b00000000010100111100111110101110;
    etalon.bits[1] = 0b00000000000000000000000000000000;
    etalon.bits[2] = 0b00000000000000000000000000000000;
    etalon.bits[3] = 0b10000000000001100000000000000000;
    ck_assert_int_eq(etalon.bits[3], result.bits[3]);
    ck_assert_int_eq(etalon.bits[2], result.bits[2]);
    ck_assert_int_eq(etalon.bits[1], result.bits[1]);
    ck_assert_int_eq(etalon.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_from_float_to_decimalTest8) {
    float src1 = 7.961328E+08;
    s21_decimal result = {0};
    s21_decimal etalon = {0};
    s21_from_float_to_decimal(src1, &result);
    etalon.bits[0] = 0b00101111011101000000010111000000;
    etalon.bits[1] = 0b00000000000000000000000000000000;
    etalon.bits[2] = 0b00000000000000000000000000000000;
    etalon.bits[3] = 0b00000000000000000000000000000000;
    ck_assert_int_eq(etalon.bits[3], result.bits[3]);
    ck_assert_int_eq(etalon.bits[2], result.bits[2]);
    ck_assert_int_eq(etalon.bits[1], result.bits[1]);
    ck_assert_int_eq(etalon.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_from_float_to_decimalTest9) {
    float src1 = -1.234568E+07;
    s21_decimal result = {0};
    s21_decimal etalon = {0};
    s21_from_float_to_decimal(src1, &result);
    etalon.bits[0] = 0b00000000101111000110000101010000;
    etalon.bits[1] = 0b00000000000000000000000000000000;
    etalon.bits[2] = 0b00000000000000000000000000000000;
    etalon.bits[3] = 0b10000000000000000000000000000000;
    ck_assert_int_eq(etalon.bits[3], result.bits[3]);
    ck_assert_int_eq(etalon.bits[2], result.bits[2]);
    ck_assert_int_eq(etalon.bits[1], result.bits[1]);
    ck_assert_int_eq(etalon.bits[0], result.bits[0]);
}
END_TEST
