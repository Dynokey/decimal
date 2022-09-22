#include "s21_decimal_test.h"


































































































































START_TEST(scale_eq_02_a) {
    
    s21_decimal src1 = {{40, 0, 0, 0}}; 
    set_scale(&src1, 0);
    s21_decimal src2 = {{2, 0, 0, 0}};
    set_scale(&src2, 1);

    scale_eq(&src1, &src2);  
    
    s21_decimal src1_1 = {{400, 0, 0, 0}};
    set_scale(&src1_1, 1);
    s21_decimal bsrc2_1 = {{2, 0, 0, 0}};
    set_scale(&bsrc2_1, 1);

    
    
    
    
    

    
    
    ck_assert_int_eq(src1.bits[0], src1_1.bits[0]);
    ck_assert_int_eq(src1.bits[1], src1_1.bits[1]);
    ck_assert_int_eq(src1.bits[2], src1_1.bits[2]);
    ck_assert_int_eq(src1.bits[3], src1_1.bits[3]);
} END_TEST

START_TEST(scale_eq_02_b) {
    
    s21_decimal a = {{40, 0, 0, 0}};
    set_scale(&a, 0);
    s21_decimal a_1 = {{400, 0, 0, 0}};
    set_scale(&a_1, 1);
    
    s21_decimal b = {{2, 0, 0, 0}};
    set_scale(&b, 1);
    s21_decimal b_1 = {{2, 0, 0, 0}};
    set_scale(&b_1, 1);
    
    scale_eq(&a, &b);
    
    ck_assert_int_eq(b.bits[0], b_1.bits[0]);
    ck_assert_int_eq(b.bits[1], b_1.bits[1]);
    ck_assert_int_eq(b.bits[2], b_1.bits[2]);
    ck_assert_int_eq(b.bits[3], b_1.bits[3]);
}
END_TEST  

START_TEST(scale_eq_03_a) {
    
    s21_decimal a = {{12345678, 0, 0, 0}};
    set_scale(&a, 0);
    s21_decimal a_1 = {{123456780, 0, 0, 0}};
    set_scale(&a_1, 1);
    
    s21_decimal b = {{12345678, 0, 0, 0}};
    set_scale(&b, 1);
    s21_decimal b_1 = {{12345678, 0, 0, 0}};
    set_scale(&b_1, 1);
    
    scale_eq(&a, &b);
    
    ck_assert_int_eq(a.bits[0], a_1.bits[0]);
    ck_assert_int_eq(a.bits[1], a_1.bits[1]);
    ck_assert_int_eq(a.bits[2], a_1.bits[2]);
    ck_assert_int_eq(a.bits[3], a_1.bits[3]);
}
END_TEST

START_TEST(scale_eq_03_b) {
    
    s21_decimal a = {{12345678, 0, 0, 0}};
    set_scale(&a, 0);
    s21_decimal a_1 = {{12345678, 0, 0, 0}};
    set_scale(&a_1, 1);
    
    s21_decimal b = {{12345678, 0, 0, 0}};
    set_scale(&b, 1);
    s21_decimal b_1 = {{12345678, 0, 0, 0}};
    set_scale(&b_1, 1);
    
    scale_eq(&a, &b);
    
    ck_assert_int_eq(b.bits[0], b_1.bits[0]);
    ck_assert_int_eq(b.bits[1], b_1.bits[1]);
    ck_assert_int_eq(b.bits[2], b_1.bits[2]);
    ck_assert_int_eq(b.bits[3], b_1.bits[3]);
    
}
END_TEST

START_TEST(scale_eq_04_a) {
    
    s21_decimal a = {{12345678, 0, 0, 0}};
    set_scale(&a, 2);
    s21_decimal a_1 = {{1234567800, 0, 0, 0}};
    set_scale(&a_1, 4);
    
    s21_decimal b = {{12345678, 0, 0, 0}};
    set_scale(&b, 4);
    s21_decimal b_1 = {{12345678, 0, 0, 0}};
    set_scale(&b_1, 4);
    
    scale_eq(&a, &b);
    
    ck_assert_int_eq(a.bits[0], a_1.bits[0]);
    ck_assert_int_eq(a.bits[1], a_1.bits[1]);
    ck_assert_int_eq(a.bits[2], a_1.bits[2]);
    ck_assert_int_eq(a.bits[3], a_1.bits[3]);
}
END_TEST

