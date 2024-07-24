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
  S21Matrix minor_matrix(int rows, int cols);
  void remove_matrix();

 public:
  // Конструкторы и Деструктор
  S21Matrix();
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix& other);
  S21Matrix(S21Matrix&& other);
  ~S21Matrix();

  // Метод
  bool equal_matrix(const S21Matrix& other);
  void sum_matrix(const S21Matrix& other);
  void sub_matrix(const S21Matrix& other);
  void mul_number(const double num);
  void mul_matrix(const S21Matrix& other);
  S21Matrix transpose();
  double determinant();
  S21Matrix calc_complements();
  S21Matrix inverse_matrix();

  //  Перегрузка операторов
  S21Matrix& operator=(const S21Matrix& other);
  bool operator==(const S21Matrix& other);
  double& operator()(int row, int col);
  S21Matrix& operator+=(const S21Matrix& other);
  S21Matrix operator+(const S21Matrix& other);
  S21Matrix& operator-=(const S21Matrix& other);
  S21Matrix operator-(const S21Matrix& other);
  S21Matrix& operator*=(const double num);
  S21Matrix operator*(const double num);
  S21Matrix& operator*=(const S21Matrix& other);
  S21Matrix operator*(const S21Matrix& other);

  // Геттер
  int get_rows() const;
  int get_cols() const;

  // Сеттер
  void set_rows(int rows);
  void set_cols(int cols);
};

#endif