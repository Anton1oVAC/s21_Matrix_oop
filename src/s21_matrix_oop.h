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

  void S21Matrix::allocate_matrix();
  void S21Matrix::copy_matrix_value(const S21Matrix& other);

  void remove_matrix();

 public:
  S21Matrix();
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix& other);
  ~S21Matrix();

  bool equal_matrix(const S21Matrix& other);
};

#endif