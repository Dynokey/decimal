#include "s21_decimal_test.h"

START_TEST(s21_mul10_1) {
    s21_decimal src1 = {12345, 0, 0, 0};
    s21_mul_10(&src1);
    s21_decimal src2 = {123450, 0, 0, 0};  // 100 = 10 / 10^1
    set_scale(&src2, 1);
    ck_assert_float_eq(src1.bits[3], src2.bits[3]);
    ck_assert_float_eq(src1.bits[2], src2.bits[2]);
    ck_assert_float_eq(src1.bits[1], src2.bits[1]);
    ck_assert_float_eq(src1.bits[0], src2.bits[0]);
}
END_TEST

// START_TEST(s21_mul10_2) {
//     s21_decimal src1 = {10000, 0, 0, 0};
//     s21_mul_10(&src1);
//     s21_decimal src2 = {1000, 0, 0, 0};  // 10000 = 1000 / 10^1
//     set_scale(&src2, 1);
//     ck_assert_float_eq(src1.bits[3], src2.bits[3]);
//     ck_assert_float_eq(src1.bits[2], src2.bits[2]);
//     ck_assert_float_eq(src1.bits[1], src2.bits[1]);
//     ck_assert_float_eq(src1.bits[0], src2.bits[0]);
// }
// END_TEST

// START_TEST(s21_mul10_3) {
//     s21_decimal src1 = {10000, 0, 0, 0};
//     s21_mul_10(&src1);
//     s21_mul_10(&src1);
//     s21_decimal src2 = {100, 0, 0, 0};  // 10000 = 10 / 10^2
//     set_scale(&src2, 2);

//     ck_assert_float_eq(src1.bits[3], src2.bits[3]);
//     ck_assert_float_eq(src1.bits[2], src2.bits[2]);
//     ck_assert_float_eq(src1.bits[1], src2.bits[1]);
//     ck_assert_float_eq(src1.bits[0], src2.bits[0]);
// }
// END_TEST

// START_TEST(s21_mul10_4) {
//     s21_decimal src1 = {100000, 0, 0, 0};
//     s21_mul_10(&src1);
//     s21_mul_10(&src1);
//     s21_mul_10(&src1);
//     s21_mul_10(&src1);
//     s21_decimal src2 = {10, 0, 0, 0};  // 100000 = 10 / 10^4
//     set_scale(&src2, 4);
//     ck_assert_float_eq(src1.bits[3], src2.bits[3]);
//     ck_assert_float_eq(src1.bits[2], src2.bits[2]);
//     ck_assert_float_eq(src1.bits[1], src2.bits[1]);
//     ck_assert_float_eq(src1.bits[0], src2.bits[0]);
// }
// END_TEST

// START_TEST(s21_mul10_5) {
//     s21_decimal src1 = {0, 100000, 0, 0};
//     s21_mul_10(&src1);
//     s21_mul_10(&src1);
//     s21_mul_10(&src1);
//     s21_mul_10(&src1);
//     s21_decimal src2 = {0, 10, 0, 0};  // 100000 = 10 / 10^4
//     set_scale(&src2, 4);
//     ck_assert_float_eq(src1.bits[3], src2.bits[3]);
//     ck_assert_float_eq(src1.bits[2], src2.bits[2]);
//     ck_assert_float_eq(src1.bits[1], src2.bits[1]);
//     ck_assert_float_eq(src1.bits[0], src2.bits[0]);
// }
// END_TEST

// START_TEST(s21_mul10_6) {
//     s21_decimal src1 = {0, 0, 100000, 0};
//     s21_mul_10(&src1);
//     s21_mul_10(&src1);
//     s21_mul_10(&src1);
//     s21_mul_10(&src1);
//     s21_decimal src2 = {0, 0, 10, 0};  // 100000 = 10 / 10^4
//     set_scale(&src2, 4);
//     ck_assert_float_eq(src1.bits[3], src2.bits[3]);
//     ck_assert_float_eq(src1.bits[2], src2.bits[2]);
//     ck_assert_float_eq(src1.bits[1], src2.bits[1]);
//     ck_assert_float_eq(src1.bits[0], src2.bits[0]);
// }
// END_TEST

// START_TEST(s21_mul10_7) {
//     s21_decimal src1 = {12345, 0, 0, 0};
//     s21_mul_10(&src1);
//     s21_decimal src2 = {12345, 0, 0, 0};  // 12345 = 1234,5 10^1
//     set_scale(&src2, 1);
//     ck_assert_float_eq(src1.bits[3], src2.bits[3]);
//     ck_assert_float_eq(src1.bits[2], src2.bits[2]);
//     ck_assert_float_eq(src1.bits[1], src2.bits[1]);
//     ck_assert_float_eq(src1.bits[0], src2.bits[0]);
// }
// END_TEST

// START_TEST(s21_mul10_8) {
//     s21_decimal src1 = {12345, 0, 0, 0};
//     s21_mul_10(&src1);
//     s21_mul_10(&src1);
//     s21_decimal src2 = {12345, 0, 0, 0};  // 12345 = 123,45 10^2
//     set_scale(&src2, 2);
//     ck_assert_float_eq(src1.bits[3], src2.bits[3]);
//     ck_assert_float_eq(src1.bits[2], src2.bits[2]);
//     ck_assert_float_eq(src1.bits[1], src2.bits[1]);
//     ck_assert_float_eq(src1.bits[0], src2.bits[0]);
// }
// END_TEST

// START_TEST(s21_mul10_9) {
//     s21_decimal src1 = {0, 1, 0, 0};
//     s21_mul_10(&src1);
//     s21_decimal src2 = {0, 1, 0, 0};  // 8589934591 = 858993459,1 / 10^1
//     set_scale(&src2, 1);
//     ck_assert_float_eq(src1.bits[3], src2.bits[3]);
//     ck_assert_float_eq(src1.bits[2], src2.bits[2]);
//     ck_assert_float_eq(src1.bits[1], src2.bits[1]);
//     ck_assert_float_eq(src1.bits[0], src2.bits[0]);
// }
// END_TEST

// START_TEST(s21_mul10_10) {
//     s21_decimal src1 = {12345, 0, 0, 0};
//     set_scale(&src1, 2);
//     s21_mul_10(&src1);
//     s21_decimal src2 = {12345, 0, 0, 0};  // 123,45(12345 / 10^2) = 12,345(12345 / 10^3)
//     set_scale(&src2, 3);
//     ck_assert_float_eq(src1.bits[3], src2.bits[3]);
//     ck_assert_float_eq(src1.bits[2], src2.bits[2]);
//     ck_assert_float_eq(src1.bits[1], src2.bits[1]);
//     ck_assert_float_eq(src1.bits[0], src2.bits[0]);
// }
// END_TEST

