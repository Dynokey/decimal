#include "s21_decimal.h"

// обнулить децимал
void empty_struct(s21_decimal* dst) { dst->bits[0] = dst->bits[1] = dst->bits[2] = dst->bits[3] = 0; }
// устанавливает в нужный бит 1 возвращает измененную структуру
s21_decimal set_bit(s21_decimal one, int x) {
    int num = x / SIZE;
    unsigned int tmp = one.bits[num];
    s21_decimal res = one;
    res.bits[num] = tmp | ~(~0u << 1) << x % SIZE;
    return res;
}
// получить значение нужного бита
int get_bit(s21_decimal one, int x) {
    int num = x / SIZE;
    int tmp = one.bits[num];
    int res = tmp & ~(~0u << 1) << x % SIZE;
    return res == 0 ? 0 : 1;
}
// двоичное представление s21_decimal
void show_bit(s21_decimal a) {
    printf("%s--------------%s\n", BLUE_P, RESET);
    for (int i = 0; i < 4; i++) {
        int arr[SIZE];
        unsigned int tmp = a.bits[i];
        for (int j = SIZE - 1; j >= 0; j--) {
            arr[j] = tmp % 2;
            tmp = tmp / 2;
        }
        for (int f = 0; f < SIZE; f++) {
            if (arr[f] == 1)
                printf("%s%d%s", RED, arr[f], RESET);
            else
                printf("%s%d%s", YELLOW, arr[f], RESET);
        }
        printf("\n");
    }
}

void show_bit_l(s21_decimal a) {
    printf("%s-----------  0%s\n", BLUE_P, RESET);
    for (int c = 0; c <= 3; c++) {
        for (int i = SIZE - 1; i >= 0; i--) {
            if ((a.bits[c] >> i) & 1)
                printf("%s%d%s", RED, 1, RESET);
            else
                printf("%s%d%s", GREEN, 0, RESET);
        }
        printf("\n");
    }
}
// результат битовой операции с двумя int
void bit_operations(int a, int b) {
    int num = 1;
    printf("\"%d | %d\" = %d\n", a, b, a | b);
    printf("\"%d ^ %d\" = %d\n", a, b, a ^ b);
    printf("\"%d & %d\" = %d\n", a, b, a & b);
    printf("\"~ %d\" = %d\n", a, (unsigned char)~a);
    printf("\"%d >> %d\" = %d\n", a, num, a >> num);
    printf("\"%d << %d\" = %d\n", a, num, a << num);
}
// двоичное представление int
void show_int_to_bit(int a) {
    int num = a;
    int arr[SIZE] = {0};
    for (int i = SIZE - 1; i >= 0; i--) {
        arr[i] = num % 2;
        num = num / 2;
    }
    for (int i = 0; i < SIZE; i++) {
        if (arr[i] == 1)
            printf("%s%d%s", RED, arr[i], RESET);
        else
            printf("%s%d%s", YELLOW, arr[i], RESET);
    }
    printf("\n");
}
// степень числа из двоичного в десятичное
int scale(s21_decimal src) {
    int res = 0;
    for (int i = 112; i < 118; i++) {  // i < 118 ????
        int bit = get_bit(src, i);
        if (bit) res += pow(2, i - 112);
    }
    return res;
}

// устанавливает в нужный бит 1 меняя стуктуру по указателю
void p_set_bit(s21_decimal* one, int x) {
    int num = x / SIZE;
    unsigned int tmp = one->bits[num];
    one->bits[num] = tmp | ~(~0u << 1) << x % SIZE;
}
// сделать децимал положительным
void set_plus(s21_decimal* dst) {
    int num = 127 / SIZE;
    int tmp = dst->bits[num];
    dst->bits[num] = tmp & ~(~(~0u << 1) << 127 % SIZE);
}
// сделать децимал отрицательным
void set_minus(s21_decimal* dst) {
    int num = 127 / SIZE;
    int tmp = dst->bits[num];
    dst->bits[num] = tmp | ~(~0u << 1) << 127 % SIZE;
}
// устанавливает в децимал d степень а
void set_scale(s21_decimal* p_one, int a) {
    p_one->bits[3] = p_one->bits[3] & (~0u << 24);  // обнуляем биты с 0 до 23
    // show_bit(*p_one);
    int num = a;
    for (int i = 112; i < 119; i++) {
        if (num % 2 == 1) {
            p_set_bit(p_one, i);
        }
        num = num / 2;
    }
}
/* увеличивает степень в переменной 'd' на число 'а'
 * меняя значение 'd' сдвигом умножая на 10 */
