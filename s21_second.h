#ifndef SRC_S21_SECOND_H_
#define SRC_S21_SECOND_H_
#include "s21_decimal.h"

#define SIZE 32
#define RESET "\033[0m"
#define RED "\033[1;31m"
#define YELLOW "\033[1;33m"
#define WHITE "\033[1;37m"
#define GREEN "\033[1;32m"
#define BLUE "\033[1;34m"
#define BLUE_P "\033[1;45m"

#define S21_TRUE 1
#define S21_FALSE 0
#define TRUE 1
#define FALSE 0
#define CONVERTERS_S21_TRUE 0
#define CONVERTERS_S21_FALSE 1
#define U_MAX_INT 4294967295          // 0b11111111111111111111111111111111
#define S21_MAX_UINT 4294967295       // 0b11111111111111111111111111111111
#define MAX_INT 2147483647            // 0b01111111111111111111111111111111
#define EXPONENT_MINUS_1 2147549184   // 0b10000000000000010000000000000000
#define EXPONENT_PLUS_1 65536         // 0b00000000000000010000000000000000
#define EXPONENT_PLUS_2 196608        // 0b00000000000000110000000000000000
#define EXPONENT_MINUS_28 2149318656  // 0b10000000000111000000000000000000
#define EXPONENT_PLUS_28 1835008      // 0b00000000000111000000000000000000
#define MINUS 2147483648              // 0b10000000000000000000000000000000
#define MAX_DECIMAL 79228162514264337593543950335.0F
#define MIN_DECIMAL -79228162514264337593543950335.0F

typedef struct {
    unsigned int bits[4];
} s21_decimal;

s21_decimal set_bit(s21_decimal d, int x);
void show_bit(s21_decimal a);
void p_set_bit(s21_decimal *d, int x);
void bit_operations(int, int);
void show_int_to_bit(int);
void set_minus(s21_decimal *dst);
void set_plus(s21_decimal *dst);
void empty_struct(s21_decimal *dst);
int get_bit(s21_decimal d, int x);
int scale(s21_decimal);
void set_scale(s21_decimal *d, int a);
int scale_plus(s21_decimal *d);
void copy_dec(s21_decimal value, s21_decimal *result);
int get_scale(const s21_decimal *varPtr);
int p_decimal_err(s21_decimal *value);
int decimal_err(s21_decimal value);
int get_sign(s21_decimal *dst);
// int normalize_new(s21_decimal *number1, s21_decimal *number2);
void s21_div10(s21_decimal *value);
int s21_mul_10(s21_decimal *a);
int s21_decimal_sub_simple(s21_decimal var1, s21_decimal var2, s21_decimal *result);
int s21_decimal_add_simple(s21_decimal var1, s21_decimal var2, s21_decimal *result);

s21_decimal clean_bit(s21_decimal one, int x);
void set_bit_s12(s21_decimal *d, int bit, int a);
int is_greater(s21_decimal value1, s21_decimal value2);
int is_equal(s21_decimal value1, s21_decimal value2);
int overflow(s21_decimal *var);

void set_bit_new(s21_decimal *number, int bit, int sign);
int shift_left_new(s21_decimal *number);
int shift_right_new(s21_decimal *number);
void initial_num_new(s21_decimal *number);
int s21_add_simple_new(s21_decimal dec1, s21_decimal dec2, s21_decimal *result);
s21_decimal s21_div_simple_new(s21_decimal dec1, s21_decimal dec2, s21_decimal *result);
int s21_is_less_simple_new(s21_decimal dec1, s21_decimal dec2);
int s21_is_equal_simple_new(s21_decimal dec1, s21_decimal dec2);
int s21_is_greater_simple_new(s21_decimal dec1, s21_decimal dec2);
int s21_is_greater_or_equal_simple_new(s21_decimal dec1, s21_decimal dec2);
int get_sign_new(s21_decimal number);
void set_sign_new(s21_decimal *number, int sign);
int s21_mul_simple_new(s21_decimal dec1, s21_decimal dec2, s21_decimal *result);
int s21_is_less_or_equal_simple_new(s21_decimal dec1, s21_decimal dec2);
void s21_sub_simple_new(s21_decimal dec1, s21_decimal dec2, s21_decimal *result);
void s21_bank_round_new(s21_decimal *value, int count);
void scale_eq(s21_decimal *dec1, s21_decimal *dec2);
int scale_eq2(s21_decimal* number1, s21_decimal* number2);

#endif  // SRC_S21_SECOND_H_
