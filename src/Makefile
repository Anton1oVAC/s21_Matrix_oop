CC=g++ -std=c++17
FLAGS=-Wall -Werror -Wextra

PROJECT=s21_matrix_oop.cpp
s21_matrix_oop=s21_matrix_oop
O=s21_matrix_oop.o
A=s21_matrix_oop.a
BUILD=./


all: s21_matrix_oop.a

s21_matrix_oop.a:
	$(CC) -c s21_matrix_oop.cpp -o matrix_oop.o $(CFLAGS)
	ar rcs s21_matrix_oop.a matrix_oop.o


run:
	./$(B)

clang_n:
	clang-format -n *.cpp *.h 

clang_i:
	clang-format -i *.cpp *.h 


clean:
	rm -rf *.o 
	rm -rf *.a