int scale_plus(s21_decimal* a) {
    int scl_a = get_scale(a);
    s21_decimal a_shift_3 = *a;  // эту переменную будем по-байтов двигать на 3 бита
    s21_decimal a_shift_1 = *a;  // эту переменную будем по-байтов двигать на 1 бит

    unsigned int a_mask_3_0 = 0;
    unsigned int a_mask_1_0 = 0;
    a_mask_3_0 = a_shift_3.bits[0] & (~0u << 29);  // маской запоминаем 3 последних бита в нулевом байте
    a_mask_1_0 = a_shift_1.bits[0] & (~0u << 31);  // маской запоминаем 1 последний бит в нулевом байте

    a_shift_3.bits[0] = a_shift_3.bits[0] << 3;  // сдвигаем нулевой байт на 3 бита
    a_shift_1.bits[0] = a_shift_1.bits[0] << 1;  // сдвигаем нулевой байт на 1 бит

    unsigned int a_mask_3_1 = 0;
    unsigned int a_mask_1_1 = 0;
    a_mask_3_1 = a_shift_3.bits[1] & (~0u << 29);  // маской запоминаем 3 последних бита в первом байте
    a_mask_1_1 = a_shift_1.bits[1] & (~0u << 31);  // маской запоминаем 1 последний бит в первом байте

    a_shift_3.bits[1] = a_shift_3.bits[1] << 3;  // сдвигаем первый байт на 3 бита
    a_shift_1.bits[1] = a_shift_1.bits[1] << 1;  // сдвигаем первый байт на 1 бит

    a_mask_3_0 = a_mask_3_0 >> 29;
    a_mask_1_0 = a_mask_1_0 >> 31;
    a_shift_3.bits[1] = a_shift_3.bits[1] | a_mask_3_0;  // записываем в младшие 3 бита значение
                                                         // из маски нулевого бита
    a_shift_1.bits[1] = a_shift_1.bits[1] | a_mask_1_0;  // записываем в младшие 3 бита значение
                                                         // из маски нулевого бита

    a_shift_3.bits[2] = a_shift_3.bits[2] << 3;  // сдвигаем второй байт на 3 бита
    a_shift_1.bits[2] = a_shift_1.bits[2] << 1;  // сдвигаем второй байт на 1 бит

    a_mask_3_1 = a_mask_3_1 >> 29;
    a_mask_1_1 = a_mask_1_1 >> 31;
    a_shift_3.bits[2] =
        a_shift_3.bits[2] | a_mask_3_1;  // записываем в младшие 3 бита значение из маски первого бита
    a_shift_1.bits[2] =
        a_shift_1.bits[2] | a_mask_1_1;  // записываем в младшие 3 бита значение из маски первого бита

    s21_decimal add_res = {{0, 0, 0, 0}};
    s21_decimal* p_add_res = &add_res;
    s21_add(a_shift_3, a_shift_1, p_add_res);
    set_scale(p_add_res, scl_a + 1);
    *a = add_res;
    return 0;
}

void copy_dec(s21_decimal value, s21_decimal* result) {
    result->bits[0] = value.bits[0];
    result->bits[1] = value.bits[1];
    result->bits[2] = value.bits[2];
    int scale = get_scale(&value);
    set_scale(result, scale);
    get_sign(&value) ? set_minus(result) : set_plus(result);
}
// ошибки

int decimal_err(s21_decimal value) {
    int res = 0;
    if (scale(value) > 28) res = 1;
    return res;
}

int p_decimal_err(s21_decimal* value) {
    int res = 0;
    if (value == NULL) res = 1;
    if (scale(*value) > 28) res = 1;
    return res;
}
// получить степень
int get_scale(const s21_decimal* varPtr) { return (char)(varPtr->bits[3] >> 16); }

// получить знак
int get_sign(s21_decimal* dst) {
    int num = 127 / SIZE;
    int tmp = dst->bits[num];
    int res = tmp & ~(~0u << 1) << 127 % SIZE;
    return res == 0 ? 0 : 1;
}

// уменьшение степени, путем деления
void s21_div10(s21_decimal* value) {
    int bmod;
    unsigned long long buf;
    buf = value->bits[2];
    for (int j = 2; j > 0;) {
        bmod = buf % 10;
        value->bits[j] = buf / 10;
        j--;
        buf = bmod * (U_MAX_INT + 1) + value->bits[j];
        if (j == 0) value->bits[j] = buf / 10;
    }
    set_scale(value, (get_scale(value) - 1));
}

