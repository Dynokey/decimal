CCF=gcc #-Wextra -Wall -Werror
CC=gcc #-g -fsanitize=address
CFLAGS=#-g -fsanitize=address -Wextra -Wall -Werror
GCOV_FLAGS=-fprofile-arcs -ftest-coverage -lgcov
CHECK_FLAGS=-lcheck -lm -lpthread
ALL_FLAGS=$(CFLAGS) $(GCOV_FLAGS) $(CHECK_FLAGS)

SRCS = s21_add.c\
	s21_add_simple.c\
	s21_sub_simple.c\
	s21_from_decimal_to_float.c\
	s21_from_decimal_to_int.c\
	s21_from_int_to_decimal.c\
	s21_from_float_to_decimal.c\
	s21_is_equal.c\
	s21_is_not_equal.c\
	s21_is_greater_or_equal.c\
	s21_is_greater.c\
	s21_is_less_or_equal.c\
	s21_is_less.c\
	s21_mod.c\
	s21_mul.c\
	s21_div.c\
	s21_round.c\
	s21_second_func.c\
	s21_negate.c\
	s21_floor.c\
	s21_sub.c\
	s21_truncate.c\

OBJS = $(SRCS:.c=.o) ./tests/main_test.c
OBJST = $(SRCS:.c=.o)
NAME = test
REPORT_NAME = report

all: objs s21_decimal.a test

test: $(OBJS)
	$(CCF) $(CHECK_FLAGS) $(OBJS) -o $(NAME)
	./test

clean:
	rm -rf $(OBJST)
	rm -rf *.o
	rm -rf *.out
	rm -rf *.dSYM
	rm -rf *.gcno
	rm -rf *.gcda
	rm -rf *.info
	rm -rf *.a
	rm -rf $(REPORT_NAME)
	rm -rf *.log
	rm -rf test


objs: $(SRCS)
	$(CC) $(CFLAGS) -c $(SRCS) 

s21_decimal.a: objs
	ar rc s21_decimal.a $(OBJST)
	ranlib s21_decimal.a

gcov_report:
	$(CCF) -o $(NAME) $(SRCS) ./tests/main_test.c $(GCOV_FLAGS) $(CHECK_FLAGS)
	./$(NAME)
	lcov -t "gcov_report" -o tests.info -c -d .
	genhtml -o $(REPORT_NAME) tests.info
	open report/src/index.html
	rm $(NAME)

check: 
	cppcheck *.c
	cp ../materials/linters/CPPLINT.cfg CPPLINT.cfg
	python3 ../materials/linters/cpplint.py --extension=c *.c
	rm -rf ./CPPßLINT.cfg ./CPPLINT.cfg 