START_TEST(scale_eq_04_b) {
    
    s21_decimal a = {{12345678, 0, 0, 0}};
    set_scale(&a, 2);
    s21_decimal a_1 = {{1234567800, 0, 0, 0}};
    set_scale(&a_1, 4);
    
    s21_decimal b = {{12345678, 0, 0, 0}};
    set_scale(&b, 4);
    s21_decimal b_1 = {{12345678, 0, 0, 0}};
    set_scale(&b_1, 4);
    
    scale_eq(&a, &b);
    
    ck_assert_int_eq(b.bits[0], b_1.bits[0]);
    ck_assert_int_eq(b.bits[1], b_1.bits[1]);
    ck_assert_int_eq(b.bits[2], b_1.bits[2]);
    ck_assert_int_eq(b.bits[3], b_1.bits[3]);
}  
END_TEST

START_TEST(scale_eq_05_a) {
    
    s21_decimal a = {{12345678, 0, 0, 0}};
    set_scale(&a, 4);
    s21_decimal a_1 = {{12345678, 0, 0, 0}};
    set_scale(&a_1, 4);
    
    s21_decimal b = {{12345678, 0, 0, 0}};
    set_scale(&b, 2);
    s21_decimal b_1 = {{1234567800, 0, 0, 0}};
    set_scale(&b_1, 4);
    
    scale_eq(&a, &b);
    
    ck_assert_int_eq(a.bits[0], a_1.bits[0]);
    ck_assert_int_eq(a.bits[1], a_1.bits[1]);
    ck_assert_int_eq(a.bits[2], a_1.bits[2]);
    ck_assert_int_eq(a.bits[3], a_1.bits[3]);
}
END_TEST

START_TEST(scale_eq_05_b) {
    
    s21_decimal a = {{12345678, 0, 0, 0}};
    set_scale(&a, 4);
    s21_decimal a_1 = {{12345678, 0, 0, 0}};
    set_scale(&a_1, 4);
    
    s21_decimal b = {{12345678, 0, 0, 0}};
    set_scale(&b, 2);
    s21_decimal b_1 = {{1234567800, 0, 0, 0}};
    set_scale(&b_1, 4);
    
    scale_eq(&a, &b);
    
    ck_assert_int_eq(b.bits[0], b_1.bits[0]);
    ck_assert_int_eq(b.bits[1], b_1.bits[1]);
    ck_assert_int_eq(b.bits[2], b_1.bits[2]);
    ck_assert_int_eq(b.bits[3], b_1.bits[3]);
}  
END_TEST

START_TEST(scale_eq_06_a) {
    
    s21_decimal a = {{12345678, 0, 0, 0}};
    set_scale(&a, 28);
    s21_decimal a_1 = {{12345678, 0, 0, 0}};
    set_scale(&a_1, 28);
    
    s21_decimal b = {{12345678, 0, 0, 0}};
    set_scale(&b, 27);
    s21_decimal b_1 = {{123456780, 0, 0, 0}};
    set_scale(&b_1, 28);
    
    scale_eq(&a, &b);
    
    ck_assert_int_eq(a.bits[0], a_1.bits[0]);
    ck_assert_int_eq(a.bits[1], a_1.bits[1]);
    ck_assert_int_eq(a.bits[2], a_1.bits[2]);
    ck_assert_int_eq(a.bits[3], a_1.bits[3]);
}
END_TEST

START_TEST(scale_eq_06_b) {
    
    s21_decimal a = {{12345678, 0, 0, 0}};
    set_scale(&a, 28);
    s21_decimal a_1 = {{12345678, 0, 0, 0}};
    set_scale(&a_1, 28);
    
    s21_decimal b = {{12345678, 0, 0, 0}};
    set_scale(&b, 27);
    s21_decimal b_1 = {{123456780, 0, 0, 0}};
    set_scale(&b_1, 28);
    
    scale_eq(&a, &b);
    
    ck_assert_int_eq(b.bits[0], b_1.bits[0]);
    ck_assert_int_eq(b.bits[1], b_1.bits[1]);
    ck_assert_int_eq(b.bits[2], b_1.bits[2]);
    ck_assert_int_eq(b.bits[3], b_1.bits[3]);

    
}
END_TEST

START_TEST(scale_eq_07_a) {
    
    s21_decimal a = {{10, 0, 0, 0}};
    set_scale(&a, 28);
    s21_decimal a_1 = {{10, 0, 0, 0}};
    set_scale(&a_1, 28);
    
    s21_decimal b = {{12345678, 0, 0, 0}};
    set_scale(&b, 27);
    s21_decimal b_1 = {{123456780, 0, 0, 0}};
    set_scale(&b_1, 28);
    
    scale_eq(&a, &b);
    
    ck_assert_int_eq(a.bits[0], a_1.bits[0]);
    ck_assert_int_eq(a.bits[1], a_1.bits[1]);
    ck_assert_int_eq(a.bits[2], a_1.bits[2]);
    ck_assert_int_eq(a.bits[3], a_1.bits[3]);
}
END_TEST