// сбрасывает нужный бит в 0 возвращает новую структуру
s21_decimal clean_bit(s21_decimal one, int x) {
    int num = x / SIZE;
    unsigned int tmp = one.bits[num];
    s21_decimal res = one;
    res.bits[num] = tmp & ~(~(~0u << 1) << x % SIZE);
    return res;
}

void set_bit_s12(s21_decimal* d, int bit, int a) {
    unsigned int mask = 1u << (bit % 32);
    if (bit / 32 < 4 && a) {
        d->bits[bit / 32] |= mask;
    } else if (bit / 32 < 4 && !a) {
        d->bits[bit / 32] &= ~mask;
    }
}

// увеличение степени путем умножения на 10
int s21_mul_10(s21_decimal* a) {
    int res = 0;
    int scl_a = scale(*a);
    if (scl_a >= 28) {
        res = 1;
    } else {
        s21_decimal a_shift_3 = *a;  // эту переменную будем по-байтов двигать на 3 бита
        s21_decimal a_shift_1 = *a;  // эту переменную будем по-байтов двигать на 1 бит

        unsigned int a_mask_3_0 = 0;
        unsigned int a_mask_1_0 = 0;
        a_mask_3_0 = a_shift_3.bits[0] & (~0u << 29);  // маской запоминаем 3 последних бита в нулевом байте
        a_mask_1_0 = a_shift_1.bits[0] & (~0u << 31);  // маской запоминаем 1 последний бит в нулевом байте

        a_shift_3.bits[0] = a_shift_3.bits[0] << 3;  // сдвигаем нулевой байт на 3 бита
        a_shift_1.bits[0] = a_shift_1.bits[0] << 1;  // сдвигаем нулевой байт на 1 бит

        unsigned int a_mask_3_1 = 0;
        unsigned int a_mask_1_1 = 0;
        a_mask_3_1 = a_shift_3.bits[1] & (~0u << 29);  // маской запоминаем 3 последних бита в первом байте
        a_mask_1_1 = a_shift_1.bits[1] & (~0u << 31);  // маской запоминаем 1 последний бит в первом байте

        a_shift_3.bits[1] = a_shift_3.bits[1] << 3;  // сдвигаем первый байт на 3 бита
        a_shift_1.bits[1] = a_shift_1.bits[1] << 1;  // сдвигаем первый байт на 1 бит

        a_mask_3_0 = a_mask_3_0 >> 29;
        a_mask_1_0 = a_mask_1_0 >> 31;
        a_shift_3.bits[1] =
            a_shift_3.bits[1] | a_mask_3_0;  // записываем в младшие 3 бита значение из маски нулевого бита
        a_shift_1.bits[1] =
            a_shift_1.bits[1] | a_mask_1_0;  // записываем в младшие 3 бита значение из маски нулевого бита

        a_shift_3.bits[2] = a_shift_3.bits[2] << 3;  // сдвигаем второй байт на 3 бита
        a_shift_1.bits[2] = a_shift_1.bits[2] << 1;  // сдвигаем второй байт на 1 бит

        a_mask_3_1 = a_mask_3_1 >> 29;
        a_mask_1_1 = a_mask_1_1 >> 31;
        a_shift_3.bits[2] =
            a_shift_3.bits[2] | a_mask_3_1;  // записываем в младшие 3 бита значение из маски первого бита
        a_shift_1.bits[2] =
            a_shift_1.bits[2] | a_mask_1_1;  // записываем в младшие 3 бита значение из маски первого бита

        s21_decimal add_res = {{0, 0, 0, 0}};
        add_res.bits[3] = a_shift_3.bits[3];
        s21_decimal* p_add_res = &add_res;
        s21_decimal_add_simple(a_shift_3, a_shift_1, p_add_res);
        set_scale(p_add_res, scl_a + 1);
        *a = add_res;
    }
    return res;
}

int is_greater(s21_decimal value1, s21_decimal value2) {  // Больше без учета знака
    int res = 0;

    if (value1.bits[2] > value2.bits[2])
        res = 1;
    else if (value1.bits[2] < value2.bits[2])
        res = 0;
    else if (value1.bits[1] > value2.bits[1])
        res = 1;
    else if (value1.bits[1] < value2.bits[1])
        res = 0;
    else if (value1.bits[0] > value2.bits[0])
        res = 1;
    else if (value1.bits[0] < value2.bits[0])
        res = 0;

    return res;
}

