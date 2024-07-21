#ifndef S21_MATRIX_H
#define S21_MATRIX_H

#include <cmath>
#include <cstring>
#include <iostream>

class S21Matrix {
 private:
  int rows_, cols_ = 0;
  double**
      matrix_;  // Двойной указатель на ячейку памяти, где храниться матрица

  // Доп. методы
  void allocate_matrix();
  void copy_matrix_value(const S21Matrix& other);
  bool matrix_size_eq(const S21Matrix& orher);
  void remove_matrix();

 public:
  // Конструкторы и Деструктор
  S21Matrix();
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix& other);
  ~S21Matrix();

  // Метод
  bool equal_matrix(const S21Matrix& other);
  void sum_matrix(const S21Matrix& other);

  //  Перегрузка операторов
  S21Matrix& operator=(const S21Matrix& other);
  bool operator==(const S21Matrix& other);
  double& operator()(int row, int col);
  S21Matrix& operator+=(const S21Matrix& other);
  S21Matrix operator+(const S21Matrix& other);
};

#endif