START_TEST(scale_eq_07_b) {
    
    s21_decimal a = {{10, 0, 0, 0}};
    set_scale(&a, 28);
    s21_decimal a_1 = {{10, 0, 0, 0}};
    set_scale(&a_1, 28);
    
    s21_decimal b = {{12345678, 0, 0, 0}};
    set_scale(&b, 27);
    s21_decimal b_1 = {{123456780, 0, 0, 0}};
    set_scale(&b_1, 28);
    
    scale_eq(&a, &b);
    
    ck_assert_int_eq(b.bits[0], b_1.bits[0]);
    ck_assert_int_eq(b.bits[1], b_1.bits[1]);
    ck_assert_int_eq(b.bits[2], b_1.bits[2]);
    ck_assert_int_eq(b.bits[3], b_1.bits[3]);
    
}
END_TEST

START_TEST(scale_eq_08_a) {
    
    s21_decimal a = {{10, 0, 0, 0}};
    set_scale(&a, 20);
    s21_decimal a_1 = {{1000000000, 0, 0, 0}};
    set_scale(&a_1, 28);
    
    s21_decimal b = {{12345678, 0, 0, 0}};
    set_scale(&b, 28);
    s21_decimal b_1 = {{12345678, 0, 0, 0}};
    set_scale(&b_1, 28);
    
    scale_eq(&a, &b);
    
    ck_assert_int_eq(a.bits[0], a_1.bits[0]);
    ck_assert_int_eq(a.bits[1], a_1.bits[1]);
    ck_assert_int_eq(a.bits[2], a_1.bits[2]);
    ck_assert_int_eq(a.bits[3], a_1.bits[3]);
}
END_TEST

START_TEST(scale_eq_08_b) {
    
    s21_decimal a = {{10, 0, 0, 0}};
    set_scale(&a, 20);
    s21_decimal a_1 = {{1000000000, 0, 0, 0}};
    set_scale(&a_1, 28);
    
    s21_decimal b = {{12345678, 0, 0, 0}};
    set_scale(&b, 28);
    s21_decimal b_1 = {{12345678, 0, 0, 0}};
    set_scale(&b_1, 28);
    
    scale_eq(&a, &b);
    
    ck_assert_int_eq(b.bits[0], b_1.bits[0]);
    ck_assert_int_eq(b.bits[1], b_1.bits[1]);
    ck_assert_int_eq(b.bits[2], b_1.bits[2]);
    ck_assert_int_eq(b.bits[3], b_1.bits[3]);
    
}
END_TEST

START_TEST(scale_eq_09) {
    
    
    
    
    s21_decimal a = {{MAX_INT, 0, 0, 0}};
    set_scale(&a, 27);  
    s21_decimal a_1 = {{4294967286, 4, 0, 0}};
    set_scale(&a_1, 28);
    
    s21_decimal b = {{12345678, 0, 0, 0}};
    set_scale(&b, 28);
    s21_decimal b_1 = {{12345678, 0, 0, 0}};
    set_scale(&b_1, 28);
    
    scale_eq(&a, &b);
    
    ck_assert_int_eq(a.bits[0], a_1.bits[0]);
    ck_assert_int_eq(a.bits[1], a_1.bits[1]);
    ck_assert_int_eq(a.bits[2], a_1.bits[2]);
    ck_assert_int_eq(a.bits[3], a_1.bits[3]);
}  
END_TEST

START_TEST(scale_eq_10) {
    
    
    
    
    s21_decimal a = {{UINT32_MAX, 0, 0, 0}};
    set_scale(&a, 27);
    s21_decimal a_1 = {{4294967286, 9, 0, 0}};
    set_scale(&a_1, 28);
    
    s21_decimal b = {{12345678, 0, 0, 0}};
    set_scale(&b, 28);
    s21_decimal b_1 = {{12345678, 0, 0, 0}};
    set_scale(&b_1, 28);
    
    scale_eq(&a, &b);
    
    ck_assert_int_eq(a.bits[0], a_1.bits[0]);
    ck_assert_int_eq(a.bits[1], a_1.bits[1]);
    ck_assert_int_eq(a.bits[2], a_1.bits[2]);
    ck_assert_int_eq(a.bits[3], a_1.bits[3]);
}  
END_TEST