int is_equal(s21_decimal value1, s21_decimal value2) {  // Равенство без учета знака
    int res = 1;
    s21_decimal tmp_a = value1;
    s21_decimal tmp_b = value2;

    for (int i = 0; i < 3; i++) {
        if ((tmp_a.bits[i] ^ tmp_b.bits[i]) != 0) {  // аналог tmp_a.bits[i] != tmp_b.bits[i]
            res = 0;
            break;
        }
    }
    return res;
}

int overflow(s21_decimal* var) {
    // Округление и надо ли
    s21_div10(var);
    return 0;
}
// _____________________set_bit_new устанавливает в bit(номер бита) sing(0 или 1)
void set_bit_new(s21_decimal* number, int bit, int sign) {
    if (sign == 0) {
        number->bits[bit / 32] = number->bits[bit / 32] & ~(1 << bit % 32);
    } else {
        number->bits[bit / 32] = number->bits[bit / 32] | (1 << bit % 32);
    }
}
// двигает весь децимал побитово на один шаг влево
int shift_left_new(s21_decimal* number) {
    int is_overflow = get_bit(*number, 95);
    for (int i = 95; i >= 0; i--) {
        if (i != 0) {
            set_bit_new(number, i, get_bit(*number, i - 1));
        } else {
            set_bit_new(number, i, 0);
        }
    }
    return is_overflow;
}

// двигает весь децимал побитово на один шаг вправо
int shift_right_new(s21_decimal* number) {
    int is_overflow = get_bit(*number, 1);
    for (int i = 0; i < 96; i++) {
        if (i != 95) {
            set_bit_new(number, i, get_bit(*number, i + 1));
        } else {
            set_bit_new(number, i, 0);
        }
    }
    return is_overflow;
}

// инициализирует децимал нулями
void initial_num_new(s21_decimal* number) {
    for (int i = 0; i < 128; i++) {
        set_bit_new(number, i, 0);
    }
}

int s21_add_simple_new(s21_decimal dec1, s21_decimal dec2, s21_decimal* result) {
    initial_num_new(result);
    int rank = 0;
    for (int i = 0; i < 96; i++) {
        int bit_dec1 = get_bit(dec1, i);
        int bit_dec2 = get_bit(dec2, i);
        set_bit_new(result, i, bit_dec1 ^ bit_dec2 ^ rank);
        rank = (bit_dec1 && bit_dec2) || (bit_dec1 && rank) || (bit_dec2 && rank);
    }
    return rank;
}

s21_decimal s21_div_simple_new(s21_decimal dec1, s21_decimal dec2, s21_decimal* result) {
    if (result) initial_num_new(result);
    s21_decimal fmod = {0};
    s21_decimal temp = {0};
    if (s21_is_greater_or_equal_simple_new(dec1, dec2)) set_bit_new(&temp, 0, 1);
    if (!s21_is_greater_simple_new(dec2, dec1)) {
        while (1) {
            s21_decimal copy_dec2 = dec2;
            while (s21_is_greater_or_equal_simple_new(dec1, copy_dec2) &&
                   !(get_bit(dec1, 95) && get_bit(copy_dec2, 95))) {
                shift_left_new(&copy_dec2);
                shift_left_new(&temp);
            }

            if (!(get_bit(dec1, 95) && get_bit(copy_dec2, 95)) ||
                (s21_is_greater_or_equal_simple_new(copy_dec2, dec1))) {
                shift_right_new(&copy_dec2);
                shift_right_new(&temp);
            }

            s21_sub_simple_new(dec1, copy_dec2, &dec1);
            if (result) s21_add_simple_new(*result, temp, result);
            initial_num_new(&temp);
            set_bit_new(&temp, 0, 1);
            if (s21_is_less_simple_new(dec1, dec2)) {
                break;
            }
        }
    }
    fmod = dec1;
    return fmod;
}

int s21_is_less_simple_new(s21_decimal dec1, s21_decimal dec2) {
    int is_less = 0;
    for (int i = 95; i >= 0; i--) {
        if (get_bit(dec1, i) ^ get_bit(dec2, i)) {
            is_less = get_bit(dec2, i);
            break;
        }
    }

    return is_less;
}

int s21_is_equal_simple_new(s21_decimal dec1, s21_decimal dec2) {
    int is_equal = 1;
    for (int i = 95; i >= 0; i--) {
        if (get_bit(dec1, i) != get_bit(dec2, i)) {
            is_equal = 0;
            break;
        }
    }
    return is_equal;
}

int s21_is_greater_simple_new(s21_decimal dec1, s21_decimal dec2) {
    return !s21_is_less_or_equal_simple_new(dec1, dec2);
}

