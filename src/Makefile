CC=g++ -std=c++17
FLAGS=-Wall -Werror -Wextra
COVFLAG = --coverage
TEST_FLAGS = -lgtest -lgmock -pthread
PROJECT=s21_matrix_oop.cpp


all: s21_matrix_oop.a

s21_matrix_oop.a:
	$(CC) -c s21_matrix_oop.cpp -o matrix_oop.o $(CFLAGS)
	ar rcs s21_matrix_oop.a matrix_oop.o

test:
	$(CC) $(COVFLAG) s21_matrix_oop.cpp s21_test.cpp -o test $(TEST_FLAGS)
	./test

gcov_report: clean test
	lcov -o S21Matrix.info -c -d .
	genhtml -o report S21Matrix.info
	open ./

valgrind: test
	valgrind  --track-origins=yes --leak-check=full --show-leak-kinds=all -v ./test

clang_n:
	clang-format -n *.cpp *.h 

clang_i:
	clang-format -i *.cpp *.h 

clean:
	rm -rf *.o 
	rm -rf *.a
	rm -rf test
	rm -rf *.gcda
	rm -rf *.gcno
	rm -rf *.info