START_TEST(scale_eq_11) {
    
    
    
    
    
    
    s21_decimal a = {{UINT32_MAX, UINT32_MAX, 0, 0}};
    set_scale(&a, 27);
    s21_decimal a_1 = {{4294967286, UINT32_MAX, 9, 0}};
    set_scale(&a_1, 28);
    
    s21_decimal b = {{12345678, 0, 0, 0}};
    set_scale(&b, 28);
    s21_decimal b_1 = {{12345678, 0, 0, 0}};
    set_scale(&b_1, 28);
    
    scale_eq(&a, &b);
    
    ck_assert_int_eq(a.bits[0], a_1.bits[0]);
    ck_assert_int_eq(a.bits[1], a_1.bits[1]);
    ck_assert_int_eq(a.bits[2], a_1.bits[2]);
    ck_assert_int_eq(a.bits[3], a_1.bits[3]);
}  
END_TEST

START_TEST(scale_eq_12) {
    
    
    
    
    
    
    s21_decimal a = {{UINT32_MAX, UINT32_MAX, 0, 0}};
    set_scale(&a, 20);
    s21_decimal a_1 = {{0b11111010000010100001111100000000,
                        0b11111111111111111111111111111111,
                        0b00000101111101011110000011111111, 0}};
    set_scale(&a_1, 28);
    
    s21_decimal b = {{12345678, 0, 0, 0}};
    set_scale(&b, 28);
    s21_decimal b_1 = {{12345678, 0, 0, 0}};
    set_scale(&b_1, 28);
    
    scale_eq(&a, &b);
    
    ck_assert_int_eq(a.bits[0], a_1.bits[0]);
    ck_assert_int_eq(a.bits[1], a_1.bits[1]);
    ck_assert_int_eq(a.bits[2], a_1.bits[2]);
    ck_assert_int_eq(a.bits[3], a_1.bits[3]);
}  
    
END_TEST

START_TEST(scale_eq_14) {
    
    s21_decimal a = {{UINT32_MAX, UINT32_MAX, UINT32_MAX, 0}};  
    set_scale(&a, 28);
    s21_decimal b = {{UINT32_MAX, UINT32_MAX, UINT32_MAX, 0}};
    set_scale(&b, 27);
    
    s21_decimal a_1 = {{0b01100011010001100000000000000000, 0b10011001100110010111101011100101, 0b11001100110011001100110011001, 0}};
    set_scale(&a_1, 27);
    s21_decimal b_1 = {{UINT32_MAX, UINT32_MAX, UINT32_MAX, 0}};
    set_scale(&b_1, 27);
    
    scale_eq(&a, &b);
    
    
    
    
    
    
    
    ck_assert_int_eq(a.bits[0], a_1.bits[0]);
    ck_assert_int_eq(a.bits[1], a_1.bits[1]);
    ck_assert_int_eq(a.bits[2], a_1.bits[2]);
    ck_assert_int_eq(a.bits[3], a_1.bits[3]);
}  
    
END_TEST













START_TEST(scale_eq_15) {  
    
    s21_decimal a = {UINT32_MAX, UINT32_MAX, UINT32_MAX, 0};
    s21_decimal b = {UINT32_MAX, UINT32_MAX, UINT32_MAX, 0};
    set_scale(&a, 28);
    set_scale(&b, 0);
    
    s21_decimal a_1 = {{7, 0, 0, 0}};
    set_scale(&a_1, 0);
    s21_decimal b_1 = {{UINT32_MAX, UINT32_MAX, UINT32_MAX, 0}};
    set_scale(&b_1, 0);
    
    scale_eq(&a, &b);
    
    
    
    
    
    
    
    ck_assert_int_eq(a.bits[0], a_1.bits[0]);
    ck_assert_int_eq(a.bits[1], a_1.bits[1]);
    ck_assert_int_eq(a.bits[2], a_1.bits[2]);
    ck_assert_int_eq(a.bits[3], a_1.bits[3]);
}  
   
END_TEST
/*
в этом тесте подается 



*/

START_TEST(scale_eq_16) {  
    
    s21_decimal a = {UINT32_MAX, UINT32_MAX, UINT32_MAX, 0};
    s21_decimal b = {UINT32_MAX, UINT32_MAX, UINT32_MAX, 0};
    set_scale(&a, 28);
    set_scale(&b, 26);
    
    s21_decimal a_1 = {{7, 0, 0, 0}};
    set_scale(&a_1, 0);
    s21_decimal b_1 = {{UINT32_MAX, UINT32_MAX, UINT32_MAX, 0}};
    set_scale(&b_1, 0);
    
    scale_eq(&a, &b);
    
    
    
    
    
    
    
    ck_assert_int_eq(a.bits[0], a_1.bits[0]);
    ck_assert_int_eq(a.bits[1], a_1.bits[1]);
    ck_assert_int_eq(a.bits[2], a_1.bits[2]);
    ck_assert_int_eq(a.bits[3], a_1.bits[3]);
}  
   
END_TEST
/*
в этом тесте подается 



*/