int s21_is_greater_or_equal_simple_new(s21_decimal dec1, s21_decimal dec2) {
    return s21_is_greater_simple_new(dec1, dec2) || s21_is_equal_simple_new(dec1, dec2);
}

int s21_mul_simple_new(s21_decimal dec1, s21_decimal dec2, s21_decimal* result) {
    s21_decimal tmp;
    initial_num_new(&tmp);
    int is_owerfull = 0;
    for (int i = 0; i < 96 && !is_owerfull; i++) {
        if (get_bit(dec2, i) == 1) {
            s21_decimal temp = dec1;
            int k = 0;
            while (k < i) {
                if (shift_left_new(&temp)) {
                    is_owerfull = 1;
                    break;
                }
                k++;
            }
            if (is_owerfull || (is_owerfull = s21_add_simple_new(temp, tmp, &tmp))) {
                break;
            }
        }
    }

    if (!is_owerfull) *result = tmp;

    return is_owerfull;
}

void s21_bank_round_new(s21_decimal* value, int count) {
    int system_bit = value->bits[3];
    int exp = scale(*value) - count;
    while (count > 0) {
        s21_decimal base = {0}, one = {0}, two = {0}, two_res = {0};
        s21_from_int_to_decimal(10, &base);
        s21_from_int_to_decimal(1, &one);
        s21_from_int_to_decimal(2, &two);
        s21_decimal dec_mod = s21_div_simple_new(*value, base, value);
        if (dec_mod.bits[0] > 5) {
            s21_add_simple_new(*value, one, value);
        } else if (dec_mod.bits[0] == 5) {
            two_res = s21_div_simple_new(*value, two, NULL);
            if (s21_is_equal_simple_new(one, two_res)) s21_add_simple_new(*value, one, value);
        }
        count--;
    }
    value->bits[3] = system_bit;
    set_scale(value, exp);
}

int get_sign_new(s21_decimal number) {
    int sign;
    if ((number.bits[3] & (1u << 31)) == 0) {
        sign = 0;
    } else {
        sign = 1;
    }
    return sign;
}

// set_sing ставит знак в децимал, можно заменить нашими двумя функциями
// set_plus  и set_minus
void set_sign_new(s21_decimal* number, int sign) {
    if (sign == 0) {
        number->bits[3] = number->bits[3] & ~(1u << 31);
    } else {
        number->bits[3] = number->bits[3] | (1u << 31);
    }
}

int s21_is_less_or_equal_simple_new(s21_decimal dec1, s21_decimal dec2) {
    return s21_is_less_simple_new(dec1, dec2) || s21_is_equal_simple_new(dec1, dec2);
}

void s21_sub_simple_new(s21_decimal dec1, s21_decimal dec2, s21_decimal* result) {
    initial_num_new(result);
    for (int i = 0; i < 96; i++) {
        int bit_dec1 = get_bit(dec1, i);
        int bit_dec2 = get_bit(dec2, i);

        set_bit_new(result, i, bit_dec1 ^ bit_dec2);

        if (!bit_dec1 && bit_dec2) {
            int k = i + 1;
            while ((bit_dec1 = get_bit(dec1, k)) != 1) {
                set_bit_new(&dec1, k, 1);
                k++;
            }
            set_bit_new(&dec1, k, 0);
        }
    }
}

void scale_eq(s21_decimal* number1, s21_decimal* number2) {
    if (get_scale(number1) < get_scale(number2)) {
        while (get_scale(number1) != get_scale(number2)) {
            if (number1->bits[2] < MAX_INT / 10)
                scale_plus(number1);
            else
                s21_bank_round_new(number2, get_scale(number2) - get_scale(number1));
        }
    } else {
        while (get_scale(number1) != get_scale(number2)) {
            if (number2->bits[2] < MAX_INT / 10)
                scale_plus(number2);
            else
                s21_bank_round_new(number1, get_scale(number1) - get_scale(number2));
        }
    }
}

int scale_eq2(s21_decimal* number1, s21_decimal* number2) {
    if (get_scale(number1) < get_scale(number2)) {
        while (get_scale(number1) != get_scale(number2)) {
            if (number1->bits[2] < MAX_INT / 10)
                scale_plus(number1);
            else
                s21_bank_round_new(number2, get_scale(number2) - get_scale(number1));
        }
    } else {
        while (get_scale(number1) != get_scale(number2)) {
            if (number2->bits[2] < MAX_INT / 10)
                scale_plus(number2);
            else
                s21_bank_round_new(number1, get_scale(number1) - get_scale(number2));
        }
    }

    return 0;
}
